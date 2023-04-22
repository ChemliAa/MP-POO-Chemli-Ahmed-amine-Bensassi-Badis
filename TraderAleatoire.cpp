#include <cmath>
#include "traderAleatoire.h"
#include "./customExceptions/TransactionUnknown.cpp"
#include "./BourseVector.h"
Transaction TraderAleatoire::choisirDecision(const Bourse& b,const PorteFeuille& p){    
   Transaction t;
   typeTransaction choixTypeTransaction=static_cast<typeTransaction>(rand() % 3);
    t.setType(choixTypeTransaction);
    vector<PrixJournalier> prixJournalierDisponible;
    int indexPrixJournalierToBuy,maxPurchasableStocks,qtteToBuy,stockToSell,quantityToSell;
    vector<Titre *> ownedTitres;
    switch (choixTypeTransaction) {
        case buy:
            prixJournalierDisponible=b.getPrixJournaliersParDateEtPrix(b.getDateFinRech(),p.getSolde());
            indexPrixJournalierToBuy=rand() % prixJournalierDisponible.size();
            t.setNomAction(prixJournalierDisponible[indexPrixJournalierToBuy].getNomAction());
            maxPurchasableStocks=floor(prixJournalierDisponible[indexPrixJournalierToBuy].getPrix() / p.getSolde());
            qtteToBuy=rand() % maxPurchasableStocks +1;
            t.setQuantite(qtteToBuy); //quantity should be and int not a double
            return t;
            break;
        case sell:
            ownedTitres=p.getTitres();
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
int main(){
    TraderAleatoire t;
    Date datecourant("1/1/2012");
    PorteFeuille p(2000);
    BourseVector b(datecourant,CHEMIN);
    auto choix=t.choisirDecision(b,p);
    cout<<choix;

    

}