#include "BourseVector.h"
BourseVector::BourseVector(const Date& date,string path):Bourse(date)
{
    historique=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
};

vector<string> BourseVector::getActionsDisponiblesParDate(const Date& date){
    vector<string> ActionsDisponibles;
    for (auto i = historique.begin(); i != historique.end(); ++i)
        if (i->getDate()==date && i->getDate()<dateFinRech)
        {
            ActionsDisponibles.push_back(i->getNomAction());
        }
    return ActionsDisponibles;       
}
 vector<PrixJournalier> BourseVector::getPrixJournaliersParDate(const Date& date){
    vector<PrixJournalier> PrixJournaliersDansDate;
    for (auto i = historique.begin(); i != historique.end(); ++i)
        if (i->getDate()==date && i->getDate()<dateFinRech)
        {
            PrixJournaliersDansDate.push_back(*i);
        }
    return PrixJournaliersDansDate;    
 }
 int main(){
    Date d("20/10/2015");
    Date d1("10/05/2010");
    BourseVector bourse(d);
    vector<PrixJournalier> PrixJournaliertoOuput=bourse.getPrixJournaliersParDate(d1);
    vector<string> nomActiontoOuput=bourse.getActionsDisponiblesParDate(d1);

    for (int i = 0; i < PrixJournaliertoOuput.size(); i++)
    {
        cout<<nomActiontoOuput[i]<<":"<<PrixJournaliertoOuput[i].getPrix()<<endl;
    }
    
    
 }