#include "PrixJournalier.h"
#include "BourseVector.h"
#include "Date.h"     
#include "BourseMap.h"
#include "BourseMapToVector.h"
#include "BourseSet.h"
using namespace std;

int main(){


    Date dateFinDeRecherche("14/9/2015");
    Date d1("01/04/2010");
    bool conditionDateFin=true;
 
    BourseSet bourse(dateFinDeRecherche,"mini.csv");
    BourseMap bourse2(dateFinDeRecherche,"mini.csv");
    for(Date d(d1);d<dateFinDeRecherche;d++){
        cout<<d<<endl;
         if(bourse2.getPrixJournaliersParDateEtPrix(d,500).size()!=bourse.getPrixJournaliersParDateEtPrix(d,500).size()){
            cout<<"here"<<endl;
            break;
        }
        if(bourse2.getPrixParDateEtAction(d,"PBCT")!=bourse.getPrixParDateEtAction(d,"PBCT")){
            cout<<"nope"<<endl;
            break;
        }
        if(bourse2.getPrixJournaliersParDate(d).size()!=bourse.getPrixJournaliersParDate(d).size()){
            cout<<"aaa"<<endl;
            break;
        }
        if(bourse2.getActionsDisponiblesParDate(d).size()!=bourse.getActionsDisponiblesParDate(d).size()){
            cout<<"b"<<endl;
            break;
        }
          if(bourse2.getPrixParDateEtAction(d,"LVLT")!=bourse.getPrixParDateEtAction(d,"LVLT")){
            cout<<"nope"<<endl;
            break;
        }
         if(bourse2.getPrixParDateEtAction(d,"MTD")!=bourse.getPrixParDateEtAction(d,"MTD")){
            cout<<"nope"<<endl;
            break;
        }
         if(bourse2.getPrixParDateEtAction(d,"MO")!=bourse.getPrixParDateEtAction(d,"MO")){
            cout<<"nope"<<endl;
            break;
        }
         if(bourse2.getPrixParDateEtAction(d,"MOS")!=bourse.getPrixParDateEtAction(d,"MOS")){
            cout<<"nope"<<endl;
            break;
        }
         if(bourse2.getPrixParDateEtAction(d,"MON")!=bourse.getPrixParDateEtAction(d,"MON")){
            cout<<"nope"<<endl;
            break;
        }
    
    }
    vector<PrixJournalier> PrixJournaliertoOuput=bourse2.getPrixJournaliersParDate(d1);
    vector<string> nomActiontoOuput=bourse2.getActionsDisponiblesParDate(d1);
    
    for (int i = 0; i < PrixJournaliertoOuput.size(); i++)
    {     //cout<<"date: " <<PrixJournaliertoOuput[i].getDate()<<"nom:"<<PrixJournaliertoOuput[i].getNomAction()<<endl;
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
 
   bool respectValidationConditions=true;
    for (int i = 0; i < PrixJournalierDisponible.size(); i++)
    {    Date stockDate=PrixJournalierDisponible[i].getDate();
         if(!((stockDate<dateCourante || stockDate==dateCourante) && (10 >PrixJournalierDisponible[i].getPrix()))){
          
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
