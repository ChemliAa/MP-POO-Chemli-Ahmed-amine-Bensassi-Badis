#include <iostream>
#include <string>
using namespace std;
class ActionNotFound: public std::exception { //standard way to declare a custom exception , you declare a  new new that extends a already built in class named exception, 
    public:
string message () {
        return "L'action a retirer n'est pas dans votre liste de titres";
    }
};

 