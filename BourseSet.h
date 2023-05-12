#if !defined(BOURSESET_H)
#define BOURSESET_H
#include "Bourse.h"
#define CHEMIN "prices_simple.csv"

class  BourseSet:public Bourse

{
private:
    set<PrixJournalier> historique;
public:
    BourseSet(const Date& date,string path=CHEMIN);
    vector<string> getActionsDisponiblesParDate(const Date& date)override;
    vector<PrixJournalier> getPrixJournaliersParDate(const Date& date)const override;
    vector<PrixJournalier> getPrixJournaliersParDateEtPrix(const Date& date,double prix)const override;
    double getPrixParDateEtAction(const Date& date,string action)const override ;
    double dernierPrixDuneAction(const Date& date,string action)const override;
    void setDateCourante(Date date)override;
};
#endif