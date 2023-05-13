#if !defined(BOURSEMAPTOVECTOR_H)
#define BOURSEMAPTOVECTOR_H
#include "Bourse.h"
#include<map>
#include<vector>
#define CHEMIN "prices_simple.csv"
class  BourseMapToVector:public Bourse
{
private:
    map<Date,vector<PrixJournalier>> historique;
    vector<PrixJournalier> getPrixJournalierFromVectorGivenDate(vector<PrixJournalier>,Date D)const;

public:
    BourseMapToVector(const Date& date,string path=CHEMIN);
    vector<string> getActionsDisponiblesParDate(const Date& date)override;
    vector<PrixJournalier> getPrixJournaliersParDate(const Date& date)const override;
    vector<PrixJournalier> getPrixJournaliersParDateEtPrix(const Date& date,double prix)const override;
    double getPrixParDateEtAction(const Date& date,string action)const override ;
    double dernierPrixDuneAction(const Date& date,string action)const override;
};
#endif