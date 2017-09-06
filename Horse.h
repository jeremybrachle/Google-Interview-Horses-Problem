//horses.h file

//set up Horse Class
#ifndef HORSE
#define HORSE

//include string library for the horse name
#include <string>

//use the standard namespace
using namespace std;

//begin class
class Horse
{
    //public functions
public:
    //default constructor
    Horse();
    //overloaded constructor
    Horse(const string&, const double&);
    //destructor
    ~Horse();
    
    //getters
    std::string getName();
    double getSpeed();
    
    //setters
    void setName(const string&);
    void setSpeed(const double&);
    
    //private data
private:
    //variable for the name of the horse
    string name;
    //variable for the speed of the horse (will never be seen by the user)
    double speed;
    
};

//end class definition
#endif
