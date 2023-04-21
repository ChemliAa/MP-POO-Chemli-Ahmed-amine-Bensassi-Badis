#if !defined(TRADER_H)
#define TRADER_H
#include "Transaction.h"
#include "Bourse.h"
#include "PorteFeuille.h"
class Trader{
    public:
    virtual Transaction choisirDecision(const Bourse&,const PorteFeuille&)=0;
    virtual ~Trader(){};
};
#endif // TRADER_H
