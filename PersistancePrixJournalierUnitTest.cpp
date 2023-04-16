#include "PersistancePrixJournaliers.h"
#include "BourseVector.h"
using namespace std;

int main()
{
    //given the existance of the csv file on the path global varibale,when  the  lirePrixJournaliersDUnFichier is exeuted,expect a 851264 sized vector 
    long int nombreDePrixJournalier=851264;
    vector<PrixJournalier> historique=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(CHEMIN);
    if(historique.size() == nombreDePrixJournalier ){
        cout<<"extraction of 'prix journalier' from a csv file [passed]"<<endl; 
    }
    else{
        cout<<"extraction of 'prix journalier' from a csv file [failed]"<<endl; 
    }
}
