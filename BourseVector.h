#if !defined(BOURSEVECTOR_H)
#define BOURSEVECTOR_H
#include "Bourse.h"
#define CHEMIN "prices_simple.csv"

class  BourseVector:public Bourse

{
private:
    vector<PrixJournalier> historique;
public:
    BourseVector(const Date& date,string path=CHEMIN);
    vector<string> getActionsDisponiblesParDate(const Date& date)override;
    vector<PrixJournalier> getPrixJournaliersParDate(const Date& date)const override;
    vector<PrixJournalier> getPrixJournaliersParDateEtPrix(const Date& date,double prix)const override;
};
#endif