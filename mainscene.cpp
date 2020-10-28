#include "mainscene.h"
#include "ui_mainscene.h"
#include "startpushbutton.h"
#include "QPainter"
#include "chooselevelscene.h"
#include "QTimer"

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("Entertainment");
    startPushButton * startBtn = new startPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5, this->height()*0.7);
    ChooseLevelScene *chooseScene = new ChooseLevelScene;
    connect(ui->actionexit, &QAction::triggered, [=](){
        this->close();
    });
    connect(startBtn, &startPushButton::clicked, [=](){
        startBtn->zoom_down();
        startBtn->zoom_up();
        QTimer::singleShot(500, this, [=](){
            this->hide();
            chooseScene->show();
        });

    });
    connect(chooseScene, &ChooseLevelScene::ChooseSceneBack, [=](){
        //chooseScene->hide();
        this->show();
    });
}

MainScene::~MainScene()
{
    delete ui;
}

//设置背景图片
void MainScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(),pix);

    //load title
    pix.load(":/res/Title.png");
    //scaled img
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    //draw title
    painter.drawPixmap(10, 30, pix.width(),pix.height(),pix);
}



