#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <dirent.h>
#include <QTimer>
#include <stdlib.h>
#include <QByteArray>
#include <QDebug>
#include <QVector>
#include <QList>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <QTextCodec>
typedef   struct
{
    int time;
    char MyLyric[256];
}lyric;
struct ViewInformation
{
    QString song;
    QString singer;
    QString album;
    QString nowtime;
    int alltime;
    QString lyric;
    int progress;
    int hub;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
extern void *MyGetTimeAndBar(void *arg);
extern void *MySendMsgToMplayer(void *arg);
extern void SetSeekBarFindViewById(int val);
extern void SetNowTime(float val);
extern void TotalTime(float val);
extern void SetNowTimeQstring(float val);
extern void SendMsgToMplayer(char *val);
extern char *QStringToChar(QString val);
extern pthread_mutex_t mutex;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void MyCutSong();
    char*MyFindLyric();
    int fd;
    char buf[128];
    int OpenFlag;
    int CutSong;
    int Volue;
    pid_t pid;
    char MyBuff[128];
    int HaveLyricFlag;
    lyric *Lyric[128];
    QString setnowtimeqstring ="";
    ViewInformation viewinformation;
    lyric StructLyric;
    void  closeEvent(QCloseEvent *event);
    void MusicNext();
    void MusicFront();
    void  resizeEvent(QResizeEvent *);
    void ReadDir(char *val);
    void Initialize();
    void PrintInformation();
    void SetInformation();
    void SetNowTimeQstring(float val);
signals:

public slots:
   void MyClickedPlaying();
   void MyDoubleClickedList(const QModelIndex &index);
private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H
