# class for  players
class Player:
    def __init__(self, gunID, playerName):
        self.gunID = gunID
        self.playerName = playerName
        self.Kills = 0
        self.Points = 0
        self.Deaths = 0
    def serialize(self):
        return{
        'gunID' : self.gunID,
        'playerName' : self.playerName,
        'Kills' : self.Kills,
        'Points' : self.Points,
        'Deaths' : self.Deaths
        }

    def AddPoint(self):
        self.Points = self.Points + 1

    def AddKill(self):
        self.Kills = self.Kills + 1

    def AddDeath(self):
        self.Deaths = self.Deaths + 1

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
        'Teams' : [obj.serialize() for obj in self.Teams],
        'Players' : [obj.serialize() for obj in self.Players]
        }

    def addPointToPlayer(self, GunID):
        for i,player in enumerate(self.Players):
            if player.gunID == GunID:
                self.Players[i].AddPoint()
                return True
            return False

    def addKillToPlayer(self, GunID):
        for i,player in enumerate(self.Players):
            if player.gunID == GunID:
                self.Players[i].AddKill()
                return True
            return False

    def addDeathToPlayer(self, GunID):
        for i,player in enumerate(self.Players):
            if player.gunID == GunID:
                self.Players[i].AddDeath()
                return True
            return False