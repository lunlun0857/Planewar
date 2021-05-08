#include "roc2.h"

roc2::roc2()
{
    //加載自動資源
    m_roc2.load(ROC_PATH);

    //子彈坐標初始化
    m_X = (GAME_WIDTH * 0.5 - m_roc2.width() * 0.5);
    m_Y = GAME_HEIGHT;

    //子彈空閒狀態
    m_Free = true;

    //子彈速度
    m_Speed = BULLET_SPEED;

    //子彈矩形邊框 （碰撞檢測）
    m_Rect.setWidth(m_roc2.width());
    m_Rect.setHeight(m_roc2.height());
    m_Rect.moveTo(m_X, m_Y);
}

void roc2::updatePosition()
{
    //如果子彈是空閒狀態，不需要計算坐標
    if (m_Free)
    {
        return;
    }

    //子彈向上移動
    m_Y -= m_Speed;
    m_Rect.moveTo(m_X, m_Y);

    if (m_Y <= -m_Rect.height())
    {
        m_Free = true;
    }

}
