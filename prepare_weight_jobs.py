import os

input_dir_preVFP = "/user/hanwen/tnp-samples/2016preVFP"
input_dir_postVFP = "/user/hanwen/tnp-samples/2016postVFP"
output_dir_postVFP = "/user/hanwen/photon-tnp-samples/2016postVFP"
output_dir_preVFP = "/user/hanwen/photon-tnp-samples/2016preVFP"

if not os.path.isdir("addweights"):
    os.mkdir("addweights")
current_path = os.getcwd()

template = """#!/bin/bash
cd /storage_mnt/storage/user/hanwen/TnPtree-analyzer/
. ./env_lcg.sh
sleep 5
/storage_mnt/storage/user/hanwen/TnPtree-analyzer/bin/addWeights --input {input_file} --output {output_file} -y 2016 -m 0 -c /storage_mnt/storage/user/hanwen/TnPtree-analyzer/config/photon.yaml
"""

def generate_scripts(input_dir, output_dir, prefix):
    file_list = os.listdir(input_dir)
    for file_name in file_list:
        if file_name.endswith(".root"):
            input_file = os.path.join(input_dir, file_name)
            output_file = os.path.join(output_dir, file_name)
            script_content = template.format(input_file=input_file, output_file=output_file)
            script_name = f"addweights/{prefix}_{file_name.replace('.root', '.sh')}"
            
            with open(script_name, "w") as script_file:
                script_file.write(script_content)
                
            print(f"Generated script: {script_name}")

generate_scripts(input_dir_preVFP, output_dir_preVFP, "preVFP_script")
generate_scripts(input_dir_postVFP, output_dir_postVFP, "postVFP_script")

