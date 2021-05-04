#include "bullet.h"

Bullet::Bullet()
{
    //加載自動資源
    m_Bullet.load(BULLET_PATH);

    //子彈坐標初始化
    m_X = (GAME_WIDTH * 0.5 - m_Bullet.width() * 0.5);
    m_Y = GAME_HEIGHT;

    //子彈空閒狀態
    m_Free = true;

    //子彈速度
    m_Speed = BULLET_SPEED;

    //子彈矩形邊框 （碰撞檢測）
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X, m_Y);
}

void Bullet::updatePosition()
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
