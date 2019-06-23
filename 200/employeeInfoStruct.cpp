/*
  main.cpp
  lab 4 Question 1
  Use Employee structure to use it as an array to get user
  And print it on the screen
  Created by Hisham on 10/8/17.
  Copyright © 2017 Hisham Hussein. All rights reserved.
*/

#include <iostream>
using namespace std;


struct Employee
{
    int age;
    int id;
    float salary;
    int getAge( ) { return age; }; //return the age
    int getId( )  {return id; }; //return Id
    float getSalary( ) {return salary; }; //return getSalary
};


void PrintEmployee(Employee [],int );

int main(int argc, const char * argv[]) {

    Employee x[2]; //and array of Employee
    int xLength=0;
    //ask the of the information
    for(int i=0;i<2;i++){
        cout<<"Enter the age: ";
        cin>>x[i].age;
        cout<<"Enter the Id: ";
        cin>>x[i].id;
        cout<<"Enter the Salary: ";
        cin>>x[i].salary;
        xLength++;
    }
        PrintEmployee(x,xLength); //function call

    return 0;
}
void PrintEmployee(Employee x[],int xLength){
    //loops through the information and print them out
    cout<<"\nFirst employee: "<<endl;
        for(int i = 0; i<xLength;i++){
            cout<<"Age for employee: "<<x[i].age<<endl;
            cout<<"Id: "<<x[i].id<<endl;
            cout<<"Salary: "<<x[i].salary<<endl;
            if(i==0){
                cout<<"Second employee: "<<endl;
            }

        }
}

