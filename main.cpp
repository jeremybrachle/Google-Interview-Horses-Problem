//25 Horses Google Interview Problem

//include the iostream library for input/output
#include <iostream>

//include string library for names of horses
#include <string>

//include vector library for holding string names
#include <vector>

//include the racing header
#include "Racing.h"

//use the standard namespace
using namespace std;

//main function
int main(int argc, const char * argv[]) {
    
    //make racing object
    Racing r;
    
    //get a vector of strings for the list of horses
    vector<string> allHorses = r.getHorseNames();
    
    //make five groups of five horses
    vector<string> group1;
    vector<string> group2;
    vector<string> group3;
    vector<string> group4;
    vector<string> group5;
    
    //loop through and put five horses into each group
    for (int i = 0; i < allHorses.size(); i++)
    {
        //first group
        if (i < 5 && i >= 0) { group1.push_back(allHorses[i]); }
        else if (i < 10 && i >= 5) { group2.push_back(allHorses[i]); } //second groupd
        else if (i < 15 && i >= 10) { group3.push_back(allHorses[i]); } //third group
        else if (i < 20 && i >= 15) { group4.push_back(allHorses[i]); } //fourth group
        else if (i < 25 && i >= 20) { group5.push_back(allHorses[i]); } //fifth group
    }
    
    //now race the horses
    //five races
    vector<string> group1RaceOrder = r.raceFive(group1);
    vector<string> group2RaceOrder = r.raceFive(group2);
    vector<string> group3RaceOrder = r.raceFive(group3);
    vector<string> group4RaceOrder = r.raceFive(group4);
    vector<string> group5RaceOrder = r.raceFive(group5);
    
    cout<<"\nFirst group order: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<group1RaceOrder[i]<<", ";
    }
    cout<<"\nSecond group order: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<group2RaceOrder[i]<<", ";
    }
    cout<<"\nThird group order: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<group3RaceOrder[i]<<", ";
    }
    cout<<"\nFourth group order: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<group4RaceOrder[i]<<", ";
    }
    cout<<"\nFifth group order: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<group5RaceOrder[i]<<", ";
    }
    
    cout<<endl<<endl;
    
    //make a group of the winners of the first five races
    vector<string> topFiveHorseGroups;
    //add the first horse of each group
    topFiveHorseGroups.push_back(group1RaceOrder[0]);
    topFiveHorseGroups.push_back(group2RaceOrder[0]);
    topFiveHorseGroups.push_back(group3RaceOrder[0]);
    topFiveHorseGroups.push_back(group4RaceOrder[0]);
    topFiveHorseGroups.push_back(group5RaceOrder[0]);
    
    //do a sixth race to find the winners of the winners
    topFiveHorseGroups = r.raceFive(topFiveHorseGroups);
    
    cout<<"Winners of winners: "<<endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout<<topFiveHorseGroups[i]<<", ";
    }
    cout<<endl<<endl;
    
    //create vectors of strings to hold the final three groups which will hold the winners
    vector<string> firstRow;
    vector<string> secondRow;
    vector<string> thirdRow;
    
    //the fastest horse in this group is the fastest overall horse, so save its name
    string fastestHorse = topFiveHorseGroups[0];
    
    //check the group that this horse came from and save it as the first row
    //check the first group's first horse and set the first row equal to this group
    if (group1RaceOrder[0].compare(fastestHorse) == 0) { firstRow = group1RaceOrder; }
    //second group
    else if (group2RaceOrder[0].compare(fastestHorse) == 0) { firstRow = group2RaceOrder; }
    //third row
    else if (group3RaceOrder[0].compare(fastestHorse) == 0) { firstRow = group3RaceOrder; }
    //fourth row
    else if (group4RaceOrder[0].compare(fastestHorse) == 0) { firstRow = group4RaceOrder; }
    //fifth  row
    else if (group5RaceOrder[0].compare(fastestHorse) == 0) { firstRow = group5RaceOrder; }
    
    cout<<"First row: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<firstRow[i]<<", ";
    }
    cout<<endl<<endl;
    
    //now save the second and third horses from the winners of the winners
    //NOTE: these are not the second and third place winners overall, just for the sixth race
    string secondPreliminaryHorse = topFiveHorseGroups[1];
    string thirdPreliminaryHorse = topFiveHorseGroups[2];
    
    //now get the second row:
    //check first group
    if (group1RaceOrder[0].compare(secondPreliminaryHorse) == 0) { secondRow = group1RaceOrder; }
    //check second group
    else if (group2RaceOrder[0].compare(secondPreliminaryHorse) == 0) { secondRow = group2RaceOrder; }
    //check third group
    else if (group3RaceOrder[0].compare(secondPreliminaryHorse) == 0) { secondRow = group3RaceOrder; }
    //check fourth group
    else if (group4RaceOrder[0].compare(secondPreliminaryHorse) == 0) { secondRow = group4RaceOrder; }
    //check fifth  group
    else if (group5RaceOrder[0].compare(secondPreliminaryHorse) == 0) { secondRow = group5RaceOrder; }
    
    //now get the third row:
    //check first group
    if (group1RaceOrder[0].compare(thirdPreliminaryHorse) == 0) { thirdRow = group1RaceOrder; }
    //check second group
    else if (group2RaceOrder[0].compare(thirdPreliminaryHorse) == 0) { thirdRow = group2RaceOrder; }
    //check third group
    else if (group3RaceOrder[0].compare(thirdPreliminaryHorse) == 0) { thirdRow = group3RaceOrder; }
    //check fourth group
    else if (group4RaceOrder[0].compare(thirdPreliminaryHorse) == 0) { thirdRow = group4RaceOrder; }
    //check fifth  group
    else if (group5RaceOrder[0].compare(thirdPreliminaryHorse) == 0) { thirdRow = group5RaceOrder; }
    
    cout<<"Second row: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<secondRow[i]<<", ";
    }
    cout<<endl<<endl;
    
    cout<<"Third row: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<thirdRow[i]<<", ";
    }
    cout<<endl<<endl;
    
    
    //now we can set up the final group of horses for the seventh and final race
    vector<string> finalRaceGroup;
    //add the horses:
    //add the second and third horses from the first row
    finalRaceGroup.push_back(firstRow[1]);
    finalRaceGroup.push_back(firstRow[2]);
    //add the first two from the second row:
    finalRaceGroup.push_back(secondRow[0]);
    finalRaceGroup.push_back(secondRow[1]);
    //add the first horse from the third row
    finalRaceGroup.push_back(thirdRow[0]);
    
    
    
    //now do the final race (the top two winners of this group will be the second and third place winners overall
    vector<string> topHorses = r.raceFive(finalRaceGroup);
    
    //output the top three horses:
    cout<<"The top three horses are:"<<endl;
    cout<<"1: "<<fastestHorse<<endl;
    cout<<"2: "<<topHorses[0]<<endl;
    cout<<"3: "<<topHorses[1]<<endl;
    
    /*
    //now get the rows of the top three horses
    for (int i = 1; i < 3; i++)
    {
        //check each first horse in each group of five horses to see if one of the top 3 horses is in it
        //check the first group of winners
        if (group1RaceOrder[0].compare(topFiveHorseGroups[i]) == 0)
        {
            //now check the value of i and create the right vector
            if (i == 0) { vector<string> firstRow = group1RaceOrder; }
            else if (i == 1) { vector<string> secondRow = group1RaceOrder; }
            else { vector<string> thirdRow = group1RaceOrder; }
        }
        //second group
        else if (group2RaceOrder[0].compare(topFiveHorseGroups[i]) == 0)
        {
            //now check the value of i and create the right vector
            if (i == 0) { vector<string> firstRow = group2RaceOrder; }
            else if (i == 1) { vector<string> secondRow = group2RaceOrder; }
            else { vector<string> thirdRow = group2RaceOrder; }
        }
        //third group
        else if (group3RaceOrder[0].compare(topFiveHorseGroups[i]) == 0)
        {
            //now check the value of i and create the right vector
            if (i == 0) { vector<string> firstRow = group3RaceOrder; }
            else if (i == 1) { vector<string> secondRow = group3RaceOrder; }
            else { vector<string> thirdRow = group3RaceOrder; }
        }
        //fourth group
        else if (group4RaceOrder[0].compare(topFiveHorseGroups[i]) == 0)
        {
            //now check the value of i and create the right vector
            if (i == 0) { vector<string> firstRow = group4RaceOrder; }
            else if (i == 1) { vector<string> secondRow = group4RaceOrder; }
            else { vector<string> thirdRow = group4RaceOrder; }
        }
        //fifth group
        else if (group5RaceOrder[0].compare(topFiveHorseGroups[i]) == 0)
        {
            //now check the value of i and create the right vector
            if (i == 0) { vector<string> firstRow = group5RaceOrder; }
            else if (i == 1) { vector<string> secondRow = group5RaceOrder; }
            else { vector<string> thirdRow = group5RaceOrder; }
        }
        
        //now get the horses for the final race
        //this will select the second and third place winners of the
        
    }
     */
    
    
    return 0;
}
