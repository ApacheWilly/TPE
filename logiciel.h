#ifndef LOGICIEL_H
#define LOGICIEL_H
#include <QGraphicsView>
#include <boutons.h>
#include <fenetrechoix.h>
#include "fenetreequivalent.h"


class logiciel : public QGraphicsView
{
    Q_OBJECT
public:
    logiciel();

public slots:
    void fenetreEquivalent();
    void fenetreChoixScience();
    void fenetreChoixEco();
    void fenetreChoixSocial();
    void fenetreChoixOptions();
    void texteScienceA();
    void texteScienceB();
    void texteScienceC();
    void texteEcoA();
    void texteEcoB();
    void texteEcoC();
    void texteSocialA();
    void texteSocialB();
    void texteSocialC();
    void sceneMenuPrincipal();


private:
    QGraphicsScene *menuPrincipal;
    boutons *boutonFusee;
    boutons *boutonEco;
    boutons *boutonScience;
    boutons *boutonSocial;
    boutons *boutonEquivalent;
};

#endif // LOGICIEL_H
