#!/usr/bin/env python3

import os

# Set the initial left and right edges
left_edge = 50
right_edge = 55

if not os.path.isdir("jobs"):
    os.mkdir("jobs")
current_path = os.getcwd()
# Loop while the right edge is less than or equal to 100
while right_edge <= 250:
    # Generate the command with the current left and right edges
    command = f"{current_path}/bin/getEff --input {current_path}/input.root --output eff{left_edge}.root --left-edge {left_edge} --right-edge {right_edge} --config {current_path}/config/photonHLT.yaml"

    # Generate the job script
    job_script = f"""#!/bin/bash
cd {current_path}/jobs
cp {current_path}/env_lcg.sh .
. env_lcg.sh
sleep 5
{command}
"""

    # Write the job script to a file
    with open(f"jobs/job_script_{left_edge}_{right_edge}.sh", "w") as f:
        f.write(job_script)

    # Update the edges for the next iteration
    right_edge += 5
    left_edge = right_edge - 5

