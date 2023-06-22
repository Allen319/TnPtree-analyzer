#!/usr/bin/env python3

import os
import sys
# Set the initial left and right edges
left_edge = 25
right_edge = 30

if len(sys.argv) < 4:
    print("Usage: python prepare_jobs <input_dir> <output_dir> <config_path>")
else:
   input_tmp = sys.argv[1]
   output_tmp = sys.argv[2]
   config_tmp = sys.argv[3]
input_dir = os.path.abspath(input_tmp)
output_dir = os.path.abspath(output_tmp)
config_path = os.path.abspath(config_tmp)
if not os.path.isdir(output_dir):
    os.mkdir(output_dir)
current_path = os.getcwd()
# Loop while the right edge is less than or equal to 100
while right_edge <= 420:
    # Generate the command with the current left and right edges
    command = f"{current_path}/bin/getEff --input {input_dir} --output eff{left_edge}.root --left-edge {left_edge} --right-edge {right_edge} --config {config_path}"

    # Generate the job script
    job_script = f"""#!/bin/bash
cd {output_dir}
cp {current_path}/env_lcg.sh .
. ./env_lcg.sh
sleep 5
{command}
"""

    # Write the job script to a file
    with open(f"{output_dir}/job_script_{left_edge}_{right_edge}.sh", "w") as f:
        f.write(job_script)

    # Update the edges for the next iteration
    right_edge += 5
    left_edge = right_edge - 5

