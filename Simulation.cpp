#include "Simulation.h"
#include <cmath>
#include "TraderAleatoire.h"
#include "./customExceptions/TransactionUnknown.cpp"
#include<map>
#include<iostream>
map<string,long> Simulation::executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde)
{   map<string, long> stats;
    
    PorteFeuille porteFeuille(solde);
    Date dateLimite(dateFin);
    dateLimite++;
    //simulation needs to verify trader doesn't break rules 
    int totalNumberOfTransactions=0;
    int totalNumberOfNonAcceptedTransactions=0;
    int totalNumberOfBuyTransaction=0;
    int totalNumberOfSellTransaction=0;
    int totalNumberOfHoldTransaction=0;
    int nbrDeTransactionsEffectuesAjourdhui=0;
    for (Date dateCourante(dateDebut);dateCourante<dateLimite;dateCourante++){
       
        bourse.setDateCourante(dateCourante);
        Transaction t;  
        nbrDeTransactionsEffectuesAjourdhui=0;
        do
            {   
 
                t=trader.choisirDecision(bourse,porteFeuille);
                nbrDeTransactionsEffectuesAjourdhui++;
                totalNumberOfTransactions++;
               
                if (t.getType()==buy){   
                    if(bourse.getPrixParDateEtAction(dateCourante,t.getNomAction()) * t.getQuantite() > porteFeuille.getSolde()){
                      totalNumberOfNonAcceptedTransactions++;
                }
                else{
                    porteFeuille.acheter(t.getNomAction(),t.getQuantite(),bourse.getPrixParDateEtAction(dateCourante,t.getNomAction()));
                    totalNumberOfBuyTransaction++;
                    }
                }
                else if (t.getType()==sell){   
                    if(porteFeuille.getTitresbyActionName(t.getNomAction()).getQtte() < t.getQuantite()){
                        totalNumberOfNonAcceptedTransactions++;
                }
                    else{
                        porteFeuille.vendre(t.getNomAction(),t.getQuantite(),bourse.getPrixParDateEtAction(dateCourante,t.getNomAction()));
                        totalNumberOfSellTransaction++;
                    }
                }

                else{/*if t==hold do nothing */
                totalNumberOfHoldTransaction++;
             }   
      
            }
                            
             while((t.getType()!=hold) && (nbrDeTransactionsEffectuesAjourdhui<100));
    }        
    double finalBalance=porteFeuille.getSolde();
        for ( auto t:porteFeuille.getTitres())
        {
            finalBalance+=bourse.dernierPrixDuneAction(dateFin,t->getNomAction());
        }
    stats["TotalTx"]=totalNumberOfTransactions;
    stats["TotalBuyTx"]=totalNumberOfBuyTransaction;
    stats["TotalSellTx"]=totalNumberOfSellTransaction;
    stats["TotalHoldTx"]=totalNumberOfHoldTransaction;
    stats["TotalFalseTX"]=totalNumberOfNonAcceptedTransactions;
    stats["Solde"]=finalBalance; 
    return stats;
}

int main(){
    TraderAleatoire t;
    Date datecourant("4/1/2010");
    Date fin("5/1/2011");
    PorteFeuille p(10);
    BourseVector b(datecourant,CHEMIN);
    map<string,long> stats ;
    stats=Simulation::executer(b,t,datecourant,fin,1000);
    cout<<"simulation terminer voici les statistiques: "<<endl;
    cout<<"nombre total des transaction: "<<stats["TotalTx"]<<endl;
    cout<<"nombre total des transaction de type achat : "<<stats["TotalBuyTx"]<<endl;
    cout<<"nombre total des transaction de type vente : "<<stats["TotalSellTx"]<<endl;
    cout<<"nombre total des transaction de type rien faire : "<<stats["TotalHoldTx"]<<endl;
    cout<<"nombre total des transaction non accepte : "<<stats["TotalFalseTX"]<<endl;
    cout<<"solde final : "<<stats["Solde"]<<endl;
 

    
}