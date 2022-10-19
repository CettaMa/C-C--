import json
from struct import pack

manufacture = {
    "toyota" : {
        "year" : 2015,
        "model" : "prius",
        "transmission" : "automatic"
    }
}
with open("/home/cetta/Documents/Vcode/C C++/Python/Sandbox/File/car.json","w") as outfile :
	json.dump(manufacture, outfile,indent=4)

with open("/home/cetta/Documents/Vcode/C C++/Python/Sandbox/File/car.json","r") as p :
	file=json.load(p)
for keys,asset in file.items():
	print(keys,asset["year"])