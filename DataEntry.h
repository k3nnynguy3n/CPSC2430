//This file includes the definition of the DataEntry class 

#include <string> 
#include <iostream> 
#ifndef DATAENTRY_H
#define DATAENTRY_H
using namespace std; 

//Class for each of the entries, representing a country 
class DataEntry {
    private: 
        string date;
        string country; 
        int c_cases; 
        int c_deaths;

    public: 
        //Constructor, setters, getters, etc. 
        DataEntry();
        DataEntry(string date, string country, int c_cases, int c_deaths); 
        
        //Methods
        string getDate();
        string getCountry();
        int getCases();
        int getDeaths();
        void setDate(string date);
        void setCountry(string country);
        void setCases(int c_cases);
        void setDeaths(int d_deaths); 
};

#endif