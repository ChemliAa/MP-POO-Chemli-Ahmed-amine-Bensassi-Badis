#ifndef PRIXJOURNALIER_H
#define PRIXJOURNALIER_H
#include "Date.h"
class PrixJournalier
{
private:
    Date date;
    string nomAction;
    double prix; 
public:
    friend istream& operator>> (istream& flux, PrixJournalier& pj );
    friend bool operator<(const PrixJournalier& pj1,const PrixJournalier& pj2);
    PrixJournalier(Date datePrixJournalier,double prix=0):date(datePrixJournalier),nomAction(""),prix(prix){};
    PrixJournalier(int d=1,int m=1,int y=2000):date(d,m,y),nomAction(""),prix(0){};
    Date getDate()const;
    string getNomAction()const;
    double getPrix()const;
};
#endif // PRIXJOURNALIER_H