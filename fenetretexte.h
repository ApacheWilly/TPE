#ifndef FENETRETEXTE_H
#define FENETRETEXTE_H
#include "QtGui"
#include "boutons.h"
#include "QTextEdit"
#include "fenetrechoix.h"


class fenetreTexte : public QGraphicsScene
{
    Q_OBJECT
public:
    fenetreTexte(QFile & fichier);
    const boutons* getflecheSuivant();
    const boutons* getflechePrecedent();
    const boutons* getRetourMenu();
private:
    boutons *flecheSuivant;
    boutons *flechePrecedent;
    boutons *retourMenu;
};

#endif // FENETRETEXTE_H
