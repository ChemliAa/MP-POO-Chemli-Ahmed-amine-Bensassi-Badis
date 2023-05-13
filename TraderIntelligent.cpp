#include <cmath>
#include "TraderIntelligent.h"
#include "./customExceptions/TransactionUnknown.cpp"
Transaction TraderIntelligent::choisirDecision(const Bourse& b,const PorteFeuille& p){    
   Transaction t;
   vector<PrixJournalier> prixJournalierDisponible;
    int indexPrixJournalierToBuy,maxPurchasableStocks,qtteToBuy,stockToSell,quantityToSell;   
    if(p.getTitres().size()==0)
   {
    t.setType(buy);
    prixJournalierDisponible=b.getPrixJournaliersParDateEtPrix(b.getDateFinRech(),p.getSolde());
    prixJournalierDisponible=b.getPrixJournaliersParDateEtPrix(b.getDateFinRech(),p.getSolde());
          
             if(prixJournalierDisponible.size()==0){
                        
                t.setType(hold); //if theres nothing we can buy today,do nothing
                return t;
            }  
            indexPrixJournalierToBuy=rand() % prixJournalierDisponible.size();
          
            t.setNomAction(prixJournalierDisponible[indexPrixJournalierToBuy].getNomAction());
           
            maxPurchasableStocks=floor(p.getSolde()/prixJournalierDisponible[indexPrixJournalierToBuy].getPrix());
            if(maxPurchasableStocks !=0)
                qtteToBuy=rand() % maxPurchasableStocks +1;
            else{qtteToBuy=0;}
             
            t.setQuantite(qtteToBuy); //quantity should be and int not a double
            return t;
   }
   else 
   {for (auto it:p.getTitres())
   {
    
   }
   }
   }