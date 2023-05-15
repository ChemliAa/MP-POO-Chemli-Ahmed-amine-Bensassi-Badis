#include "Simulation.h"
#include <cmath>
#include "TraderAleatoire.h"
#include "TraderIntelligent.h"
#include "TraderAvare.h"
#include "traderMoyenne.h"
#include "BourseSet.h"
#include "./customExceptions/TransactionUnknown.cpp"
#include<map>
#include<chrono>
#include<iostream>
#include"BourseMultiMap.h"
#include "BourseVector.h"    
#include "BourseMapToVector.h"
#include "Simulation.h"
using namespace std;
bool isNumeral(const string& str){
    if(str.empty()){
        return false; 
    }
    bool hasDigit=false;

    bool hasDecimal=false;
    for(char c:str){
        if(isdigit(c)){
            hasDigit=true;
        }
        else if(c=='.'&& !hasDecimal){
            hasDecimal=true;
        }
        else {
            return false;
        }
    }
    return hasDigit; 
}
int main()
{   string m;
    double montant=-1;
    do{
	cout << "Entrez le solde initial du trader(positif): ";
    
    cin>>m;
	 
	}while(!isNumeral(m) && !(atof(m.c_str())>0 ));
    montant=atof(m.c_str());
    
    Date dateDebutSimulation("3/1/2010");
    Date dateFinSimulation("31/12/2016");
    Date dateLimDebut("4/1/2010");
    Date dateLimFin("30/12/2016");
    string d;
            do{
                cout << "Entrez date debut simulation (dd/mm/yyyy) entre 4/1/2010 et 30/12/2016 : ";
                cin >> d;
                try
                {
                    dateDebutSimulation=Date(d);
                    if(((dateLimDebut< dateDebutSimulation||dateLimDebut==dateDebutSimulation)&&(dateDebutSimulation<dateLimFin ||dateDebutSimulation==dateLimFin)))
                        break;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                
            }while (!((dateLimDebut< dateDebutSimulation||dateLimDebut==dateDebutSimulation)&&(dateDebutSimulation<dateLimFin ||dateDebutSimulation==dateLimFin)));
            
            
            do{
                cout << "Entrez date fin simulation (dd/mm/yyyy) entre "<<dateDebutSimulation<<" et 30/12/2016 : ";
                cin >> d;
                try
                {
                    dateFinSimulation=Date(d);
                    if(((dateDebutSimulation<dateFinSimulation ||dateDebutSimulation==dateFinSimulation)&&(dateFinSimulation<dateLimFin ||dateFinSimulation==dateLimFin)))
                        break;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                
            }while(!((dateDebutSimulation<dateFinSimulation ||dateDebutSimulation==dateFinSimulation)&&(dateFinSimulation<dateLimFin ||dateFinSimulation==dateLimFin)));
    // display menu for bourse type selection
    cout << "Selectionnez type bourse:" << endl;
    cout << "1. Bourse Vecteur" << endl;
    cout << "2. Bourse Set" << endl;
    cout << "3. Bourse MultiMap" << endl;
    cout << "4. Bourse MapToVector" << endl;
    cout << "Entrez choix: ";
    int bourseChoice;
    Bourse* bourse=nullptr;
    cin >> bourseChoice;
    switch (bourseChoice) {
        case 1:
            bourse=new BourseVector(dateDebutSimulation,CHEMIN);
            cout<<"BourseVector created successfully"<<endl;
            break;
        case 2:
            bourse=new BourseSet(dateDebutSimulation,CHEMIN);
            cout<<"BourseVector created successfully"<<endl;
            break;
        case 3:
            bourse=new BourseMultiMap(dateDebutSimulation,CHEMIN);
            cout<<"BourseMultiMap created successfully"<<endl;
            break;
        case 4:
            bourse=new BourseMapToVector(dateDebutSimulation,CHEMIN);
            cout<<"BourseMapToVector created successfully"<<endl;
            break;
        default:
            cout << "Invalid choice. Exiting." << endl;
            return 0;
    }
    // display menu for trader type selection
    cout << "Selectionnez type trader:" << endl;
    cout << "1. Trader Aleatoire" << endl;
    cout << "2. Trader Avare" << endl;
    cout << "3. Trader Moyenne" << endl;
    cout << "4. Trader Intelligent" << endl;
    cout << "Entrez choix: ";
    int traderChoice;
    Trader* trader=nullptr;
    cin >> traderChoice;
    switch (traderChoice) {
        case 1:
            trader=new TraderAleatoire;
            cout<<"TraderAleatoire cree avec succes"<<endl;
            break;
        case 2:
            trader=new TraderAvare;
            cout<<"TraderAvare cree avec succes"<<endl;
            break;
        case 3:
            trader=new TraderMoyenne;
            cout<<"TraderMoyenne cree avec succes"<<endl;
            break;
        case 4:
            trader=new TraderIntelligent;
            cout<<"TraderIntelligent cree avec succes"<<endl;
            break;
        default:
            cout << "Invalid choice. Exiting." << endl;
            return 0;
    }
    map<string,long> stats=Simulation::executer(*bourse,*trader,dateDebutSimulation,dateFinSimulation,montant);
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
    delete bourse;
    delete trader;
}
