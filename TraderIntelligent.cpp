#include <cmath>
#include "TraderIntelligent.h"
#include "./customExceptions/TransactionUnknown.cpp"
Transaction TraderIntelligent::choisirDecision(const Bourse& b,const PorteFeuille& p){    
   Transaction t;
   vector<PrixJournalier> prixJournalierDisponible;
    prixJournalierDisponible=b.getPrixJournaliersParDateEtPrix(b.getDateFinRech(),p.getSolde());
    int indexPrixJournalierToBuy,maxPurchasableStocks,qtteToBuy,stockToSell,quantityToSell;  
    if( prixJournalierDisponible.size()==0 )
    {
        t.setType(hold);
        return t;
    }
    if(p.getTitres().size()<5 )

   {
    t.setType(buy);
    indexPrixJournalierToBuy=rand() % prixJournalierDisponible.size();
    t.setNomAction(prixJournalierDisponible[indexPrixJournalierToBuy].getNomAction()); 
    maxPurchasableStocks=floor(p.getSolde()/prixJournalierDisponible[indexPrixJournalierToBuy].getPrix());
    qtteToBuy=rand() % maxPurchasableStocks +1;
    t.setQuantite(qtteToBuy);
    return t;
   }
   else{
    PrixJournalier prixJournalierWithMinimumPrice=*b.getPrixJournaliersParDate(b.getDateFinRech()).begin();
    for (auto it:b.getPrixJournaliersParDate(b.getDateFinRech()))
        {
            if (it.getPrix()<prixJournalierWithMinimumPrice.getPrix())
            {
                 prixJournalierWithMinimumPrice=it;
            }
        
        }

    if (phase==sell && p.getTitres().size()!=0 )
    {    
        Titre titreAvecMaxPrix("",0);
        for (auto it:p.getTitres())
        {
             if (b.dernierPrixDuneAction(b.getDateFinRech(),it->getNomAction())>b.getPrixParDateEtAction(b.getDateFinRech(),titreAvecMaxPrix.getNomAction()))
            {
                 titreAvecMaxPrix=*it;
             }
        
         }
        t.setType(sell);
        t.setNomAction(titreAvecMaxPrix.getNomAction());
        t.setQuantite(titreAvecMaxPrix.getQtte());
        phase=buy;
        return t;
        
    }
    else if (phase==buy ){

         if(prixJournalierDisponible.size()==0){
                        
                t.setType(hold); //if theres nothing we can buy today,do nothing
               phase=sell;
            }  
        else{
            t.setType(buy);
            t.setNomAction(prixJournalierWithMinimumPrice.getNomAction());
            maxPurchasableStocks=floor(p.getSolde()/prixJournalierWithMinimumPrice.getPrix());
            qtteToBuy=rand() % maxPurchasableStocks +1;
            t.setQuantite(qtteToBuy);
            phase=hold;
        }
        
        return t;
    }
    else if(phase==hold)
    {
       phase=sell;
       t.setType(hold); 
       return t; 
    }
   }
   t.setType(hold);
   return t;
}
