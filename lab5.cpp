//Kenny Nguyen
//LAB5.CPP
#include <iostream> 
#include <chrono> 
using namespace std;

//Functions for Heap Sort 
void heapSort(int* A, int size);
void buildMaxHeap(int* A, int size);
void heapify(int* A, int size, int i);

//Functions for Merge Sort 
void mergeSort(int* A, int size); 
void recurMergeSort(int* A, int left, int right);
void merge(int* A, int left, int mid, int right);

//Functions for Quick Sort 
void quickSort(int* A, int size); 
void quickSort(int* A, int i, int k);
int partition(int* A, int i, int k); 
int generateRandomPivot(int i, int k);

//Other functions
void printArray(int* A, int size);
void measureSort(void (*sortingFunction)(int*, int));


int main() {

    //Function pointer
    void (*sortingFunction)(int*, int);

    //Heap Sort 
    cout << endl << endl << "HEAP SORT" << endl;
    sortingFunction = &heapSort;
    measureSort(sortingFunction);
    cout << endl; 

    //Merge Sort 
    cout << endl << "MERGE SORT" << endl;
    sortingFunction = &mergeSort;
    measureSort(sortingFunction);
    cout << endl; 
    
    //Quick Sort
    cout << endl << "QUICK SORT" << endl;
    sortingFunction = &quickSort;
    measureSort(sortingFunction);
    cout << endl; 

    cout << endl << endl; 

    return 0; 
}

//Function to measure the time 
void measureSort(void (*sortingFunction)(int*, int)){
    
    int size[] = {10,100,1000,10000,100000};
    for(int i = 0; i < 5; i ++){
        //allocate memory for the array
        int* array = new int[size[i]];
        //fill in array with random numbers
        for(int j=0; j<size[i]; j++){
            array[j] = rand() % 100000;
        }
        
        // display size 10 random array
        if (size[i] == 10){
            cout << "--Random array-- " << endl;
            printArray(array, size[i]);
        }

        //Call the sorting function (make sure to
        //start with a new unsorted array each time)
        //and measure the execution time here
        auto start = chrono::high_resolution_clock::now();
        sortingFunction(array, size[i]);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
        
        //display size 10 sorted array
        if (size[i] == 10){
            cout << "--Sorted array-- " << endl;
            printArray(array, size[i]);
        }
        //display the time measurement with units
        cout << endl << "Array size " << size[i] << " duration: ";
        cout << duration << " ns.";
        
        delete[] array; 
    }
}

//Prints the unsorted and sorted array 
void printArray(int* A, int size) {

    for (int i = 0; i < size; i++) {
        cout << A[i] << " "; 
    }
    cout << endl; 
}

//Heap Sort function 
void heapSort(int* A, int size) {

    buildMaxHeap(A, size); 

    for (int i = size - 1; i > 0; i--) {
        //Swap the root with the last element
        swap(A[0], A[i]);
        //Calls heapify on the reduced heap
        heapify(A, i, 0);
    }
}

//Builds a max heap
void buildMaxHeap(int* A, int size) {
    
    //Starts from the last non-leaf node and heapifies each node in reverse order
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(A, size, i);
    }
}

//Heapify for min heap 
void heapify(int* A, int size, int i) {
    
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    //Checks if left child is smaller than the root
    if (leftChild < size && A[leftChild] > A[largest])
        largest = leftChild;
    
    if (rightChild < size && A[rightChild] > A[largest])
        largest = rightChild;

    //If the smallest child is different from the current node then swap and heapify if needed
    if (largest != i) {
        swap(A[i], A[largest]);
        heapify(A, size, largest);
    }
}


//Overload function for merge sort 
void mergeSort(int* A, int size) {

    recurMergeSort(A, 0, size-1); 
}

//Merge Sort function 
void recurMergeSort(int* A, int left, int right) {

    if (left < right) {
        int mid = (left + right) / 2; 
        recurMergeSort(A, left, mid);
        recurMergeSort(A, mid + 1, right); 
        merge(A, left, mid, right); 
    }
}

//Merge function 
void merge(int* A, int left, int mid, int right) {

    //Calculate the sizes of the two subarrays
    int size1 = mid - left + 1;
    int size2 = right - mid;

    //Temporary subarrays for left and right 
    int* L = new int[size1];
    int* R = new int[size2];

    //Copy the elements from the original array to the temporary arrays
    for (int i = 0; i < size1; i++) {
        L[i] = A[left + i];
    }

    for (int j = 0; j < size2; j++) {
        R[j] = A[mid + 1 + j];
    }

    //Index for both subarrays and the sorted array 
    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < size1 && j < size2) {
        //Compare the elements from the left and right subarrays
        //and store the smaller element in the merged array
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    //Copy the remaining elements from the left subarray
    while (i < size1) {
        A[k] = L[i];
        i++;
        k++;
    }

    //Copy the remaining elements from the right subarray
    while (j < size2) {
        A[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}


//Overload function for quick sort 
void quickSort(int* A, int size) {

    quickSort(A, 0, size - 1); 
}

//Recursive quicksort
void quickSort(int* A, int i, int k) {

    if (i < k) {
        int pivotIndex = partition (A, i, k); 
        quickSort(A, i, pivotIndex - 1); 
        quickSort(A, pivotIndex + 1, k);
    }
}

//Partition function 
int partition(int* A, int i, int k) {

    int p = A[i]; //Pivot 
    int m = i; //Intial S1 and S2 are empty
    
    //Processes the unknown region
    for (int n = i + 1; n <= k; n++) {
        //Orders the S1 and S2 areas
        if (A[n] <= p) {
            m++; 
            swap(A[m], A[n]);
        }
    }

    //Puts the pivot in the right place
    swap(A[m], A[i]);
    return m;
}

//Gets a random number for the pivot
int generateRandomPivot(int i, int k) {
    
    srand(time(0));

    //Generates a random number between k and i 
    return rand() % (k - i + 1) + i;
} 
