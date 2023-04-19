#include<string>
using namespace std;
class  Titre
{
    private:
        string nomAction;
        int qtte;
    public:
        string getNomAction();
        int getQtte(); 
        void setNomAction(string nouveaNom);
        void setQtte(int nouvelleQtte);
    
};
