#include <iostream>
using namespace std;
class ActionNotFoundException : public std::exception { //standard way to declare a custom exception , you declare a  new new that extends a already built in class named exception, 
    public:
char * message () {
        return "L'action a retirer n'est pas dans votre liste de titres";
    }
};

 