//Kenny Nguyen
//assignment1.cpp 

#include <iostream> 
#include <queue> 
#include <string>
#include <list> 
using namespace std; 

//A struct of the pet with all the data needed from an animal 
class Pet {

    private:
    string name;
    string animal;

    public: 
    Pet(string x, string y); 
    string get_name();
    string animal_type(); 
};

void add_animal(list<Pet*> &list, queue<Pet*> &queue, string name, string category); 
void adopt(list<Pet*> &list, queue<Pet*> &queue);  
void adopt_any(list<Pet*> &list, queue<Pet*> &queue_one, queue<Pet*> &queue_two); 
void welcome(); 

int main() {

    queue<Pet*> dogs;
    queue<Pet*> cats;
    list<Pet*> animal_list;
    const string DOGS = "dog";
    const string CATS = "cat"; 
    int command = 0; 

    while (command != 6) {
        welcome(); //Welcomes user

        //Gets command from the user, and checks if it is a valid input to execute
        cout << "Option: ";
        cin >> command; 
        if (command < 0 || command > 6) {
            cout << "Error, invalid input (Please enter a number from 1-6)" << endl; 
            cin >> command; 
        }

        //Switch statements for each of the possible executables
        switch(command) {

            //Adds a cat 
            case 1: { 
                string name; 
                cout << "Enter a name for the cat: "; 
                cin >> name; 
                add_animal(animal_list, cats, name, CATS);
                break; 
            }

            //Adds a dog 
            case 2: {
                string name; 
                cout << "Enter a name for the dog: ";
                cin >> name; 
                add_animal(animal_list, dogs, name, DOGS);
                break;
            }
 
            //Adopts a cat
            case 3: {
                adopt(animal_list, cats);
                break; 
            }

            //Adopts a dog 
            case 4: {
                adopt(animal_list, dogs);
                break; 
            }

            //Adopts an animal 
            case 5: {
                adopt_any(animal_list, cats, dogs);
                break; 
            } 

            //Quits the program 
            case 6: {
                cout << "Goodbye, thank you for visiting the shelter!" << endl << endl; 
                return 0; 
            }
        }
    }
    return 0; 
}

//Welcomes the user, and shows the list of actions the user can take
void welcome() {

    cout << endl << endl << 
    "Welcome to the Animal Shelter!" << endl << 
    "Below is a list of things you can do:" << endl << 
    "Please enter the number associated with your option" << endl << endl << 
    "1. Add a CAT to the shelter" << endl << 
    "2. Add a DOG to the shelter" << endl << 
    "3. Adopt a CAT from the shelter" << endl << 
    "4. Adopt a DOG from the shelter" << endl << 
    "5. Adopt any animal from the shelter" << endl << 
    "6. Exit" << endl << endl;
}

void add_animal(list<Pet*> &list, queue<Pet*> &queue, string name, string animal) {

    //Creates an instance of the pet in dynamic memory 
    Pet *new_pet = new Pet(name, animal);

    //Pushes the new pet into both the queue and the list and then prints message 
    queue.push(new_pet);
    list.push_back(new_pet); 
    cout << name << " was added to the shelter! Thank you!" << endl; 
    cout << "Press enter to continue..."; 
    cin.ignore();
    cin.get();
    
}

void adopt(list<Pet*> &list, queue<Pet*> &queue) {

    //Checks if the animal queue they are trying to adopt from is empty
    if (queue.size() == 0) {
        cout << "Sorry, there are currently no animals at the shelter to adopt :(" << endl; 
        cout << "Press enter to continue..."; 
        cin.ignore();
        cin.get();
        return; 
    } 
    
    //Gets the oldest pet from the animal queue that is desired and prints message then deletes to prevent leak
    Pet *front = queue.front();
    queue.pop();
    string type = front->animal_type();
    cout << "You have adopted a " << type << " named " << front->get_name() << endl; 
    delete front; 
    cout << "Press enter to continue..."; 
    cin.ignore();
    cin.get();
    
} 

void adopt_any(list<Pet*> &list, queue<Pet*> &queue_one, queue<Pet*> &queue_two) {

    //Checks for valid size, if there are no pets in the list then return 
    if (list.size() == 0) {
        cout << "Sorry, there are currently no animals at the shelter to adopt :(" << endl; 
        cout << "Press enter to continue..."; 
        cin.ignore();
        cin.get();
        return;
    } 

    //Gets the oldest pet from the front of the list, and removes it from both the list and the correct animal queue 
    Pet *oldest = list.front();
    list.pop_front(); 
    string type = oldest->animal_type();
    if (type == "cat") {
        queue_one.pop(); 
    } else {
        queue_two.pop(); 
    }
    
    //Message and delete to prevent memory leak
    cout << "Congratulations, you adopted a " << type << " named " << oldest->get_name() << endl; 
    delete oldest;  
    cout << "Press enter to continue..."; 
    cin.ignore();
    cin.get();
    
}

//Constructor to make each object 
Pet::Pet(string x, string y) {

    name = x;
    animal = y;
} 

//This method gets the names of the pets since it is a private member 
string Pet::get_name() {

    return name;
}

//This method gets the animal's type (dog or cat) because the animal type is private 
string Pet::animal_type() {

    return animal; 
}