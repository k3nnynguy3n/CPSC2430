//Kenny Nguyen
//assignment2.cpp

#include <iostream> 
#include <array> 
#include <cmath> 
using namespace std; 

void welcome();
int mysterySequence(int num); 
int tennisBalls(int num);
string decToBase2(int num);
bool isDivisibleBy7(int num);
double ramanujan(int depth, int maxdepth);
void test(); 

int main() {  

    int choice = 0; 

    //Welcomes the user, takes user option
    welcome();
    cout << endl << "Option: ";
    cin >> choice; 
    
    //Checks the input for valid choice 
    while (choice < 1 || choice > 7) {
        welcome();
        cout << endl << "Option: ";
        cin >> choice; 
    }

    switch (choice) {
    
        //Task 1 
        case 1: {
            int ans; 
            cout << endl << "Enter a number for the mystery sequence: ";
            cin >> ans; 
            int num1 = mysterySequence(ans);
            cout << "Number " << ans << " in the mystery sequence is " << num1 << endl << endl; 
            break;
        } 

        //Task 2
        case 2: {
            int height; 
            cout << endl << "Enter a number for the height of the pyramid: ";
            cin >> height; 
            int num2 = tennisBalls(height); 
            cout << "A pyramid with " << height << " levels has " << num2 << " tennis balls" << endl << endl; 
            break;
        }

        //Task 3 
        case 3: {
            int binary;
            cout << endl << "Enter a number to convert into a binary sequence: ";
            cin >> binary; 
            string binaryString = decToBase2(binary);
            cout << binary << " converted into a binary sequence is "<< binaryString << endl << endl;
            break; 
        }

        //Task 4 
        case 4: {
            int divisible; 
            cout << endl << "Enter a number to see if it is divisible by 7!: ";
            cin >> divisible; 
            bool dividable = isDivisibleBy7(divisible);
            if (dividable) {
                cout << divisible << " is divisible by 7" << endl << endl;
            } else {
                cout << divisible << " is not divisible by 7" << endl << endl; 
            }
            break;
        }

        //Task 5
        case 5: {
            int depth; 
            cout << endl << "Enter a number for the depth of the ramanujan: ";
            cin >> depth; 
            double result = ramanujan(0, depth);
            cout << "Answer: " << result << endl << endl; 
            break;
        }

        //Test function
        case 6: {
            test();
            break; 
        }

        //Quit
        case 7: {
            cout << "Thank you for visiting, Goodbye!" << endl << endl;
            return 0; 
        }
    }

    return 0; 
}

//Welcomes the user and presents the options that the user can take
void welcome() {

    cout << endl << "Welcome to the program!" << endl 
        << "Please select one of the following items below: " << endl << endl
        << "1. Mystery Sequence" << endl 
        << "2. Tennis Balls" << endl 
        << "3. DecToBase2" << endl 
        << "4. IsDivisibleBy7" << endl
        << "5. Ramanujan" << endl
        << "6. Test" << endl 
        << "7. Quit" << endl;
}

//Task 1: Starts at 2 and 3, and multiplies the previous two numbers in the array for the next element
int mysterySequence(int num) {

    if (num <= 0) {
        return 2;
    } else if (num == 1) {
        return 3; 
    } else {
        return mysterySequence(num - 1) * mysterySequence(num - 2);
    }

}

//Task 2: Calculates the total number of balls in a pryamid 
int tennisBalls(int num) {
    
    if (num == 0) {
        return 0; 
    } else {
        return (num * num) + tennisBalls(num - 1); 
    }
    
}

//Task 3: Takes the input, and turns it into a binary representation of a string
string decToBase2(int num) {

    if (num == 0) {
        return "0"; 
    } else if (num == 1) {
        return "1"; 
    } else {
        return decToBase2(num/2) + to_string(num % 2); 
    }
}

//Task 4: Returns true or false depending on if the number is divisible by 7 
bool isDivisibleBy7(int num) {
    
    //If the number is less than 100 meaning it is 2 digits divide
    if (num < 100) {
        return num % 7 == 0; 
    } 

    //Removes the last digit and doubles it 
    int last_digit = num % 10; 
    int doubled = last_digit * 2; 

    //Subtracts the remaining number to the doubled number
    int remaining = num / 10;
    remaining -= doubled; 

    return isDivisibleBy7(remaining);
}

//Task 5: Takes, as one of its arguments, the depth of a rational approximation to the above nested expression
double ramanujan(int depth, int maxDepth) {

    if (depth == maxDepth) {
        return (depth+1) * sqrt(6);
    } else {
        return (depth+1) * sqrt((depth+6)+ramanujan(depth+1,maxDepth));
    }
}

//Task 6: Test function 
void test() {

    //Mystery Sequence
    //Array for the test numbers from the assignment2 document
    array<int, 4>array1{{0, 1, 4, 7}};

    //Gets the size and stores it into a variable 
    int size1 = array1.size();
    cout << endl << "Mystery Sequence:" << endl;
    //Checks every element in the array, and outputs the statement
    for (int i = 0; i < size1; i++) {
        cout << "Number " << array1[i] << " in the mystery sequence is " << mysterySequence(array1[i]) << endl; 
    }
    cout << endl; 

    //TennisBalls 
    array<int, 4>array2{{0,1,3,10}};

    int size2 = array2.size(); 
    cout << endl << "Tennis Balls:" << endl; 
    for (int j = 0; j < size2; j++) {
        cout << "A pyramid with " << array2[j] << " levels has " << tennisBalls(array2[j]) 
        << " tennis balls" << endl; 
    }
    cout << endl;

    //DecToBase2 
    array<int, 5>array3{{0,1,13,32,321}};

    int size3 = array3.size(); 
    cout << endl << "DecToBase2:" << endl; 
    for (int k = 0; k < size3; k++) {
        cout << array3[k] << " converted into a binary sequence is "<< decToBase2(array3[k]) 
        << endl;
    }
    cout << endl; 

    //IsDivisibleBy7
    array<int, 5>array4{{1,7,31,1073,1729}};

    int size4 = array4.size();
    cout << endl << "IsDivisibleBy7:" << endl; 
    for (int e = 0; e < size4; e++) {
        bool divisible = isDivisibleBy7(array4[e]);
        if (divisible) {
            cout << array4[e] << " is divisible by 7" << endl;
        } else {
            cout << array4[e] << " is not divisible by 7" << endl;
        }
    }
    cout << endl;

    //Ramanujan
    array<int, 3>array5{{1,3,10}};

    int size5 = array5.size(); 
    cout << endl << "Ramanujan:" << endl; 
    for (int z = 0; z < size5; z++) {
        int number = array5[z];
        double answer = ramanujan(0, number);
        cout << "Result at " << array5[z] << " is: " << answer << endl; 
    }
    double infinity = ramanujan(0, 1000);
    cout << "Result at infinity is: " << infinity << endl; 
    cout << endl; 
}
