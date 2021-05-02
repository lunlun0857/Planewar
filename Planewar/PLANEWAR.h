#include <QtWidgets/QWidget>
#include "ui_PLANEWAR.h"
#include<qtimer.h>
#include "Map.h"
#include "Myplane.h"


class PLANEWAR : public QWidget
{
    Q_OBJECT

public:
    PLANEWAR(QWidget *parent = Q_NULLPTR);
    void initScene();

    //啟動遊戲
    void playgame();
     
    //更新所有遊戲中元素的座標
    void updatePosition();

    //繪製到屏幕中 
    void paintEvent(QPaintEvent*);

    //鼠標移動
    void mouseMoveEvent(QMouseEvent*);

    //地圖對象
    Map m_map;

    //飛機對象
    Myplane m_plane;

    //定時器
    QTimer m_Timer;
private:
    Ui::PLANEWARClass ui;
};
