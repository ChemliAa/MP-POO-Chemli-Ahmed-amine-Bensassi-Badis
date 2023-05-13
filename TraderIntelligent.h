#if !defined(TRADERINTELLIGENT_H)
#define TRADERINTELLIGENT_H
#include "Transaction.h"
#include "BourseVector.h"
#include "Trader.h"
#include "PorteFeuille.h"
class TraderIntelligent:public Trader {
    public:
      Transaction choisirDecision(const Bourse&,const PorteFeuille&);
    
};
#endif