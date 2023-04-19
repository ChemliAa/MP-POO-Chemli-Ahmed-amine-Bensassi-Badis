#include "./customExceptions/IncorrectMontantRetirer.cpp"
#include <iostream>
class  PorteFeuille
{
    private:
        double solde;
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


