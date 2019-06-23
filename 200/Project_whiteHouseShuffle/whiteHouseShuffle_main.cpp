/*main.cpp

 White House Shue:
    This program sumlaite the process of Presidential campaigns where a President can hire staff to help him get elected.
    Moreover, each staff can hire people to work for them. For example if YOU hire A,B,C to work for you; 'A' can hire D,E
    to work for him. Also The President can fire people who work for him, For example President TR can Fire A,B,C. And 'A'
    Fire D,E

 ______________________________________________Rules of Firing staff(from PDF)____________________________________________

 If the victim (the person who gets red) had no subordinates, then he or she will simply be dropped from the white
 house's hierarchy. If the victim had any subordinates, then his or her highest-ranking (by seniority) direct subordinate
 will be promoted to ll the resulting vacancy.The promoted person will also inherit the victim's seniority. Now,
 if the promoted person also had some subordinates, then his or her highest-ranking direct subordinate will
 similarly be promoted, and the promotions will cascade down the hierarchy until a person having no subordinates has been
 promoted

    ________________________________________________how the program works_________________________________________________
    You have Tree commands to remember which are Hire,Fire,Print
    -if you want to Hire someone then you need to to write command -->[Existing member] hires [new member]
    -If you want to Fire someone then you need to write command -->Fire [existing member])
    -If you want to Print the current employee hierarchy then you need to write command -->Print
    -If you want to exit from the program then you need to write command -->Quit



  Created by Hisham on 6/3/18.
  Copyright © 2018 Hisham Hussein. All rights reserved.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct WhiteHouse{//struct that holds string name for the bosses and vector of namesInclude that holds the worker
    string name;
    vector<WhiteHouse*>namesInclude; //holds worker
    WhiteHouse *next; //pointed to the next child or as parent child...only this one was create so that i can delete them
};

class hiringFiringProcess{

private:

    void privateHireWhiteHouse(string boss,string employee){

        WhiteHouse *isFoundRoot = findFirst(root, boss);//it search inside the root if it has the boss name

        if(isFoundRoot != nullptr){ //if the root has something then it will run the if statement
            WhiteHouse *worker = new WhiteHouse;  //create new pointer of WhiteHouse O(1)
            worker->name = employee; //assigning worker name inside the worker root name O(n)
            isFoundRoot->namesInclude.push_back(worker); //pushing the worker information and child to the root
            worker->next= isFoundRoot; //go to the next object
        }
    }


    WhiteHouse *findFirst(WhiteHouse* ptr, string target) {

        WhiteHouse * findingResult;

        if(ptr == nullptr){ //check if ptr is nullptr empty
            return nullptr;
        }else if(ptr->name == target) { //if ptr name is same as the target name then return root ptr
            return ptr;
        }else{
            //the loop will keep loops on the namesInclude vector recursively to find the target name on the vectors
            for(int i=0; i<ptr->namesInclude.size();i++){
                findingResult = findFirst(ptr->namesInclude[i], target);//
                if(findingResult != nullptr){//it will only return non nullptr result which they have all the names
                    return findingResult;
                }
            }

            return nullptr;
        }
    }

    void privateFire(WhiteHouse *ptr){

        if(ptr -> namesInclude.size()!= 0){ //if he vector is not empty then the code will run
            privateFire(ptr->namesInclude[0]);//recurisvely take the first child
            ptr->namesInclude[0]->namesInclude.resize(ptr->namesInclude.size());//resize the current ptr after the child begin deleted
            for(int i=1;i<ptr->namesInclude.size();i++){ //run the loop depends on the size of the vector
                ptr->namesInclude[0]->namesInclude[i]= ptr->namesInclude[i]; //reassign and orginzeing the name
            }
        }else{
            return;
        }

        if(ptr->namesInclude[0]->namesInclude[0]==nullptr){ //if the name of root and the children is null ptr
            ptr->namesInclude[0]->namesInclude.erase(ptr->namesInclude[0]->namesInclude.begin()); //then erase the node
        }
    }

    void privetActuallyfire(string name){

        WhiteHouse *fireing = findFirst(root, name);//finding the name in the root to fire  ()
        int index=-1;

        if(fireing !=nullptr){//if Fireing returning from finding not null then it will reutn privateFire(Fire)
            privateFire(fireing);//if return something the it will run the fire command in the privateFire() function
        }

        if(fireing->next == nullptr){//if the next of parent c is null ptr then delete it
            root = fireing->namesInclude[0];//deleting the child in next parent
            delete fireing;
            return;
        }

        for(int i=0;i<fireing->next->namesInclude.size();i++){//if keeps loop depends on what inside next
            if(fireing->next->namesInclude[i]->name == fireing->name){ //if names are in there next equal to the name in fireing
                index = i;
            }
        }

        if(!fireing->namesInclude.empty()){//if size is not equal zero then
            fireing->next->namesInclude[index]= fireing->namesInclude[0]; //replacing names in next to the first name in firing root includes names
            fireing->namesInclude[0]->next = fireing->next;
        }else{

            fireing->next->namesInclude.erase(fireing->next->namesInclude.begin()+index);//earase that extra nodes

        }
            delete fireing;//delete the node
    }

    void privatePrint(WhiteHouse *ptr,int treeDeepth){

        for(int i =0; i<treeDeepth;i++){//print the depth of the tree
            cout<<"+";
        }
        cout<<ptr->name<<endl;//print the name inside the tree
        for(int i=0; i<ptr->namesInclude.size();i++){
             privatePrint(ptr->namesInclude[i], treeDeepth+1);

        }
    }


public:
    WhiteHouse * root=nullptr;
     int treeDepth = 0;

    hiringFiringProcess(string boss){ //constructor that will only runes onces so that it can create the president
        root = new WhiteHouse;//create new node
        root->name = boss; //assign the new node a boss
    }

    void publicHireWhiteHouse(string boss,string target){//this call the private hiring for the white house
        privateHireWhiteHouse(boss,target); //private function calll
    }

    void publicFire(string name){
        privetActuallyfire(name);
    }

    WhiteHouse *findFirst(string target) {
        return findFirst(root, target);
    }

    void publicPrint(){
        privatePrint(root,treeDepth);//function call
    }

};


int main(int argc, const char * argv[]) {

    string boss,worker,worker2,userHire;

    cin>>boss;//ask the user for the leader or prsident
    hiringFiringProcess whiteH(boss);//creat first roo

    do{
        if(boss =="Fire"){
            cin>>worker;
            whiteH.publicFire(worker);//function call
        }else if(boss =="Quit"){
            exit(0);
        }else if(boss =="Print"){
            whiteH.publicPrint();//function call

        }else{
            cin>>userHire;
            cin>>worker2;
            worker = worker2;
            whiteH.publicHireWhiteHouse(boss, worker);//function call
        }
        cin>>boss;
    }while(boss !="Quit");

    return 0;
}
