#include "PLANEWAR.h"
#include "config.h"
#include <qicon.h>
#include <qpainter.h>
#include <QMouseEvent>

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
}

void PLANEWAR::playgame()
{
    //啟動定時器
    m_Timer.start();

    //監聽定時器發送的信號
    connect(&m_Timer, &QTimer::timeout, [=]() {
        //更新遊戲中元素的座標
        updatePosition();
        //繪製到屏幕中
        update();
    });
}

void PLANEWAR::updatePosition()
{
    //更新地圖座標
    m_map.mapPosition();

}

void PLANEWAR::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    //繪製地圖
    painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
    painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

    //繪製英雄飛機
    painter.drawPixmap(m_plane.m_X, m_plane.m_Y, m_plane.m_Plane);
}

void PLANEWAR::mouseMoveEvent(QMouseEvent* event)
{
    int x = event->x();
    int y = event->y();

    m_plane.setPosition(x - 60, y - 45);
}
