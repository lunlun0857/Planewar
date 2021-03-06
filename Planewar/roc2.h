#ifndef ROC2_H
#define ROC2_H
#include "config.h"
#include <QPixmap>

class roc2
{
public:
    roc2();

    //更新子彈坐標
    void updatePosition();

    //子彈資源對象
    QPixmap m_roc2;

    //子弹坐标
    int m_X;
    int m_Y;

    //子彈移動速度
    int m_Speed;

    //子彈是否閒置
    bool m_Free;

    //子彈的矩形邊框（用於碰撞檢測）
    QRect m_Rect;

};

#endif // ROC2_H
