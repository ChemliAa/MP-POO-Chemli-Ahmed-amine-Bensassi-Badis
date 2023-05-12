#include "BourseSet.h"
BourseSet::BourseSet(const Date& date,string path):Bourse(date)
{
    vector <PrixJournalier> historiqueVector=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
    for (auto pj:historiqueVector)
    {
        historique.insert(pj);
    }
    
};
vector<string> BourseSet::getActionsDisponiblesParDate(const Date& date){
    vector<string> ActionsDisponibles;
     if (date<historique.begin()->getDate()||historique.rbegin()->getDate()<date || (dateCourante<date))//if the searched date is lower/greater than the upper bound of the set or wants to see into the future return empty vector (out of search range)       
            return ActionsDisponibles;   
    PrixJournalier pj1(date);
    Date dateLimite(date);
    PrixJournalier pj2(dateLimite++);
    auto it1 = historique.lower_bound(pj1);
    auto it2 = historique.upper_bound(pj2);
    if (it1!=historique.end())
    {
        for (auto it = it1; it !=it2; ++it) {
            ActionsDisponibles.push_back(it->getNomAction());
        } 
    } 
    return ActionsDisponibles;       
}
 vector<PrixJournalier> BourseSet::getPrixJournaliersParDate(const Date& date)const{
    vector<PrixJournalier> PrixJournaliersDansDate;
     if (date<historique.begin()->getDate()||historique.rbegin()->getDate()<date || (dateCourante<date))//if the searched date is lower/greater than the upper bound of the set or wants to see into the future return empty vector (out of search range)       
            return PrixJournaliersDansDate;   
    PrixJournalier pj1(date);
    Date dateLimite(date);
    PrixJournalier pj2(dateLimite++);//creates prix journalier with date being the day after date and price==0 which should be less than any actual price did this because of the way < works for pj 
    auto it1 = historique.lower_bound(pj1);
    auto it2 = historique.upper_bound(pj2);
    if (it1!=historique.end())
    {
        for (auto it = it1; it !=it2; ++it) {
            PrixJournaliersDansDate.push_back(*it);
        } 
    }
    return PrixJournaliersDansDate;       
}
vector<PrixJournalier> BourseSet::getPrixJournaliersParDateEtPrix(const Date& date,double prix)const{
    vector<PrixJournalier> PrixJournaliersDansDate;
     if (date<historique.begin()->getDate()||historique.rbegin()->getDate()<date || (dateCourante<date))//if the searched date is lower/greater than the upper bound of the set or wants to see into the future return empty vector (out of search range)       
            return PrixJournaliersDansDate;   
    PrixJournalier pj1(date);
    auto it1 = historique.lower_bound(pj1);
    if (it1!=historique.end())
    {
        for (auto it = it1; it !=historique.end(); ++it) {
            if(date<it->getDate()||prix<it->getPrix())break;
            PrixJournaliersDansDate.push_back(*it);
        } 
    }
    return PrixJournaliersDansDate;       
}


double  BourseSet::getPrixParDateEtAction(const Date& date,string action)const{

}