#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTableWidgetItem>>
#include "playerclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void removePlayerByGunID(int gunID);
    void resetPlayersList();
    void updatePlayersListWidget();
private slots:
    void on_SearchPlayersButton_clicked();
    void onResultSearchPlayers();
    void downloading(qint64, qint64 );

    void on_TablePlayers_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *netwerkmanager;
    QNetworkRequest request;
    QList<QSharedPointer<playerClass>> players;

};
#endif // MAINWINDOW_H
