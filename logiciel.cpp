#include "logiciel.h"
#include "fenetretexte.h"


logiciel::logiciel()
{
   //Fenetre entiere
   setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setFixedSize(QGuiApplication::screens()[0]->availableGeometry().width(),QGuiApplication::screens()[0]->availableGeometry().height());

  // Menu Principal
  menuPrincipal = new QGraphicsScene;
  menuPrincipal->setSceneRect(0,0,QGuiApplication::screens()[0]->availableGeometry().width(),QGuiApplication::screens()[0]->availableGeometry().height());
  menuPrincipal->setBackgroundBrush(QBrush(QColor(211,211,211)));
  setScene(menuPrincipal);
  QString cheminCentre(":/images/boutonCENTRE.png");
  QString cheminSocial(":/images/boutonSOCIAL.png");
  QString cheminEco(":/images/boutonECO.png");
  QString cheminSciences(":/images/boutonSCIENCE.png");
  boutonFusee = new boutons(cheminCentre);
  boutonEco = new boutons(cheminEco);
  boutonSocial = new boutons(cheminSocial);
  boutonScience = new boutons(cheminSciences);
  menuPrincipal->addItem(boutonFusee);
  menuPrincipal->addItem(boutonEco);
  menuPrincipal->addItem(boutonSocial);
  menuPrincipal->addItem(boutonScience);

  boutonFusee->setPos(768,375);
  boutonScience->setPos(627,400);
  boutonEco->setPos(882,405);
  boutonSocial->setPos(625,180);


QObject::connect(boutonFusee,SIGNAL(isClicked()),this,SLOT(fenetreChoixOptions()));
QObject::connect(boutonEco,SIGNAL(isClicked()),this,SLOT(fenetreChoixEco()));
QObject::connect(boutonSocial,SIGNAL(isClicked()),this,SLOT(fenetreChoixSocial()));
QObject::connect(boutonScience,SIGNAL(isClicked()),this,SLOT(fenetreChoixScience()));
}

void logiciel::fenetreEquivalent()
{
    fenetreEquivalents *equivalents;
    // equivalents->show();
}

void logiciel::sceneMenuPrincipal(){setScene(menuPrincipal);}

void logiciel::fenetreChoixScience()
{
    fenetreChoix *choixScience = new fenetreChoix(122,218,93);
    QString titreA("Partie A : ");
    QString titreB("Partie B : ");
    QString titreC("Partie C : ");
    texteChoix *partA = new texteChoix(titreA,choixScience);
    texteChoix *partB = new texteChoix(titreB,choixScience);
    texteChoix *partC = new texteChoix(titreC,choixScience);
    partA->setPos(20,20);
    partB->setPos(20,120);
    partC->setPos(20,220);
    menuPrincipal->addItem(choixScience);
    choixScience->setPos(100,700);

    QObject::connect(partA,SIGNAL(isClicked()),this,SLOT(texteScienceA()));
    QObject::connect(partB,SIGNAL(isClicked()),this,SLOT(texteScienceB()));
    QObject::connect(partC,SIGNAL(isClicked()),this,SLOT(texteScienceC()));
}
void logiciel::fenetreChoixEco()
{
   fenetreChoix *choixEco = new fenetreChoix(88,173,253);
   QString titreA("Partie A : ");
   QString titreB("Partie B : ");
   QString titreC("Partie C : ");
   texteChoix *partA = new texteChoix(titreA,choixEco);
   texteChoix *partB = new texteChoix(titreB,choixEco);
   texteChoix *partC = new texteChoix(titreC,choixEco);
   partA->setPos(20,20);
   partB->setPos(20,120);
   partC->setPos(20,220);
   menuPrincipal->addItem(choixEco);
   choixEco->setPos(1100,700);

   QObject::connect(partA,SIGNAL(isClicked()),this,SLOT(texteEcoA()));
   QObject::connect(partB,SIGNAL(isClicked()),this,SLOT(texteEcoB()));
   QObject::connect(partC,SIGNAL(isClicked()),this,SLOT(texteEcoC()));
}

void logiciel::fenetreChoixOptions()
{
  QFile fichierBiblio(":/texte/tpeOptions.txt");
  fenetreTexte *biblio = new fenetreTexte(fichierBiblio);
  setScene(biblio);

  QObject::connect(biblio->getflechePrecedent(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));
  QObject::connect(biblio->getRetourMenu(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));

}

