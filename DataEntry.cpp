//This file includes the body of the methods apart of the DataEntry class

#include <string>
#include "CovidDB.h"
using namespace std; 

//Constructor
DataEntry::DataEntry() {
    
    this->date = "";
    this->country = "";
    this->c_cases = 0;
    this->c_deaths = 0;
}

//Constructor with parameter initialization
DataEntry::DataEntry(string date, string country, int c_cases, int c_deaths) {

    this->date = date; 
    this->country = country; 
    this->c_cases = c_cases;
    this->c_deaths = c_deaths; 
}
        
//Get the value of date from the object 
string DataEntry::getDate() {
    return date; 
}

//Gets the value of country from the object 
string DataEntry::getCountry() {
    return country;
}

//Gets the value of cases from the object 
int DataEntry::getCases() {
    return c_cases;
}

//Gets the value of deaths from the object 
int DataEntry::getDeaths() {
    return c_deaths;
}

//Set the value of the 'date' member variable in the current object
void DataEntry::setDate(string date) {
    this->date = date; 
}

//Set the value of the 'country' member variable in the current object
void DataEntry::setCountry(string country) {
    this->country = country; 
}

//Set the value of the 'c_cases' member variable in the current object
void DataEntry::setCases(int c_cases) {
    this->c_cases = c_cases;
}

//Set the value of the 'd_deaths' member variable in the current object
void DataEntry::setDeaths(int d_deaths) {
    this->c_deaths = d_deaths;
}
