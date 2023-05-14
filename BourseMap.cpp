#include "BourseMap.h"
#include <algorithm>
 BourseMap::BourseMap(const Date& date,string path):Bourse(date)
{    
    vector <PrixJournalier> historiqueVector=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
     
        for(auto pr:historiqueVector){
        PrixJournalier toInsert(pr.getDate(),pr.getNomAction(),pr.getPrix());
        historique.insert(make_pair(pr.getDate(),toInsert));
        }
    }
 vector<PrixJournalier>BourseMap::getPrixJournaliersParDate(const Date& date)const {
    vector<PrixJournalier> resultPrixJournalier;
    auto range=historique.equal_range(date);
    for(auto it=range.first;it!=range.second;it++){
        resultPrixJournalier.push_back(it->second);
    }

 
    return resultPrixJournalier;
 }

 vector<PrixJournalier>BourseMap::getPrixJournaliersParDateEtPrix(const Date& date,double prix)const {
    vector<PrixJournalier> resultPrixJournalier;
    auto range=historique.equal_range(date);
    for(auto it=range.first;it!=range.second;it++){
        if(it->second.getPrix()<prix)
            resultPrixJournalier.push_back(it->second);
    } 
    return resultPrixJournalier;
 }

double BourseMap:: getPrixParDateEtAction(const Date& date,string action)const{
 
  auto range=historique.equal_range(date);
    for(auto it=range.first;it!=range.second;it++){
            if(it->second.getNomAction()==action)
            return it->second.getPrix();
    } 
    return -1;
 }
 double BourseMap:: dernierPrixDuneAction(const Date& date,string action)const{

    if (date<historique.begin()->first ||historique.rbegin()->first<date || (dateCourante<date))//if the searched date is lower/greater than the upper bound of the set or wants to see into the future return empty vector (out of search range)       
            return -1;  
    double dernierPrix=-1;
    double prixSpecifiqueAuneDate;
    Date dateLimite(date);
    dateLimite++;
     for (Date d(historique.begin()->first); d < dateLimite; d++){
        prixSpecifiqueAuneDate=getPrixParDateEtAction(d,action);
        if(prixSpecifiqueAuneDate!=-1){
            dernierPrix=prixSpecifiqueAuneDate;
        }
     }  
    return dernierPrix;

}
    
vector<string> BourseMap:: getActionsDisponiblesParDate(const Date& date) {

    vector<string> resultAction;
    auto range=historique.equal_range(date);
    for(auto it=range.first;it!=range.second;it++){
        resultAction.push_back(it->second.getNomAction());
    }
    return resultAction;
 }
 
        