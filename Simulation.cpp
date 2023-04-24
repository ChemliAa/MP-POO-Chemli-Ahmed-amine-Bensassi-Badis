#include "Simulation.h"
void Simulation::executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde)
{   
    PorteFeuille porteFeuille(solde);
    Date dateLimite(dateFin);
    dateLimite++;
    //simulation needs to verify trader doesn't break rules 
    
    for (Date dateCourante(dateDebut);dateCourante<dateLimite;dateCourante++)
    {
    bourse.setDateCourante(dateCourante);
    Transaction t=trader.choisirDecision(bourse,porteFeuille);
    int nbrDeTransactionsEffectues=0;
    while((t.getType()!=hold) && (nbrDeTransactionsEffectues<100))
    {   
    
        Transaction t=trader.choisirDecision(bourse,porteFeuille);
        nbrDeTransactionsEffectues++;
        if (t.getType()==buy)
        {
            porteFeuille.acheter(t.getNomAction(),t.getQuantite(),bourse.getPrixParDateEtAction(dateCourante,t.getNomAction()));
        }
        else if (t.getType()==sell)
        {
            porteFeuille.vendre(t.getNomAction(),t.getQuantite(),bourse.getPrixParDateEtAction(dateCourante,t.getNomAction()));
        }

        else{/*if t==hold do nothing */}
        
    }
    }
    double finalBalance=porteFeuille.getSolde();
        for ( auto t:porteFeuille.getTitres())
        {
            finalBalance+=bourse.dernierPrixDuneAction(dateFin,t->getNomAction());
        }
    cout<<"Solde finale:"<<finalBalance<<endl;
}
