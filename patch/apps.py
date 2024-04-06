import os

# Define the directory containing the scripts
apps_dir = os.path.expanduser("~/apps")

# Iterate over subdirectories and run up.sh scripts
apps = os.listdir(apps_dir)
for j in apps:
  os.system("bash ~/apps/" + j + "/up.sh")