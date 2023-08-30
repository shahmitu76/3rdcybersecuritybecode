# To install Mongodb
1. Use the link: <https://www.mongodb.com/try/download/community>
2.  Click on download and install mongodb.

3.  Your files will be downloaded in C:\Program Files\MongoDB\Server\7.0\bin". Set  the path of system variable PATH to bin folder: "C:\Program Files\MongoDB\Server\7.0\bin"

4. While installing, it will give the option to separately install mongo shell: click on it or if you skip it, go to <https://www.mongodb.com/try/download/shell> and download mongodb shell .
5. It will download a zip file. Extract it and it will have mongosh.exe file. This file has to be put into bin folder where other exe files are there like mongod.exe: -  "C:\Program Files\MongoDB\Server\7.0\bin"

7. Note that we have to separately install mongosh in higher versions of mongodb.
8. Also, we have to make data folder. I created in "C:\mongodb\data". Here mongodb will store its data.

# How to run Mongodb

1. Go to command prompt and type mongodb --dbpath "c:\mongodb\data". You have to specify the path to data folder.
2. it will run mongodb server.
3. Open another instance of command prompt and type mongosh. It will run mongo shell.
4. You will get the cursor of test>, which shows that we are already in test database.

# Starting with Mongodb and commands

1. Show dbs: gives you all the list of databases
2. use <database name> : to start using existing database
3. show collections: to see if there is any document collection in the test database or schema

# Procedure

1. **Create a database example:** use example . Result:switched to db example
2. **Create a collection cars in the example :** db.createCollection("cars"). Result: { ok: 1 }
3. **Check whether collection has been made or not:**
example> show collections
Result:cars
4. **Insert a document/record:**
example> db.car.insertOne({
... Name: 'Honda',
... Make:'accord',
... Year:'2010'})

Result:
{
  acknowledged: true,
  insertedId: ObjectId("64e4687314880d938c2b9c78")
}

5. **Updation of record:**
 example> db.car.updateOne({Name:'Ford'}, {$set:{Make:'Wagon',Year:'2000'}})
{
  acknowledged: true,
  insertedId: null,
  matchedCount: 1,
  modifiedCount: 1,
  upsertedCount: 0
}
example> db.car.find()
[
  {
    _id: ObjectId("64e4678b14880d938c2b9c77"),
    Name: 'Ford',
    Make: 'Wagon',
    Year: '2000'
  },
  {
    _id: ObjectId("64e4687314880d938c2b9c78"),
    Name: 'Honda',
    Make: 'accord',
    Year: '2010'
  }
]

6. **To add a new record in a collection:**
 example> db.car.updateOne({Name:'Ford'}, {$set:{ transmission: 'automatic'}}, {upsert:true})
 
 Result:
{
  acknowledged: true,
  insertedId: null,
  matchedCount: 1,
  modifiedCount: 1,
  upsertedCount: 0
}
example> db.car.find() //To check the collection again

Result:

[
  {
    _id: ObjectId("64e4678b14880d938c2b9c77"),
    Name: 'Ford',
    Make: 'Wagon',
    Year: '2000',
    transmission: 'automatic'
  },
  {
    _id: ObjectId("64e4687314880d938c2b9c78"),
    Name: 'Honda',
    Make: 'accord',
    Year: '2010'
  }
]

7. **To delete the record:**
 example> db.car.deleteOne({Name:'Honda'})
 Result:
{ acknowledged: true, deletedCount: 0 }
example> db.car.find() //check it
[
  {
    _id: ObjectId("64e4678b14880d938c2b9c77"),
    Name: 'Ford',
    Make: 'Wagon',
    Year: '2000',
    transmission: 'automatic'
  }
]
example>

8. **To insert a document in a loop**
 example> for (var i=0;i<10;i++) {db.cars.insertOne({x:i})} //added into cars 
 
 Result:
{
  acknowledged: true,
  insertedId: ObjectId("64e4789814880d938c2b9c82")
}
example> db.cars.find() // *to check it*

Result:
[
  { _id: ObjectId("64e4789814880d938c2b9c79"), x: 0 },
  { _id: ObjectId("64e4789814880d938c2b9c7a"), x: 1 },
  { _id: ObjectId("64e4789814880d938c2b9c7b"), x: 2 },
  { _id: ObjectId("64e4789814880d938c2b9c7c"), x: 3 },
  { _id: ObjectId("64e4789814880d938c2b9c7d"), x: 4 },
  { _id: ObjectId("64e4789814880d938c2b9c7e"), x: 5 },
  { _id: ObjectId("64e4789814880d938c2b9c7f"), x: 6 },
  { _id: ObjectId("64e4789814880d938c2b9c80"), x: 7 },
  { _id: ObjectId("64e4789814880d938c2b9c81"), x: 8 },
  { _id: ObjectId("64e4789814880d938c2b9c82"), x: 9 }
  
  
] 


