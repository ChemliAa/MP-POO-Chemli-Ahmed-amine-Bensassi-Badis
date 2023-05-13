#include "PrixJournalier.h"
#include "BourseVector.h"
#include "Date.h"     
#include "BourseMap.h"
#include "BourseMapToVector.h"
#include "BourseSet.h"
using namespace std;

int main(){


    Date dateFinDeRecherche("14/9/2010");
    Date d1("05/05/2012");
    bool conditionDateFin=true;
 
    BourseMapToVector bourse(dateFinDeRecherche,"mini.csv");
 
    vector<PrixJournalier> PrixJournaliertoOuput=bourse.getPrixJournaliersParDate(d1);
    vector<string> nomActiontoOuput=bourse.getActionsDisponiblesParDate(d1);
    cout<<PrixJournaliertoOuput.size()<<endl;
       cout<<nomActiontoOuput.size()<<endl;
    for (int i = 0; i < PrixJournaliertoOuput.size(); i++)
    {         //cout<<"date: " <<PrixJournaliertoOuput[i].getDate()<<"nom:"<<PrixJournaliertoOuput[i].getNomAction()<<endl;
        if((dateFinDeRecherche<PrixJournaliertoOuput[i].getDate()) || (d1<PrixJournaliertoOuput[i].getDate())){
            conditionDateFin=false;
            break;
        }

    }
 
    if(conditionDateFin){
        cout<<"extraction of 'prix journalier' before a given date [passed]"<<endl;
    }
    else {
        cout<<"extraction of 'prix journalier' before a given date [failed]"<<endl;
    }
   Date dateCourante("4/1/2010");
 
   vector<PrixJournalier> PrixJournalierDisponible=bourse.getPrixJournaliersParDateEtPrix(dateCourante,10);
   cout<<PrixJournalierDisponible.size()<<endl;
   bool respectValidationConditions=true;
    for (int i = 0; i < PrixJournalierDisponible.size(); i++)
    {    Date stockDate=PrixJournalierDisponible[i].getDate();
         if(!((stockDate<dateCourante || stockDate==dateCourante) && (10 >PrixJournalierDisponible[i].getPrix()))){
            cout<<"date: " <<PrixJournalierDisponible[i].getDate()<<"nom:"<<PrixJournalierDisponible[i].getNomAction()<<PrixJournalierDisponible[i].getPrix()<<endl;
            respectValidationConditions=false;
         }
    }
     if(respectValidationConditions){
        cout<<"extraction of 'prix journalier' before a given date and being below a price range [passed]"<<endl;
    }
    else {
        cout<<"extraction of 'prix journalier' before a given date and being below a price range  [failed]"<<endl;
    }
 

 

}
