#include "Bourse.h"
#include "PrixJournalier.cpp"
#include "PersistancePrixJournaliers.h"
#include <vector>
#define CHEMIN "C:/Users/ahmad/Documents/Enit/P3-4/MiniProjetC++/prices_simple.csv"

class  BourseVector:public Bourse

{
private:
    vector<PrixJournalier> historique;
public:
    BourseVector(const Date& date,string path=CHEMIN);
    vector<string> getActionsDisponiblesParDate(const Date& date)override;
    vector<PrixJournalier> getPrixJournaliersParDate(const Date& date)override;
};
