#include "enemy.h"
#include "config.h"



Enemy::Enemy() {

	//敵機資源加載
	m_enemy.load(ENEMY_PATH);

	m_X = 0;
	m_Y = 0;

	m_Free = true;

	m_Speed = ENEMY_SPEED;

	m_Rect.setWidth(m_enemy.width());
	m_Rect.setHeight(m_enemy.height());
	m_Rect.moveTo(m_X, m_Y);
}

void Enemy::updatePosition()
{
	//空閒狀態敵機
	if (m_Free) {
		return;
	}

	m_Y += m_Speed;
	m_Rect.moveTo(m_X, m_Y);

	//超出屏幕重置
	if (m_Y >= GAME_HEIGHT + m_Rect.height()) {
		m_Free = true;
	}
}
