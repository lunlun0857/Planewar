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

	//�؈DY�S����
	int m_map1_posY;
	int m_map2_posY;

	//�؈D�L�ӷ���
	int m_scroll_speed;
};

#endif // Map.h