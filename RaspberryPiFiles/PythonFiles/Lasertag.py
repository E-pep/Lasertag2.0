#!/usr/bin/python

import json
from flask import jsonify
from flask import request
from flask import make_response
from flask import make_response
from flask_api import FlaskAPI
import Classes
# import RPi.GPIO as GPIO

# This function is called when we need to find players using the wireless module
def FindPlayersWireless(Game):
    #For now we are going to add dummy players
    player1 = Classes.Player(1, "Player1")
    Game.addPlayer(player1)
    player2 = Classes.Player(2, "Player2")
    Game.addPlayer(player2)

# Save the data to the main JSON file
def SaveJSONFile(Game):
    with open('GameInfo.json', 'w') as file:
        json.dump(Game.serialize(), file)


# When a player needs to be deleted
def RemovePlayerByGunID(Game, GunID):
    Game.removePlayerByGunID(GunID)

# When A player scores a point (etc. capture the flag)
def AddPointsToPlayer(Game, GunID):
    Game.addPointToPlayer(GunID)

def AddKillToPlayer(Game, GunID):
    Game.addKillToPlayer(GunID)

def AddDeathToPlayer(Game, GunID):
    Game.addDeathToPlayer(GunID)






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

    # Add 2 Teams Standard
    Team1 = Classes.Team(1,"Red", "Red")
    Team2 = Classes.Team(2, "Blue", "Blue")
    Game.addTeam(Team1)
    Game.addTeam(Team2)

    # Initialize add players with guns on
    FindPlayersWireless(Game)
    print("Players:")
    print(Game.Players)
    # RemovePlayerByGunID(Game,1)
    print("Players:")
    print(Game.Players)
    SaveJSONFile(Game)
    AddKillToPlayer(Game,1)
    AddDeathToPlayer(Game,1)
    AddPointsToPlayer(Game,1)
    SaveJSONFile(Game)


    # Intialisation functions



    # app.run()