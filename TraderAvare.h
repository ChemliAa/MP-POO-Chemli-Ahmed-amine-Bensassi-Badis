#if !defined(TADERAVARE_H)
#define TADERAVARE_H
#include "Transaction.h"
#include "BourseVector.h"
#include "Trader.h"
#include "PorteFeuille.h"
#include <map>
class TraderAvare:public Trader {
    public:
      Transaction choisirDecision(const Bourse&,const PorteFeuille&);
    private:
    int findQuantityByActionName(string name,vector<Titre*> titles);
    string findCheapestAction(vector<PrixJournalier> pr);
    map<string,int> totalPrice;
};
#endif