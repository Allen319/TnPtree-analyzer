#include <iostream>
#include <algorithm>
#include <PhotonPrescales.h>
#include <HZZException.h>
#include "yaml-cpp/yaml.h"


PhotonPrescales::PhotonPrescales(std::string configPath, bool isMC, unsigned int run, unsigned int lumi)
    : photonTriggers_{GetTriggers(configPath)},
      isSim_{isMC},
      run_{run},
      lumi_{lumi} {}


std::vector<double> PhotonPrescales::GetThresholdsBinning() const {
  std::vector<double> binEdges;
  binEdges.emplace_back(0.);
  for (auto const &trigger : photonTriggers_) {
    binEdges.emplace_back(trigger.threshold);
  }
  if (binEdges.back() < 1500.) {
    binEdges.emplace_back(1500.);
  }
  return binEdges;
}

void PhotonPrescales::Update(int run, int lumi) {
  run_ = run;
  lumi_ = lumi;
}

int PhotonPrescales::GetPhotonPrescale(double photonPt) const {
  // First determine which trigger to use, by photonPt, and retrieve the prescale map
  const PhotonTrigger* trigger = FindTrigger(photonPt);
  int prescale = 1;

  if (isSim_) return 1;  // fast return if is not data

  // For run number, every run shall exisit in the list
  auto lumiMap = trigger->prescaleMap->find(run_);
  if (lumiMap == trigger->prescaleMap->end()) {
    std::cout << "[PhotonPrescales::GetPhotonPrescale] Cannot find run " << run_
             << " in the prescale table!" << std::endl;
    return 1;
  }
  // For lumi number, only the lowest lumi of each prescale is recorded
  auto ilumi = (lumiMap->second).upper_bound(lumi_);
  if (ilumi != (lumiMap->second).begin()) ilumi--;
  if (lumi_ < ilumi->first) {
    std::cout << "[PhotonPrescales::GetPhotonPrescale] Cannot find luminosity block "
             << lumi_ << " in run " << run_
             << " in the prescale table! Apply default prescale of 1." << std::endl;
    return 1;
  }
  prescale = ilumi->second;

  return prescale;
}


std::vector<PhotonTrigger> PhotonPrescales::GetTriggers(std::string configPath) {
  std::vector<PhotonTrigger> photonTriggers;
  YAML::Node configNode = YAML::LoadFile(configPath);
  std::string psfilePath = configNode["photon_triggers"]["photon_prescale_map"].as<std::string>();
  YAML::Node psfileNode = YAML::LoadFile(psfilePath);

  auto const &parentNode = configNode["photon_triggers"]["triggers"];
  for (auto &node : parentNode){
    PhotonTrigger currentTrigger;
    currentTrigger.name = node["name"].as<std::string>();
    currentTrigger.threshold = node["threshold"].as<float>();

    // Loading the prescale map from the yaml file
    YAML::Node trigNode = psfileNode[currentTrigger.name];
    if (!trigNode) {
      std::cout << "[PhotonPrescales::GetTriggers] Cannot find the prescale map for trigger "
               << currentTrigger.name << std::endl;
      continue;
    }
    // Create the map object
    auto* psmap = new std::map<unsigned, std::map<unsigned,int>>;
    for (auto rnode : trigNode) {
      unsigned run = rnode.first.as<unsigned>();
      std::map<unsigned,int> lumiMap;
      for (auto lnode : rnode.second) {
        lumiMap[lnode.first.as<unsigned>()] = lnode.second.as<int>();
      }
      (*psmap)[run] = std::move(lumiMap);
    }
    currentTrigger.prescaleMap.reset(psmap);

    photonTriggers.emplace_back(std::move(currentTrigger));
  }
  std::sort(photonTriggers.begin(), photonTriggers.end());
  return photonTriggers;
}


const PhotonTrigger* PhotonPrescales::FindTrigger(double photonPt) const {
  int expectedTriggerNum = -1;

  for (unsigned trigNum = 0; trigNum < photonTriggers_.size(); trigNum++) {
    if (photonTriggers_[trigNum].threshold < photonPt) {
      expectedTriggerNum = trigNum;
    }
    else break;
  }
  if (expectedTriggerNum == -1) {
    std::cout << "[PhotonPrescales::FindTrigger] No expected photon trigger threshold could be found."
             << std::endl;
    return nullptr;
  }

  return &photonTriggers_[expectedTriggerNum];
}
