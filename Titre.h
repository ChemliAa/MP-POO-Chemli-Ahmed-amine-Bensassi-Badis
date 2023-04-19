#include<string>
using namespace std;
class  Titre
{
    private:
        string nomAction;
        int qtte;
    public:
        Titre(string nomAction,int qtte);
        string getNomAction();
        int getQtte(); 
        void setNomAction(string nouveaNom);
        void setQtte(int nouvelleQtte);
    
};
