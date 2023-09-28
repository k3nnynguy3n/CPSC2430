//Kenny Nguyen
//Min-Heap construction and basic operations
//Lab 4, CPSC 2430-01

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Pet{
    string name;
    int arrival;
};

class PetHeap {
    
    private:
    vector<Pet*> petHeap;
    void percolateUp(int index);
    void percolateDown(int index);
    void deleteMin();
    Pet* peekMin();
    
    public:
    PetHeap(){
    petHeap = vector<Pet*>();
    }
    void insert(Pet* pet);
    Pet* adoptOldestPet();
    int numPets();
    void displayPets();
    ~PetHeap(){
        petHeap.clear();
    }
};

void welcome(); 
void exit(); 
void test(); 

int main() {

    int choice = -1; 
    PetHeap petHeap;

    while (choice != 6) {
            
        welcome();
        cout << endl << "Option: ";
        cin >> choice; 

        switch(choice) {
                
            //Insert a pet 
            case 1: {
                string name; 
                int arrival; 

                cout << "Enter a name for the pet: ";
                cin >> name; 
                cout << "Enter the arrival for the pet: "; 
                cin >> arrival; 
                cout << endl << endl;

                Pet* pet = new Pet{name, arrival}; 
                petHeap.insert(pet);
                break; 
            }

            //Adopt a pet 
            case 2: {
                Pet* adopted = petHeap.adoptOldestPet();

                if (adopted == nullptr) {
                    cout << "Sorry there are no pets available at this time" << endl; 
                    cout << "Press enter to continue..." << endl; 
                    cin.get();
                    cin.ignore(); 
                    break;  
                }

                cout << "You adopted: " << endl 
                    << "Name: " << adopted->name << endl 
                    << "Arrival: " << adopted->arrival << endl << endl; 
                
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore(); 
                break;
            }

            //Number of pets 
            case 3: {
                int totalpets = petHeap.numPets(); 

                cout << "There are " << totalpets << " total pets" << endl; 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore(); 
                break; 
            }

            //Display pets
            case 4: {
                petHeap.displayPets(); 
                    
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore(); 
                break; 
            }

            //Run Tests 
            case 5: {
                test(); 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore();   
                break; 
            }

            //Quit 
            case 6: {
                exit(); 
                cout << "Press enter to continue..." << endl; 
                cin.get();
                cin.ignore(); 
                return 0; 
            }
        }
    }

    return 0; 
}


//Private Methods: 

// implement the above-mentioned functions below
void PetHeap::percolateUp(int index){

    //Find the parent node
    int parent = (index-1)/2;

    //Check to see if current node is less than parent node, if so switch 
    if (index > 0 && petHeap[index]->arrival < petHeap[parent]->arrival) {
        swap(petHeap[index], petHeap[parent]);
        percolateUp(parent);
    } else {
        return; 
    }
}

//Maintains the heap structure
void PetHeap::percolateDown(int index){

    //Find the left and right child of the index 
    int indexleft = (index * 2) + 1; 
    int indexright = indexleft + 2; 
    int smallerindex = index;
    int size = petHeap.size(); 

    //Find which child is smaller 
    if (indexright < size && petHeap[indexright]->arrival < petHeap[indexleft]->arrival) {
        smallerindex = indexright; 
    } else {
        smallerindex = indexleft; 
    } 

    //If smaller child is smaller than parent in terms of arrival then swap 
    if (indexleft < size && petHeap[smallerindex]->arrival < petHeap[index]->arrival) {
        swap(petHeap[index], petHeap[smallerindex]);
        percolateDown(smallerindex); 
    }

}

//Deletes and removes the oldest pet by arrival 
void PetHeap::deleteMin(){

   if (petHeap.empty()) {
        return;
   } 
   
    //Replaces the root with the last element
    Pet* lastPet = petHeap.back();
    petHeap.pop_back();
    
    if (!petHeap.empty()) {
        petHeap[0] = lastPet;
        lastPet->arrival = peekMin()->arrival - 1;
        percolateDown(0);
    }

}

//Finds the oldest animal in the heap 
Pet* PetHeap::peekMin(){

    if (petHeap.empty()) {
        return nullptr; 
    } 
    return petHeap[0]; 

}


//Public Methods: 

//Inserts a pet then organizes the pet 
void PetHeap::insert(Pet* pet){

    int size = petHeap.size();
    petHeap.resize(size+1);
    petHeap[size] = pet; 
    percolateUp(size); 

}

//Find the oldest, delete it and return the pet
Pet* PetHeap::adoptOldestPet(){

    if (petHeap.empty()) {
        return nullptr; 
    }

    //Grabs the oldest pet and deletes it then heapify
    Pet* oldest = peekMin();
    deleteMin();

    return oldest; 

}

//Returns the size of the heap
int PetHeap::numPets(){

    int size = petHeap.size();

    return size;

}

//Prints the elements int the vector 
void PetHeap::displayPets(){

    int size = petHeap.size();
    for (int i = 0; i < size; i++) {
        cout << "Name: " << petHeap[i]->name << endl <<
                "Arrival: " << petHeap[i]->arrival << endl << endl;  
    }
    cout << endl; 

}


//Functions:

//Welcome message 
void welcome() {

    cout << endl << endl << "Welcome to Lab4!" << endl <<
    "Choose an option below to execute:" << endl << 
    "1) Insert Pet" << endl <<
    "2) Adopt Pet" << endl << 
    "3) Number of Pets" << endl << 
    "4) Display Pets" << endl << 
    "5) Run Tests" << endl << 
    "6) Exit" << endl << endl; 

}

//Goodbye message 
void exit() {
    
    cout << "Thank you for visiting! Goodbye!" << endl << endl; 

}

//Test function 
void test() {
    
    PetHeap petHeap;

    //Create some pets and insert them into the heap
    Pet* pet1 = new Pet{"Max", 1};
    Pet* pet2 = new Pet{"Charlie", 3};
    Pet* pet3 = new Pet{"Buddy", 2};
    Pet* pet4 = new Pet{"Lucy", 4};

    petHeap.insert(pet1);
    petHeap.insert(pet2);
    petHeap.insert(pet3);
    petHeap.insert(pet4);

    //Display the pets in the heap
    petHeap.displayPets();

    //Adopt the oldest pet
    Pet* adoptedPet = petHeap.adoptOldestPet();
    cout << "Adopted pet: " << endl;
    cout << "Name: " << adoptedPet->name << endl;
    cout << "Arrival: " << adoptedPet->arrival << endl << endl;
    
    cout << "Pets in the heap" << endl; 
    petHeap.displayPets();
    Pet* pet5 = new Pet{"Rocky", 5};
    petHeap.insert(pet5);

    //Adopts all pets
    while (petHeap.numPets() > 0) {
        Pet* adoptedPet = petHeap.adoptOldestPet();
        cout << "Adopted pet: " << endl;
        cout << "Name: " << adoptedPet->name << endl;
        cout << "Arrival: " << adoptedPet->arrival << endl << endl;
    }

    cout << "Remaining pets in the heap: " << endl;
    petHeap.displayPets();
}

