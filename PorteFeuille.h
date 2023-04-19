#include "./customExceptions/IncorrectMontantRetirer.cpp"
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


    public:
        void ajoutMontant(double montant){
            solde+=montant;
        }
        void retirerMontant(double montant){
            if(montant <= solde){
                solde-=montant;
                return ;
            }
        throw  incorrectMontantRetirer();         
    }
};


