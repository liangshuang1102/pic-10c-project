/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  Source file of GameCentralWidget class
  **/
#include "gamecentralwidget.h"
#include "ui_gamecentralwidget.h"
#include <QString>
#include "mainwindow.h"

GameCentralWidget::GameCentralWidget(QWidget *parent,int n) :
    QWidget(parent),
    ui(new Ui::GameCentralWidget)
{
    ui->setupUi(this);
    level = n;
    //myparent = parent;
    //Create new QPixmap object and import image
    QString fileName("://caocao.jpg");
    QString fileName2("://caocao_4.jpeg");
    caocao_image = new QPixmap(fileName);
    caocao_double_image = new QPixmap(fileName2);

    QString fileName1("://kongming.jpg");
    kongming_image = new QPixmap(fileName1);
    QString fileName3("://kongming_3.jpg");
    kongming_double_image = new QPixmap(fileName3);
    QString fileName5("://pokerback");
    pokerback_image = new QPixmap(fileName5);

    //Put imported images inside QLabels
    ui->label_8->setPixmap(*caocao_image);
    ui->label_7->setPixmap(*kongming_image);
    ui->label_5->setPixmap(*pokerback_image);
    ui->label_3->setPixmap(*pokerback_image);
    ui->label_4->setPixmap(*pokerback_image);
    ui->label_6->setPixmap(*pokerback_image);

    //Create a new deck
    gamedeck = Deck();
    //Resize card images
    card_images.resize(4);

    //set up connection
    connect(this->ui->pushButton_2,SIGNAL(clicked(bool)),parent,SLOT(back_to_menu()));
    connect(this->ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(begin_game()));
    connect(this->ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(set_QLineEdit()));
    connect(this->ui->lineEdit,SIGNAL(editingFinished()),this,SLOT(read_input()));
    connect(this->ui->buttonBox,SIGNAL(accepted()),this,SLOT(change_blind_card()));
    connect(this->ui->buttonBox,SIGNAL(rejected()),this,SLOT(display_pushbutton3()));
    connect(this->ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(display_result()));
    connect(this->ui->buttonBox_2,SIGNAL(accepted()),this,SLOT(double_bet()));
    connect(this->ui->buttonBox_2,SIGNAL(rejected()),this,SLOT(display_pushbutton3_forbB2()));
}

/**
 * @brief GameCentralWidget::begin_game
 * Begin new hand
 */
void GameCentralWidget::begin_game(){
    //If it is the first hand
    //deal the card only
    if(step_count==0){
        this->deal_card();
    }
    //If the first hand has been played, clean the cards from last hand
    //and deal card
    else if(step_count== 4 && round_count>1 && round_count <8){
         this->clear_last_hand();
         this->deal_card();
         step_count = 1;
    }
    //If the round has been played, user needs to go back to the main menu
    else if(step_count== 4 && round_count ==8){
         ui->pushButton->setText("Game Ends~");
    }
     //If user accidently click it, prompt an error msg
    else{
        ui->pushButton->setText("Please finish\nthis round");
    }
}

/**
 * @brief GameCentralWidget::deal_card
 * randomly draw cards from deck and store them
 * also load the images
 */
void GameCentralWidget::deal_card(){
    int size;
    //Draw cards
    int random;
    for(size_t i = 0 ; i < 2; ++i){
    size = gamedeck.decksize()-1;
    random = Deck::random(size);
    //myhand[i] = Card(random);
    human.load_card(random,i);
    gamedeck.remove_card(random);
    random = Deck::random(size-1);
    //computer_hand[i] = Card(random);
    computer.load_card(random,i);
    gamedeck.remove_card(random);
    }

    //store card images into the vector.index 0 is the card each player can see.index 1 is
    //the blind card (opponent's card)
    card_images[0]=(new QPixmap(human.get_card(0).get_path_name()));
    card_images[1]=(new QPixmap(computer.get_card(1).get_path_name()));
    card_images[2]=(new QPixmap(computer.get_card(0).get_path_name()));
    card_images[3]=(new QPixmap(human.get_card(1).get_path_name()));
    ui->label_5->setPixmap(*card_images[0]);
    ui->label_3->setPixmap(*card_images[3]);
    ++step_count;
}

/**
 * @brief GameCentralWidget::set_QLineEdit
 * Dispaly set_QLineEdit
 */
void GameCentralWidget::set_QLineEdit(){
    if(step_count==1){
    ui->lineEdit->setStyleSheet("background-color:yellow;border:none");
    ++step_count;
   }
}

