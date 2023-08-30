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

# How to activate already existing virtual environment

1. Go to virtual env dir:C:\Githubciscopackettraceractivity\2ndcybersecurityBecode\project-dir\venv
2. To activate virtual environment: scripts\activate
3. will get a prompt (venv)
4. you are in your virtual env venv
5. Trouble shooting: when I try to run flask, it gives the error: module flask not found
 Solution( found after wasting whole 3 hrs): 
 - go to the dir where app.py is : (venv) PS C:\Githubciscopackettraceractivity\2ndcybersecurityBecode\project-dir\app>
 - make sure virtual environment is activated
 - there you set flask environment byn these 2 commands:
            - set FLASK_APP=app
            - set FLASK_ENV=development
 - After this when I try to run flask:python -m flask run, it says can't find flask sqlAlchemy. That means I have to install flask SQLAlchemy
 - Check which all pip packages are installed: python -m pip list
 - It gave me this:Package         Version
--------------- -----------
anyio           3.7.1
blinker         1.6.2
certifi         2023.7.22
click           8.1.6
colorama        0.4.6
dnspython       2.4.0
email-validator 2.0.0.post2
Flask           2.3.2
Flask-WTF       1.1.1
h11             0.14.0
httpcore        0.17.3
idna            3.4
itsdangerous    2.1.2
Jinja2          3.1.2
MarkupSafe      2.1.3
pip             23.2.1
setuptools      65.5.0
sniffio         1.3.0
Werkzeug        2.3.6
WTForms         3.0.1
so no flask-sqlalchemy.

- Install Flask-SQLAlchemy:python -m pip install Flask-SQLAlchemy, and it is installed :)
6. Now run flask again: python -m flask run: it again gives error about pymongo not found because my mongod is not running.
          - So open 2 command prompts
          - 1st- mongod
          - 2nd- mongosh
7. Now again run flask and it will run successfully(on 3rd command prompt)


# How to check both databases(mysql and mongodb)

1. **MySql**: Go to workbench and go to your schema(mydatabaseflask). Click on the table required under it(course). Right click on course and select first option of query. It will show you all the data.
2. **Mongodb**: - Go to mongosh command prompt.
            - Type 'show dbs' // to check all the databases
            - in the list you will see flask_db
            - type 'use flask_db' . You will get the prompt of flask_db
            -type 'show collections'
            -it will show'todos'
            -type 'db.todos.find()'
            -It will show the list of all documents. You can see the latest record which you have inserted.


 