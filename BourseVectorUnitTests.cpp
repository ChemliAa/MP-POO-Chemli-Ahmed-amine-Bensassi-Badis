#include "PrixJournalier.h"
#include "BourseVector.h"
#include "Date.h"     
using namespace std;

int main(){


    Date dateFinDeRecherche("20/10/2015");
    Date d1("10/05/2010");
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
   
    
}
