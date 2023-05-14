#include <cmath>
#include "TraderMoyenne.h"
#include "./customExceptions/TransactionUnknown.cpp"
#include <algorithm>
Transaction TraderMoyenne::choisirDecision(const Bourse& b,const PorteFeuille& p){    
   Transaction t;
   vector<PrixJournalier> prixJournalierDisponible=b.getPrixJournaliersParDateEtPrix(b.getDateFinRech(),p.getSolde());
 
   double maxRsIntrestBuy=100,curentmaxRsIntrestBuy;
   double maxRsIntrestSell=0,curentmaxRsIntrestSell=100;
   string nomActionToBuy,nomActionToSell;
   int ownedTitlesToSell=0;
   for (auto p:prixJournalierDisponible){
      curentmaxRsIntrestBuy=CalculerRsAction(b,p.getNomAction());
 
      if(curentmaxRsIntrestBuy<maxRsIntrestBuy){
         maxRsIntrestBuy=curentmaxRsIntrestBuy;
         nomActionToBuy=p.getNomAction();
      }
   }
   vector<Titre*> ownedTitles=p.getTitres();
   for(auto t:ownedTitles){
       curentmaxRsIntrestSell=CalculerRsAction(b,t->getNomAction());
      if(curentmaxRsIntrestSell  >  maxRsIntrestSell){
         maxRsIntrestSell=curentmaxRsIntrestSell;
         nomActionToSell=t->getNomAction();
         ownedTitlesToSell=t->getQtte();
      }
   }
   double intrestToBuy=70-maxRsIntrestBuy;
   double interestToSell=maxRsIntrestSell-70; 
 
   if(prixJournalierDisponible.size()==0  && ownedTitles.size()==0){
      return t;
   }
 
   if(prixJournalierDisponible.size()==0){
 
      t.setType(sell);
   }
   else if(ownedTitles.size()==0) {
      t.setType(buy);
   }
   else if(p.getSolde()<=500 && interestToSell > 0 ){
      t.setType(sell);
   }
   else if(p.getSolde()<=500){
      t.setType(hold);
   }
   else if(intrestToBuy>interestToSell){
    
      t.setType(buy);
   }
   else if(interestToSell>intrestToBuy){
      t.setType(sell);
   }
   int maxPurchasableStocks,quantite;
   switch (t.getType())
   {
      case buy:
         t.setNomAction(nomActionToBuy);
         maxPurchasableStocks=floor(p.getSolde()/b.getPrixParDateEtAction(b.getDateFinRech(),nomActionToBuy));
  
         if(maxPurchasableStocks<=5){ 
            t.setType(hold);
            return t;
         } 
         maxPurchasableStocks=floor(maxPurchasableStocks/5);
         t.setQuantite(maxPurchasableStocks);
         return t;
         break;
      case sell:
     
      t.setNomAction(nomActionToSell);
      if(b.getPrixParDateEtAction(b.getDateFinRech(),nomActionToSell)==-1){
         cout<<"iam a big afat"<<endl;
         t.setType(hold);
         return t;
      }
      quantite=floor(ownedTitlesToSell/2);
      t.setQuantite(quantite);
      return t; 
      break;
      case hold:
    
         return t; 
         break;
      default:
        
         t.setType(hold);
         return t;
      }
      return t;    
 }
double TraderMoyenne::CalculerRsAction(const Bourse& b,string action){
double averedgePositiveChange;
double averedgeNegativeChange;
Date decalageJour(b.getDateFinRech());
Date dateCentral(b.getDateFinRech());
decalageJour--;
int nomberOfDays=0;
int change=0;
while(nomberOfDays<18){
   double prixCentral=b.getPrixParDateEtAction(dateCentral,action);
   double prixDecale=b.getPrixParDateEtAction(decalageJour,action);
   if(prixCentral!=-1 && prixDecale!=-1){
   change=prixCentral-prixDecale;

   if(change!=0){
      
   }
   if(change>0){
      averedgePositiveChange=averedgePositiveChange+change;
   }
   else{
      averedgeNegativeChange=averedgeNegativeChange-change;
   }
   nomberOfDays++;
   decalageJour--;
   dateCentral--;
}
   else{
   nomberOfDays++;
   decalageJour--;
   dateCentral--;
   }
}
 
averedgePositiveChange=averedgePositiveChange/18;
averedgeNegativeChange=averedgeNegativeChange/18;
double rs=averedgePositiveChange/averedgeNegativeChange;
return(100-(100/(1+rs)));
}