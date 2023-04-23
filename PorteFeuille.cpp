   
#include "PorteFeuille.h"
#include <vector>
#include "./customExceptions/IncorrectMontantRetirer.cpp"
#include "./customExceptions/ActionNotFound.cpp"
#include <iostream>
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
int PorteFeuille::findTitreIndex(string nomAction)const{
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
    if (findTitreIndex(t->getNomAction())==-1)
    {
        titres.push_back(t);
        return ;
    }
    else
    {
        titres[findTitreIndex(t->getNomAction())]->setQtte((titres[findTitreIndex(t->getNomAction())]->getQtte())+(t->getQtte()));
    }
    
    }
double PorteFeuille::getSolde()const{
    return solde;
}
vector<Titre*> PorteFeuille::getTitres()const{  
    return  titres;

}
int PorteFeuille::getQuantiteTitre(string nomAction)const
{
    return (titres[findTitreIndex(nomAction)]->getQtte());
}
