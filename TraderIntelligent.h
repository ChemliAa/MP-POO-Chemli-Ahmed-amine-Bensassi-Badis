#if !defined(TRADERINTELLIGENT_H)
#define TRADERINTELLIGENT_H
#include "Transaction.h"
#include "BourseVector.h"
#include "Trader.h"
#include "PorteFeuille.h"
class TraderIntelligent:public Trader {
    private:
    typeTransaction phase; 
    public:
    TraderIntelligent():phase(sell){}
    Transaction choisirDecision(const Bourse&,const PorteFeuille&);
    
};
#endif