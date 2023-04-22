#include "Transaction.h"
#include "Bourse.h"
#include "Trader.h"
#include "PorteFeuille.h"
#include "traderAleatoire.h"
Transaction TraderAleatoire::choisirDecision(const Bourse& b,const PorteFeuille& p){    
   Transaction t;
   typeTransaction choixTypeTransaction=static_cast<typeTransaction>(rand() % 3);;
    switch (choixTypeTransaction) {
        case buy:
            b.getActionsDisponiblesParDate(b.getDateFinRech());
            break;
        case sell:
            // logic for selling stocks
            break;
        case hold:
            // logic for holding onto stocks
            break;
        default:
            // error handling if the random value is out of range
            break;
    }
    return t;    
 }
 