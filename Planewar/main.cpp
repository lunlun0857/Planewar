#include "PLANEWAR.h"
#include <QtWidgets/QApplication>
#include <qresource.h>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    //Ô]ƒÔ¶þßMÖÆÙYÔ´
    QResource::registerResource(GAME_RES_PATH);

    PLANEWAR w;
    w.show();
    return a.exec();
}
