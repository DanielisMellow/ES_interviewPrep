import csv
import json
from pprint import pprint

EINSTEIN = {
    "birthplace": "Germany",
    "name": "Albert",
    "surname": "Einstein",
    "born": "1879-03-14",
    "category": "physics",
    "motivation": "for his services to Theoretical Physics...",
}

with open("laureates.csv", "r") as f:
    reader = csv.DictReader(f)
    laureates = list(reader)


# 1. you can access parts of strings the same way you do lists
#      hey[2] == "y"
# 2. You can add to a list using
#      my_list.append("something")

laureates_beginning_with_a = []


for laureate in laureates:
    if laureate["name"][0] == "A":
        laureates_beginning_with_a.append(laureate)


with open("laureatesFiltered.json", "w") as f:
    json.dump(laureates_beginning_with_a, f, indent=2)