/**
 * @brief GameCentralWidget::read_input
 * Read user's input and give the answer
 */
void GameCentralWidget::read_input(){
    if(step_count==2){
    ++step_count;
    QString input = ui->lineEdit->text();
    QStringList input_split = input.split(":");
    int input_num = input_split.at(1).toInt();

    std::string rank = std::to_string(((computer.get_card(1)).getRank()));

    if(input_num < ((computer.get_card(1)).getRank())){
       ui->label_9->setText("Blind Card is bigger than "+input_split.at(1)+"\nDo you want to change your \nblind card?");
    }
    else if(input_num > ((computer.get_card(1)).getRank())){
       ui->label_9->setText("Blind Card is smaller than "+input_split.at(1)+"\nDo you want to change your \nblind card?");
    }
    else
    {
       ui->label_9->setText("Equal to "+ input_split.at(1)+"\nDo you want to change your \nblind card?");
    }
      ui->label_9->setStyleSheet("background-color:yellow;border:none");
      ui->lineEdit->clearFocus();
      ui->buttonBox->setStyleSheet("background-color:yellow;border:none");
   }
}

/**
 * @brief GameCentralWidget::change_blind_card
 * If player wish to change the blind card
 * draw a new card from the deck
 * and replace it with the old blind card
 */
void GameCentralWidget::change_blind_card(){
    if(step_count==3){
    ++step_count;
    ui->label_6->setPixmap(QPixmap("://back.png"));
    int size = gamedeck.decksize()-1;
    int random = Deck::random(size);
    //It's a little bit confusing...
    //but Human's blind card is stored as computer's ophand
    computer.load_card(random,1);
    gamedeck.remove_card(random);
    delete card_images[1];
    card_images[1] = new QPixmap((computer.get_card(1)).get_path_name());
    }


    if(step_count ==3 && level>1){
    //Computer's action
    //If computer wants to change his/her card....
    int computer_status = computer.ask_blind_card_action(human);
    if(computer_status==1){
        int size = gamedeck.decksize()-1;
        int random = Deck::random(size);
        human.load_card(random,1);
        gamedeck.remove_card(random);
        delete card_images[3];
        card_images[3] = new QPixmap((human.get_card(1)).get_path_name());
        ui->label_3->setPixmap(*card_images[3]);
    }
    if(computer_status==2){
        computer.double_bet_action(2);
    }
    }

    //If level is easy, skip the double bet option
    if(level==1){
        ui->pushButton_3->setStyleSheet("background-color:yellow;border:none");
    }
    else{
        ui->label_9->setText("Do you want to double your bet?\nThis will increase your earn\nor loss by multiplier 2.");
        ui->buttonBox_2->setStyleSheet("background-color:yellow;border:none");
        ui->buttonBox->setStyleSheet("background-color:black");
    }
}



/**
 * @brief GameCentralWidget::display_pushbutton3
 * Display the pushbutton3 if human player rejects change card action
 */
void GameCentralWidget::display_pushbutton3(){
    //If level is easy, skip the double bet option
    if(step_count == 3 && level == 1){
        ++step_count;
        ui->pushButton_3->setStyleSheet("background-color:yellow;border:none");
    }
    if(step_count == 3 && level >1 ){
        ++step_count;
        ui->label_9->setText("Do you want to double your bet?\nThis will increase your earn\nor loss by multiplier 2.");
        ui->buttonBox_2->setStyleSheet("background-color:yellow;border:none");
        ui->buttonBox->setStyleSheet("background-color:black");
        //ui->pushButton_3->setStyleSheet("background-color:yellow;border:none");

        //Computer's action
        //Computer wants to check his/her card....
        int computer_status = computer.ask_blind_card_action(human);
        if(computer_status==1){
            int size = gamedeck.decksize()-1;
            int random = Deck::random(size);
            human.load_card(random,1);
            gamedeck.remove_card(random);
            delete card_images[3];
            card_images[3] = new QPixmap((human.get_card(1)).get_path_name());
            ui->label_3->setPixmap(*card_images[3]);
        }
        if(computer_status==2){
            computer.double_bet_action(2);
        }
    }

}


/**
 * @brief GameCentralWidget::display_pushbutton3_forbB2
 * display pushbutton3 if human player rejects double bet action
 */
