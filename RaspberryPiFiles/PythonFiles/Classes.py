# class for  players
class Player:
    def __init__(self, gunID, playerName):
        self.gunID = gunID
        self.playerName = playerName
    def serialize(self):
        return{
        'gunID' : self.gunID,
        'playerName' : self.playerName,
        }

# class for each team
class Team:
    def __init__(self, TeamID, TeamName, TeamColor):
        self.TeamID = TeamID
        self.TeamName = TeamName
        self.TeamColor = TeamColor

    def serialize(self):
        return{
        'TeamID' : self.TeamID,
        'TeamName' : self.TeamName,
        'TeamColor': self.TeamColor
        }

class Game:
    def __init__(self, GameType, Duration, MaxPoints, DamageRate):
        self.GameType = GameType
        self.Duration = Duration
        self.MaxPoints = MaxPoints
        self.DamageRate = DamageRate
        self.Teams = []
        self.Players = []

    def addTeam(self, Team):
        self.Teams.append(Team)

    def addPlayer(self, Player):
        self.Players.append(Player)

    def removePlayerByGunID(self, GunID):
        for i,player in enumerate(self.Players):
            if player.gunID == GunID:
                del self.Players[i]
                return True
            return False

    def serialize(self):
        return{
        'GameType' : self.GameType,
        'Duration' : self.Duration,
        'MaxPoints' : self.MaxPoints,
        'Players' : self.players
        }


