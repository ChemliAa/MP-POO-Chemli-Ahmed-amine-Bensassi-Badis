#if !defined(BOURSE_H)
#define BOURSE_H
#include <vector>
#include "PrixJournalier.h"
#include "PersistancePrixJournaliers.h"
#include "Date.h"
class Bourse{
    protected:
    Date dateCourante;
    public:
    Bourse(const Date& date):dateCourante(date){}
    virtual ~Bourse(){};
    Date getDateFinRech()const{return dateCourante;}
    virtual vector<string> getActionsDisponiblesParDate(const Date&)=0;
    virtual vector<PrixJournalier> getPrixJournaliersParDate(const Date&)const =0;
    virtual vector<PrixJournalier> getPrixJournaliersParDateEtPrix(const Date& date,double soldeCourant)const =0;
    virtual double getPrixParDateEtAction(const Date& date,string action)const =0;
    virtual double dernierPrixDuneAction(const Date& date,string action)const =0;
    virtual void setDateCourante(Date date)=0;
};
#endif // BOURSE_H