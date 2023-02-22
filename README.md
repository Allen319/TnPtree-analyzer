# TnPtree-analyzer

## Usage:
Follow
```
git clone https://github.com/Allen319/TnPtree-analyzer.git
cd TnPtree-analyzer
mkdir build
cd build
cmake ..
make -j$(nproc)
```

Simple test
```
./bin/addBranches --config config/electron.yaml --input /path/to/tree --output /path/to/output/XXX.root --year 2018 --isMC 0
```
