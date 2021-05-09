#include "Planewar.h"
#include "config.h"
#include <qicon.h>
#include <qpainter.h>
#include <QMouseEvent>
#include <ctime>
#include <qsound.h>
#include <qpen.h>
#include <qbrush.h>


PLANEWAR::PLANEWAR(QWidget *parent)
    : QWidget(parent)
{
    //調用初始化場景
    initScene();

    //啟動遊戲
    playgame();

    score = 0.3;
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
    //啟動背景音樂
    QSound::play(SOUND_BG);


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
    m_plane.shootb();
    m_plane.shootr1();
    m_plane.shootr2();

    //計算所有非空閒子彈當前座標
    for (int i = 0; i < BULLET_NUM; i++) {
        //如果非空閒
        if (m_plane.m_bullets[i].m_Free == false) {
            m_plane.m_bullets[i].updatePosition();
        }
    }

    for (int i = 0; i < ROC_NUM; i++) {
        //如果非空閒
        if (m_plane.m_rocs[i].m_Free == false) {
            m_plane.m_rocs[i].updatePosition();
        }
    }

    for (int i = 0; i < ROC_NUM; i++) {
        //如果非空閒
        if (m_plane.m_rocs2[i].m_Free == false) {
            m_plane.m_rocs2[i].updatePosition();
        }
    }

    //敵機出場
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free == false) {
            m_enemys[i].updatePosition();
        }
    }

    //計算爆炸的播放圖
    for (int i = 0; i < EXPLODE_NUM; i++) {
        if (m_bombs[i].m_Free == false) {
            m_bombs[i].updateInfo();
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

    painter.drawPixmap(m_map.s_sco_X, m_map.s_sco_Y, m_map.s_sco);

    QFont font1("Courier", 30, QFont::Bold, true);
    painter.setFont(font1);
    painter.setPen(QPen(Qt::yellow, 5, Qt::DashDotLine, Qt::RoundCap));
    painter.drawText(400, 50, QString::number(score));


    //繪製子彈
    for (int i = 0; i < BULLET_NUM; i++) {
        //如果非空閒，繪製
        if (m_plane.m_bullets[i].m_Free == false) {
            painter.drawPixmap(m_plane.m_bullets[i].m_X, m_plane.m_bullets[i].m_Y, m_plane.m_bullets[i].m_Bullet);
        }
    }

    for (int i = 0; i < ROC_NUM; i++) {
        //如果非空閒，繪製
        if (m_plane.m_rocs[i].m_Free == false) {
            painter.drawPixmap(m_plane.m_rocs[i].m_X, m_plane.m_rocs[i].m_Y, m_plane.m_rocs[i].m_roc);
        }
    }

    for (int i = 0; i < ROC_NUM; i++) {
        //如果非空閒，繪製
        if (m_plane.m_rocs2[i].m_Free == false) {
            painter.drawPixmap(m_plane.m_rocs2[i].m_X, m_plane.m_rocs2[i].m_Y, m_plane.m_rocs2[i].m_roc2);
        }
    }

    //繪製敵機
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free == false) {
            painter.drawPixmap(m_enemys[i].m_X, m_enemys[i].m_Y, m_enemys[i].m_enemy);
        }
    }

    //繪製爆炸
    for (int i = 0; i < EXPLODE_NUM; i++) {
        if (m_bombs[i].m_Free == false) {
            painter.drawPixmap(m_bombs[i].m_X, m_bombs[i].m_Y, m_bombs[i].m_pixArr[m_bombs[i].m_index]);
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

        for (int j = 0; j < ROC_NUM; j++) {
            if (m_plane.m_rocs[j].m_Free) {
                continue;
            }
            //飛機子彈皆非空閒
            if (m_enemys[i].m_Rect.intersects(m_plane.m_rocs[j].m_Rect)) {
                m_enemys[i].m_Free = true;
                m_plane.m_rocs[j].m_Free = true;
                score += 7.8;

                //播放爆炸效果
                for (int k = 0; k < EXPLODE_NUM; k++) {
                    if (m_bombs[k].m_Free) {

                        QSound::play(SOUND_BOMB);

                        m_bombs[k].m_Free = false;

                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }

        for (int j = 0; j < ROC_NUM; j++) {
            if (m_plane.m_rocs2[j].m_Free) {
                continue;
            }
            //飛機子彈皆非空閒
            if (m_enemys[i].m_Rect.intersects(m_plane.m_rocs2[j].m_Rect)) {
                m_enemys[i].m_Free = true;
                m_plane.m_rocs2[j].m_Free = true;
                score += 7.8;

                //播放爆炸效果
                for (int k = 0; k < EXPLODE_NUM; k++) {
                    if (m_bombs[k].m_Free) {

                        QSound::play(SOUND_BOMB);

                        m_bombs[k].m_Free = false;

                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }

        for (int j = 0; j < BULLET_NUM; j++) {
            if (m_plane.m_bullets[j].m_Free) {
                continue;
            }
            //飛機子彈皆非空閒
            if (m_enemys[i].m_Rect.intersects(m_plane.m_bullets[j].m_Rect)) {
                m_enemys[i].m_Free = true;
                m_plane.m_bullets[j].m_Free = true;
                score += 6.8;

                //播放爆炸效果
                for (int k = 0; k < EXPLODE_NUM; k++) {
                    if (m_bombs[k].m_Free) {

                        QSound::play(SOUND_BOMB);

                        m_bombs[k].m_Free = false;

                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }
    }
}
