//This file includes the definition of the CovidDB class 

#include <string> 
#include <vector> 
#include <iostream> 
#include "DataEntry.h"
#ifndef COVIDDB_H
#define COVIDDB_H
using namespace std; 

//The covid database that holds the information 
class CovidDB {
    private: 
        vector<vector<DataEntry*>> hashTable; 
        int hash(string country); 
        int tableSize;
        int entryCount; 

    public: 
        //Constructor, setters, getters, etc. 
        CovidDB(int size); 
        ~CovidDB();

        //Methods 
        DataEntry* get(string &country); 
        bool add(DataEntry *entry); 
        bool remove(string country); 
        bool isPrime(int num); 
        bool comparedates(string countrydate1, string countrydate2);
        void displayTable(); 
        void rehashTable(); 
        int getNextPrime(int num);

};

#endif