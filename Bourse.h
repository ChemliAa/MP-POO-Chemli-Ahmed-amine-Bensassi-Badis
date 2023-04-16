#if !defined(BOURSE_H)
#define BOURSE_H

#include "Date.h"
class Bourse{
    protected:
    Date dateFinRech;
    public:
    Bourse(Date date):dateFinRech(date){};
    virtual ~Bourse(){};
    Date getDateFinRech(){return dateFinRech;}
    virtual vector<string> getActionsDisponiblesParDate(Date)=0;
    virtual vector<PrixJournalier> getPrixJournaliersParDate(Date)=0;
};
#endif // BOURSE_H