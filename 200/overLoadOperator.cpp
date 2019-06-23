//
//  main.cpp
//  project 2 question 1 compare two grade using the overload
//         operator and friend class. Takes two grades and
//	    compare them together
//
//  Created by Hisham on 10/29/17.
//  Copyright © 2017 Hisham Hussein. All rights reserved.
//

#include <iostream>

using namespace std;
class Teacher;


class Student{

private:

    int FinalGrade;
    int Id;
    float Grade[4];
public:
    Student(){
        FinalGrade = 0;  //defaulted constrictor
        Id = 0;

        for(int i=0;i<4;i++){
            Grade[i]=0;
        }
    }

    Student(const Student &x){

        for(int i=0;i<4;i++){
            Grade[i]= x.Grade[i];
        }
    }

    void setId(int x){
        Id = x;
    }
    void setGrade(float Grades[]){ //sets the grades to Grade[4]
        for(int i=0;i<4;i++){
            Grade[i]= Grades[i];
        }

    }
    //overload operator
    bool operator ==(Student &x){  //check if the student x is equal to student y
        if(FinalGrade == x.FinalGrade){
            return true;
        }else{
            return false;
        }
    }

    friend class Teacher;  //class friend of Student

};//End of Student class

class Teacher{

private:
    int id;
    float salary;
public:

    Teacher(){
        salary =0.0;
        id = 0;
    }
    void calculateGrade(Student &x){
        x.FinalGrade=x.Grade[0]+x.Grade[1]+x.Grade[2]+x.Grade[3];
    }
};//end of teacher class

int main(int argc, const char * argv[]) {


    float g1[] = {10.0, 20.0, 25.0, 25.0};
    float g2[] = {25.0, 20.0, 10.0, 25.0};

    Student x, y;

    x.setGrade(g1);  //send the array
    y.setGrade(g2);  //send the array

    Student w(x);
    Student v;
    v = y;

    Teacher z;
    z.calculateGrade(x);
    z.calculateGrade(y);

    //check if student A equal to student Y
    if(x==y)
        cout << " Students x and y have the same grade !"  << endl;
    else
        cout << " Students  x and y don’t have the same grade !"  << endl;


    return 0;
}
