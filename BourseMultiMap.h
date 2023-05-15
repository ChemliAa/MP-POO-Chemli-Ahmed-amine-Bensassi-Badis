#if !defined(BOURSEMULTIPMAP_H)
#define BOURSEMULTIPMAP_H
#include "Bourse.h"
#include<map>
#define CHEMIN "prices_simple.csv"
class  BourseMultiMap:public Bourse
{
private:
    multimap <Date,PrixJournalier> historique;
public:
    BourseMultiMap(const Date& date,string path=CHEMIN);
    vector<string> getActionsDisponiblesParDate(const Date& date)override;
    vector<PrixJournalier> getPrixJournaliersParDate(const Date& date)const override;
    vector<PrixJournalier> getPrixJournaliersParDateEtPrix(const Date& date,double prix)const override;
    double getPrixParDateEtAction(const Date& date,string action)const override ;
    double dernierPrixDuneAction(const Date& date,string action)const override;
};
#endif