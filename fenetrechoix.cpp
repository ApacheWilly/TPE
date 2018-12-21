#include "fenetrechoix.h"
#include "boutons.h"

fenetreChoix::fenetreChoix(int r ,int g, int b)
{
 QPen stylo ;
 stylo.setWidth(0);
 stylo.setStyle(Qt::NoPen);
 setPen(stylo);
 setRect(0,0,600,300);
 setBrush(QBrush(QColor(r,g,b)));
 QString petiteCroix(":/images/petiteCroix.png");
 fermer = new boutons(petiteCroix);
 fermer->setParentItem(this);
 fermer->setPos(560,10);

 QObject::connect(fermer,SIGNAL(isClicked()),this,SLOT(close()));
}

void fenetreChoix::close(){
    delete this;
}

void fenetreChoix::setFermer(int x , int y ){fermer->setPos(x,y);}

texteChoix::texteChoix(QString &nomPartie, QGraphicsItem *parent)
{
    setParentItem(parent);
    setPlainText(nomPartie);
    policeTitre.setFamily("Calibri");
    policeTitre.setPointSize(20);
    policeTitre.setWeight(72);
    policeTitre.setUnderline(false);
    setFont(policeTitre);
    setAcceptHoverEvents(true);}

void texteChoix::mousePressEvent(QGraphicsSceneMouseEvent *event){emit isClicked();}

void texteChoix::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{policeTitre.setUnderline(true);
    setFont(policeTitre);}

void texteChoix::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){policeTitre.setUnderline(false);
                                                                 setFont(policeTitre);}

