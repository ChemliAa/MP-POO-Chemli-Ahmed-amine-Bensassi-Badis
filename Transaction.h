#if !defined(TRANSACTION_H)
#define TRANSACTION_H
#include <string>
using namespace std;
enum typeTransaction {buy,sell,hold};
class Transaction{
    private:
    typeTransaction type;
    string nomAction;
    double quantite; 
    public:
    typeTransaction getType()const;
    string getNomAction()const;
    double getQuantite()const;
    void setType(typeTransaction t);
    void setNomAction(string nom);
    void setQuantite(double q);
};

#endif // TRANSACTION_H