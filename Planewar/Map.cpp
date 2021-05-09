#include "Map.h"
#include "config.h"

Map::Map()
{
	//��ʼ���؈D���d����
	m_map1.load(MAP_PATH);
	m_map2.load(MAP_PATH);
	s_sco.load(SCORE);

	//��ʼ��Y�S����
	m_map1_posY = -GAME_HEIGHT;
	m_map2_posY = 0;

	//�؈D�L���ٶ�
	m_scroll_speed = MAP_SCROLL_SPEED;

	s_sco_X = 350;
	s_sco_Y = 0;
}

void Map::mapPosition()
{
	//̎���һ���DƬ�L��λ��
	m_map1_posY += m_scroll_speed;
	if (m_map1_posY >= 0) {
		m_map1_posY = -GAME_HEIGHT;
	}

	//̎��ڶ����DƬ�L��λ��
	m_map2_posY += m_scroll_speed;
	if (m_map2_posY >= GAME_HEIGHT) {
		m_map2_posY = 0;
	}
}