void GameCentralWidget::display_pushbutton3_forbB2(){
    if(step_count == 4 && level >1 ){
        ui->pushButton_3->setStyleSheet("background-color:yellow;border:none");
    }
    if(computer.get_double_status()){
        ui->label_7->setPixmap(*kongming_double_image);
    }
}

/**
 * @brief GameCentralWidget::display_result
 * Display the result of each hand
 */
void GameCentralWidget::display_result(){
    //Calculate the ones digit of sum of two cards
    if(step_count==4){
    //int a = myhand[0]+myhand[1];
    int a = (human.get_card(0))+computer.get_card(1);

    //int b = computer_hand[0] + computer_hand[1];
    int b = human.get_card(1)+computer.get_card(0);

    //Update Score
    if(human.get_double_status() && computer.get_double_status()){
       score += (a-b)*4;
    }
    else if(human.get_double_status() || computer.get_double_status() ){
       score += (a-b)*2;
    }
    else {
       score += (a-b);
    }

    //Display other cards
    ui->label_6->setPixmap(*card_images[1]);
    ui->label_4->setPixmap(*card_images[2]);
    ui->lcdNumber->display(score);

    //Store 4 cards into deck used_car
    gamedeck.used_card.push_back((human.get_card(0)).get_index());
    gamedeck.used_card.push_back((human.get_card(1)).get_index());
    gamedeck.used_card.push_back((computer.get_card(0)).get_index());
    gamedeck.used_card.push_back((computer.get_card(1)).get_index());
    //Update round count
    ++round_count;

    //If it is final round, display the final result
    if(round_count == 8){
        if(score < 0){
        ui->label->setText("You Lose!");
        }
        else{
        ui->label->setText("You Win!");
        }
    }
    }
}
/**
 * @brief GameCentralWidget::clear_last_hand
 * reset everything,poker back, lineEdit etc..
 */
void GameCentralWidget::clear_last_hand(){
    //Delete card images
    for(size_t i = 0; i<card_images.size();++i){
        if (card_images[i] != nullptr)
        delete card_images[i];
     }

    //Set label, buttonbox,and lineEdit to transparency
    ui->buttonBox->setStyleSheet("background-color: rgba(0,0,0,0%)");
    ui->pushButton->setText("Start!");
    ui->buttonBox_2->setStyleSheet("background-color: rgba(0,0,0,0%)");
    ui->label_9->setStyleSheet("background-color: rgba(0,0,0,0%)");
    ui->lineEdit->setStyleSheet("background-color: rgba(0,0,0,0%)");
    ui->lineEdit->setText("Type number you want to ask:");
    ui->pushButton_3->setStyleSheet("background-color: rgba(0,0,0,0%)");
    ui->label_6 ->setPixmap(*pokerback_image);
    ui->label_4 ->setPixmap(*pokerback_image);

    if(human.get_double_status()){
      ui->label_8->setPixmap(*caocao_image);
      human.double_bet_action(0);
    }

    if(computer.get_double_status()){
      ui->label_7->setPixmap(*kongming_image);
      computer.double_bet_action(0);
    }


    //Change the title
    switch(round_count){
    case 2:{
        ui->label->setText("Second Hand");
        break;
    }
    case 3:{
        ui->label->setText("Third Hand");
        break;
    }
    case 4:{
        ui->label->setText("Fourth Hand");
        break;
    }
    case 5:{
        ui->label->setText("Fifth Hand");
        break;
    }
    case 6:{
        ui->label->setText("Sixth Hand");
        break;
    }
    case 7:{
        ui->label->setText("Seventh Hand");
        break;
    }
    case 8:{
        ui->label->setText("Game Ends");
    }
    }
}

/**
 * @brief GameCentralWidget::double_bet
 */
void GameCentralWidget::double_bet(){
    if(step_count == 4 && level>1){
        human.double_bet_action(2);
        ui->label_9->setText("You have doubled your bet!");
        ui->label_8->setPixmap(*caocao_double_image);
        if(computer.get_double_status()){
            ui->label_7->setPixmap(*kongming_double_image);
        }
    }
    ui->pushButton_3->setStyleSheet("background-color:yellow;border:none");

}

/**
 * @brief GameCentralWidget::~GameCentralWidget
 */
GameCentralWidget::~GameCentralWidget()
{
    delete ui;
    delete caocao_image;
    delete kongming_image;
    delete pokerback_image;
    delete caocao_double_image;
    delete kongming_double_image;
    for(size_t i = 0; i<card_images.size();++i){
        if (card_images[i] != nullptr)
          delete card_images[i];
     }

}
