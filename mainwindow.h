/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  This program implements my poker game~
  **/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamecentralwidget.h"
#include "tutorialwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //Decalre public slots
public slots:
    /**  Create new window when player clicks tutorail button
     * return void
     * */
    void tutorial_begin();
    /**  Create new window when player clicks easy button
     * return void
     * */
    void easy_game_begin();

    /**  Create new window when player clicks medium button
     * return void
     * */
    void medium_game_begin();

    void back_to_menu();

private:
    Ui::MainWindow *ui;
    GameCentralWidget* board;
    tutorialwidget* tboard;

};

#endif // MAINWINDOW_H
