#include <cmath>
#include "TraderAvare.h"
#include "./customExceptions/TransactionUnknown.cpp"
#include <string>
Transaction TraderAvare::choisirDecision(const Bourse& b,const PorteFeuille& p){    
    Transaction t;
    vector<PrixJournalier> PrixJournalierForToday=b.getPrixJournaliersParDate(b.getDateFinRech());
    double maxBenefit=0;
    std::string possbileSellingAction;
    int qauntityToSell;
    if(totalPrice.size()!=0){
        for(auto pt:totalPrice){
            qauntityToSell=findQuantityByActionName(pt.first,p.getTitres());
            double curentSellingValue=b.getPrixParDateEtAction(b.getDateFinRech(),pt.first)*qauntityToSell;
            if(curentSellingValue>pt.second){
                    if(curentSellingValue>maxBenefit){
                        maxBenefit=curentSellingValue-pt.second;
                        possbileSellingAction=pt.first;
                    }
            }
        }
    }  
    if(maxBenefit>5){
        t.setType(sell);
        t.setQuantite(qauntityToSell);
        t.setNomAction(possbileSellingAction);
        totalPrice[possbileSellingAction]=0;
        return t;
    }
    else if(PrixJournalierForToday.size()!=0){
        string actionToBuy;
        actionToBuy=findCheapestAction(PrixJournalierForToday);
        double price =  b.getPrixParDateEtAction(b.getDateFinRech(),actionToBuy);
        int maxBuyable=floor(p.getSolde()/price);
        if(maxBuyable==0 || floor(maxBuyable/7)<1){
            t.setType(hold);
            return t;
        }
        t.setType(buy);
        t.setNomAction(actionToBuy);
        t.setQuantite( floor(maxBuyable/7));
        totalPrice.insert(make_pair(actionToBuy,floor(maxBuyable/7)*price));
        return t;
    }
    t.setType(hold);
    return t;

}
int TraderAvare::findQuantityByActionName(std::string actionName,vector<Titre*> titles){
for(auto t: titles){
    if(t->getNomAction()==actionName){
        return t->getQtte();
    }
}
return 0;
} 
string TraderAvare::findCheapestAction(vector<PrixJournalier> pr){
string cheapast=pr[0].getNomAction();
double currentCheapest=pr[0].getPrix();
for(auto p:pr){
    if(p.getPrix()<currentCheapest){
        currentCheapest=p.getPrix();
        cheapast=p.getNomAction();
    }
}
return cheapast;

}