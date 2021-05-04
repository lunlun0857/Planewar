#include "PLANEWAR.h"
#include "config.h"
#include <qicon.h>
#include <qpainter.h>
#include <QMouseEvent>
#include <ctime>

PLANEWAR::PLANEWAR(QWidget *parent)
    : QWidget(parent)
{
    //調用初始化場景
    initScene();

    //啟動遊戲
    playgame();
}

void PLANEWAR::initScene()
{
    //設置窗口固定尺寸
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);

    //設置標題
    setWindowTitle(GAME_TITLE);

    //加載圖標
    setWindowIcon(QIcon(GAME_ICON));

    //定時器設置
    m_Timer.setInterval(GAME_RATE);

    //敵機出場時間隔 初始化
    m_recorder = 0;

    //隨機數種子
    srand((unsigned int)time(NULL));

}

void PLANEWAR::playgame()
{
    //啟動定時器
    m_Timer.start();

    //監聽定時器發送的信號
    connect(&m_Timer, &QTimer::timeout, [=]() {

        //敵機出場
        enemyToScene();

        //更新遊戲中元素的座標
        updatePosition();

        //繪製到屏幕中
        update();

        //碰撞檢測
        collisionDetection();
    });
}

void PLANEWAR::updatePosition()
{
    //更新地圖座標
    m_map.mapPosition();

    //發射子彈
    m_plane.shoot();

    //計算所有非空閒子彈當前座標
    for (int i = 0; i < BULLET_NUM; i++) {
        //如果非空閒
        if (m_plane.m_bullets[i].m_Free == false) {
            m_plane.m_bullets[i].updatePosition();
        }
    }

    //敵機出場
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free == false) {
            m_enemys[i].updatePosition();
        }
    }
}

void PLANEWAR::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    //繪製地圖
    painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
    painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

    //繪製英雄飛機
    painter.drawPixmap(m_plane.m_X, m_plane.m_Y, m_plane.m_Plane);

    //繪製子彈
    for (int i = 0; i < BULLET_NUM; i++) {
        //如果非空閒，繪製
        if (m_plane.m_bullets[i].m_Free == false) {
            painter.drawPixmap(m_plane.m_bullets[i].m_X, m_plane.m_bullets[i].m_Y, m_plane.m_bullets[i].m_Bullet);
        }
    }

    //繪製敵機
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free == false) {
            painter.drawPixmap(m_enemys[i].m_X, m_enemys[i].m_Y, m_enemys[i].m_enemy);
        }
    }
}

void PLANEWAR::mouseMoveEvent(QMouseEvent* event)
{
    int x = event->x();
    int y = event->y();

    m_plane.setPosition(x - 60, y - 45);
}

void PLANEWAR::enemyToScene()
{
    m_recorder++;

    if (m_recorder < ENEMY_INTERVAL) {
        return;
    }

    m_recorder = 0;

    for (int i = 0; i < ENEMY_NUM; i++) {
        //若空閒則出場
        if (m_enemys[i].m_Free) {
            m_enemys[i].m_Free = false;

            //座標
            m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void PLANEWAR::collisionDetection()
{
    
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free) {
            continue;
        }

        for (int j = 0; j < BULLET_NUM; j++) {
            if (m_plane.m_bullets[j].m_Free) {
                continue;
            }

            if (m_enemys[i].m_Rect.intersects(m_plane.m_bullets[j].m_Rect)) {
                m_enemys[i].m_Free = true;
                m_plane.m_bullets[j].m_Free = true;
            }
        }
    }

    //飛機子彈皆非空閒


}
