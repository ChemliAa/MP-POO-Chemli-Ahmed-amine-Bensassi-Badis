#if !defined(TRADERRSI_H)
#define TRADERRSI_H
#include "Transaction.h"
#include "BourseVector.h"
#include "Trader.h"
#include "PorteFeuille.h"
class TraderMoyenne:public Trader {
    public:
      Transaction choisirDecision(const Bourse&,const PorteFeuille&);
    private:
     double CalculerRsAction(const Bourse& b ,string action);
};
#endif