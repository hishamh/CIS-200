/*
  main.cpp
  lab 4 question 2
  Create an class which will take an array that will ask the user
  For information out o the screen

  Created by Hisham on 10/8/17.
  Copyright © 2017 Hisham Hussein. All rights reserved.
*/

#include <iostream>
using namespace std;


class Employee
{
private:
    int age;
    int id;
    float salary;
public:
    void setAge(int x); //takes age
    void setId(int x); //takes id
    void setSalary(float x); //takes salary
    int getAge( ); //return age
    int getId( ); //return id
    float getSalary( ); //return salary
};


int Employee::getAge(){ //return age
    return age;
}
int Employee::getId(){//return id
    return id;
}
float Employee::getSalary(){//return salary
    return salary;
}

void Employee::setAge(int eAge){ //sets age to eAge number enter by user
    age = eAge;
}
void Employee::setId(int eId){//set id to eId entered by user
    id = eId;
}
void Employee::setSalary(float eSalary){//set salary to the value entered by user
    salary = eSalary;
}

void PrintEmployee(Employee [],int);//function


int main(int argc, const char * argv[]) {


    Employee emp[2]; //array
    int length =2;

    //sets the information
    emp[0].setAge(30);
    emp[0].setId(30042554);
    emp[0].setSalary(50000.00);
    emp[1].setAge(45);
    emp[1].setId(40041002);
    emp[1].setSalary(70000.00);


     PrintEmployee(emp,length  ); //function call

    return 0;
}

void PrintEmployee(Employee emp[], int length ){
    //print employee inforamtion to employees
    cout<<"\nFirst employee: "<<endl;
    for(int i = 0; i<length;i++){
        cout<<"Age for employee: "<<emp[i].getAge()<<endl;  //prints age
        cout<<"Id: "<<emp[i].getId()<<endl; //prints id
        cout<<"Salary: "<<emp[i].getSalary()<<endl; //prints salary
        if(i==0){
            cout<<"Second employee: "<<endl;
        }
    }//end of loop

}
