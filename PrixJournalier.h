#include "Date.cpp"
class PrixJournalier
{
private:
    Date date;
    string nomAction;
    double prix; 
public:
    friend istream& operator>> (istream& flux, PrixJournalier& pj );
    PrixJournalier():date(1,1,2000),nomAction(""),prix(0){};
    Date getDate()const;
    string getNomAction()const;
    double getPrix()const;
};