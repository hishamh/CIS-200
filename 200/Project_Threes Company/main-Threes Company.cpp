/*
  main.cpp program

    Threes Company(PDF):
                     This program jacob and edwared will go to the cave to find bella. Jacob explores each passage through the caves one by
                     one, clockwise, while Edward explores each passage through the caves one by one counter-clockwise. Each turn, both
                     Edward and Jacob try to move to a new cave. If either reach Bella (who does not move, since she is so distraught),
                     the simulation ends and Bella marries her rescuer. If they both reach her at the same time, Jacob and Edward
                     and all 3 of them die as a result.

                     To complicate matters, in some of the caves there is naturally growing wolf's bane and Jacob cannot enter those.
                     In other caves there is naturally growing garlic which Edward cannot enter. If either boy is moving towards a cave
                     with a plant they are allergic to, he turns around halfway up the passage and ends up back in the cave he just left.
                     When the simulation starts, Jacob takes the smallest numbered passage, while Edward takes the highest numbered
                     passage. After 100 turns, if no one ands Bella, everyone dies of starvation

 _________________________________________________Rules of the program_________________________________________________

    *This program the rules are very simply which are:
        1) Bella go the one of the cave and she never move from it
        2) jacob go to one of the cave that the user choose for him
        3) Edware go to one of the cave that the user choos for him
        4) Jacob keeps move from cave to another clockwise
        5) Edwared keep move from cave to other counter-clockwise
        6) The caves Edware will go might have allergic so he must check first
        7) The cave Jacob will go might have allergic so he must check first
    *Who wines rules:
        1) if Jacob meets Bella in the cave first then Bella will marry him
        2) if Edwared meet bella in the cave first then Bella will marry him
        3) if Edwared and Jacob meet Bell in the cave together then both Edwared and Jacob dies
        4) If both Edwared and Jacob can't find Bella within 100 moves, then they all dies starving to death


 ________________________________________________how the program inputs works_________________________________________________

  1) the first  line of each test case will contain 4 integers separated by a single space Example (4 1 3 2)
            -The first input in the example above (4) is the number of test case or the number of caves that will be create
                * The next 3 (1  3 2) input are the location of each actors Bella, Edward, and jacob
                * The second number (1) is the location of the cave that bella is located in cave one
                * The Third number (3) is Jacob location which is he located in cave 3
                * The fourth number (2) is where Edware located which is in cave 2.
        so in Simply the inputs are consider in This : number of caves    Bella Location    Jacob location    Edwared Location in caves;
 2) for the next inputs will consider The next n lines will specify the layout of the cave system.
    The  line of the test case  will start with 2 integers.
                * the first integer will consider the allergic which might be -1,0,1 where -1 indicates the presence of garlic in the cave
                  and 1 represents the presence of wolf's bane in the cave, while 0 represents the cave is free of allergen
                * Next will be the integer di , the degree of vertex i, followed by di integers separated by a single space,
                  which represent the caves adjacent to i in clockwise order. The test case starting with 0 0 0 0 will represent t
                  he end of input.


  Created by Hisham Hussein on 7/5/18.
  Copyright © 2018 Hisham Hussein. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct actors{
    int alrgen_flg;
    int degree;
    vector<int>edges;
    bool vistedByEdward=false;
    bool vistedByJacob=false;

};

class actorsStage{
private:
    int numOfCaves,eCurrentLocation,jCurrentLocation,bLocation,jOldLocation,eOldLocation,edj;
public:
    vector<actors>cave_system;
    void creatingCave(){

        jOldLocation = jCurrentLocation;
        eOldLocation=eCurrentLocation;
        cave_system.clear();
        cave_system.resize(numOfCaves);
        for(int x=0; x<numOfCaves;x++){     //o(n)
            //cout<<"enter allergic, and degree ";
            cin>>cave_system[x].alrgen_flg;
            cin>>cave_system[x].degree;
            for(int i =0; i<cave_system[x].degree;i++){//o(n)
                //   cout<<"edges ";
                cin>>edj;
                cave_system[x].edges.push_back(edj); //time O(n)

            }

        }

    }


    void actorsLocation(int b,int j, int e, int caveCases){

        numOfCaves = caveCases;
        eCurrentLocation=e;
        jCurrentLocation=j;
        bLocation = b;
    }


    void actor_edward(){

        int holdOldLocation;
        //checking for edware which is second location
        if(eOldLocation!=eCurrentLocation){
            //this will keep moving edwared to the next cave
            for(int i=0; i<cave_system[eCurrentLocation-1].edges.size();i++){
                if(eOldLocation==cave_system[eCurrentLocation-1].edges[i]){

                    if(i==0){  //checking if edware was in the cave and it will keep move to the next one
                        eOldLocation=eCurrentLocation;
                        eCurrentLocation=cave_system[eCurrentLocation-1].edges[cave_system[eCurrentLocation-1].edges.size()-1];
                        cave_system[eCurrentLocation-1].edges[cave_system[eCurrentLocation-1].vistedByEdward=true];//mark the new cave as visited so he wont repeat
                                                                                                                   //it and for test purpose
                        // checking if there is alrgen_flg for the  cave he is going to
                        if(cave_system[eCurrentLocation-1].alrgen_flg==-1){
                            cave_system[eCurrentLocation-1].vistedByEdward = true;
                            holdOldLocation = eOldLocation; //exchange he location to the previous one that he came from
                            eOldLocation = eCurrentLocation;
                            eCurrentLocation=holdOldLocation;
                        }
                    }
                    else{
                        eOldLocation=eCurrentLocation;
                        if(i!=0){
                            eCurrentLocation=cave_system[eCurrentLocation-1].edges[i-1];
                            // checking the allergic  for the new cave he is going to
                            if(cave_system[eCurrentLocation-1].alrgen_flg == -1){
                                holdOldLocation = eOldLocation;
                                eOldLocation = eCurrentLocation;
                                eCurrentLocation=holdOldLocation;
                            }
                        }
                        else
                            // if the cave does not contain and allergic  then put him inside the new cave
                            eCurrentLocation=cave_system[eCurrentLocation-1].edges[cave_system[eCurrentLocation-1].edges.size()-1];
                           cave_system[eCurrentLocation-1].edges[cave_system[eCurrentLocation-1].alrgen_flg= true];//markup the place he vsited as true
                    }
                    return;
                }
            }
        }

        //this is jacob second new move after edwared
        else{
            eOldLocation=eCurrentLocation;
            eCurrentLocation=cave_system[eCurrentLocation-1].edges[cave_system[eCurrentLocation-1].edges.size()-1]; //move him the the new cave
            cave_system[eCurrentLocation-1].edges[cave_system[eCurrentLocation-1].vistedByEdward = true] ; // markup the new cave as visited

            if(cave_system[eCurrentLocation-1].alrgen_flg==-1){ //checking if the cave has any allergic
                int holdOldLocation = eOldLocation;
                eOldLocation = eCurrentLocation;
                eCurrentLocation=holdOldLocation;
            }

        }
    }


    void Actor_jacob(){

        int holdOldLocation;
        //look if jacbo is still in his old location with th new location if not then skip go to the else
        if(jOldLocation!=jCurrentLocation){
              for(int i=0; i<cave_system[jCurrentLocation-1].edges.size();i++){
                if(jOldLocation==cave_system[jCurrentLocation-1].edges[i]){
                    //this will keep move jacobs to the next moves fir his fist move
                    if(i!=cave_system[jCurrentLocation-1].edges.size()-1){
                        jOldLocation=jCurrentLocation;
                        jCurrentLocation=cave_system[jCurrentLocation-1].edges[i+1];
                        if(cave_system[jCurrentLocation-1].alrgen_flg==1){//checking for allergic
                            holdOldLocation = jOldLocation;
                            jOldLocation = jCurrentLocation;
                            jCurrentLocation=holdOldLocation;
                            cave_system[jCurrentLocation-1].vistedByJacob= true;
                        }
                    }

                    else{
                        //jacob move to the next location
                        jOldLocation=jCurrentLocation;
                        jCurrentLocation=cave_system[jCurrentLocation-1].edges[0];
                        cave_system[jCurrentLocation-1].vistedByJacob= true; //markup the location he visited as true

                        if(cave_system[jCurrentLocation-1].alrgen_flg==1){//check if the place he is going has any allergic
                            holdOldLocation = jOldLocation;
                            jOldLocation = jCurrentLocation;
                            jCurrentLocation=holdOldLocation;
                        }

                    }
                    return;
                }
            }
        }

        else{
            //jacob now will get into new location
            jOldLocation=jCurrentLocation;
            jCurrentLocation=cave_system[jCurrentLocation-1].edges[0];
            cave_system[jCurrentLocation-1].vistedByJacob= true; //markup the location he visited so that he wont visited again
            if(cave_system[jCurrentLocation-1].alrgen_flg==1){ //checking if the cave he going has an allergic that will kill jacbon
                holdOldLocation = jOldLocation;
                jOldLocation = jCurrentLocation;
                jCurrentLocation=holdOldLocation;

            }
        }
    }



    void theStage(){

        int moveCount=0;
        cout<<endl;
            for( int i=0; i<100; i++){
                //if they both meet in the same cave they they will die
                if(eCurrentLocation ==jCurrentLocation){// Edwared and jacob can't be in the same cave
                    return;
                }
                 Actor_jacob(); //function to determine the move of jacob o(n)
                 actor_edward(); //function to determine the move of edwared o(n)
                 moveCount++;
                //both die if they meet in bella cave
                if(bLocation==eCurrentLocation && bLocation==jOldLocation){
                   cout<<"Everyone dies in "<<i+1<<" moves";
                    return;
                }
                else if (bLocation==jCurrentLocation){
                    //jacob will marry bella if he went to the cave first
                      cout<<"Bella marries Jacob in "<<i+1<<" moves";
                    return;
                }
                else if (bLocation==eCurrentLocation){
                    //edward will marry bella if he went to the cave first
                    cout<<"Bella marries Edward in "<<i+1<<" moves";
                    return;
                }

            }
          cout<<"Everyone dies in "<<moveCount+1<<" moves"; //everyone dies if they keep moves up 100 without meeting bella

    }
    };


int main(int argc, const char * argv[]) {

    actorsStage play;  //class
    int b,e,j,n;

    cin>>n>>b>>j>>e;   //asking for test case bella,jacob,edwared location
    while(b!=0 && e !=0 && j!=0 && n!=0){ //O(n);
        play.actorsLocation(b, j, e,n); //keeps refreing to there current location
        play.creatingCave();//setting the cave system O(n^2)
        play.theStage(); //this is the starge where every one paly the roles O(n^2)
        cin>>n>>b>>j>>e;
    }

    return 0;

}
