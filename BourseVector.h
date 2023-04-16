#include "Bourse.h"
#include "PrixJournalier.h"
#include "PersistancePrixJournaliers.h"
#include <vector>
class  BourseVector:public Bourse

{
private:
    vector<PrixJournalier> historique;
public:
    BourseVector(Date date,string path="C:\Users\ahmad\Documents\Enit\P3-4\MiniProjetC++\prices_simple.csv");
    BourseVector(string date,string path="C:\Users\ahmad\Documents\Enit\P3-4\MiniProjetC++\prices_simple.csv");
    BourseVector(int d,int m,int y,string path="C:\Users\ahmad\Documents\Enit\P3-4\MiniProjetC++\prices_simple.csv");
    vector<string> getActionsDisponiblesParDate(Date date)override;
    vector<PrixJournalier> getPrixJournaliersParDate(Date date)override;
};

BourseVector::BourseVector(Date date,string path="C:\Users\ahmad\Documents\Enit\P3-4\MiniProjetC++\prices_simple.csv"):Bourse(date)
{
    historique=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
};
BourseVector::BourseVector(string date,string path="C:\Users\ahmad\Documents\Enit\P3-4\MiniProjetC++\prices_simple.csv"):Bourse(date)
{
    historique=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
};
BourseVector::BourseVector(int d,int m,int y,string path="C:\Users\ahmad\Documents\Enit\P3-4\MiniProjetC++\prices_simple.csv"):Bourse(d,m,y)
{
    historique=PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(path);
};
vector<string> BourseVector::getActionsDisponiblesParDate(Date date){
    vector<string> ActionsDisponibles;
    for (auto i = historique.begin(); i != historique.end(); ++i)
        if (i->getDate()==date)
        {
            ActionsDisponibles.push_back(i->getNomAction());
        }
    return ActionsDisponibles;       
}
 vector<PrixJournalier> BourseVector::getPrixJournaliersParDate(Date date){
    vector<PrixJournalier> PrixJournaliersDansDate;
    for (auto i = historique.begin(); i != historique.end(); ++i)
        if (i->getDate()==date)
        {
            PrixJournaliersDansDate.push_back(*i);
        }
    return PrixJournaliersDansDate;    
 }