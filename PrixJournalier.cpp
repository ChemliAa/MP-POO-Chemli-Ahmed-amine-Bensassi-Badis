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
int main()
{
    PrixJournalier pj;

    cin>>pj;
    cout<<pj.getDate()<<endl;
    cout<<pj.getNomAction()<<endl;
    cout<<pj.getPrix()<<endl;
    
}