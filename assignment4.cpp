//Kenny Nguyen 
//Assignment4 - Covid Database 

#include <iostream>
#include <fstream> 
#include <sstream>
#include <string.h> 
#include "CovidDB.h"
using namespace std; 

void welcome(); 
void goodbye(); 
void pause();
void readfile(CovidDB &CovidDataBase); 

int main() {

    int tablesize = 17; 
    CovidDB CovidDataBase(tablesize);
    int choice = -1; 

    while (choice != 6) {
        //Displays the user interface
        welcome();
        cout << "Option: ";
        cin >> choice;

        switch (choice) {
            
            //Creates the initial hash table
            case 1: {
                readfile(CovidDataBase);
                cout << "Initial hash table created." << endl;

                pause();
                break; 
            }

            //Adds a new data entry 
            case 2: {
                string date, country;
                int cases, deaths;

                cout << "Enter the date: ";
                cin >> date;
                cout << "Enter the country: ";
                cin >> country;
                cout << "Enter the number of cases: ";
                cin >> cases;
                cout << "Enter the number of deaths: ";
                cin >> deaths;

                DataEntry *newEntry = new DataEntry(date, country, cases, deaths);

                if (CovidDataBase.add(newEntry)) {
                    cout << "Data entry added successfully." << endl;
                } else {
                    cout << "Data entry ignored. Date is earlier or the same as the existing entry's date." << endl;
                }

                pause();
                break;
            }

            //Gets and searches for a data entry
            case 3: {
                string countrysearch; 
                cout << "Enter the name of the country that you would like to search for: "; 
                cin.ignore();
                getline(cin, countrysearch);

                DataEntry *result = CovidDataBase.get(countrysearch);

                if (result == nullptr) {
                    cout << "Data entry not found for the specified country." << endl;
                } else {
                    cout << "Data entry found:" << endl;
                    cout << "Country: " << result->getCountry() << endl;
                    cout << "Date: " << result->getDate() << endl;
                    cout << "Cases: " << result->getCases() << endl;
                    cout << "Deaths: " << result->getDeaths() << endl;
                }

                pause();
                break;
            }
                
            //Removes a data entry 
            case 4: {
                string country;
    
                cout << "Enter the name of the country: ";
                cin.ignore();
                getline(cin, country);
                bool success = CovidDataBase.remove(country);
                
                if (success) {
                    cout << "Data entry removed successfully." << endl;
                } else {
                    cout << "Failed to remove data entry. Country not found." << endl;
                }

                pause();
                break;   
            }

            //Display 
            case 5: {
                CovidDataBase.displayTable();
                pause();
                break;
            }

            //Quit 
            case 6: {
                goodbye(); 
                return 0; 
            }

            default: {
                cout << "Invalid option. Please try again." << endl;
                pause();
                break;
            }

        }
    }
    return 0; 
}

void welcome() {

    cout << endl << endl << "Covid Tracker" << endl 
        << "Please choose an operation to execute:" << endl 
        << "1) Create the initial hash table" << endl 
        << "2) Add a new data entry" << endl 
        << "3) Get a data entry" << endl 
        << "4) Remove a data entry" << endl
        << "5) Display hash table" << endl 
        << "6) Quit the system" << endl << endl; 

}

void goodbye() {

    cout << "System exited" << endl << endl; 

}

void pause() {
    cout << "Press Enter to continue..."; 
    cin.ignore();
    cin.get();
}


void readfile(CovidDB &CovidDataBase) {

    const string FILE = "WHO-COVID-data.csv";
    //const string TESTFILE = "Test.csv";

    ifstream inFile;
    inFile.open(FILE);
    if (!inFile) {
        cout << "Error opening the file! Press enter to continue..." << endl; 
        cin.ignore(); 
    }
    
    

    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
        stringstream ss(line);
        string date, country, cases, deaths;

        //Read in the information 
        getline(ss, date, ',');
        cout << date << ' ';
        getline(ss, country, ',');
        cout << country << ' ';
        getline(ss, cases, ',');
        cout << cases << ' ';
        getline(ss, deaths, ',');
        cout << deaths << endl;

        //Convert strings into ints
        int c_cases = stoi(cases);
        int c_deaths = stoi(deaths); 

        DataEntry *newEntry = new DataEntry(date, country, c_cases, c_deaths);
        CovidDataBase.add(newEntry);
    }
    inFile.close();
}
    