void logiciel::fenetreChoixSocial()
{
  fenetreChoix *choixSocial = new fenetreChoix(250,95,90);
  QString titreA("Partie A : ");
  QString titreB("Partie B : ");
  QString titreC("Partie C : ");
  texteChoix *partA = new texteChoix(titreA,choixSocial);
  texteChoix *partB = new texteChoix(titreB,choixSocial);
  texteChoix *partC = new texteChoix(titreC,choixSocial);
  partA->setPos(20,20);
  partB->setPos(20,120);
  partC->setPos(20,220);
  menuPrincipal->addItem(choixSocial);
  choixSocial->setPos(1100,30);

  QObject::connect(partA,SIGNAL(isClicked()),this,SLOT(texteSocialA()));
  QObject::connect(partB,SIGNAL(isClicked()),this,SLOT(texteSocialB()));
  QObject::connect(partC,SIGNAL(isClicked()),this,SLOT(texteSocialC()));

}

void logiciel::texteScienceA()
{
   QFile fichier(":/texte/sciencesPartieA.txt");
   fenetreTexte *partie = new fenetreTexte(fichier);
   setScene(partie);
   QObject::connect(partie->getRetourMenu(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));
   QObject::connect(partie->getflecheSuivant(),SIGNAL(isClicked()),this,SLOT(texteScienceB()));
}

void logiciel::texteScienceB()
{
    QFile fichier(":/texte/sciencesPartieB.txt");
    fenetreTexte *partie = new fenetreTexte(fichier);
    setScene(partie);
    QObject::connect(partie->getflecheSuivant(),SIGNAL(isClicked()),this,SLOT(texteScienceC()));
    QObject::connect(partie->getflechePrecedent(),SIGNAL(isClicked()),this,SLOT(texteScienceA()));
    QObject::connect(partie->getRetourMenu(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));
}

void logiciel::texteScienceC()
{ 
    QFile fichier(":/texte/sciencesPartieC.txt");
    fenetreTexte *partie = new fenetreTexte(fichier);
    setScene(partie);

    QObject::connect(partie->getflecheSuivant(),SIGNAL(isClicked()),this,SLOT(texteEcoA()));
    QObject::connect(partie->getflechePrecedent(),SIGNAL(isClicked()),this,SLOT(texteScienceB()));
    QObject::connect(partie->getRetourMenu(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));
}

void logiciel::texteEcoA()
{
    QFile fichier(":/texte/ecoPartieA.txt");
    fenetreTexte *partie = new fenetreTexte(fichier);
    setScene(partie);

    QObject::connect(partie->getflecheSuivant(),SIGNAL(isClicked()),this,SLOT(texteEcoB()));
    QObject::connect(partie->getflechePrecedent(),SIGNAL(isClicked()),this,SLOT(texteScienceC()));
    QObject::connect(partie->getRetourMenu(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));
}

void logiciel::texteEcoB()
{
    QFile fichier(":/texte/ecoPartieB.txt");
    fenetreTexte *partie = new fenetreTexte(fichier);
    setScene(partie);
    QObject::connect(partie->getflecheSuivant(),SIGNAL(isClicked()),this,SLOT(texteEcoC()));
    QObject::connect(partie->getflechePrecedent(),SIGNAL(isClicked()),this,SLOT(texteEcoA()));
    QObject::connect(partie->getRetourMenu(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));
}

void logiciel::texteEcoC()
{
    QFile fichier(":/texte/ecoPartieC.txt");
    fenetreTexte *partie = new fenetreTexte(fichier);
    setScene(partie);

    QObject::connect(partie->getflecheSuivant(),SIGNAL(isClicked()),this,SLOT(texteSocialA()));
    QObject::connect(partie->getflechePrecedent(),SIGNAL(isClicked()),this,SLOT(texteEcoB()));
    QObject::connect(partie->getRetourMenu(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));
}

void logiciel::texteSocialA()
{
    QFile fichier(":/texte/socialPartieA.txt");
    fenetreTexte *partie = new fenetreTexte(fichier);
    setScene(partie);

    QObject::connect(partie->getflecheSuivant(),SIGNAL(isClicked()),this,SLOT(texteSocialB()));
    QObject::connect(partie->getflechePrecedent(),SIGNAL(isClicked()),this,SLOT(texteEcoC()));
    QObject::connect(partie->getRetourMenu(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));
}

void logiciel::texteSocialB()
{
    QFile fichier(":/texte/socialPartieB.txt");
    fenetreTexte *partie = new fenetreTexte(fichier);
    setScene(partie);

    QObject::connect(partie->getflecheSuivant(),SIGNAL(isClicked()),this,SLOT(texteSocialC()));
    QObject::connect(partie->getflechePrecedent(),SIGNAL(isClicked()),this,SLOT(texteSocialA()));
    QObject::connect(partie->getRetourMenu(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));
}

void logiciel::texteSocialC()
{
    QFile fichier(":/texte/socialPartieC.txt");
    fenetreTexte *partie = new fenetreTexte(fichier);
    setScene(partie);

    QObject::connect(partie->getflechePrecedent(),SIGNAL(isClicked()),this,SLOT(texteSocialB()));
    QObject::connect(partie->getRetourMenu(),SIGNAL(isClicked()),this,SLOT(sceneMenuPrincipal()));
}
