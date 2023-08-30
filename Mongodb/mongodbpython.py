import pymongo
myclient=pymongo.MongoClient("mongodb://localhost:27017/")
mydb=myclient["mymongodatabase"]
mycol=mydb["customers"]
mydict={"name":'John', "address": "Highway 37"}
x=mycol.insert_one(mydict)
print(mydb.list_collection_names())
y=mycol.insert_one({"name": "Peter", "Address": "Lowstreet 27"})
print(y.inserted_id)
for z in mycol.find():
    print(z)