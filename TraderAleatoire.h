#if !defined(TRADERALEATOIRE_H)
#define TRADERALEATOIRE_H
#include "Transaction.h"
#include "Bourse.h"
#include "Trader.h"
#include "PorteFeuille.h"
class TraderAleatoire:public Trader {
    public:
      Transaction choisirDecision(const Bourse&,const PorteFeuille&);
    
};
#endif