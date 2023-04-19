   
#include "Titre.h"
 string getNomAction();
        int getQtte(); 
        void setNomAction();
        void setQtte();
int Titre::getQtte(){
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