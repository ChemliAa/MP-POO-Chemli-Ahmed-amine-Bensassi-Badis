#include "Transaction.h"

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