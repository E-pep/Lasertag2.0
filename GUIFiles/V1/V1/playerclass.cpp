#include "playerclass.h"

playerClass::playerClass()
{

}

playerClass::playerClass(int gunID, QString playerName)
{
    this->setGunID(gunID);
    this->setPlayerName(playerName);
}

int playerClass::getGunID() const
{
    return gunID;
}

void playerClass::setGunID(int value)
{
    gunID = value;
}

QString playerClass::getPlayerName() const
{
    return playerName;
}

void playerClass::setPlayerName(const QString &value)
{
    playerName = value;
}

void playerClass::readFromJson(QJsonObject &json)
{
    this->setGunID(json["gunID"].toInt());
    this->setPlayerName(json["playerName"].toString());
}
