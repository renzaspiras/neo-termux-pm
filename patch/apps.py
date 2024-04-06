import os
import subprocess

# Define the directory containing the scripts
apps_dir = os.path.expanduser("~/apps")

# Iterate over subdirectories and run up.sh scripts
apps = os.listdir(apps_dir)
processes = []
for app in apps:
    script_path = os.path.join(apps_dir, app, "up.sh")
    if os.path.isfile(script_path):
        process = subprocess.Popen(["bash", script_path])
        processes.append(process)

# Wait for all processes to finish
for process in processes:
    process.wait()
