#!/bin/bash

# Set the initial left and right edges
left_edge=50
right_edge=55

# Loop while the right edge is less than or equal to 100
while (( right_edge <= 250 )); do
  # Run the command with the current left and right edges
  ./bin/makeHisto --input samples/2018/2018AllData.root --output /Users/allen/TnPtree-analyzer/output --left-edge $left_edge --right-edge $right_edge --config config/photonHLT.yaml

  # Update the edges for the next iteration
  right_edge=$(( right_edge + 5 ))
  left_edge=$(( right_edge - 5 ))
done

