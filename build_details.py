import os
import json
from datetime import datetime

now = datetime.now()
version = "1.0"
buildtime = now.strftime("%y.%m.%d %H:%M")

try:
    basedir = os.path.dirname(os.path.abspath(__file__))
except:
    basedir = "."

details_file = os.path.join(basedir, "version.json")
if not os.path.exists(details_file):
    with open(details_file, "w") as f:
        json.dump({"build_no": 0}, f)

with open(details_file, "r") as f:
    details = json.load(f)
    details["build_no"] += 1
    details["version"] = version
    details["buildtime"] = buildtime
with open(details_file, "w") as f:
    json.dump(details, f)

header_file = os.path.join(basedir, "lib/menu/pages", "versiondetails.h")

with open(header_file, "w") as f:
    f.write("#ifndef DEFENDERHUB_VERSIONDETAILS_H\n")
    f.write("#define DEFENDERHUB_VERSIONDETAILS_H\n")
    f.write(f"#define VERSION \"{details.get('version')}.{details.get('build_no')}\"\n")
    f.write(f"#define BUILDTIME \"{details.get('buildtime')}\"\n")
    f.write("#endif //DEFENDERHUB_VERSIONDETAILS_H\n")