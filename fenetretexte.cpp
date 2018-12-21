#include "fenetretexte.h"


fenetreTexte::fenetreTexte(QFile & fichier)
{
    setSceneRect(0,0,QGuiApplication::screens()[0]->availableGeometry().width(),QGuiApplication::screens()[0]->availableGeometry().height());
    setBackgroundBrush(QBrush(QColor(211,211,211)));
    QTextEdit *texte = new QTextEdit;
    QString cheminSuivant(":/images/flecheSuivant.png");
    QString cheminPrecedent(":/images/flechePrecedent.png");
    QString cheminRetour(":/images/croix.png");
    flecheSuivant = new boutons(cheminSuivant);
    flechePrecedent = new boutons(cheminPrecedent);
    texte->setGeometry(0,0,QGuiApplication::screens()[0]->availableGeometry().width(),QGuiApplication::screens()[0]->availableGeometry().height());
    texte->setReadOnly(true);
    texte->setTextBackgroundColor(QColor(211,211,211));
    fichier.open(QIODevice::ReadOnly);
    if(!fichier.exists())
    {
       texte->setText("Le fichier n'existe pas. Une vérification des fichiers du logiciel peut régler le problème.");
    }
    retourMenu = new boutons(cheminRetour);
    addItem(retourMenu);
    addItem(flechePrecedent);
    addItem(flecheSuivant);
    retourMenu->setPos(1500,0);
    flecheSuivant->setPos(850,0);
    flechePrecedent->setPos(775,0);
    texte->setHtml(QString(fichier.readAll()));
    texte->setGeometry(0,50,QGuiApplication::screens()[0]->availableGeometry().width(),QGuiApplication::screens()[0]->availableGeometry().height());
    addWidget(texte);

}

const boutons* fenetreTexte::getflechePrecedent(){ return flechePrecedent;}

const boutons* fenetreTexte::getflecheSuivant(){ return flecheSuivant;}

const boutons* fenetreTexte::getRetourMenu(){return retourMenu;}
