//Kenny Nguyen
//lab1.cpp 

#include <iostream>
using namespace std;

void bico(int **array, int n, int i);
void delete_array(int **&array, int i);
void create_array(int **&array, int n);
void print(int **array, int n); 

int main() {

    int binomial, coefficient; 
    int **array = nullptr; 

    cout << endl << endl; 

    //Assuming valid integer input for both the binomial and coefficient
    cout << "Please input the degree of the binomial: ";
    cin >> binomial; 

    cout << "Please input the degree of the coefficient: ";
    cin >> coefficient; 
    
    binomial += 1; 
    create_array(array, binomial);
    print(array, binomial);
    binomial -= 1; 
    bico(array, binomial, coefficient);
    delete_array(array, binomial);

    cout << endl << endl;

    return 0; 
}

//Returns the int at the degree of the binomial and coefficient that the user wnats 
void bico(int **array, int n, int i) { 

    cout << "The result is " << array[n][i] << endl;
}

//Deallocates the memory from a 2D array
void delete_array(int **&array, int n) {

    //Traverses through the rows and deletes the rows, then deletes the array itself 
    for(int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array; 
    array = nullptr; 
}

//Prints the elements of Pascals Triangle size dependent on the 
void print(int **array, int n) {

    char const SPACE = ' ';

    //Prints all of the elements in the array
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (array[i][k] != 0) { //Does not print out 0's 
                cout << array[i][k] << SPACE; 
            }
        }
        cout << endl; 
    }
}

//Creates the 2D array, initializing the elements to 0
void create_array(int **&array, int n) {

    array = new int*[n]; //Allocation of the column  
    for (int row = 0; row < n; row++) {
        array[row] = new int[n]; //Allocation of the rows 
        for (int col = 0; col < n; col++) {
            //Checks if the row is 0 or equal to the coefficient which signifies that it is the 
            //beginning of a new row or the end of one 
            if (col == 0 || col == row) { 
                array[row][col] = 1;
            } else {
                if (row > 0 && col > 0 && col < row) {
                    array[row][col] = array[row-1][col-1] + array[row-1][col];
                }
            }
        }
    }
}