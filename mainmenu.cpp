#include "mainmenu.h"
#include "boutons.h"

mainMenu::mainMenu() : QGraphicsScene ()
{


   setSceneRect(0,0,1792,1088);
    QString cheminCentre(":/images/boutonCentre.png");
    boutons *boutonCentral = new boutons(cheminCentre,200,800);
    addItem(boutonCentral);



}
