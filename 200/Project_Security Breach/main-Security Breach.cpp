/*
  Program 4 warehouse thief

 **************************Software description (PDF):*****************************
 There is a shipment of exotic gems, gold, and movie snacks in a warehouse
    where you are helping your  best in stealing good of boxes whiteout out alerting
    the security cameras. The shipment is stored in large cubical crates, all of which
    have identical dimensions. These crates are stacked in neat piles, forming a
    three-dimensional grid. The security system takes pictures of the piles once
    every hour using three cameras: a front camera, a side camera, and a top camera.
    The front camera shows the height of the tallest pile in each column, the side
    camera shows the height of the tallest pile in each row, and the top camera
    shows whether or not each pile is empty.

 If the security system detects a change in any of these images, it sounds an alarm.
     Once Butch is inside, he will determine the heights of the piles and send them
     to you. Butch wants to steal as many crates as possible. Since he can’t
     disable the security system, he plans to fool it by arranging the remaining
     crates into piles so that the next set of camera images are the same.
     In the above example, it is possible to steal nine crates. The post-heist
     figure shows that the cameras will detect an identical configuration.

 **********************************Program rules********************************
 1)	Rows and number can be between 1 to 100 for each row and column
 2)	Each of the following r lines contains c integers, indicating the heights (in crates) of the piles in the corresponding row
 3)	All heights for the row is between 0 and 109

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct crate{
    bool take;
    int num;
    int dim;

    crate(){
        take=true;
        num=0;
        dim = 0;
    }
};

class cameraView{
public:

    vector<vector<crate> >all_cameraViews;
    vector<crate>allGrides;
    vector<crate>frontvies;
    vector<crate>sideView;

   //this will make max number in sideview camera as false so that we don't touch max number
    void sideViewTaken(){

        //loop through the rows to find the max number and market as false so that we do not touch it later
        for(int i =0;i<all_cameraViews.size();i++){
            findMaxSideView(i)->take=false;
        }
    }


    void frontViewTaken(){

        //loop through the columns to get the max number and market as false as identify not to touch it
        for(int i =0;i<all_cameraViews[0].size();i++){

            findMaxFrontView(i)->take=false; //mark the max as false so that we do not touch it latter on
        }
    }

    crate * findMaxFrontView(int col){

        //gets the first number in column
        int max=all_cameraViews[0][col].num,index=0;
        crate mx;
        for(int i =1;i<all_cameraViews.size();i++){
            //compare if the current max is less then then the next column, and if it greater
            if(max<all_cameraViews[i][col].num) { //max will be replace by new found max
                max = all_cameraViews[i][col].num;
                index = i; //update the index of the current found max to be send the location another func

            }
        }
        mx.num=max;
        mx.dim = index;
        frontvies.push_back(mx); //push_back the found max to the frontviees
        return &all_cameraViews[index][col];
    }

    crate * findMaxSideView(int row){

        int max=all_cameraViews[row][0].num,index=0;
        crate mx;
        for(int i =1;i<all_cameraViews[row].size();i++){
            //combare if the current max is less then then the next column, and if it greater
            if(max<all_cameraViews[row][i].num) {
                max = all_cameraViews[row][i].num; //max will be replace by new found max
                index = i; //update the inex of the current found max to be send the location another func

            }

        }
        mx.dim = index;
        mx.num=max;
        sideView.push_back(mx);
        return &all_cameraViews[row][index];


    }

    void pushBackVector(int x){

        crate temp;
        for(int j=0;j<x;j++){
            cin>>temp.num;   //reads user input
            allGrides.push_back(temp); //push it back to vector of grades
        }

        all_cameraViews.push_back(allGrides); //the the information of vector for each row
        allGrides.clear(); //clear the vector so that we can save new row on it
    }

    void swapMartix(){

        for( int i = 0; i<all_cameraViews.size();i++){

            for( int j = 0; j<all_cameraViews[i].size();j++){
                //will only runs  if on values that greate then zero
                if(sideView[i].num==frontvies[j].num && all_cameraViews[i][j].num !=0){

                    //it will solve tie probem and will assign dim of two number in different column and row
                    if(sideView[i].dim !=-1 && frontvies[j].dim !=-1){

                        //swapping the position and change the turn or false for max when they move to
                        //new position
                        all_cameraViews[i][sideView[i].dim]=all_cameraViews[i][j];
                        all_cameraViews[i][j]=all_cameraViews[frontvies[j].dim][j];
                        all_cameraViews[frontvies[j].dim][j].take = true;
                        all_cameraViews[i][sideView[i].dim].take = true;
                        all_cameraViews[i][j].take=false;
                        sideView[i].dim =-1;
                        frontvies[j].dim=-1;
                    }

                }

            }

        }
    }

    int topView(){

        int total=0;
        for(int i =0;i<all_cameraViews.size();i++){
            for(int j=0;j<all_cameraViews[i].size();j++){
                if(all_cameraViews[i][j].take==true && all_cameraViews[i][j].num>1){
                    total+=all_cameraViews[i][j].num-1; //subtract the answers
                    all_cameraViews[i][j].num=1; //just for test purpose
                }
            }

        }

        return total; //return the total
    }

};

int main(int argc, const char * argv[]) {

    int rows,column,amtSteal;
    cameraView thef;

    cin>>rows>>column;  //ask the user for number of rows and column

    for(int i=0;i<rows;i++){

        if(column>100 || rows>100){//check if the rows and column are grater then 100 then it will exit
            exit(0);
        }else{

        thef.pushBackVector(column); //function to get the grids from the user
        }
    }
    thef.sideViewTaken();  //find the max and mark it as false
    thef.frontViewTaken(); //find the max and mark it as false
    thef.swapMartix();  //doing the swap
    amtSteal = thef.topView(); //solving the problem
    cout<<endl;
    cout<<amtSteal<<endl;   //result

    return 0;
}
