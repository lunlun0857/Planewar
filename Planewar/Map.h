#ifndef Map_H
#define Map_h
#include <qpixmap.h>
class Map
{
public:
	Map();

	//�؈D�L������Ӌ��
	void mapPosition();

	//�؈D�DƬ����
	QPixmap m_map1;
	QPixmap m_map2;
	QPixmap s_sco;

	//�؈DY�S����
	int m_map1_posY;
	int m_map2_posY;

	//�؈D�L�ӷ���
	int m_scroll_speed;

	int s_sco_X;
	int s_sco_Y;
};

#endif // Map.h