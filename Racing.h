//Racing header file

//set up Racing Class
#ifndef RACING
#define RACING

//include the string library for the horse name
#include <string>

//include the vector library for storing horses
#include <vector>

//include the Horse Library
#include "Horse.h"

//use the standard namespace
using namespace std;

//begin class
class Racing
{
    //public functions
public:
    //default constructor
    Racing();
    //destructor
    ~Racing();
    
    //return a vector of strings of the horse names (separated by space)
    vector<string> getHorseNames();
    
    //race 5 horses and return a string with the order they're in (separated by space)
    vector<string> raceFive(const vector<string>&);
    
    //private data
private:
    //vector of horses
    vector<Horse> horses;
    //number of horses
    int numHorses = 25;
    //generate 25 horses
    void generateHorses();
    //check the name of a horse given its speed
    string getNameOfHorse(const double&);
    //check the speed of a horse given a string
    double getSpeedOfHorse(const string&);
    //sort the horse speeds given a vector of speeds
    vector<double> sortFiveSpeeds(const vector<double>&);
    
    
};

#endif
