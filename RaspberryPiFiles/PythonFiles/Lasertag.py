#!/usr/bin/python

import json
from flask import jsonify
from flask import request
from flask import make_response
from flask import make_response
from flask_api import FlaskAPI
# import RPi.GPIO as GPIO


app = FlaskAPI(__name__)
# class for  players
class player:
    def __init__(self, gunID, playerName):
        self.gunID = gunID
        self.playerName = playerName

    def serialize(self):
        return{
        'gunID' : self.gunID,
        'playerName' : self.playerName
        }

# list of dummy players




@app.route('/')
def hello_world():
    # return 'Hello, World!'
    list = [
        {'a': 1, 'b': 2},
        {'a': 5, 'b': 10}
    ]
    return list

@app.route('/getplayers', methods=['GET'])
def getPlayers():
    p1 = player(1, "test1")
    p2 = player(2, "test2")
    p3 = player(3, "test3")
    players = [p1, p2, p3]
    print(players)

    playerListOfDicts = [obj.serialize() for obj in players]

    return {"players":playerListOfDicts}

@app.route('/removeplayer', method=['POST'])
def removePlayer():
    print("removing player")



if __name__ == "__main__":
    app.run()