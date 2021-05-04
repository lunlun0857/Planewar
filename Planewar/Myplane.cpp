#include "Myplane.h"
#include "config.h"

Myplane::Myplane()
{
	//初始化加載飛機圖片資源
	m_Plane.load(MYPLANE_PATH);

	//初始化飛機坐標
	m_X = (GAME_WIDTH  - m_Plane.width()) * 0.5;
	m_Y =  GAME_HEIGHT - m_Plane.height();

	//初始化矩形邊框
	m_Rect.setWidth(m_Plane.width());
	m_Rect.setHeight(m_Plane.height());
	m_Rect.moveTo(m_X, m_Y);
}

void Myplane::shoot() {

	//累加時間間隔
	m_recorder++;

	//如果紀錄的數字為達到發射子彈的時間間隔
	if (m_recorder < BULLET_INTERVAL) {
		return;
	}

	//達到發射時間
	m_recorder = 0;

	//發射子彈
	for (int i = 0; i < BULLET_NUM; i++) {
		//如果子彈空閒則發射
		if (m_bullets[i].m_Free) {
			//空閒狀態變為假
			m_bullets[i].m_Free = false;

			//設置子彈座標
			m_bullets[i].m_X = m_X + 45;
			m_bullets[i].m_Y = m_Y;
			break;
		}
	}
}

void Myplane::setPosition(int x, int y)
{
	m_X = x;
	m_Y = y;
	m_Rect.moveTo(m_X, m_Y);
}
