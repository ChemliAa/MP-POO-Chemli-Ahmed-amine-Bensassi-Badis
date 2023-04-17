#ifndef PRIXJOURNALIER_H
#define PRIXJOURNALIER_H
#include "Date.cpp"
class PrixJournalier
{
private:
    Date date;
    string nomAction;
    double prix; 
public:
    friend istream& operator>> (istream& flux, PrixJournalier& pj );
    PrixJournalier(Date datePrixJournalier):date(datePrixJournalier),nomAction(""),prix(0){};
    PrixJournalier(int d=1,int m=1,int y=2000):date(d,m,y),nomAction(""),prix(0){};
    Date getDate()const;
    string getNomAction()const;
    double getPrix()const;
};
#endif // PRIXJOURNALIER_H