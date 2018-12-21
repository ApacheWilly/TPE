#ifndef BOUTONS_H
#define BOUTONS_H
#include <QtWidgets>
#include <QPixmap>


class boutons : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    boutons(QString &chemin);
    boutons(boutons &copieBouton);
    void boutonMousePress();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);


signals:
 void isClicked();
private:

 QPixmap bouton;

};

#endif // BOUTONS_H
