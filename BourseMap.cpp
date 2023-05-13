#include "BourseMap.h"
#include <algorithm>

set<PrixJournalier>BourseMap::getPrixJournalierFromVectorGivenDate(vector<PrixJournalier>PrixJournalierVector,Date D)const{
set<PrixJournalier> setOfPrixJournalierFromSpecifiqueDate;
auto it=find_if(PrixJournalierVector.begin(),PrixJournalierVector.end(),[D](const PrixJournalier& p){return p.getDate()==D;}); //lambda expression,kind off like an inline functions that 
                                                                                                                              //takes the place of the == overide for this and only this find
    if (it == PrixJournalierVector.end()) {
    
        return setOfPrixJournalierFromSpecifiqueDate;
    }
 
     for (auto v = it; v != PrixJournalierVector.end() ; v++) {
        if (v->getDate() == D) {
            setOfPrixJournalierFromSpecifiqueDate.insert(*v);
        }
        else if(D<v->getDate()){
       
            break;
        }
     }
   
    return setOfPrixJournalierFromSpecifiqueDate;
}
BourseMap::BourseMap(const Date& date,string path):Bourse(date)
{    
    vector <PrixJournalier> historiqueVector=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
    for(Date dateCourante(historiqueVector.front().getDate());dateCourante<historiqueVector.back().getDate();dateCourante++){
    
        historique.insert(make_pair(dateCourante,getPrixJournalierFromVectorGivenDate(historiqueVector,dateCourante)));
    }
};


 vector<PrixJournalier>BourseMap::getPrixJournaliersParDate(const Date& date)const {
   cout<<"here the error"<<date<<endl;
   cout<<"this is hisotrique: "<<historique.count(date)<<endl;
   
    set<PrixJournalier> resultSet=historique.at(date);
    cout<<"here"<<date<<endl;
    vector<PrixJournalier> resultPrixJournalier(resultSet.begin(),resultSet.end());
 
    return resultPrixJournalier;
 }

 vector<PrixJournalier>BourseMap::getPrixJournaliersParDateEtPrix(const Date& date,double prix)const {
    set<PrixJournalier> resultSet=historique.at(date);
    vector<PrixJournalier> results;
    for (auto it=resultSet.begin();it!=resultSet.end();it++){
        if(it->getPrix()<=prix){
            results.push_back(*it);
        }
    }
    return results;
 }
double BourseMap:: getPrixParDateEtAction(const Date& date,string action)const{
    PrixJournalier toFind(date,action,-1);
    set<PrixJournalier> resultSet=historique.at(date);
    auto it = resultSet.find(toFind);

     if (it != resultSet.end()) {
        return it->getPrix();
     }
     else return -1;
 }
 double BourseMap:: dernierPrixDuneAction(const Date& date,string action)const{

    if (date<historique.begin()->first ||historique.rbegin()->first<date || (dateCourante<date))//if the searched date is lower/greater than the upper bound of the set or wants to see into the future return empty vector (out of search range)       
            return -1;  
    double dernierPrix=-1;
    Date dateLimite(date);
    dateLimite++;
    for (Date d(historique.begin()->first); d < dateLimite; d++)
    {    set<PrixJournalier> setAtDate=historique.at(d);
         auto it=setAtDate.find(PrixJournalier (d,action));
         if (it!=setAtDate.end())
        {
            dernierPrix= it->getPrix();
        }
    }
    return dernierPrix;

}
    
vector<string> BourseMap:: getActionsDisponiblesParDate(const Date& date) {

    vector<string> results;
    set<PrixJournalier> resultSet=historique.at(date);
 
    for (auto it=resultSet.begin();it!=resultSet.end();it++){
      
         results.push_back(it->getNomAction());
     
    }
    return results;
 }
        