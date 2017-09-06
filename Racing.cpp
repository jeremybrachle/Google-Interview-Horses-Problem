//Racing implementation file

//include Racing header file
#include "Racing.h"

//include horse header file
#include "Horse.h"

//include the string library for horse names
#include <string>

//include vector library for storing horse lists
#include <vector>

//include time and c-standard library for random number generation
#include<ctime>
#include<cstdlib>

#include <iostream>

//use the standard namespace
using namespace std;

//begin class implementation

//default constructor
Racing::Racing()
{
    //call the generate horses function
    generateHorses();
}

//destructor
Racing::~Racing()
{
    //delete racing objects
}

//generate horse function
void Racing::generateHorses()
{
    //make a char value for the letters
    char letter = 0;
    //make a string value for the horse name
    string horseName = "";
    //make a double for the speed
    double randomSpeed = 0.0;
    
    //seed the time
    srand( unsigned(time(NULL)));
    
    //loop through and generate horse names
    for (int i = 1; i <= numHorses; i++)
    {
        //set the character to the ascii code
        letter = (i + 64); //(1 + 64 = 65, which is the letter A)
        
        //make the horse name
        horseName = "Horse ";
        horseName += letter;
        
        //generate a random speed between 100 and 200 seconds
        randomSpeed = (double)rand()/(RAND_MAX)+100+(rand()%100);
        
        //make a new horse object
        Horse h(horseName, randomSpeed);
        //push to the back of the vector
        horses.push_back(h);
    }
    
    //output the horse name and speed:
    for (int i = 0; i < numHorses; i++)
    {
        if (i % 5 == 0) {cout<<endl;}
        cout<<"name: "<<horses[i].getName()<<", speed: "<<horses[i].getSpeed()<<endl;
    }
    
}

//get horse names
vector<string> Racing::getHorseNames()
{
    //make a string for the horse names
    vector<string> names;
    
    //loop through all 25
    for (int i = 0; i < horses.size(); i++)
    {
        //put the name into the vector
        names.push_back((horses[i].getName()));
    }
    
    //now return the vector
    return names;
}

//race 5 horses
vector<string> Racing::raceFive(const vector<string> &fiveHorses)
{
    //make a new vector of strings
    vector<string> sortedHorses;
    
    //make a vector of the unsorted speeds
    vector<double> unsortedSpeeds;
    
    //get the speeds
    for (int i = 0; i < fiveHorses.size(); i++)
    {
        //get each speed from the name of the horse
        double eachSpeed = getSpeedOfHorse(fiveHorses[i]);
        //put it into the unsorted speeds
        unsortedSpeeds.push_back(eachSpeed);
    }
    
    //sort the vector of speeds
    vector<double> sortedSpeeds = sortFiveSpeeds(unsortedSpeeds);
    
    //now assign the sorted horses
    for (int i = 0; i < fiveHorses.size(); i++)
    {
        //get the order of the horses based on the speeds
        sortedHorses.push_back(getNameOfHorse(sortedSpeeds[i]));
    }
    
    //return the list of horses
    return sortedHorses;
}

//function for sorting the speeds
vector<double> Racing::sortFiveSpeeds(const vector<double> &givenSpeeds)
{
    
    //make a new vector for the sorted speeds
    vector<double> sortedSpeeds;
    
    //make an array for holding the sorted speeds
    double newArr[5] = {0.0,0.0,0.0,0.0,0.0};
    
    //put the unsorted speeds into the array
    for (int i = 0; i < givenSpeeds.size(); i++)
    {
        newArr[i] = givenSpeeds[i];
    }
    
    
    //use insertion sort
    for (int i = 1; i < givenSpeeds.size(); i++)
    {
        //make a key value
        double key = newArr[i];
        
        //set the previous element position
        int j = i-1;
        
        //loop while the current posiiton is greater than the key
        while (j >= 0 && newArr[j] > key)
        {
            //when it is not greater, insert it into the new position
            newArr[j+1] = newArr[j];
            //update the position
            j = j-1;
        }
        
        //put the key into the proper position
        newArr[j+1] = key;
    }
    
    //put the sorted speeds into the vector
    for (int i = 0; i < givenSpeeds.size(); i++)
    {
        sortedSpeeds.push_back(newArr[i]);
    }
    
    //now return the sorted speeds vector
    return sortedSpeeds;
}


//function for checking the name of a horse from the speed
string Racing::getNameOfHorse(const double &givenSpeed)
{
    //loop through and look for the horse with this speed
    for (int i = 0; i < numHorses; i++)
    {
        //check to see if the speed given equals the current horse in the list
        if (horses[i].getSpeed() == givenSpeed)
        {
            //return the speed
            return horses[i].getName();
        }
    }
    
    //if control reaches here, just return an empty string
    return "";
}

//function for checking the speed of a horse from the original list of horses
double Racing::getSpeedOfHorse(const string &givenHorseName)
{
    //loop through and look for the horse with this name
    for (int i = 0; i < numHorses; i++)
    {
        //check to see if the name given equals the current horse in the list
        if (horses[i].getName().compare(givenHorseName) == 0)
        {
            //return the speed
            return horses[i].getSpeed();
        }
    }
    
    //if control reaches here, just return 0.0
    return 0.0;
}
