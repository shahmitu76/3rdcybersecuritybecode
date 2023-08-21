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
