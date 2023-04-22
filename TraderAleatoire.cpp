#include "Transaction.h"
#include "Bourse.h"
#include "Trader.h"
#include "PorteFeuille.h"
#include <cmath>
#include "traderAleatoire.h"
#include "./customExceptions/TransactionUnknown.cpp"
Transaction TraderAleatoire::choisirDecision(const Bourse& b,const PorteFeuille& p){    
   Transaction t;
   typeTransaction choixTypeTransaction=static_cast<typeTransaction>(rand() % 3);
    t.setType(choixTypeTransaction);

    switch (choixTypeTransaction) {
        case buy:
            auto prixJournalierDisponible=b.getPrixJournaliersParDateEtPrix(b.getDateFinRech(),p.getSolde());
            int indexPrixJournalierToBuy=rand() % prixJournalierDisponible.size();
            t.setNomAction(prixJournalierDisponible[indexPrixJournalierToBuy].getNomAction());
            int maxPurchasableStocks=floor(prixJournalierDisponible[indexPrixJournalierToBuy] / p.getSolde());
            int qtteToBuy=rand() % maxPurchasableStocks +1;
            t.setQuantite(qtteToBuy); //quantity should be and int not a double
            return t;
            break;
        case sell:
            auto ownedTitres=p.getTitres();
            int stockToSell=rand() % ownedTitres.size();
            t.setNomAction=ownedTitres[stockToSell]->getNomAction();
            int quantityToSell=rnad() % ownedTitres[stockToSell]->getQtte();
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
 