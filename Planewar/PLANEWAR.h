#include <QtWidgets/QWidget>
#include "ui_PLANEWAR.h"
#include<qtimer.h>
#include "Map.h"
#include "Myplane.h"
#include "enemy.h"
#include "explode.h"


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

    //敵機出場
    void enemyToScene();

    //碰撞檢測
    void collisionDetection();

    //敵機數組
    Enemy m_enemys[ENEMY_NUM];

    //敵機出場間隔紀錄
    int m_recorder;

    //地圖對象
    Map m_map;

    //飛機對象
    Myplane m_plane;

    //定時器
    QTimer m_Timer;

    //爆炸數組
    explode m_bombs[EXPLODE_NUM];

private:
    Ui::PLANEWARClass ui;
};
