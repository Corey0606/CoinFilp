#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString butImg); //代表图片路径
    void changeFlag(); //改变标志，执行翻转效果
    QTimer * timer1;
    QTimer * timer2;
    int min = 1; //最小图片
    int max = 8; //最大图片

    int posX; //x坐标
    int posY; //y坐标
    bool flag; //正反标志



signals:

};

#endif // MYCOIN_H
