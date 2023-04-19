   
#include "PorteFeuille.h"
PorteFeuille::PorteFeuille(double solde):solde(solde){}
void PorteFeuille::ajoutMontant(double montant){
    solde+=montant;
   }
 void PorteFeuille::retirerMontant(double montant){
            if(montant <= solde){
                solde-=montant;
                return ;
            }
        throw  incorrectMontantRetirer();         
    }




int PorteFeuille::findTitreIndex(string nomAction){
           return 0;   //to implement: shoudl search through the Titre , find the one correspending, and returning its index , i dont know it its usefulll for a vector, probably
    }
void PorteFeuille::suprimerTitre(string nomAction){
        //to implement,we should not forget to use free pointer ;will use find index most likely
            
    }