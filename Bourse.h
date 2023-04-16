#include "Date.h"
class Bourse{
    private:
    Date dateFinRech;
    public:
    Bourse():dateFinRech("1/1/2000"){};
    virtual ~Bourse();
    virtual string getActionsDisponiblesParDate(Date)=0;
    virtual double getPrixJournaliersParDate(Date)=0;
};