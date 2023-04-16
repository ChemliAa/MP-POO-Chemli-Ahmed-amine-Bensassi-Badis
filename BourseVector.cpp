#include "BourseVector.h"
BourseVector::BourseVector(Date date,string path=CHEMIN):Bourse(date)
{
    historique=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
};
BourseVector::BourseVector(string date,string path=CHEMIN):Bourse(date)
{
    historique=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
};
BourseVector::BourseVector(int d,int m,int y,string path=CHEMIN):Bourse(d,m,y)
{
    historique=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
};
vector<string> BourseVector::getActionsDisponiblesParDate(Date date){
    vector<string> ActionsDisponibles;
    for (auto i = historique.begin(); i != historique.end(); ++i)
        if (i->getDate()==date && i->getDate()<dateFinRech)
        {
            ActionsDisponibles.push_back(i->getNomAction());
        }
    return ActionsDisponibles;       
}
 vector<PrixJournalier> BourseVector::getPrixJournaliersParDate(Date date){
    vector<PrixJournalier> PrixJournaliersDansDate;
    for (auto i = historique.begin(); i != historique.end(); ++i)
        if (i->getDate()==date && i->getDate()<dateFinRech)
        {
            PrixJournaliersDansDate.push_back(*i);
        }
    return PrixJournaliersDansDate;    
 }
 