#ifndef SIMULATION_H
#define SIMULATION_H
#include "Trader.h"
#include "Bourse.h"
#include "Transaction.h"
#include "Date.h"
#include "PorteFeuille.h"
#include<map>
class Simulation
{
public:
    static map<string,long> executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde);

};


#endif