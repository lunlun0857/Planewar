#ifndef Map_H
#define Map_h
#include <qpixmap.h>
class Map
{
public:
	Map();

	//地圖滾動座標計算
	void mapPosition();

	//地圖圖片對象
	QPixmap m_map1;
	QPixmap m_map2;

	//地圖Y軸座標
	int m_map1_posY;
	int m_map2_posY;

	//地圖滾動幅度
	int m_scroll_speed;
};

#endif // Map.h