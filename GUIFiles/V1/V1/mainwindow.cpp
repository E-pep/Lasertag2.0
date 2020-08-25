#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    netwerkmanager = new QNetworkAccessManager(this);
    QList<QString> m_strList = QList<QString>() << QString("gunID") << QString("playerName");
    ui->TablePlayers->setHorizontalHeaderLabels(m_strList);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/* API sends back list of players found*/
void MainWindow::on_SearchPlayersButton_clicked()
{
    //delete current saved players:
    this->resetPlayersList();

    qDebug() << "search players clicked";
    QUrl url("http://127.0.0.1:5000/getplayers");
    request.setUrl(url);
    QNetworkReply *reply = netwerkmanager->get(request);
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloading(qint64,qint64)));
    connect(reply, SIGNAL(finished()), this, SLOT(onResultSearchPlayers()));
}

void MainWindow::downloading(qint64 bytesReceived, qint64 bytesTotal) {
    qDebug() << "Downloading " << bytesReceived/bytesTotal*100 << " %.";
}


void MainWindow::onResultSearchPlayers()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*> (QObject::sender());
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error downloading. " << reply->errorString();
        return;
    }
    reply->deleteLater();
    QByteArray jsonArray = reply->readAll();
    qDebug().noquote() << "bytearray:" << jsonArray;
    QJsonDocument replyJson = QJsonDocument::fromJson(jsonArray);
    QJsonObject obj = replyJson.object();
    QJsonArray playersarray = obj["players"].toArray();
    for(int i =0; i < playersarray.size(); i++)
    {
        QJsonObject tempObj = playersarray[i].toObject();
        playerClass *player = new playerClass();
        player->readFromJson(tempObj);
        this->players.append(QSharedPointer<playerClass>(player));
    }
    this->updatePlayersListWidget();
}


void MainWindow::removePlayerByGunID(int gunID)
{
    for (int i = 0; i < this->players.size(); ++i) {
        if (this->players.at(i)->getGunID() == gunID)
            this->players.removeAt(gunID);
    }
    //qDebug() << "playerlist removed:" << this->players;
}
void MainWindow::resetPlayersList()
{
    for(auto&& player: players)
    {
        player.clear();
    }
    players.clear();
}


void MainWindow::updatePlayersListWidget()
{
    ui->TablePlayers->blockSignals(true);
    qDebug() << "playersize" << players.size();
    this->ui->TablePlayers->setRowCount(0);
    QList<QString> m_strList = QList<QString>() << QString("gunID") << QString("playerName");
    ui->TablePlayers->setHorizontalHeaderLabels(m_strList);
    foreach(QSharedPointer<playerClass> player,players)
    {
        this->ui->TablePlayers->insertRow(ui->TablePlayers->rowCount());
        // set GunID
        this->ui->TablePlayers->setItem(ui->TablePlayers->rowCount()-1, 0, new QTableWidgetItem((QString::number(player->getGunID()))));
        // GunID not edible
        this->ui->TablePlayers->item(ui->TablePlayers->rowCount()-1, 0)->setFlags(Qt::NoItemFlags);
        this->ui->TablePlayers->setItem(ui->TablePlayers->rowCount()-1, 1, new QTableWidgetItem(player->getPlayerName()));
    }
    ui->TablePlayers->blockSignals(false);
}

void MainWindow::on_TablePlayers_itemChanged(QTableWidgetItem *item)
{
    qDebug() << "item veranderd in players table";
}
