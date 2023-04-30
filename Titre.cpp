   
#include "Titre.h"
#include <iostream>
Titre::Titre(string nomAction,int qtte):nomAction(nomAction),qtte(qtte){
    //if we have the time we might make controlls about the nom action and qtte and make it throw a custom mexception if not respected
};
int Titre::getQtte()const{
    return qtte;
   }
 string Titre::getNomAction(){
    
    return nomAction;
 }
 void Titre::setNomAction(string nouveaNom){
    nomAction=nouveaNom;
   }
 void Titre::setQtte(int nouvelleQtte){
    qtte=nouvelleQtte;
 }