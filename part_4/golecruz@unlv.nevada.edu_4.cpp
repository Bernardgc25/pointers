// Bernard J. Gole Cruz, CS 202-2002, Assignment 3 part 4
// This program implement the use of pointers in class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int maxvalue = 1000;
const int minvalue = 1;

class DArr{
public:

    DArr (){
       size = 0;
    };

    DArr(int x){

    this->size = x;

    //allocate new array
    arr = nullptr;
    arr = new double[size];

    //create double type array
    double nArray[size];
    arr = nArray;
    cout << "Constructor: allocating " <<  sizeof(nArray) << " bytes of memory "<< endl;

    displayElement(nArray, size);
        };

    ~DArr(){
    delete []arr;
        };

    double *arr;
    int size;
    void displayElement(double *Array, int size);
    double *getmax(double *Array, int x);


};
//generate random numbers
void DArr::displayElement(double *Array, int size)
{
    cout << "array elements: " << endl;

     for(int i=0; i<size; i++)
        {
         double num = (rand() % (maxvalue - minvalue)) * 1.2;
         *(Array + i) = num;
        }
     for(int i=0; i<size; i++)
        {
        cout << fixed << showpoint << setprecision(2);
        cout << *(Array + i) << ", ";

        }
      cout << endl;
      cout << "Destructor: freeing " << sizeof(Array) << right << setw(16) << "bytes if memory" << endl;

}

//highest number in array
double DArr::*getmax(double *Array, int size)
{
    /*
    //highest element
    double *maximum;
    int highest = 0;

    for(int i=1; i<size; i++){
             if( Array[i] > Array[highest])
                highest = i; }

       maximum = Array;
       return maximum[highest];
    */
}


int main()
{
        /*
        double Array[asize];

        unsigned seed = time(0);
        srand(seed);

        for(int i=0; i<asize;i++)
            {
            double y = (rand() % (maxvalue - minvalue)) * .03 ;
            Array[i] = y;
            }
        for(int i=0; i<asize;i++)
            {
             cout << Array[i] << ", " ;
            }

         cout << fixed << showpoint << setprecision(2);
         cout<<"size of double array:" << sizeof(Array) << endl;

        */

    int asize;

    cout << "Enter the array size: ";
    cin >> asize;

    unsigned seed = time(0);
    srand(seed);
    DArr d1(asize);


    return 0;
}
