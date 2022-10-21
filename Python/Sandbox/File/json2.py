import json
from struct import pack

manufacture = {
    "toyota" : {
        "year" : 2015,
        "model" : "prius",
        "transmission" : "automatic"
    }
}
with open("Python/Sandbox/File/car.json","w") as f:
    json.dump(manufacture, f)

with open("Python/Sandbox/File/car.json","r") as p :
	file=json.load(p)

for keys,asset in file.items():
	print(keys,asset["year"])