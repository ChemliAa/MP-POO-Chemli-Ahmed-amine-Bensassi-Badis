   
#include "PorteFeuille.h"
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