#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <QString>
#include <QJsonObject>

class playerClass
{
public:
    playerClass();
    playerClass(int gunID, QString playerName);



    int getGunID() const;
    void setGunID(int value);

    QString getPlayerName() const;
    void setPlayerName(const QString &value);

    void readFromJson(QJsonObject &json);

private:
    int gunID;
    QString playerName;

};

#endif // PLAYERCLASS_H
