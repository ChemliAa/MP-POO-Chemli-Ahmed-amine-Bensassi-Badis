#if !defined(PORTEFEUILLE_H)
#define PORTEFEUILLE_H
#include "./customExceptions/IncorrectMontantRetirer.cpp"
#include "./customExceptions/ActionNotFound.cpp"
#include <iostream>
#include <vector>
#include "Titre.h"
 

class  PorteFeuille
{
    private:
        double solde;
        vector<Titre*> titres; //for now i chose to put pointer to respect la relation d'aggregation , PorteFeuille can have no titre,
                                // but i have doubts about choosing a vector,i made this choice because its an easy implementation of a 
                                //dynamic structure, we might change this  choice when we dive into collections
        int findTitreIndex(string nomAction);

    public:

        PorteFeuille(double solde);
        double getSolde();
        vector<Titre*> getTitres();
        void ajoutMontant(double montant);
        void retirerMontant(double montant);
        void ajoutTitre(Titre *titre);
        void suprimerTitre(string action);
};
#endif

