/*
________________________________Ultra-Modern software Development (UMD)____________________________
  Created by Hisham on 5/12/18.
  Copyright © 2018 Hisham Hussein. All rights reserved.
 
 ________________________________________Program Description_______________________________________
    Ultra-Modern software Development (UMD) a program to help air traffic controllers.Air traffic controllers have to help land planes. For the safety the airplanes should land far as match possible time between each airplane. The airplane will have start time and end time of landing. This program will ask for you to enter test case which Each test case will beon 2 lines and then will ask you how many airplane that will be landing; for each airplane you will enter the sart time and end tim of the airplane, for example if you enter 3 airlane then the input will be 0 2 0 5 0 20. After you enter the end and start time the program will do peremutation to find and calcualte the best time for each airplane to land. then it will go bakc and ask you for the second test case which will ask you for how many airplane and there start and end time
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
using namespace std;

class AirPlaneInterval{
    
public:
 
    vector<int>startTime;
    vector<int>endTime;
    vector<int>AiprplneId;
    vector<float>testingLanding;
    vector<float>tResult;
    vector<vector<float>>showAll;
    int sTime,eTime,planeCount,iD,cases,CaseCount;
    
    void loadToIntervalVector(){
        /* ----pre-condation: get the inputs from the user
           ----Post-condatin:  it pushes the id and sTime and eTime from the user to be save in vector
         */
        
        //loading the informatin to vectors to store start time, end time and id of airplanes
        AiprplneId.push_back(iD);
        startTime.push_back(sTime);
        endTime.push_back(eTime);
    
    }
    void print(){
        /* ----pre-condation: test case for airplane must be less or equal to CaseCount during incrment
           ----Post-condatin:  it prints everyting inside the vector of vector
         */
       
        
            
            for(int i = 0; i<showAll.size();i++){
                for(int x = 0; x<showAll[i].size();x++){
                    cout<<showAll[i][x]<<" ";  //print out the landing time
                }
                cout<<endl;
            }
        
    }
    
    void permutation(){

        float starttimeLocal=0,max=0,holdMax=0,min=0,endtimeLocal=0;
        int eId=0;
        
        /* ----pre-condation: do the permutation for the ideas and connected them to start and end tie
                               for each airpalne
           ----Post-condatin:  it calcualte the end time and start time for landing airplane and finding        
                               the max and min for each palne landing time and send it to function 
                               to insert the max number into vectorx
         */
        
        do{//looping through the permutation
            
            for(int i=0;i<AiprplneId.size();i++){

                starttimeLocal=startTime[AiprplneId[i]-1]; //gets the start time of landing
                endtimeLocal = endTime[planeCount-1]; //get the end time of the last airplane landing
                
                if (endTime.size()==2){ //check how many airpane to do calculation
                   endtimeLocal = endTime[AiprplneId[i]-1];
                }
                //calcualtion for landing airpalne and find their max
                testingLanding.push_back((endtimeLocal - starttimeLocal) /(planeCount-1));
                
                max =  *max_element(testingLanding.begin(),testingLanding.end());//find max
                min =  *min_element(testingLanding.begin(),testingLanding.end()); //find min

                if(testingLanding[i]>holdMax){//stor the maximum number of landing
                    holdMax = testingLanding[i];
                    eId =  AiprplneId[i];//get the permutation id
                   
                    if(holdMax>min){//check elimunate of getting the same number
                        result(eId,max,holdMax,min);  //function call to check same number
                    }
                }
            }
        }while(next_permutation(AiprplneId.begin(),AiprplneId.end()));
        

        
    }
    
    
    void result(int eid,float max,float holdMax,float min){
        /* ----pre-condation: check if maximum is grather then min so that it can minumes the repeated asnwer
         ----Post-condatin:  it pushes the id and max number to a vector of vector
         */


        if(holdMax>min){  //check the user if max is grater the min to elminate the repeated answers
            tResult.push_back(eid);
            tResult.push_back(max);
            showAll.push_back(tResult);
            CaseCount++;  //increametn for testing
        }

    }
    
    void clcear(){
        /* ----pre-condation: vectos are filled up of numbers
           ----Post-condatin:  it deletes everyting from vectore it it reset it to empty
         */
        
        //clear everything inside the tbe vectors so it can go to the next case of airlane
        testingLanding.clear();
        startTime.clear();
        endTime.clear();
        tResult.clear();
        AiprplneId.clear();
    }
    
};

int main(int argc, const char * argv[]) {
    
    int airplaine,testCase;
    AirPlaneInterval info;

    cin>>testCase;  //reades the test case
    info.cases= testCase;
    
    for(int i=0;i<testCase;i++){
 
        cin>>airplaine;//ask from how many airplane
        info.planeCount=airplaine;
        
        for(int x = 0;x<airplaine;x++){
            cin>>info.sTime>>info.eTime; //ask the user for start time and end time
            info.iD = x+1;
            info.loadToIntervalVector();   //function call to proceses
        }
        
        info.permutation(); //doing the permuation
        info.clcear(); //clear everyting
 
    }
    info.print(); //print out the result

    return 0;
    
}
