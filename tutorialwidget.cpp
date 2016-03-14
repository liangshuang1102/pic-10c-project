/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  Source file of tutorialwidget class
  **/
#include "tutorialwidget.h"
#include "ui_tutorialwidget.h"
#include "mainwindow.h"
#include <vector>
#include <QString>

tutorialwidget::tutorialwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tutorialwidget)
{
    ui->setupUi(this);
    //Create new QPixmap object and import image
    QString fileName("://caocao.jpg");
    caocao_image = new QPixmap(fileName);
    QString fileName1("://kongming.jpg");
    kongming_image = new QPixmap(fileName1);
    QString fileName5 = ("://pokerback");
    pokerback_image = new QPixmap(fileName5);

    //Put imported images inside QLabels
    ui->label_8->setPixmap(*caocao_image);
    ui->label_7->setPixmap(*kongming_image);
    ui->label_5->setPixmap(*pokerback_image);
    ui->label_3->setPixmap(*pokerback_image);
    ui->label_4->setPixmap(*pokerback_image);
    ui->label_6->setPixmap(*pokerback_image);

    card_images.push_back(new QPixmap("://PNG-cards-1.3/1_of_spades"));
    card_images.push_back(new QPixmap("://PNG-cards-1.3/2_of_spades"));

    //Connect slot to pushbutton
    connect(this->ui->pushButton_2,SIGNAL(clicked(bool)),parent,SLOT(back_to_menu()));
    connect(this->ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(deal_card()));
}

/**
 * @brief tutorialwidget::deal_card
 */
void tutorialwidget::deal_card(){
    display_instr();
    ui->label_5->setPixmap(*card_images[0]);
    ui->label_3->setPixmap(*card_images[1]);
}

/**
 * @brief tutorialwidget::display_instr
 */
void tutorialwidget::display_instr(){
    rule1 = new QString("  You aim is to get the ones digit of the sum of 2 cards you have as large as possible. You can ask one question about the range of your blind card, and computer will answer your question. If you feel confident,keep the blind card.If not,you have one chance to exchange the blind card from the deck");
    rule2 = new QString("  You can see only one of your card, but your opponent can see the other card that you can’t see. Let’s call the card that you can not see \"blind card.\"");
    rule3 = new QString("  Each round has seven hands. After seven hands, if you have positive total score, you win.Hard mode has a double bet option and allows computer interaction.");
    instruction1 = new QLabel(*rule1,this);
    instruction2 = new QLabel(*rule2,this);
    instruction3 = new QLabel(*rule3,this);
    instruction1->move(40,180);
    instruction2->move(430,360);
    instruction3 ->move(360,52);
    setMyQLabelStyle(instruction1);
    setMyQLabelStyle(instruction2);
    setMyQLabelStyle(instruction3);
    instruction1->setFixedSize(210,200);
    instruction2->setFixedSize(150,150);
    instruction3->setFixedSize(180,130);
    instruction1->setWordWrap(true);
    instruction2->setWordWrap(true);
    instruction3->setWordWrap(true);
    instruction1->show();
    instruction2->show();
    instruction3->show();
}

/**
 * @brief tutorialwidget::setMyQLabelStyle
 * @param l
 */
void tutorialwidget::setMyQLabelStyle(QLabel* l){
    QFont myfont("Chalkduster",13);
    l->setStyleSheet("color:yellow");
    l->setFont(myfont);
}

/**
 * @brief tutorialwidget::~tutorialwidget
 */
tutorialwidget::~tutorialwidget()
{
    delete ui;
    delete caocao_image;
    delete kongming_image;
    delete pokerback_image;
    delete instruction1;
    delete instruction2;
    delete instruction3;
    delete rule1;
    delete rule2;
    delete rule3;
    for(size_t i = 0; i<card_images.size();++i){
        delete card_images[i];
    }
}
