#include "BourseMapToVector.h"
#include <algorithm>
#include<vector>
vector<PrixJournalier>BourseMapToVector::getPrixJournalierFromVectorGivenDate(vector<PrixJournalier>PrixJournalierVector,Date D)const{
vector<PrixJournalier> vectorOfPrixJournalierFromSpecifiqueDate;
auto it=find_if(PrixJournalierVector.begin(),PrixJournalierVector.end(),[D](const PrixJournalier& p){return p.getDate()==D;}); //lambda expression,kind off like an inline functions that 
                                                                                                                              //takes the place of the == overide for this and only this find
    if (it == PrixJournalierVector.end()) {
    
        return vectorOfPrixJournalierFromSpecifiqueDate;
    }
 
     for (auto v = it; v != PrixJournalierVector.end() ; v++) {
        if (v->getDate() == D) {
            vectorOfPrixJournalierFromSpecifiqueDate.push_back(*v);
        }
        else if(D<v->getDate()){
       
            break;
        }
     }
 
    return vectorOfPrixJournalierFromSpecifiqueDate;
}
BourseMapToVector::BourseMapToVector(const Date& date,string path):Bourse(date)
{        
    vector <PrixJournalier> historiqueVector=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
    Date limiteBound=historiqueVector.back().getDate();
    limiteBound++;
    for(Date dateCourante(historiqueVector.front().getDate());dateCourante<limiteBound;dateCourante++){
      
        historique.insert(make_pair(dateCourante,getPrixJournalierFromVectorGivenDate(historiqueVector,dateCourante)));
    }
   
};


 vector<PrixJournalier>BourseMapToVector::getPrixJournaliersParDate(const Date& date)const {
    
    vector <PrixJournalier> result;
    if(dateCourante<date)
        return result;
        try{
    return historique.at(date);
    }catch(out_of_range& e){  
    return result;
    }
 }

 vector<PrixJournalier>BourseMapToVector::getPrixJournaliersParDateEtPrix(const Date& date,double prix)const {
  
    vector<PrixJournalier> results;
    vector<PrixJournalier> resultsToGive;
    if(dateCourante<date)
        return results;
    try{
    results=historique.at(date);
    }catch(out_of_range& e){
        return resultsToGive;
    }
    for (auto p:results){
        if(p.getPrix()<prix){
   
            resultsToGive.push_back(p);
        }
    }
 
    return resultsToGive;
 }
double BourseMapToVector::getPrixParDateEtAction(const Date& date,string action)const{
 
 
    if(dateCourante<date){
        
        return -1;
    }
    try{
     vector<PrixJournalier> results=historique.at(date);
      for (auto p:results){
        if(p.getNomAction()==action){
          
            return p.getPrix();
        }
  
 }}catch(out_of_range& e){  
    return -1;  
    }
    return -1;
}
 double BourseMapToVector::dernierPrixDuneAction(const Date& date,string action)const{

    if (date<historique.begin()->first ||historique.rbegin()->first<date || (dateCourante<date)){//if the searched date is lower/greater than the upper bound of the set or wants to see into the future return empty vector (out of search range)       
            return -1;  
    }
    double dernierPrix=-1;
    Date dateLimite(date);
    dateLimite++;
    for (Date d(historique.begin()->first); d < dateLimite; d++)
    {    vector<PrixJournalier> vectorOfPrixAtDate=historique.at(d);
     
         for(auto p:vectorOfPrixAtDate){
             
            if( p.getNomAction()==action) {
                dernierPrix=p.getPrix();
            }
         }
    }
    return dernierPrix;

}
    
vector<string> BourseMapToVector:: getActionsDisponiblesParDate(const Date& date) {
  
        vector<string> results;
        try{
        if(dateCourante<date)
            return results;
        vector<PrixJournalier> resultVect=historique.at(date);
        for(auto p: resultVect){
            results.push_back(p.getNomAction());
        }
    }catch(out_of_range& e){
       
    }
    return results;
 }
        