//  main.cpp
//  assignment 1 question 2
//  make and array class with 2d where you add and find
//  the average of age and salary of all employees
//
//  Created by Hisham on 10/8/17.
//  Copyright © 2017 Hisham Hussein. All rights reserved.
//

#include <iostream>
using namespace std;


class Employee
{
private:
    int age;
    int id;
    float salary;
public:
    Employee( );  // default constructor: age=0, id=0, and salary=0

    void setAge(int x){ //sets age to Age number entered by user
        age = x;
    }
    void setId(int x){//set id to that entered by user
        id = x;
    }
    void setSalary(float x){//set salary to the value entered by user
        salary = x;
    }


    int getAge( );        // return age
    int getId( );            // return id
    float getSalary( );  //  return salary

};

Employee::Employee(){
    age = 0;
    id = 0;
    salary = 0.0;

}

int Employee::getAge(){ //return age
    return age;
}
int Employee::getId(){//return id
    return id;
}
float Employee::getSalary(){//return salary
    return salary;
}

//function prototype
void PrinteEmployee(Employee[][3], int,int );

int main(int argc, const char * argv[]) {


    Employee x[2][3];
    int row=2,column=3;
    //set the values for employees 1
    x[0][0].setAge(40);
    x[0][0].setId(111);
    x[0][0].setSalary(40000);

     //set the values for employees 2
    x[0][1].setAge(41);
    x[0][1].setId(112);
    x[0][1].setSalary(41000);

     //set the values for employees 3
    x[0][2].setAge(42);
    x[0][2].setId(113);
    x[0][2].setSalary(42000);

     //set the values for employees 4
    x[1][0].setAge(43);
    x[1][0].setId(114);
    x[1][0].setSalary(43000);

     //set the values for employees 5
    x[1][1].setAge(44);
    x[1][1].setId(115);

    x[1][1].setSalary(44000);
    //set the values for employyes 6
    x[1][2].setAge(45);
    x[1][2].setId(116);
    x[1][2].setSalary(45000);

    //function call
    PrinteEmployee(x,row,column);

    return 0;
}

void PrinteEmployee(Employee x[][3], int row,int column){

    int avgAge=0,totalAge=0;
    float avgSalary=0.0,totalSalary=0.0;
    //it will keep loop depends on the
    for(int i = 0;i<row;i++){
        for(int j = 0;j<column;j++){
            //prints out the age, id, and salary of every employee
            cout<<"Age: "<<x[i][j].getAge()<<endl;
            cout<<"Id: "<<x[i][j].getId()<<endl;
            cout<<"Salary: "<<x[i][j].getSalary()<<endl;

            totalAge = totalAge+ x[i][j].getAge(); //adding all the ages
            totalSalary = totalSalary+ x[i][j].getSalary(); //adding all salary
        }

    }
    avgAge = totalAge / 6; //calculating the age average
    avgSalary = totalSalary / 6; //calculating the salary average

    //print out the result
    cout<<"The average age is "<<avgAge<<endl;
    cout<<"The average salary is "<<avgSalary<<endl;
}
