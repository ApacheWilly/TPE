#include "boutons.h"

boutons::boutons(QString &chemin) : QGraphicsPixmapItem()
{
    bouton = (chemin);
    setPixmap(bouton);
    setTransformOriginPoint(QPointF(bouton.width()/2,bouton.height()/2));

    setAcceptHoverEvents(true);
}

boutons::boutons(boutons &copieBouton)
{
    QPixmap bouton(copieBouton.bouton);
    setPixmap(bouton);
    setTransformOriginPoint(QPointF(bouton.width()/2,bouton.height()/2));
    setAcceptHoverEvents(true);
}

void boutons::hoverEnterEvent(QGraphicsSceneHoverEvent *event){setScale(1.05);}

void boutons::mousePressEvent(QGraphicsSceneMouseEvent *event){emit isClicked();}

void boutons::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){setScale(1);}




