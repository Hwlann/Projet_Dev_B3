#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QMouseEvent>
#include <QPainter>
#include <QFontDatabase>
#include <QSound>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define     WINDOW_WIDTH    395 // 350
#define     WINDOW_HEIGHT   580 // 550
#define     WINDOW_TITLE    "EFM Launcher"

#define     SCORES_URL      "http://lortetcesar.fr/efm/score"
#define     REGISTER_URL    "http://lortetcesar.fr/register"
#define     DEF_VOLUME      0.05f

#define     SOUND_ICON      ":/img/res/images/soundOn.png"
#define     MUTE_ICON       ":/img/res/images/mute.png"
#define     BACKGROUND_IMG  ":/img/res/images/background_2.jpg"

// Click sound : https://freesound.org/s/399934/
// Music : Portal Sound Track, Portal Soundtrack - Self Esteem Fund ,https://www.youtube.com/watch?v=t9nocjg2OLI

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Instance & Destructor
    static MainWindow *getInstance(QWidget *parent = nullptr);
    ~MainWindow();

    // UI
    void setupUi();
    void changeStatusbarText(QString *text);
    void changeStartGameBtn(bool enable);
    void setStyleSheets();
    void setFont();
    void setBackground();
    void setSounds();
    void playClickSound();
    void manageSound(bool mute = false);
    void clearLineEditCommand();
    void disableLineEdit();

private slots:
    void on_lineEdit_returnPressed();
    void changeLoginVisibilty();
    void on_le_id_textEdited();
    void on_btn_register_clicked();
    void on_btn_login_clicked();
    void on_btn_play_clicked();
    void on_le_username_textEdited();
    void on_le_password_textEdited();
    void on_btn_exit_clicked();
    void on_btn_reduce_clicked();
    void on_btn_sound_clicked();

protected:
    void mousePressEvent(QMouseEvent *evt);
    void mouseMoveEvent(QMouseEvent *evt);


private:
    virtual bool eventFilter(QObject* watched, QEvent* event);
    static MainWindow *m_mainWindow;
    MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *ui;
    QPoint oldPos;
    bool locked = false;

    QPixmap *m_soundOnPixmap;
    QPixmap *m_mutePixmap;

    QIcon *soundIcon;
    QIcon *muteIcon;

signals:
    void commandCommit(QString cmd);
    void login(QString id, QString password);
    void getPlayerName(QString id);
    void startGame();
    void changeSound(bool force = false, bool mute = false);
    void playHover();
    void playClick();

};
#endif // MAINWINDOW_H
