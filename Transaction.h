#if !defined(TRANSACTION_H)
#define TRANSACTION_H
#include <string>
using namespace std;
enum typeTransaction {buy,sell,hold};
class Transaction{
    private:
    typeTransaction type;
    string nomAction;
    int quantite; 
    public:
    friend ostream& operator<< (ostream& flux,const Transaction& t );     
    typeTransaction getType()const;
    string getNomAction()const;
    int getQuantite()const;
    void setType(typeTransaction t);
    void setNomAction(string nom);
    void setQuantite(int q);
};

#endif // TRANSACTION_H