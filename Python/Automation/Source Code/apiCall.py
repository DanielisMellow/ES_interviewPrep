import requests
import json

baseUrl = "https://api.upcitemdb.com/prod/trial/lookup"
parameters = {"upc": "012993441012"}
response = requests.get(baseUrl, params=parameters)
# print(response.url)

content = response.content
info = json.loads(content)
# print(info)
item = info["items"]
itemInfo = item[0]
title = itemInfo["title"]
brand = itemInfo["brand"]
print(title)
print(brand)
