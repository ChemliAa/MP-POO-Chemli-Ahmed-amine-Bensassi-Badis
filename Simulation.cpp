#include "Simulation.h"
#include <cmath>
#include "TraderAleatoire.h"
#include "BourseSet.h"
#include "./customExceptions/TransactionUnknown.cpp"
#include<map>
#include<chrono>
#include<iostream>
#include"BourseMap.h"
#include "BourseVector.h"    
#include "BourseMap.h"
#include "BourseMapToVector.h"

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
    int nbrGetPrixParDateEtAction=0;



    for (Date dateCourante(dateDebut);dateCourante<dateLimite;dateCourante++){
        cout<<dateCourante<<endl;
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
                auto start = chrono::high_resolution_clock::now();
                t=trader.choisirDecision(bourse,porteFeuille);
                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
                stats["TEMPS_TX_µs"]+=duration.count();
                nbrDeTransactionsEffectuesAjourdhui++;
                totalNumberOfTransactions++;
                if (t.getType()==buy){   
                    auto start = chrono::high_resolution_clock::now();
                    double prixActionAdateCourante=bourse.getPrixParDateEtAction(dateCourante,t.getNomAction());
                    auto stop = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
                    stats["TEMPS_GET_PRIX_PAR_DATE_ET_ACTION_µs"]+=duration.count();
                    nbrGetPrixParDateEtAction++;
                    if(prixActionAdateCourante==-1||prixActionAdateCourante * t.getQuantite() > porteFeuille.getSolde())
                    {
                      totalNumberOfNonAcceptedTransactions++;
                    }
                else
                    {
                    porteFeuille.acheter(t.getNomAction(),t.getQuantite(),prixActionAdateCourante);
                    totalNumberOfBuyTransaction++;
                    }
                }
                else if (t.getType()==sell){   
                    auto start = chrono::high_resolution_clock::now();
                    double prixActionAdateCourante=bourse.getPrixParDateEtAction(dateCourante,t.getNomAction());
                    auto stop = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
                    stats["TEMPS_GET_PRIX_PAR_DATE_ET_ACTION_µs"]+=duration.count();
                    nbrGetPrixParDateEtAction++;
                    if(prixActionAdateCourante==-1||porteFeuille.getTitresbyActionName(t.getNomAction()).getQtte() < t.getQuantite())
                    {
                        totalNumberOfNonAcceptedTransactions++;
                    }
                    else
                    {
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
    stats["Gains"]=finalBalance-solde;
    stats["PourcentageGains"]=((finalBalance-solde)/solde)*100; 
    stats["nbrGetActionsDisponiblesParDate"]=nbrGetActionsDisponiblesParDate;
    stats["nbrGetPrixParDateEtAction"]=nbrGetPrixParDateEtAction;
    stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_TOTAL_µs"]=stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_µs"];
    stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_µs"]/=nbrGetActionsDisponiblesParDate;
    stats["TEMPS_GET_PRIX_PAR_DATE_ET_ACTION_TOTAL_µs"]=stats["TEMPS_GET_PRIX_PAR_DATE_ET_ACTION_µs"];
    stats["TEMPS_GET_PRIX_PAR_DATE_ET_ACTION_µs"]/=nbrGetPrixParDateEtAction;
    stats["TEMPS_TOTAL_TX_µs"]=stats["TEMPS_TX_µs"];
    stats["TEMPS_TX_µs"]/=totalNumberOfTransactions;
    return stats;
}

int main(){
    srand(1);
    TraderAleatoire t;
    Date datecourant("4/1/2010");
    Date fin("5/1/2011");
    PorteFeuille p(10);
    //BourseVector b(datecourant,CHEMIN);
    BourseMapToVector b(datecourant,CHEMIN);
    map<string,long> stats ;
    stats=Simulation::executer(b,t,datecourant,fin,1000);
    cout<<"Simulation terminee voici les statistiques: "<<endl;
    cout<<"Nombre total des transactions: "<<stats["TotalTx"]<<endl;
    cout<<"Nombre total des transactions de type achat : "<<stats["TotalBuyTx"]<<endl;
    cout<<"Nombre total des transactions de type vente : "<<stats["TotalSellTx"]<<endl;
    cout<<"Nombre total des transactions de type rien faire : "<<stats["TotalHoldTx"]<<endl;
    cout<<"Nombre total des transactions non accepte : "<<stats["TotalFalseTX"]<<endl;
    cout<<"Solde final : "<<stats["Solde"]<<endl;
    cout<<"Gains : "<<stats["Gains"]<<endl;
    cout<<"Pourcentage Gains : "<<stats["PourcentageGains"]<<"%"<<endl;
    cout<<"Nombre d'utilisations de getActionsDisponiblesParDate : "<<stats["nbrGetActionsDisponiblesParDate"]<<endl;
    cout<<"Nombre d'utilisations de getPrixParDateEtAction : "<<stats["nbrGetPrixParDateEtAction"]<<endl;
    cout<<"Duree totale d'utilisation de getActionsDisponiblesParDate en micro secondes: "<<stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_TOTAL_µs"]<<" micro secondes"<<endl;
    cout<<"Duree moyenne d'utilisation de getActionsDisponiblesParDate en micro secondes: "<<stats["TEMPS_GET_ACTIONS_DISPO_PAR_DATE_µs"]<<" micro secondes"<<endl;
    cout<<"Duree totale d'utilisation de getPrixParDateEtAction en micro secondes: "<<stats["TEMPS_GET_PRIX_PAR_DATE_ET_ACTION_TOTAL_µs"]<<" micro secondes"<<endl;
    cout<<"Duree moyenne d'utilisation de getPrixParDateEtAction en micro secondes: "<<stats["TEMPS_GET_PRIX_PAR_DATE_ET_ACTION_µs"]<<" micro secondes"<<endl;
    cout<<"Duree totale de transactions: "<<stats["TEMPS_TOTAL_TX_µs"]<<" micro secondes"<<endl;
    cout<<"Duree moyenne de transactions:"<<stats["TEMPS_TX_µs"]<<" micro secondes"<<endl;


    
}