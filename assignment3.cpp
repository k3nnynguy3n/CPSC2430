//Kenny Nguyen
//assignment3.cpp

#include <iostream> 
#include "ShelterBST.h"
using namespace std; 

void welcome(); 
void test(); 

int main() {

    //Definition of the binary tree and other variable declarations 
    ShelterBST tree;
    int choice; 

    //Tests 
    tree.insertPet("Zelda", 5);
    tree.insertPet("Link", 7);
    tree.insertPet("Kenny", 9);
    tree.insertPet("Bryan", 2);
    tree.insertPet("Ryan", 1); 
    tree.insertPet("Lauren", 3);
    tree.insertPet("Nathan", 10);
    tree.insertPet("Remy", 14);
    tree.insertPet("Max", 18);
    tree.insertPet("Tony", 4);
     
    while (choice != 13) {
        //Welcomes the user, takes user option
        welcome();
        cout << endl << "Option: ";
        cin >> choice; 
        
        //Checks the input for valid choice 
        while (choice < 1 || choice > 13) {
            welcome();
            cout << endl << "Option: ";
            cin >> choice; 
        }

        switch (choice) {
            
            //Insert
            case 1: {
                string insertName;
                int insertAge; 

                cout << "Name of the pet: ";
                cin >> insertName; 
                cout << "Age: "; 
                cin >> insertAge; 
                cout << endl; 
                tree.insertPet(insertName, insertAge);
                
                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break; 
            }

            //Search
            case 2: {
                string searchName; 

                cout << "Name of Pet to search: ";
                cin >> searchName; 
                cout << endl; 
                tree.searchPet(searchName); 

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break;
            }

            //Print
            case 3: {
                cout << "Here is the printed animals in the shelter by order:" << endl << endl; 
                tree.preorderDisplay();
                tree.inorderDisplay();
                tree.postorderDisplay();

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break;
            }
            

            //Find the parent of a pet
            case 4: {
                string childname; 

                cout << "Enter a name of an animal to find the parent: ";
                cin >> childname; 
                tree.parent(childname);

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break; 
            }
            

            //Find the predecessor 
            case 5: {
                string prename; 

                cout << "Enter a name to find the predecessor for: ";
                cin >> prename; 
                tree.predecessor(prename);
                cout << endl; 

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break; 
                

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break; 
            }
            

            //Total number of internal nodes
            case 6: {
                tree.internal(); 

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break; 
            }

            //Total number of nodes
            case 7: {
                tree.countTreeNodes();

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break; 
            }

            //The height of the tree
            case 8: {
                tree.treeHeight();

                //Pause for the user to look at the result before continuing 
                cout << endl << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break; 
            }

            //Tree balance check 
            case 9: {
                tree.balance(); 

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break; 
            }

            //Delete 
            case 10: {
                tree.deleten();

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break;     
            }
            

            //Destroy
            case 11: {
                tree.destroyTree();

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break; 
            }

            //Test 
            case 12: {
                test(); 

                //Pause for the user to look at the result before continuing 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();
                break; 
            }
            
            //Quit 
            case 13: {
                cout << "Thank you for visiting!" << endl << endl;
                return 0;
            }
        }
    }
    return 0;
}

void welcome() {

    cout << endl << endl <<
    "Welcome to my implementation of ShelterBST!" << endl <<  
    "Please choose one of the operations below to execute:" << endl << 
    "(Enter the number associated with task)" << endl << endl <<
    "1. Insert a node" << endl <<
    "2. Search for a specific node by name" << endl << 
    "3. Print the InOrder, PreOrder, and PostOrder" << endl << 
    "4. Find the parent of the given pet name" << endl << 
    "5. Find the predecessor" << endl << 
    "6. Total number of internal nodes" << endl << 
    "7. Total number of nodes" << endl << 
    "8. The height of the tree" << endl << 
    "9. Tree balance check" << endl << 
    "10. Delete a node based on pet name" << endl << 
    "11. Destroy the tree" << endl << 
    "12. Test function" << endl << 
    "13. Quit" << endl << endl; 
}

void test() {

    ShelterBST tree; 

    //Insert
    tree.insertPet("Zelda", 5);
    tree.insertPet("Link", 7);
    tree.insertPet("Kenny", 9);
    tree.insertPet("Bryan", 2);
    tree.insertPet("Ryan", 1); 
    tree.insertPet("Lauren", 3);
    tree.insertPet("Nathan", 10);
    tree.insertPet("Remy", 14);
    tree.insertPet("Max", 18);
    tree.insertPet("Tony", 4);

    //Tests 
    tree.searchPet("Zelda");
    tree.preorderDisplay();
    tree.inorderDisplay();
    tree.postorderDisplay();
    tree.parent("Remy");
    tree.predecessor("Max");
    tree.internal();
    tree.countTreeNodes();
    tree.treeHeight();
    tree.balance();
    tree.deleten();
    tree.destroyTree();
}

