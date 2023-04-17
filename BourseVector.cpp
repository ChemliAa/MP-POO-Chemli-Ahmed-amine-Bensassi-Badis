#include "BourseVector.h"
BourseVector::BourseVector(const Date& date,string path):Bourse(date)
{
    historique=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
};

vector<string> BourseVector::getActionsDisponiblesParDate(const Date& date){
    vector<string> ActionsDisponibles;
     if (historique[historique.size()-1].getDate()<date)//if the searched date is greater than the upper bound of the vector return empty vector (out of search range)       
            return ActionsDisponibles;   
    for (auto i = historique.begin(); i != historique.end(); ++i)
       { 
        if (date< i->getDate())//if the iterated date is greater than the searched date exit the loop       
            break;     
        if (i->getDate()==date && i->getDate()<dateCourante)
        {
            ActionsDisponibles.push_back(i->getNomAction());
        }           
       } 
    return ActionsDisponibles;       
}
 vector<PrixJournalier> BourseVector::getPrixJournaliersParDate(const Date& date){
    vector<PrixJournalier> PrixJournaliersDansDate;
    if (historique[historique.size()-1].getDate()<date)//if the searched date is greater than the upper bound of the vector return empty vector (out of search range)       
            return PrixJournaliersDansDate;  
    for (auto i = historique.begin(); i != historique.end(); ++i)
        {
        if (date< i->getDate())//if the iterated date is greater than the searched date exit the loop       
            break;
        if (i->getDate()==date && i->getDate()<dateCourante)
        {
            PrixJournaliersDansDate.push_back(*i);
        }
        }
    return PrixJournaliersDansDate;    
 }
 