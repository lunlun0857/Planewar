#include "Map.h"
#include "config.h"

Map::Map()
{
	//初始化地圖加載對象
	m_map1.load(MAP_PATH);
	m_map2.load(MAP_PATH);
	s_sco.load(SCORE);

	//初始化Y軸座標
	m_map1_posY = -GAME_HEIGHT;
	m_map2_posY = 0;

	//地圖滾動速度
	m_scroll_speed = MAP_SCROLL_SPEED;

	s_sco_X = 350;
	s_sco_Y = 0;
}

void Map::mapPosition()
{
	//處理第一張圖片滾動位置
	m_map1_posY += m_scroll_speed;
	if (m_map1_posY >= 0) {
		m_map1_posY = -GAME_HEIGHT;
	}

	//處理第二張圖片滾動位置
	m_map2_posY += m_scroll_speed;
	if (m_map2_posY >= GAME_HEIGHT) {
		m_map2_posY = 0;
	}
}
