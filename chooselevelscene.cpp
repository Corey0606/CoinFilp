#include "chooselevelscene.h"
#include "startpushbutton.h"
#include "QMenuBar"
#include "QPainter"
#include "QTimer"
#include "QLabel"
#include "QDebug"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("选择关卡");
    QMenuBar *mb_bar = this->menuBar();
    this->setMenuBar(mb_bar);
    QMenu * startMenu =mb_bar->addMenu("开始");
    QAction * ac_quit = startMenu->addAction("退出");
    startPushButton * pb_back = new startPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    pb_back->setParent(this);
    pb_back->move(this->width()-pb_back->width(), this->height()-pb_back->height());
    //创建关卡btn
    for (int i = 0;i<20;i++) {
        startPushButton *pb_level = new startPushButton(":/res/LevelIcon.png");
        pb_level->setParent(this);
        pb_level->move(25 + (i%4)*70, 130+(i/4)*70);

        //btn 文字
        QLabel*lb_number = new QLabel;
        lb_number->setParent(this);
        lb_number->setFixedSize(pb_level->width(),pb_level->height());
        lb_number->setText(QString::number(i+1));
        lb_number->setAlignment(Qt::AlignCenter|Qt::AlignVCenter); //set center
        lb_number->move(25+(i%4)*70, 130+(i/4)*70);
        lb_number->setAttribute(Qt::WA_TransparentForMouseEvents, true);

        connect(pb_level, &startPushButton::clicked,[=](){
            if(pScene == NULL)//场景最好不复用，直接移除掉创建新的场景
               {
                this->hide();
                pScene = new PlayScene(i+1); //传关卡id
                pScene->show();
                connect(pScene,&PlayScene::chooseSceneBack,[=](){
                                    this->show();
                                    delete pScene;
                                    pScene = NULL;
                                });

            }
        });

    };



    connect(ac_quit, &QAction::triggered, [=](){
       this->close();
    });
    connect(pb_back, &QPushButton::clicked, [=](){
        QTimer::singleShot(500, this, [=](){
            this->hide();
           emit this->ChooseSceneBack();
        });
    });



}

void ChooseLevelScene::paintEvent(QPaintEvent *){
  QPainter painter(this);
  QPixmap pix;
  pix.load(":/res/OtherSceneBg.png");
  painter.drawPixmap(0,0,this->width(), this->height(),pix);
  pix.load(":/res/Title.png");
  painter.drawPixmap((this->width()-pix.width())*0.5, 30, pix.width(), pix.height(), pix);
};

