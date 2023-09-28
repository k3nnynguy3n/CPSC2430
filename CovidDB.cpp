//This file includes the body of the methods apart of the CovidDB class

#include <string>
#include <vector> 
#include <sstream>
#include "CovidDB.h"
using namespace std; 

//Constructor
CovidDB::CovidDB(int size) {
    
    tableSize = size; 
    entryCount = 0; 
    hashTable.resize(tableSize);
}

//Deconstructor 
CovidDB::~CovidDB() {
    
    for (int i = 0; i < (int)hashTable.size(); i++) {
        for (int k = 0; k < (int)hashTable[i].size(); k++) {
            delete hashTable[i][k]; //Deletes the elements in the table by column 
        }
        hashTable[i].clear(); //Clears the column
    }
    hashTable.clear(); //Clears the row after columns are cleared 
}


bool isValidDate(string date) {
    
    //Check if the string has the correct length
    if (date.length() != 10) {
        return false;
    }

    //Check if each digit is a valid integer 
    if (!isdigit(date[0]) || !isdigit(date[1]) || date[2] != '/' ||
        !isdigit(date[3]) || !isdigit(date[4]) || date[5] != '/' ||
        !isdigit(date[6]) || !isdigit(date[7]) || !isdigit(date[8]) || !isdigit(date[9]))
        return false;

    return true; 
}

//Grabs the characters in the string into ASCII 
int CovidDB::hash(string country) {

    int sum = 0; 
    for (int i = 0; i < (int)country.length(); i++) {
        sum += ((i+1) * (country[i]));
    }

    return sum % 17; 
}

//Return data for country, if there is no country then return nullptr 
DataEntry* CovidDB::get(string &country) {

    int index = hash(country);
    for (int i = 0; i < (int)hashTable[index].size(); i++) {
        if (hashTable[index][i]->getCountry() == country) {
            return hashTable[index][i];
        }
    }
    return nullptr;  
}



//Adds a DataEntry into the hash table, and if it already exists then update it
bool CovidDB::add(DataEntry *entry) {

    int index = hash(entry->getCountry()); 
    int totalcases = 0, totaldeaths = 0;

    for (int i = 0; i < (int)hashTable[index].size(); i++) {
        if (hashTable[index][i]->getCountry() == entry->getCountry()) {
            //Checks the dates 
            
            string date1 = entry->getDate();
            string date2 = hashTable[index][i]->getDate();
            bool compare = comparedates(date1, date2);

            if (compare) {
                //Updates the information the newer date 
                hashTable[index][i]->setDate(entry->getDate());

                //Adds the cases and deaths to have a cumalative number 
                totalcases += hashTable[index][i]->getCases();
                totaldeaths += hashTable[index][i]->getDeaths();
                int cases = entry->getCases();
                int deaths = entry->getDeaths();
                cases += totalcases;
                deaths += totaldeaths;
                entry->setCases(cases);
                entry->setDeaths(deaths);

                //Sets the cumative total to the cases and deaths 
                hashTable[index][i]->setCases(cases);
                hashTable[index][i]->setDeaths(deaths);
                return true;
            } 
            return false;
        }
    }

    //Add a new entry if country doesnt exist 
    DataEntry* newEntry = new DataEntry(entry->getDate(), entry->getCountry(), entry->getCases(), entry->getDeaths());
    hashTable[index].push_back(newEntry);
    return true;
}

//Remove data for country 
bool CovidDB::remove(string country) {

    int index = hash(country);
    vector<DataEntry*>& entries = hashTable[index];

    for (int i = 0; i < (int)entries.size(); i++) {
        if (entries[i]->getCountry() == country) {
            delete entries[i];
            entries.erase(entries.begin() + i);
            return true; 
        }
    }
    return false; 
}

//Displays the data stored in the hash table 
void CovidDB::displayTable() {

    //Check if hashTable is empty 
    if (hashTable.empty()) {
        cout << "There is no data to display" << endl; 
        return; 
    }

    //Display 
    cout << "All entries in the HashTable: (Country, Date, Covid Cases, Covid Deaths)" << endl;
    for (int i = 0; i < (int)hashTable.size(); i++) {
        for (int k = 0; k < (int)hashTable[i].size(); k++) {
            cout << hashTable[i][k]->getCountry() << " " 
                << hashTable[i][k]->getDate() << " "
                << hashTable[i][k]->getCases() << " "
                << hashTable[i][k]->getDeaths() << " " << endl; 
        }
        cout << endl; 
    } 
}

//Rehash the table size 
void CovidDB::rehashTable() {

    //Gets new size by multiplying by 2 then getting the next prime number 
    int doubleSize = hashTable.size() * 2; 
    int newSize = getNextPrime(doubleSize); 
    vector<vector<DataEntry*>> newHashTable(newSize); 

    //Rehash all entries from old hashtable into the new one 
    for (int i = 0; i < (int)hashTable.size(); i++) {
        for (int k = 0; k < (int)hashTable[i].size(); k++) {
            DataEntry* entry = hashTable[i][k]; 

            //Gets new index based on new size
            int newIndex = hash(entry->getCountry()) % newSize;

            //Adds the entry to new hash table
            newHashTable[newIndex].push_back(entry); 
        }
    }
    

    //deletes and clears old hash table 
    for (int i = 0; i < (int)hashTable.size(); i++) {
        hashTable[i].clear(); 
    }
    
    hashTable.clear(); 

    tableSize = newSize; 
    hashTable = newHashTable;
}

//Checks if the number is a prime number 
bool CovidDB::isPrime(int num) {

    if (num <= 1) {
        return false; 
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; 
        }
    }
    return true; 
}

//Gets the next prime number 
int CovidDB::getNextPrime(int num) {

    while (!isPrime(num)) {
        num++;
    }
    return num; 
}

//Compares the dates to determine which date is most recent
bool CovidDB::comparedates(string countrydate1, string countrydate2) {
    
    int currentMonth, currentDay, currentYear;
    int comparedMonth, comparedDay, comparedYear;
    
    stringstream ssNew(countrydate1);
    string token;

    getline(ssNew, token, '/');
    currentMonth = stoi(token);

    getline(ssNew, token, '/');
    currentDay = stoi(token);

    getline(ssNew, token);
    currentYear = stoi(token);

    //Extracts day, month, and year from the compared date
    stringstream ssOld(countrydate2);

    getline(ssOld, token, '/');
    comparedMonth = stoi(token);

    getline(ssOld, token, '/');
    comparedDay = stoi(token);

    getline(ssOld, token);
    comparedYear = stoi(token);

    //Check year
    if (currentYear > comparedYear) {
        return true;
    }
    //If year is the same, check month
    else if (currentYear == comparedYear) {
        if (currentMonth > comparedMonth) {
            return true;
        }
        //If month is the same, check day
        else if (currentMonth == comparedMonth) {
            if (currentDay > comparedDay) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}
