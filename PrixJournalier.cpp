#include "PrixJournalier.h"

Date PrixJournalier::getDate()const {return date;}
string PrixJournalier::getNomAction()const {return nomAction;}
double PrixJournalier::getPrix()const {return prix;}
istream& operator>> (istream& flux, PrixJournalier& pj )
{
    flux >>pj.date;
    char tab[100];
	flux.getline(tab,100,';');
    pj.nomAction=tab;
    flux.getline(tab,100);
    double p=atof(tab);
    pj.prix=p;
    return flux;
}
bool operator<(const PrixJournalier& pj1,const PrixJournalier& pj2)
{
	if (!(pj1.date==pj2.date)) return (pj1.date<pj2.date); 
	if (!(pj1.prix==pj2.prix)) return (pj1.prix<pj2.prix); 
	return (pj1.nomAction<pj2.nomAction); 
}
