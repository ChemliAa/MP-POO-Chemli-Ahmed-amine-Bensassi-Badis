#include "Transaction.h"
#include <iostream>
typeTransaction Transaction::getType()const
{
    return type;
}
string Transaction::getNomAction()const
{
    return nomAction;
}
double Transaction::getQuantite()const
{
    return quantite;
}
void Transaction::setType(typeTransaction t)
{
    type=t;
}
void Transaction::setNomAction(string nom)
{
    nomAction=nom;
}
void Transaction::setQuantite(double q)
{
    quantite=q;
}
 ostream& operator<< (ostream& flux,const Transaction& t )
{
	flux<<"Choix de transaction: "<<t.type<<"    Nom action :"<<t.nomAction<<"   quantite: "<<t.quantite<<endl;
    return flux;
}