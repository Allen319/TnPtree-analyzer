cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(tnpfit CXX)
# Require C++17 in all targets
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -pedantic)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

find_package(ROOT 6 REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(Boost REQUIRED
  COMPONENTS program_options
)

add_library(tnpfit SHARED
  src/PhotonPrescales.cc
  src/Options.cc
)
target_include_directories(tnpfit PUBLIC include)
target_link_libraries(tnpfit
  PUBLIC ROOT::Hist ROOT::MathCore ROOT::Physics ROOT::Tree ROOT::TreePlayer
  PUBLIC yaml-cpp
  PUBLIC Boost::program_options
)
add_executable(makeHisto src/makeHisto.cc)
target_link_libraries(makeHisto PRIVATE tnpfit Boost::program_options ROOT::ROOTDataFrame)

add_executable(addWeights src/addWeights.cc)
target_link_libraries(addWeights PRIVATE tnpfit PUBLIC ROOT::Tree yaml-cpp)

add_executable(addBranches src/addBranches.cc)
target_link_libraries(addBranches PRIVATE tnpfit PUBLIC ROOT::Tree yaml-cpp)
#install(TARGETS addWeights DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
#set(SHELL_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/env.sh)
#execute_process(
#  COMMAND bash ${SHELL_SCRIPT}
#  RESULT_VARIABLE SCRIPT_RESULT
#)
#if(SCRIPT_RESULT EQUAL 0)
#  message("脚本执行成功")
#else()
#  message("脚本执行失败")
#endif()
#get_filename_component(INSTALL_DIR ${CMAKE_SOURCE_DIR}/bin ABSOLUTE)
#set(ENV{PATH} "$ENV{PATH}:${INSTALL_DIR}")
