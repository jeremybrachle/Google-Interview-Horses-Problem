//Horse Implementation File

//include the header file
#include "Horse.h"

//include string library
#include <string>

//use the standard namespace
using namespace std;

//begin class implementation

//default constructor
Horse::Horse()
{
    //give a default name
    setName("default");
    //give default speed
    setSpeed(0.0);
}

//overloaded constructor
Horse::Horse(const string &givenName, const double &givenSpeed)
{
    //set the name
    setName(givenName);
    //set the speed
    setSpeed(givenSpeed);
}

//destructor
Horse::~Horse()
{
    //delete horse object
}

//get the name
string Horse::getName()
{
    //return the name of the horse
    return name;
}

//get the speed of the horse
double Horse::getSpeed()
{
    //return the speed of the horse
    return speed;
}

//set the name of the horse
void Horse::setName(const string &givenName)
{
    //set the name to the given name
    name = givenName;
}

//set the speed of the horse
void Horse::setSpeed(const double &givenSpeed)
{
    //set the speed to be the given speed
    speed = givenSpeed;
}
