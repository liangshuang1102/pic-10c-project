/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  Header file of tutorialwidget class
  **/
#ifndef TUTORIALWIDGET_H
#define TUTORIALWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

namespace Ui {
class tutorialwidget;
}

class tutorialwidget : public QWidget
{
    Q_OBJECT

public:
    explicit tutorialwidget(QWidget *parent = 0);
    ~tutorialwidget();
    void display_instr();
    void setMyQLabelStyle(QLabel* l);

public slots:
    void deal_card();
private:
    Ui::tutorialwidget *ui;
    std::vector<QPixmap*> card_images;
    const QPixmap* caocao_image;
    const QPixmap* kongming_image;
    const QPixmap* pokerback_image;
    const QString* rule1;
    const QString* rule2;
    const QString* rule3;
    QLabel* instruction1;
    QLabel* instruction2;
    QLabel* instruction3;
};

#endif // TUTORIALWIDGET_H
