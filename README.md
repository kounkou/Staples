# Staples


[![Build Status](https://travis-ci.org/kounkou/Staples.svg?branch=master)](https://travis-ci.org/kounkou/Staples)
[![codecov.io](https://codecov.io/github/kounkou/Staples/coverage.svg?branch=master)](https://codecov.io/github/kounkou/Staples?branch=master)
[![Issue Count](https://codeclimate.com/github/kounkou/Staples/badges/issue_count.svg)](https://codeclimate.com/github/kounkou/Staples)


Staples is an Android application that enables controlling your household staples
The application is made of clients, and a server hosted on some personal
machine. In my particular case, the server side is hosted on a Raspberry PI
The server provide information with the following format :

```c++
data.json

 "{
    "status":
    "ok",
    "data":
    {
       "staples":
       {
          "water"  :{ "exp"  : "20180501", "name" : "Vitel",    "price": "0.50" },
          "juice"  :{ "exp"  : "20170501", "name" : "Orangina", "price": "1.50" }          
       }
       ...
```

The information contained inside data.json are fetched from client(s) applications.The server application is updated with *.in_json files.
Here below, you can find some pictures of the application in development.

<p align="center">
  <img src="images/home.png" width="350"/>
  <img src="images/main_screen.png" width="350"/>
</p> 
