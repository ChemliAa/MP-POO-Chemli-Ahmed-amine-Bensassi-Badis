   
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
 
    if(titres.size()!=0){
    
    }
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
void PorteFeuille::enleverAction(string action,int qtte){
    int indexAction=findTitreIndex(action);
    if(qtte==titres[indexAction]->getQtte()){
        suprimerTitre(action);
    }
    else{
        titres[indexAction]->setQtte(titres[indexAction]->getQtte()-qtte);
    }
}
void PorteFeuille::acheter(string nomAction,int quantite,double prix ){
    retirerMontant(quantite*prix);
    Titre *t=new Titre(nomAction,quantite); 
    ajoutTitre(t);
}
 void PorteFeuille::vendre(string nomAction,int quantite,double prix )
 {
    ajoutMontant(quantite*prix);
    enleverAction(nomAction,quantite);
 }
Titre PorteFeuille::getTitresbyActionName(string actionName){
return *titres[findTitreIndex(actionName)];

}