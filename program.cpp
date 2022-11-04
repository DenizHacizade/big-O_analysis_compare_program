#include<iostream>
#include <time.h>

using namespace std;

void binarySearch(int*,int,int);
void sequentialSearch(int*,int,int);
void bubbleSort(int*, int);
void insertionSort(int*, int);
void randomArray(int*,int);


int main() {

    int searchNumber;
    int size;
  
    cout << "Q1 - Number of Comparisons for Searching Algorithms" << endl;
    cout << "\nSize of the Sorted Array> " << endl;
    cin >> size;
    cout << "Enter a number to search: " << endl;
    cin >> searchNumber;

    int* p = new int[size]; // A dynamic array is required to fill an array with the amount we want.
    
    for (int i = 0; i < size; i++) {
        p[i] = i;
    }
   
    binarySearch(p,size,searchNumber);
    sequentialSearch(p,size,searchNumber);

    cout << "\n" << endl;

    cout << "\nQ2 - Number of Comparisons on Sorted (in Ascending Order) Arrays" << endl;
    cout << "Size:"<< endl;
    cin >> size;

    int* p2 = new int[size];  // A dynamic array is required to fill an array with the amount we want.

    for (int i = 0; i < size; i++) {
        p2[i] = i;
    }

    bubbleSort(p2, size);
    insertionSort(p2, size);

    cout << "\nQ2 - Number of Comparisons on Randomly Generated (Unsorted) Arrays" << endl;
    randomArray(p2, size); // we are shuffling the array to sort the bubble sort function.
    bubbleSort(p2, size);  // bubble sort function sorts array
    randomArray(p2, size);  // again array shuffles randomly
    insertionSort(p2, size); // insertion sort function sorts array
 
	return 0;
}


void binarySearch(int *p,int  size, int searchNumber ){
   
    int ctr = 0;
    int mid; int min = 0; int max = size - 1;


    cout << "\n#####Binary Search######\n" << endl;

      do {

        mid = (min+max) / 2;
        ctr++;
        if (p[mid] == searchNumber) {   // When the middle number is equal to the searched number, the searched number is found.
            cout << "Item found at: " << mid << endl;
            cout << "Number of Comparisons: " << ctr << endl;
            break;
        }

        else {
            if (p[mid] < searchNumber) {
                min = (mid + 1);       //the number trying to search is to the right of the middle number.
                ctr++;
            }
            else {
                max = (mid - 1); // the number trying to search is to the left of the middle number.
                ctr++;           
            }
        }
      } while (min <= max);

    if (min >= max){  //If min value is greater than or equal to max value, then the searched number is not in the array.
        cout <<"Number of Comparisons: "<<ctr << endl;
        cout << searchNumber << " is not in the list." << endl;
    }
   
    
}



void sequentialSearch(int*p,int size,int searchNumber) {

    int ctr = 0;  bool search=0;
    int i;

    cout << "\n#####Sequential Search######\n" << endl;

    for ( i = 0; i < size; i++) {
        ctr++;     // shows how many numbers it compares until you find the number
        if (searchNumber == p[i]) {    

            // check if the number is in the array
            search = 1;
            break;
        }

    }

    if (search == 1) {   
        cout << "Item found at: " << i << endl;
        cout << "Number of Comparisons:" << ctr << endl;
    }
    else {   // If the number is not found in the array
        cout << searchNumber << " not in the list" << endl;
        cout << "Number of Comparisons:" << ctr << endl;
    }
}

void bubbleSort(int* p, int size) {

    int temp;
    int ctr = 0;

    for (int i = 0; i < size; i++) { 

        for (int j = 1; j < size - i; j++) {

            if (p[j - 1] > p[j]) {
                temp = p[j];          // swapping part
                p[j] = p[j - 1];
                p[j - 1] = temp;
                
            }
            ctr++;  // counter gives the same value in ascending order array and unsorted array
        }
        
    }
    cout << "\nBubble Sort # of Comparisons: " << ctr << endl;
    
}

void insertionSort(int* p, int size) {

    int i, j, min, ctr = 0;

    for (i = 1; i < size; i++) {
        
        min = p[i];
        j = i - 1;
        ctr++; // this ctr counts ascending order array
        
        
        while (j >= 0 && p[j] > min) {
            
            p[j + 1] = p[j];  // the smallest value shifts to the left
            j--;
            ctr++; // this ctr counts unsorted array 
            
        }
        p[j + 1] = min;  
      
    }

    cout << "Insertion Sort # of Comparisons: " << ctr << endl;

}

void randomArray(int* p, int size) {

    for (int i = 0; i < size; i++){
    
        int temp;
        while (1){
        
            bool check = 0;
            temp = (rand() % size); // temp variable is given the value of a random number

            for (int j = 0; j < i ; j++){  // comparison part
            
                if (p[j] == temp){    // check if the number has come before
                
                    check++;     // if the same number comes out, value of the check increases
                }
            }
            if (check == 0) {   // the number is added to the array if it has not repeated before

                p[i] = temp;
                break;
            }
        }
    }

}



        
   