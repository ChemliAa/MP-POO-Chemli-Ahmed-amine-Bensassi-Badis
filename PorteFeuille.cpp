   
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
    int indexOfIndexToSearch= 0;
    for (Titre* t : titres){
        if(t->getNomAction()==nomAction){
            return indexOfIndexToSearch;
        }
        indexOfIndexToSearch++;
    }
    return -1;   
    }
void PorteFeuille::suprimerTitre(string nomAction){
    int indexOfTiTileToDelete=findTitreIndex(nomAction);
    if(indexOfTiTileToDelete!=-1){
        delete titres[indexOfTiTileToDelete];
        titres.erase(titres.begin()+indexOfTiTileToDelete);
        return;
    }
    throw ActionNotFound();
    return ;
    }
void PorteFeuille::ajoutTitre(Titre* t){
    titres.push_back(t);
    return ;
    }