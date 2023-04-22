#include <iostream>
using namespace std;
class incorrectMontantRetirer : public std::exception { //standard way to declare a custom exception , you declare a  new new that extends a already built in class named exception, 
    public:
char * message () {
        return "Le montant a retirer depasse votre solde actuelle";
    }
};

 