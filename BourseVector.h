#include "Bourse.h"
#include "PrixJournalier.h"
#include "PersistancePrixJournaliers.h"
#include <vector>
#define CHEMIN "C:\Users\ahmad\Documents\Enit\P3-4\MiniProjetC++\prices_simple.csv"

class  BourseVector:public Bourse

{
private:
    vector<PrixJournalier> historique;
public:
    BourseVector(Date date,string path=CHEMIN);
    vector<string> getActionsDisponiblesParDate(Date date)override;
    vector<PrixJournalier> getPrixJournaliersParDate(Date date)override;
};

