#if !defined(BOURSE_H)
#define BOURSE_H
#include <vector>
#include "PrixJournalier.h"
#include "PersistancePrixJournaliers.h"
#include "Date.h"
class Bourse{
    protected:
    Date dateFinRech;
    public:
    Bourse(const Date& date):dateFinRech(date){}
    virtual ~Bourse(){};
    Date getDateFinRech(){return dateFinRech;}
    virtual vector<string> getActionsDisponiblesParDate(const Date&)=0;
    virtual vector<PrixJournalier> getPrixJournaliersParDate(const Date&)=0;
};
#endif // BOURSE_H