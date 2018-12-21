#ifndef FENETRECHOIX_H
#define FENETRECHOIX_H
#include<QtGui>
#include <QGraphicsRectItem>
#include <boutons.h>

class fenetreChoix : public QObject,  public QGraphicsRectItem
{
    Q_OBJECT
public:
    fenetreChoix(int r, int g, int b);
    void setFermer(int x , int y );

public slots:
    void close();

private:
    boutons* fermer;


};



class  texteChoix : public QGraphicsTextItem
{
   Q_OBJECT
public :
    texteChoix(QString &nomPartie, QGraphicsItem *parent);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void isClicked();
private:
    QFont policeTitre;

};



#endif // FENETRECHOIX_H
