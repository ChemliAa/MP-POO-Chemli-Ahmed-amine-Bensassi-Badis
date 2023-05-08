#include "Simulation.h"
#include <cmath>
#include "TraderAleatoire.h"
#include "./customExceptions/TransactionUnknown.cpp"
#include<map>
#include<chrono>
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
    int nbrGetActionsDisponiblesParDate=0;
    int nbrGetPrixParDateEtActione=0;



    for (Date dateCourante(dateDebut);dateCourante<dateLimite;dateCourante++){
        bourse.setDateCourante(dateCourante);
        auto start = chrono::high_resolution_clock::now();
        if(bourse.getActionsDisponiblesParDate(dateCourante).size()!=0){ 
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_µs"]+=duration.count();
        nbrGetActionsDisponiblesParDate++;
        Transaction t;  
        nbrDeTransactionsEffectuesAjourdhui=0;
        do
            {   
                t=trader.choisirDecision(bourse,porteFeuille);
                nbrDeTransactionsEffectuesAjourdhui++;
                totalNumberOfTransactions++;
                double prixActionAdateCourante=bourse.getPrixParDateEtAction(dateCourante,t.getNomAction());
                nbrGetPrixParDateEtActione++;
                if (t.getType()==buy){   
                    if(prixActionAdateCourante==-1||prixActionAdateCourante * t.getQuantite() > porteFeuille.getSolde()){
                      totalNumberOfNonAcceptedTransactions++;
                }
                else{
                    porteFeuille.acheter(t.getNomAction(),t.getQuantite(),prixActionAdateCourante);
                    totalNumberOfBuyTransaction++;
                    }
                }
                else if (t.getType()==sell){   
                    if(prixActionAdateCourante==-1||porteFeuille.getTitresbyActionName(t.getNomAction()).getQtte() < t.getQuantite()){
                        totalNumberOfNonAcceptedTransactions++;
                }
                    else{
                        porteFeuille.vendre(t.getNomAction(),t.getQuantite(),prixActionAdateCourante);
                        totalNumberOfSellTransaction++;
                    }
                }

                else{/*if t==hold do nothing */
                totalNumberOfHoldTransaction++;
             }   
      
            }
                            
             while((t.getType()!=hold) && (nbrDeTransactionsEffectuesAjourdhui<100));
            }
            else{
                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
                stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_µs"]+=duration.count();
                nbrGetActionsDisponiblesParDate++;

            }
    }        
    double finalBalance=porteFeuille.getSolde();
        for ( auto t:porteFeuille.getTitres())
        {
            finalBalance+=bourse.dernierPrixDuneAction(dateFin,t->getNomAction())*t->getQtte();
        }
    stats["TotalTx"]=totalNumberOfTransactions;
    stats["TotalBuyTx"]=totalNumberOfBuyTransaction;
    stats["TotalSellTx"]=totalNumberOfSellTransaction;
    stats["TotalHoldTx"]=totalNumberOfHoldTransaction;
    stats["TotalFalseTX"]=totalNumberOfNonAcceptedTransactions;
    stats["Solde"]=finalBalance; 
    stats["nbrGetActionsDisponiblesParDate"]=nbrGetActionsDisponiblesParDate;
    stats["nbrGetPrixParDateEtActione"]=nbrGetPrixParDateEtActione;
    stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_TOTAL_µs"]=stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_µs"];
    stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_µs"]/=nbrGetActionsDisponiblesParDate;
    return stats;
}

int main(){
    srand(time(NULL));
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
    cout<<"nombre d'utilisations de getActionsDisponiblesParDate : "<<stats["nbrGetActionsDisponiblesParDate"]<<endl;
    cout<<"nombre d'utilisations de getPrixParDateEtActione : "<<stats["nbrGetPrixParDateEtActione"]<<endl;
    cout<<"Duree totale d'utilisation de getActionsDisponiblesParDate en micro secondes: "<<stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_µs"]<<" micro secondes"<<endl;
    cout<<"Duree Moyenne d'utilisation de getActionsDisponiblesParDate en micro secondes: "<<stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_TOTAL_µs"]<<" micro secondes"<<endl;

 

    
}