Schema-collection-document

9. **To add many documents in one time. Use of array, boolean type**
 example> db.student.insertMany([ {name:'Jane',undergrad:false,units:12, classes:['geography','science','journalism','history']},{name:'Kevin',undergrad:true,units:3,classes:['geography']}])
 
 Result:
{
  acknowledged: true,
  insertedIds: {
    '0': ObjectId("64e47e0f14880d938c2b9c84"),
    '1': ObjectId("64e47e0f14880d938c2b9c85")
  }
}
example> db.student.find() //to check
[
  {
    _id: ObjectId("64e47bb314880d938c2b9c83"),
    name: 'Joe',
    undergrad: true,
    units: 9,
    classes: [ 'geography', 'math', 'journalism' ]
  },
  {
    _id: ObjectId("64e47e0f14880d938c2b9c84"),
    name: 'Jane',
    undergrad: false,
    units: 12,
    classes: [ 'geography', 'science', 'journalism', 'history' ]
  },
  {
    _id: ObjectId("64e47e0f14880d938c2b9c85"),
    name: 'Kevin',
    undergrad: true,
    units: 3,
    classes: [ 'geography' ]
  }
] 

10. **To find the documents who have units greater than 6**

example> db.student.find({units:{$gt:6}})

Result:

[
  {
    _id: ObjectId("64e47bb314880d938c2b9c83"),
    name: 'Joe',
    undergrad: true,
    units: 9,
    classes: [ 'geography', 'math', 'journalism' ]
  },
  {
    _id: ObjectId("64e47e0f14880d938c2b9c84"),
    name: 'Jane',
    undergrad: false,
    units: 12,
    classes: [ 'geography', 'science', 'journalism', 'history' ]
  }
]

11. **To find all the documents for the students who are enrolled in classes: history or geography( It has to be array, for using in operator)**

example> db.student.find({classes:{$in:['history','geography']}}
)

Result:

[
  {
    _id: ObjectId("64e47bb314880d938c2b9c83"),
    name: 'Joe',
    undergrad: true,
    units: 9,
    classes: [ 'geography', 'math', 'journalism' ]
  },
  {
    _id: ObjectId("64e47e0f14880d938c2b9c84"),
    name: 'Jane',
    undergrad: false,
    units: 12,
    classes: [ 'geography', 'science', 'journalism', 'history' ]
  },
  {
    _id: ObjectId("64e47e0f14880d938c2b9c85"),
    name: 'Kevin',
    undergrad: true,
    units: 3,
    classes: [ 'geography' ]
  }
]

12. **sort operator**
 example> db.student.find({ classes: { $in: ['geography'] } }).sort({ units: 1 }) //ascending
 
 Result:
 
[
  {
    _id: ObjectId("64e47e0f14880d938c2b9c85"),
    name: 'Kevin',
    undergrad: true,
    units: 3,
    classes: [ 'geography' ]
  },
  {
    _id: ObjectId("64e47bb314880d938c2b9c83"),
    name: 'Joe',
    undergrad: true,
    units: 9,
    classes: [ 'geography', 'math', 'journalism' ]
  },
  {
    _id: ObjectId("64e47e0f14880d938c2b9c84"),
    name: 'Jane',
    undergrad: false,
    units: 12,
    classes: [ 'geography', 'science', 'journalism', 'history' ]
  }
]


Ref: <https://www.w3schools.com/mongodb/mongodb_mongosh_insert.php>
      <https://www.mongodb.com/docs/v3.2/reference/method/>
      <https://www.udemy.com/course/mongodb-essentials/learn/lecture/4322786#content>
      <https://www.mongodb.com/docs/v3.2/crud/>
      
      
#  Python MongoDB

Navigate your command line to the location of PIP, and type the following:

**Download and install "PyMongo":**

C:\Users\Your Name\AppData\Local\Programs\Python\Python36-32\Scripts>python -m pip install pymongo

Now you have downloaded and installed a mongoDB driver.


# To check whether particular collection exists in python

collist = mydb.list_collection_names()
if "customers" in collist: //we have already made customers collection
  print("The collection exists.")


# How To Use MongoDB in a Flask Application


      