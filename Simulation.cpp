#include "Simulation.h"
void Simulation::executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde)
{   
    PorteFeuille porteFeuille(solde);
    Date dateLimite(dateFin);
    dateLimite++;
    Transaction t=trader.choisirDecision(bourse,porteFeuille);
    int nbrDeTransactionsEffectues=0;
    
    for (Date dateCourante(dateDebut);dateCourante<dateLimite;dateCourante++)
    {
    while((t.getType()!=hold) && (nbrDeTransactionsEffectues<100))
    {   
    
        Transaction t=trader.choisirDecision(bourse,porteFeuille);
        nbrDeTransactionsEffectues++;
        if (t.getType()==buy)
        {
            porteFeuille.retirerMontant(t.getQuantite()*bourse.getPrixParDateEtAction(dateCourante,t.getNomAction()));
            Titre titreAchete(t.getNomAction(),t.getQuantite());
            porteFeuille.ajoutTitre(&titreAchete);
        }
        if (t.getType()==sell)
        {
            porteFeuille.ajoutMontant(t.getQuantite()*bourse.getPrixParDateEtAction(dateCourante,t.getNomAction()));
            Titre titreVendu(t.getNomAction(),t.getQuantite());
            
            if(titreVendu.getQtte()!=porteFeuille.getQuantiteTitre(titreVendu.getNomAction()))
              {  Titre titreAPlacer(t.getNomAction(),porteFeuille.getQuantiteTitre(titreVendu.getNomAction())-t.getQuantite());
                porteFeuille.suprimerTitre(titreVendu.getNomAction());
                porteFeuille.ajoutTitre(&titreAPlacer);}
            else
            {
                porteFeuille.suprimerTitre(titreVendu.getNomAction());
            }
        }
        
        
    }
    }
    double finalBalance=porteFeuille.getSolde();
        for ( auto t:porteFeuille.getTitres())
        {
            finalBalance+=bourse.dernierPrixDuneAction(dateFin,t->getNomAction());
        }
    cout<<"Solde finale:"<<finalBalance<<endl;
}
