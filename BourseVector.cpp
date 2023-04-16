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
  