import json

manufacture = {
    "toyota" : {
        "year" : 2015,
        "model" : "prius",
        "transmission" : "automatic"
    }
}
with open("car.json","w") as outfile :
    json.dump(manufacture, outfile)