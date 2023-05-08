#include "PrixJournalier.h"
#include "BourseVector.h"
#include "Date.h"     
using namespace std;

int main(){


    Date dateFinDeRecherche("20/10/2015");
    Date d1("04/01/2010");
    bool conditionDateFin=true;
    BourseVector bourse(dateFinDeRecherche);
    vector<PrixJournalier> PrixJournaliertoOuput=bourse.getPrixJournaliersParDate(d1);
    vector<string> nomActiontoOuput=bourse.getActionsDisponiblesParDate(d1);

    for (int i = 0; i < PrixJournaliertoOuput.size(); i++)
    {         
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
   BourseVector bourse2(dateCourante);
   vector<PrixJournalier> PrixJournalierDisponible=bourse2.getPrixJournaliersParDateEtPrix(dateCourante,10);
   bool respectValidationConditions=true;
    for (int i = 0; i < PrixJournalierDisponible.size(); i++)
    {    Date stockDate=PrixJournalierDisponible[i].getDate();
         if(!(stockDate==dateCourante && (stockDate<dateCourante || stockDate==dateCourante) && (10 >PrixJournalierDisponible[i].getPrix()))){
            respectValidationConditions=false;
         }
    }
     if(respectValidationConditions){
        cout<<"extraction of 'prix journalier' before a given date and being below a price range [passed]"<<endl;
    }
    else {
        cout<<"extraction of 'prix journalier' before a given date and being below a price range  [failed]"<<endl;
    }
  cout<<nomActiontoOuput.size()<<endl;
  cout<<PrixJournaliertoOuput.size()<<endl;
}
