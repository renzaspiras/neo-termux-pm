import os

# Define the directory containing the scripts
script_dir = os.path.expanduser("~/apps")

# Iterate over subdirectories and run up.sh scripts
for root, dirs, files in os.walk(script_dir):
    if "up.sh" in files:
        script_path = os.path.join(root, "up.sh")
        print(f"Running script: {script_path}")
        os.system(f"bash {script_path}")
