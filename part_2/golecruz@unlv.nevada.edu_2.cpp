//Bernard J. Gole Cruz, CS 202-2002, Assignment 3 part 2
//This program implement the use of pointers in class

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

//class declaration and its members
class Student{
    public:
        string name;
        int id;
        double gpa;

        void getdata(Student *&Array, int size);
        void printlist(Student *Array, int size);
        void HigestandLowest(Student *Array, int size);
};


//input data
void Student::getdata(Student *&Array, int size){
    int i = 0;
    while(i<size){
        cout << "Enter student " << i + 1 << " name: ";
        cin.ignore();
        getline(cin, Array[i].name);

        cout << "Enter student " << i + 1 << " id: ";
        cin >> Array[i].id;

        cout << "Enter student " << i + 1<< " gpa: ";
        cin >> Array[i].gpa;

        i++;}
}

//diaplay list of students
void Student::printlist(Student *Array, int size){

    cout << "Student list: (array address:" << right << setw(9) << &Array <<")" << endl;

    for(int i=0; i<size; i++){
    cout << fixed << showpoint << setprecision(2);
    cout << "Student "<< i + 1 << ":" << right <<setw(7) << Array[i].name << ", " << right << setw(2) << Array[i].id << ", " << right << setw(2) << Array[i].gpa << right << setw(13) << "(at address " << &Array[i] << ")" ;
    cout << endl;}

    cout << endl;

    //display student with highest and lowest gpa
    HigestandLowest(Array, size);
}

void Student::HigestandLowest(Student *Array, int size) //Student *&bestgpa_ptr, Student *&lowestgpa_ptr, int size)
{
 //pointer to higest gpa
 Student *BestGpaofSemester;
 BestGpaofSemester = new Student;

 //copy the student with highest gpa from sArr object to BestGpaofSemester object;
 BestGpaofSemester = Array;

 cout << "Array deleted" << endl;

    //get student with highest gpa
    int highest;
    highest = 0;

    //get student with highest gpa
    for( int i=1; i<size; i++){
            if(BestGpaofSemester[i].gpa > BestGpaofSemester[highest].gpa)
                highest = i;}
            cout <<"Student with highest GPA:" << endl;
            cout << BestGpaofSemester[highest].name << ", " << BestGpaofSemester[highest].id <<", "<< BestGpaofSemester[highest].gpa << right << setw(24) <<"(at address " << &BestGpaofSemester << ")" ;


 cout << endl;
 cout << endl;

 //student with lowest gpa
 //pointer to lowest gpa
 Student *LowestGpaOfSemester;
 LowestGpaOfSemester = new Student;

 //copy the student with highest gpa from sArr object to BestGpaofSemester object;
 LowestGpaOfSemester = Array;


    int lowest;
    lowest = 0;

    for( int i=1; i<size; i++){
            if(LowestGpaOfSemester[i].gpa < LowestGpaOfSemester[lowest].gpa)
                lowest = i;}
            cout <<"Student with lowest GPA:" << endl;
            cout << LowestGpaOfSemester[lowest].name <<", " << LowestGpaOfSemester[lowest].id <<", "<< LowestGpaOfSemester[lowest].gpa << right << setw(24) <<"(at address " << &LowestGpaOfSemester << ")" ;


  //deallocate memory space for BestGpaofSemester and LowestGpaofSemester objects
  delete []BestGpaofSemester;
  delete []LowestGpaOfSemester;

  //points to null
  BestGpaofSemester = nullptr;
  LowestGpaOfSemester = nullptr;
}

 int main(){
    int size = 0;
    //int count = 0;

    //Student pointers
    Student *current = nullptr;
    Student *sArr = nullptr;

    cout <<"Please input the size of array: ";
    cin >> size;

    //create the following student objects
    sArr = new Student[size]; //dynamic array of sArr object

    //current pointer point to sArr address
    current = sArr;

    //input and store data into sArr via current pointer
    current->getdata(sArr, size);
    cout << endl;

    //display list of student stored in sArr object access via current pointer
    current->printlist(sArr,size);

    //current pointer points to null
    current = nullptr;

    //deallocate sArr
    delete []sArr;
    sArr = nullptr;

     return 0;
 }

