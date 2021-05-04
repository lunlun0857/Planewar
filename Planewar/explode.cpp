#include "explode.h"

explode::explode() {

	//將所有爆炸PIXMAP放進數組
	for (int i = 1; i <= EXPLODE_MAX; i++) {
		QString str = QString(EXPLODE_PATH).arg(i);
		m_pixArr.push_back(QPixmap(str));
	}

	m_X = 0;
	m_Y = 0;

	m_Free = true;

	m_index = 0;

	m_recorder = 0;
}

void explode::updateInfo()
{
	//空閒狀態下的爆炸效果直接return
	if (m_Free) {
		return;
	}

	m_recorder++;

	if (m_recorder < EXPLODE_INTERVAL) {
		return;
	}

	//重置間隔
	m_recorder = 0;

	//切換爆炸播放圖片下標
	m_index++;


	//數組從0開始計算
	if (m_index > EXPLODE_MAX - 1) {
		m_index = 0;
		m_Free = true;
	}

}





