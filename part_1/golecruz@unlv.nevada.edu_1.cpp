// Bernard J. Gole Cruz, CS 202-2002, Assignment 3 part 1
// This program implement the use of pointers, dyanamic memory allocation

#include <iostream>
using namespace std;

//function prototype
double *resize(double *Array, int &arraysize, int newarraysize, int count);
void currentArray(double *currArray, int &arraysize, int &count);
void lowest_highest(double *updateArray, int array_capacity, double *&pmin, double *&pmax);
double oldhighest(double *&updateArray, int array_capacity);

 int main(){
     int count; //tracks the number of

     //size of array given by user
     int asize = 0;

     cout << "Enter size of array: ";
     cin >> asize;

     //new size of array
     int newsize = 0;

     //pointer to double variable
     double *array = nullptr;

     //allocate an array with size given by user
     array = new double[asize];

     //store in array with current size
     currentArray(array, asize, count);

     //store in array with updated size
     asize = asize + 1;
     array = resize(array, asize, newsize, count);

     //free memory space
     delete []array;
     //point to null
     array = nullptr;
     return 0;
 }

//old array
void currentArray(double *currArray, int &arraysize, int &count){
int i = 0; // holds number of iterations

     while(i<arraysize){
        cout << "Enter a number into subscript[" << i << "] of array: " ;
        cin >> *(currArray + i);
        i++;
     }

     count = i;
     cout << endl;
     cout <<"Iteration number: " << count << endl;

}
//updated array
double *resize(double *Array, int &arraysize, int newarraysize, int count){
    double *p_max;
    double *p_min;
    double *NewArray = nullptr;

    //allocate new array with updated size
    NewArray = new double[arraysize + newarraysize];

        //copy the contents from fold Array to NewArray
        for(int i=0; i <arraysize; i++){
            NewArray[i] = Array[i];
        }

        //deallocate memory space from old array
        delete []Array;
        Array = nullptr;

        //add a new number in array
        cout <<"Please enter element number " << count << ": ";
        double add_element;
        cin >> add_element;

        //update new size of Array
        int capacity = arraysize;

        //highest element in old array
        double highest_old;

        //store highest element in old array to double variable
        highest_old = oldhighest(NewArray, capacity);


        //compare the highest element from old and new array
        //print the highest element in new array
        if (add_element > highest_old){
          cout <<"Updating p_max to address " << &add_element << ", now pointing to value: " << add_element << endl;
            }
        //print the highest element from old array
        else
         cout <<"Updating p_max to address " << &highest_old<< ", now pointing to value: " << highest_old << endl;


         cout <<"Read number: " << add_element << endl;


        //add new number into new Array
        for(int i=0; i<capacity; i++){
             //assign new element to new array via pointer
             *(NewArray+(capacity - 1)) = add_element;
            }

        //display updated contents of array
        cout << "Current array elements: ";
        for(int i=0; i<capacity; i++){
             //display elements via pointer
              cout << *(NewArray + i) << " " ;
            }
        cout << endl;

        //display highest and lowest element in new array
        lowest_highest(NewArray,capacity,p_min,p_max);

        return NewArray;
}

//lowest and highest element
void lowest_highest(double *updateArray, int array_capacity, double *&pmin, double *&pmax){
    //lowest element
    double lowest = 0;
    lowest = *(updateArray); //assign subscript 0 as highest

    for(int i=1; i<array_capacity; i++){
             if( *(updateArray + i) < lowest)
                lowest = *(updateArray + i);
            }
            pmin = &lowest;
        //display lowest element and its variable address
        cout <<"Current minimum = " << lowest << " at address " << pmin ;

   cout << endl;

   //highest element
    double highest = 0;
    highest = *(updateArray); //assign subscript 0 as highest

    for(int i=1; i<array_capacity; i++){
             if( *(updateArray + i) > highest)
                highest = *(updateArray + i);
            }
            pmax = &highest;
        //display lowest element and its variable address
        cout <<"Current maximum = " << highest << " at address " << pmax ;

}

//display highest element in old array
double oldhighest(double *&updateArray, int array_capacity){

    //highest element
    double *maximum;
    int highest = 0;
   // highest = *(updateArray); //assign subscript 0 as highest

    for(int i=1; i<array_capacity; i++){
             if( updateArray[i] > updateArray[highest])
                highest = i; }

       maximum = updateArray;
       return maximum[highest];
}
