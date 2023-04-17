#include "PrixJournalier.h"
#include <iostream>
#include "PrixJournalier.cpp"
#include <sstream>
using namespace std;

int main()
{   string pjStringFormat = "1/1/2010;ESS;250.5524";
    Date dateToCompare("1/1/2010");
    istringstream input_stream_pj(pjStringFormat);
    PrixJournalier pj;
    input_stream_pj>>(pj);

    //given an inputstream , when executing the '>>' overload operator on a 'prixjournalier' type, expect a correct parsing to the date,action name and value
    if(pj.getDate()==dateToCompare && pj.getNomAction()=="ESS" && pj.getPrix()==250.5524){
        cout<<"extraction of 'prixJournalier' given a stream using the '>>' operator overload [passed]"<<endl;
    }
    else{
         cout<<"extraction of 'prixJournalier' given a stream using the '>>' operator overload [failed]"<<endl;
    }

}