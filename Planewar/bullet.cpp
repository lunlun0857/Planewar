#include "bullet.h"

Bullet::Bullet()
{
    //���d�Ԅ��YԴ
    m_Bullet.load(BULLET_PATH);

    //�ӏ����˳�ʼ��
    m_X = (GAME_WIDTH * 0.5 - m_Bullet.width() * 0.5);
    m_Y = GAME_HEIGHT;

    //�ӏ����f��B
    m_Free = true;

    //�ӏ��ٶ�
    m_Speed = BULLET_SPEED;

    //�ӏ�����߅�� ����ײ�z�y��
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X, m_Y);
}

void Bullet::updatePosition()
{
    //����ӏ��ǿ��f��B������ҪӋ������
    if (m_Free)
    {
        return;
    }

    //�ӏ������Ƅ�
    m_Y -= m_Speed;
    m_Rect.moveTo(m_X, m_Y);

    if (m_Y <= -m_Rect.height())
    {
        m_Free = true;
    }

}
