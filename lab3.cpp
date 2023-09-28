//Kenny Nguyen
//lab3.cpp 

#include <iostream> 
#include "ShelterBST.h"
using namespace std; 

int main() {

    ShelterBST tree;
    // insert 10 pets, for example: (this syntax may be different
    // depending on how you design your constructors)
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

    //In-Order Display 
    cout << endl << endl << "In-Order Display:" << endl;
    tree.inorderDisplay();
    //Pre-Order Display 
    cout << endl << "Pre-Order Display:" << endl; 
    tree.preorderDisplay();
    //Post-Order Display 
    cout << endl << "Post-Order Display:" << endl; 
    tree.postorderDisplay();
    //Sucessful Search 
    cout << endl << "Search:" << endl; 
    tree.searchPet(9);
    //Unsucessful Search 
    tree.searchPet(100); //Assuming no Pet in your tree is aged 100
    cout << endl;

    return 0;
}

