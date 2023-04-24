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
        if (i->getDate()==date && (i->getDate()<dateCourante || i->getDate()==dateCourante ))
        {
            ActionsDisponibles.push_back(i->getNomAction());
        }           
       } 
    return ActionsDisponibles;       
}
 vector<PrixJournalier> BourseVector::getPrixJournaliersParDate(const Date& date)const{
    vector<PrixJournalier> PrixJournaliersDansDate;
    if (historique[historique.size()-1].getDate()<date)//if the searched date is greater than the upper bound of the vector return empty vector (out of search range)       
            return PrixJournaliersDansDate;  
    for (auto i = historique.begin(); i != historique.end(); ++i)
        {   
        if (date< i->getDate())//if the iterated date is greater than the searched date exit the loop       
            break;
        if (i->getDate()==date && (i->getDate()<dateCourante || i->getDate()==dateCourante ))
        {
            PrixJournaliersDansDate.push_back(*i);
        }
        }
    return PrixJournaliersDansDate;    
 }
 vector<PrixJournalier> BourseVector::getPrixJournaliersParDateEtPrix(const Date& date,double soldeCourant)const{
    vector<PrixJournalier> PrixJournaliersDansDate;
    
    if (historique[historique.size()-1].getDate()<date)//if the searched date is greater than the upper bound of the vector return empty vector (out of search range)       
            return PrixJournaliersDansDate;  
    for (auto i = historique.begin(); i != historique.end(); ++i)
        {   
        if (date< i->getDate()){
            
            break; 
        }
        if (i->getDate()==date && (i->getDate()<dateCourante || i->getDate()==dateCourante) && soldeCourant>i->getPrix())
        {    
            PrixJournaliersDansDate.push_back(*i);
        }
        }
    return PrixJournaliersDansDate;    
 }
double BourseVector::getPrixParDateEtAction(const Date& date,string action)const
{
    if ((date<dateCourante) || (date==dateCourante))
    {
    for (auto i = historique.begin(); i != historique.end(); ++i)
    {
        if(i->getDate()==date && i->getNomAction()==action)
            return i->getPrix();
    }
    }
    return -1;

}
double BourseVector::dernierPrixDuneAction(const Date& date,string action)const
{   
    Date dateLimite(date);
    dateLimite++;
    double dernierPrix=-1;
    if ((date<dateCourante) || (date==dateCourante))
    {
    for (Date d(historique[0].getDate()); d < dateLimite; d++)
    {
        dernierPrix=this->getPrixParDateEtAction(date,action);
    }
    }
    return dernierPrix;
}
void BourseVector::setDateCourante(Date date)
{
    dateCourante=date;
}

