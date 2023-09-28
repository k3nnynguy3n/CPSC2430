//Kenny Nguyen
//lab2.cpp 

#include <iostream> 
#include <chrono> 
using namespace std;
using namespace std::chrono;

void delete_array(int **&array, int i);
void print(int **array, int n, int i); 
int **recursivePascal(int degree, int index);
int recursiveBico(int degree, int index); 
int **iterativePascal(int degree, int index); 

int main() { 

    cout << endl << "Lab 1 Iterative Pascal: " << endl;
    //Set a clock before the program executes
    auto start = high_resolution_clock::now(); 

    //Program execution 
    int **iPascal = iterativePascal(3,2);

    //Set a clock after the program executes 
    auto stop = high_resolution_clock::now(); 

    //Get the execution time of the program by calculating the difference
    auto duration = stop - start; 
    auto duration_ns = duration_cast<nanoseconds>(duration);

    //Prints the duration 
    cout << "Time: " << duration_ns.count() << endl; 

    print(iPascal, 3,2); 


    cout << endl << "Lab 2 Recursive Pascal: " << endl;
    //Set a clock before the program executes
    start = high_resolution_clock::now(); 

    //Program execution
    int **rPascal = recursivePascal(3,2); 

    //Set a clock after the program executes 
    stop = high_resolution_clock::now(); 

    //Get the execution time of the program by calculating the difference
    duration = stop - start; 
    duration_ns = duration_cast<nanoseconds>(duration);

    //Prints the duration 
    cout << "Time: " << duration_ns.count() << endl; 

    print(rPascal, 3, 2);
    
    //Deallocation of the arrays 
    delete_array(rPascal, 3);
    delete_array(iPascal, 3); 
    
    return 0; 
}

//Prints the elements of Pascals Triangle size dependent on the 
void print(int **array, int n, int i) {

    char const SPACE = ' ';

    //Prints all of the elements in the array
    for (int i = 0; i < n+1; i++) {
        for (int k = 0; k <= i; k++) {
            cout << array[i][k] << SPACE;
        }
        cout << endl; 
    }
    //Prints the location of the number at the given degree and index
    cout << "The result is " << array[n][i] << endl;
}


//Deallocates the memory from a 2D array
void delete_array(int **&array, int n) {

    //Traverses through the rows and deletes the rows, then deletes the array itself 
    for(int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array; 
}


//Returns a 2D array filled with pascals triangle up to the given degree
int** iterativePascal(int degree, int index) {

    int **array = new int*[degree+1]; //Allocation of the column  
    for (int row = 0; row <= degree; row++) {
        array[row] = new int[row+1]; //Allocation of the row
        for (int col = 0; col <= row; col++) {
            //Checks if the row is 0 or equal to the coefficient which signifies that it is the 
            //beginning of a new row or the end of 
            if (col == 0 || col == row) { 
                array[row][col] = 1;
            } else {
                array[row][col] = array[row-1][col-1] + array[row-1][col];
            }
        }
    }
    return array; 
}

int **recursivePascal(int degree, int index) { 

    int **pascal = new int*[degree+1]; //Allocation of the column  
    for (int row = 0; row <= degree; row++) {
        pascal[row] = new int[row+1]; //Allocation of the rows 
        pascal[row][0] = 1; //Sets the first number of the triangle to one 
        for (int col = 1; col <=row; col++) {
            pascal[row][col] = recursiveBico(row-1, col-1) + recursiveBico(row-1, col);
        }
    }
    return pascal;
}

int recursiveBico(int degree, int index) {

    //Base case to check and end the function once a the index is equal to 0 or equal to the degree 
    if (index == 0 || index == degree) {
        return 1;
    } else if (degree == 0) {
        return 0;
    } else {
        return recursiveBico(degree-1, index-1) + recursiveBico(degree-1, index); 
        //Adds the elements one above and to the left, to the elements directly above the current element
    }
}