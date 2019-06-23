//
//  main.cpp
//  project 2 Question 2
//  this will teach us how to open a file and make insert
//  ,delete,look,check if full to an array that can be
//  change the size and
//
//  Created by Hisham on 11/5/17.
//  Copyright © 2017 Hisham Hussein. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;


#define MAX_ITEMS  10
typedef   float  ItemType;

class SortedList
{
private:
    int length;
    ItemType values[MAX_ITEMS];
    int currentPos;
public:
    SortedList(){
        length =0;
        currentPos = -1;
    }// default constructor: length=0, currentPos=-1
    void MakeEmpty(){
         length = 0;
    }// let length=0

    void InsertItem(ItemType x){

        bool moreToSearch;
        int location =0;
        moreToSearch = (location < length);
        while(moreToSearch){

            if(x<values[location]){ //trying to search and look for to be inserted
                moreToSearch = false;
            }else{

                location++;
                moreToSearch = (location<length);
            }

        }//end of while

        for(int i = length; i>location;i--){

            values[i]= values[i-1];
        }
        values[location] = x;
        length++;

    }// insert x into the list

    void DeleteItem(ItemType x){
        int location;
        //keeps loop till the value x is equal the value of the found location
        for(location=0;location<length;location++){
            if(x==values[location]){
                break;
            }
        }
        for(int i=location+1;i<length;i++){ //organize the order
            values[i-1]= values[i];
        }
        length--;

    }// delete x from the list

    bool IsFull( ){

        if (length == MAX_ITEMS){
            return true;
        }else{
            return false;
        }
    }   // test if the list is full

    int Lengthls( ){
        return length;
    }//return length

    void RetrieveItem(ItemType &x, bool &found){

        int midPoint, first = 0, last = length-1;

        bool moreToSearch =(first<=last);
        found = false;

        while(moreToSearch && !found){

            midPoint = (first+last)/2;

            if(x<values[midPoint]){

                last = midPoint-1;
                moreToSearch = (first<= last);

            }
            else if (x>values[midPoint]){
                first = midPoint+1;
                moreToSearch = (first<= last);

            }else{

                x=values[midPoint];
                found = true;
            }//end of if and if else


        }//end of while

    }// retrieve x from the list, the Boolean result is stored in found

    void ResetList( ){
          currentPos = -1;

    }// currentPos=-1

    void GetNextItem(ItemType &x){

        currentPos++;
        x=values[currentPos];
        cout<<x<<endl;

    }// get the next element from the list with respect to the currentPos

};
int main(int argc, const char * argv[]) {


    SortedList list;
    int choose;

    ifstream inPut("float.txt");//open the fold for reading

    float values,retrive,deleteNum,insertNum;
    bool found;

    //reading the list from the file insert it into the array
    for(int i=0;i<10;i++){
        inPut>>values;
        list.InsertItem(values);
    }//end of for loop
    list.ResetList();

    do{
        //let the user choose from the option which will make it easy
        cout<<"\n1) Sort the list for me";
        cout<<"\n2) Delete number from the list";
        cout<<"\n3) Inser number to the list";
        cout<<"\n4) Check if the list is full";
        cout<<"\n5) Look for a number";
        cout<<"\n6) Delete everything in the list";
        cout<<"\n7) Save the numbers to the file";
        cout<<"\n8) Quit";
        cout<<"\n*) Choose ==>: ";
        cin>>choose;

        switch (choose) {
            case 1:
                list.ResetList();
                cout<<"\nDisplay the sorted list\n";  //this only show and sorting the list
                for(int i=0;i<list.Lengthls();i++){
                    list.GetNextItem(values);
                }//end of for loop

                break;
            case 2:
                //deleting the number from the list which will be entered by the user
                cout<<"\nEnter the number you want to delete: ";
                cin>>deleteNum;

                list.ResetList();
                list.DeleteItem(deleteNum);

                //printing the list again with ordered
                for(int i=0;i<list.Lengthls();i++){
                    list.GetNextItem(values);
                }//end of for loop

                break;
            case 3:
                 list.ResetList();
                if(list.IsFull()){
                     cout<<"\n\nThe list is full\n\n";
                }else{

                    cout<<"\nEnter the number you want to insert:";
                    cin>>insertNum;
                    list.InsertItem(insertNum);

                    //print the list again after editing it
                    for(int i=0;i<list.Lengthls();i++){
                        list.GetNextItem(values);
                    }//end of for loop
                }
                break;
            case 4:
                //check if the list is full of every time the user delete or insert number
                //if the list is not then it will go to else
                list.ResetList();
                if(list.IsFull()==true){
                    cout<<"\nThe array is full\n";
                }else{
                    cout<<"\nThe array is not full\n";
                }
                break;
            case 5:
                //searching the number by the number it was entered by the user
                cout<<"\nEnter the number you want to search: ";
                cin>>retrive;
                //reset list so that we can check the information
                list.ResetList();
                list.RetrieveItem(retrive, found);
                //if the number found then it will display true and found if not then
                //it will go to else
                if(found==true){
                    cout<<"\nThe number " <<retrive<<" is found in the list\n";
                }else{
                    cout<<"\nThe number " <<retrive<<" is not found in the list\n";
                }

                break;
            case 6:
                //if the user want to delete the whole file and start new numbers
                list.MakeEmpty();
                list.ResetList();
                cout<<"\n\nThe list is empty: \n";
                //print the list again with orzinized number
                for(int i=0;i<list.Lengthls();i++){
                    list.GetNextItem(values);
                }//end of for loop
                break;
            case 7:
            {
                //this will safe any changes happen to the list to a file
                 ofstream outPut("output.txt"); //create file
                list.ResetList();
                cout<<"\nThe Inofrmation been saved \n";
                //print the list again
                for(int i=0;i<list.Lengthls();i++){
                    list.GetNextItem(values);
                    outPut<<values<<endl;
                }//end of for loop
                inPut.close(); //close file
                outPut.close(); //close file
            }
                break;
            case 8:
                //exit the program
                cout<<"\nHave nice day\n";
                exit(0);
                break;
            default:
                //if the user choose wrong option
                cout<<"\nYou choose the wrong option\n";
                break;
        }

    }while(choose!=-1);

       return 0;
}
