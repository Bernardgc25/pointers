// Bernard J. Gole Cruz, CS 202-2002, Assignment 3 part 3
// This program is implement pointers arithmetic

#include<iostream>
#include<iomanip>

using namespace std;

//function prototype
void prompt(int *Array, int *&ptr, int &size);
void promptposition(int *Array, int size, int *&currentptr, int *&last_subscrpt);
void movesubscript(int *Array, int size, int &pos, int *&currentptr, int *&last_subscrpt);
void reprompt(int *Array, int size, int pos, int *&currentptr, int *&last_subscrpt);
bool valid(int number, int size);
bool positive(int pos);



int main(){
    int asize;


    //pointer variables
    int *current;
    current = nullptr;

    int *Darr;
    Darr = nullptr;

    //allocated space for dynamic array
    Darr = new int[asize];

      prompt(Darr, current, asize);

      cout << endl;


    //deallocate Darr
    delete []Darr;
    //point current to null
    current = nullptr;

    return 0;


}

//prompt user for size of array
void prompt(int *Array, int *&currptr, int &size){

    cout << "enter array size: ";
    cin >> size;

    //input data in array
    for(int i= 0; i<size; i++){
            cin >> Array[i];
            cin.clear();
            cin.ignore();
            }

    //print elements of the array
    for(int i= 0; i<size; i++){
            currptr = &Array[i];
            cout << *currptr << ", ";
            }

    int *first_position = &Array[0];
    int *last_position = &Array[size-1];
    size--;
    currptr = first_position;
    cout << endl;
    promptposition(Array, size, currptr, last_position);

    last_position = nullptr;
    currptr = nullptr;
}


//check if position enter by user is within range of array
bool valid(int pos, int size){
    bool status;

     if (pos >= 0 && pos <= size)
        status = true;
     else
        status = false;
     return  status;
}

//check if position is positive or negative, move to the right or left of array subscript
bool positive(int pos)
{
    bool status;

     if (pos >= 0){
        status = true;
     }
     else{
        status = false;
     }
     return status;
}


//prompt user for array subscript position
void promptposition(int *Array, int size, int *&currentptr, int *&last_subscrpt){
     int pos;
     cout << "enter relative pos: " ;
     cin >> pos;


     if (valid(pos, size)){

        //pointer points to Array subscript chosen by user
        currentptr = &Array[pos];

        //display address of Array, current pointer, and last subscript
        cout << "DArr=" << &Array << right << setw(10) << "current=" << &currentptr << right << setw(7) << "last=" << &last_subscrpt << endl;

        //display deference value of current pointer
        cout << "current value=" << *currentptr << "," << right << setw(18) << "current position=" << pos << "/" << size << endl;

        movesubscript(Array, size, pos, currentptr, last_subscrpt);
     }
    else{
        //pointer points to Array subcript 0
        pos = 0;
        currentptr = &Array[pos];

        //insert function, pointer points to subscript 0
        cout << "Position set to: " <<  pos << endl;
        currentptr = nullptr;
        }
}


//pointer moves left if user input for position is negative and moves right if positive
void movesubscript(int *Array, int size, int &pos, int *&currentptr, int *&last_subscrpt){

     //moves array subscript
     int move_position;
     cout << "enter relative pos: " ;
     cin >> move_position;

     //if position entered is positve, moves to the right of array
     if (positive(move_position)){
        //update subscript position
        currentptr = &Array[pos + move_position];


        //display address of Array, current pointer, and last subscript
        cout << "DArr=" << &Array << right << setw(10) << "current=" << &currentptr << right << setw(7) << "last=" << &last_subscrpt << endl;

        //display deference value of current pointer
        cout << "current value=" << *currentptr << "," << right << setw(18) << "current position=" << pos + move_position << "/" << size << endl;


        promptposition(Array, size, currentptr, last_subscrpt);
        currentptr = nullptr;
        }


     //if position entered is negative, moves to the left of array
     else
        {
        int *newcurrenptr = nullptr;
        newcurrenptr = &Array[pos + move_position];

              //display address of Array, current pointer, and last subscript
        cout << "DArr=" << &Array << right << setw(10) << "current=" << &newcurrenptr << right << setw(7) << "last=" << &last_subscrpt << endl;

        //display deference value of current pointer
        cout << "current value=" << *newcurrenptr << "," << right << setw(18) << "current position=" << pos + move_position << "/" << size << endl;

        promptposition(Array, size, newcurrenptr, last_subscrpt);
        newcurrenptr = nullptr;
        }

}


