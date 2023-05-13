#include <cmath>
#include "TraderAleatoire.h"
#include "./customExceptions/TransactionUnknown.cpp"
Transaction TraderAleatoire::choisirDecision(const Bourse& b,const PorteFeuille& p){    
   Transaction t;
   typeTransaction choixTypeTransaction=static_cast<typeTransaction>(rand() % 3);
   if(p.getTitres().size()==0){
    choixTypeTransaction=buy;
   }
    t.setType(choixTypeTransaction);
    vector<PrixJournalier> prixJournalierDisponible;
    int indexPrixJournalierToBuy,maxPurchasableStocks,qtteToBuy,stockToSell,quantityToSell;
    vector<Titre *> ownedTitres;
    
    switch (choixTypeTransaction) {
        case buy: 
            
            prixJournalierDisponible=b.getPrixJournaliersParDateEtPrix(b.getDateFinRech(),p.getSolde());
             if(prixJournalierDisponible.size()==0){
                        
                t.setType(hold); //if theres nothing we can buy today,do nothing
                return t;
            }  
            indexPrixJournalierToBuy=rand() % prixJournalierDisponible.size();
             
            t.setNomAction(prixJournalierDisponible[indexPrixJournalierToBuy].getNomAction());
             
            maxPurchasableStocks=floor(p.getSolde()/prixJournalierDisponible[indexPrixJournalierToBuy].getPrix());
            if(maxPurchasableStocks==0){
         
                t.setType(hold);
                return t;
            }
            qtteToBuy=rand() % maxPurchasableStocks +1;
              
            t.setQuantite(qtteToBuy); 
 
            return t;
            break;
        case sell:
          
            ownedTitres=p.getTitres();
     
            if(ownedTitres.size()==0){
                t.setType(hold); //if theres nothing to sell,do nothing
                return t;
            } 
            stockToSell=rand() % ownedTitres.size();
              
            
            t.setNomAction(ownedTitres[stockToSell]->getNomAction());
            quantityToSell=rand() % ownedTitres[stockToSell]->getQtte();
           
            t.setQuantite(quantityToSell);
              
            return t;
            break;
        case hold:
            return t; 
            break;
        default:
            throw TransactionUnknown();
            break;
    }
    return t;    
 }
 