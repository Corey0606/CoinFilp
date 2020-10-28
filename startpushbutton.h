#ifndef STARTPUSHBUTTON_H
#define STARTPUSHBUTTON_H
#include <QPushButton>

class startPushButton : public QPushButton
{
    Q_OBJECT
public:
    startPushButton(QString normalImg, QString pressImg = "");
    QString normalImgPath;
    QString pressedImgPath;
    void zoom_down();
    void zoom_up();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);


signals:

};

#endif // STARTPUSHBUTTON_H
