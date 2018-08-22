﻿#ifndef HOME_H
#define HOME_H

#include "messagethread.h"
#include "message.h"
#include "dialog.h"
#include "purchase.h"
#include "useritem.h"
#include "creatgroup.h"
#include "filecontext.h"

#include <QWidget>
#include <QThread>
#include <QHash>
#include <QList>
#include <QTime>
#include <QJsonObject>
#include <QtWebEngineWidgets/QWebEngineView>

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    QString Token;
    QString userName;
    explicit Home(QWidget *parent = 0);
    ~Home();
    void startListen();
public slots:
    void updateList(QJsonObject list);
    void newMsg(Message*);
    void updateStatus(int,QString);
    void sendNewFile(QString,qint64,QString);
    void setProgress(QString,qint64,qint64);
    void newJoinedGroup(QString);

private:
    Ui::Home *ui;
    QThread* thread;
    MessageThread* messageThread;
    Purchase* purchase;
    FileContext* webContext;
    QString currentUser;
    void changeSelected();
    void insertTime(QTime);
    QWebEngineView* chat;
    QHash<QString,QString> usernameAvatar;
    QHash<QString,QString> usernameEmail;
    QHash<QString, UserItem* > usernameItem;
    QHash<QString,QList<Message> > messageList;
    QHash<QString,QTime> userTime;
signals:
    void startThread();
    void sendMsg(QString,QString,QString,QString);
    void sendImg(QString,QString,QString,QString);
    void sendFile(QString,QString,QString,QString);
    void creatGroup(QString,QString,QList<QString>);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_4_clicked();
};

#endif // HOME_H
