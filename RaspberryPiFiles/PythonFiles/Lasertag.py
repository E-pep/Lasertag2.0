#!/usr/bin/python

import json
from flask import jsonify
from flask import request
from flask import make_response
from flask import make_response
from flask_api import FlaskAPI
import Classes
# import RPi.GPIO as GPIO


# Classes made for the Lasertag 2.0 game


# Setup Functions to call to initialize

## Init game with 0 players and init data

# This function is called when we need to find players using the wireless module
def FindPlayersWireless(Game):
    #For now we are going to add dummy players
    player1 = Classes.Player(1, "Player1")
    Game.addPlayer(player1)
    player2 = Classes.Player(2, "Player2")
    Game.addPlayer(player2)

def RemovePlayerByGunID(Game, GunID):
    Game.removePlayerByGunID(GunID)


app = FlaskAPI(__name__)

@app.route('/')
def hello_world():
    # return 'Hello, World!'
    list = [
        {'a': 1, 'b': 2},
        {'a': 5, 'b': 10}
    ]
    return list

# @app.route('/getplayers', methods=['GET'])
# def getPlayers():
#     p1 = player(1, "test1",1)
#     p2 = player(2, "test2",2)
#     p3 = player(3, "test3",3)
#     players = [p1, p2, p3]
#     print(players)
#
#     playerListOfDicts = [obj.serialize() for obj in players]
#
#     return {"players":playerListOfDicts}

@app.route('/removeplayer', methods=['POST'])
def removePlayer():
    print("removing player")
    data = request.form
    print(data)


if __name__ == "__main__":
    # Main Game Variable
    Game = Classes.Game("Deadmatch", 10, 7500,1)
    FindPlayersWireless(Game)

    print("Players:")
    print(Game.Players)
    RemovePlayerByGunID(Game,1)
    print("Players:")
    print(Game.Players)

    # Intialisation functions



    # app.run()