/*
 Hisham  Hussein
 CIS 306-Online student

 Program 1:
    To wirte lexive program that convet to c-- language by reading a file
    and  finding the indenfier keyword,token, and attrubite and at the end
    output the result to Output.txt.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

void findKeyWord(string);
void findNumAttrubit(string);
void findToken(string);
string stripOfComments();
ofstream myWords("Output.txt");
ifstream readFile("remove.txt");
vector<string>saveKeyWord;
vector<double>ItsNumber;


int main(int argc, const char * argv[]) {

    string source;
    //function call
    source = stripOfComments();//removing comments from source code
    findKeyWord(source);//find keyword
    findNumAttrubit(source);//find attrbuit
    findToken(source);//find token
    myWords.close(); //close file
    readFile.close(); //close file
    cout<<"\"Output.txt\" been created(check your folder)"<<endl;
    return 0;
}

string stripOfComments(){
    string source;


    myWords<<"\t    Removing off comments"<<endl;
    myWords<<"---------------------------------------------"<<endl;
    getline(readFile, source, '\0');
    while(source.find("/*") != std::string::npos) {//find the mutipl commetns that strart with /*
        size_t Beg = source.find("/*");
        source.erase(Beg, (source.find("*/", Beg) - Beg)+2); //and goest to the through everyting that between */ and delete it
    }
    myWords<<source;
    myWords<<endl<<endl<<endl<<endl;
    return source;
}
void findKeyWord(string source){
    string keyWords[] = {"if","else","void","true","false","return","float","int","while","main"};


    myWords<<"Key Word\t\t\t\tIndex"<<endl;
    myWords<<"---------------------------------------------"<<endl;
    //cout<<"Key Word\t\t\t\tFound"<<endl;
    for(int x=0;x<=9;x++){
        string wordLook = keyWords[x];//assign wordLook for the word we want to look for
        string::size_type keyWordFound = source.find(wordLook);//look for the word in our source code
        while (keyWordFound != string::npos)//keeps loop for evey single letters in source code
        {
            keyWordFound = source.find(keyWords[x], keyWordFound + 1);//will keep go to the next one

            if(saveKeyWord.empty()){//first we check if our vector has something saved so that we do not repeat word again
                saveKeyWord.push_back(keyWords[x]); //insert if the vector is empty
            }else{
                for(int j=0;j<saveKeyWord.size();j++){//loops through the vector and check if a word reserve is  already found on the saveKyeword
                    if(find(saveKeyWord.begin(), saveKeyWord.end(), keyWords[x]) != saveKeyWord.end()){
                        //do noting just skip
                        //if not saved in the keyWord then
                    }else{
                        saveKeyWord.push_back(keyWords[x]);//we inset the to the vectory of new saved keyWords
                    }
                }
            }
        }
    }
    //myWords<<endl<<endl;
    //printing out the result
    for(int i =0;i<saveKeyWord.size();i++){
        //cout<<saveKeyWord[i]<<"\t\t\t\t\t   "<<i<<endl;
        myWords<<saveKeyWord[i]<<"\t\t\t\t\t   "<<i+1<<endl;
    }
}
void findNumAttrubit(string source){

    string onGoString;
        readFile.seekg(0, ios_base::beg); //reads the file again after it already hit the last line eof

        while(!readFile.eof()){

            readFile>>onGoString;
 //           cout<<onGoString<<endl;
            size_t i;
            for ( i=0; i < onGoString.length(); i++ ){//this will keep look on the string and
                if ( isdigit(onGoString[i]) ) //it figure it out if a string is a digit, if it is digit then it will break
                    break;
            }

            onGoString = onGoString.substr(i, onGoString.length() - i ); //we subtract from the string so we can get a number

            if(onGoString.empty()){//sometime we need to check if a string is empty becaue we cannot convert empty string to a number

            }else{
                 double myFloa = stod(onGoString.c_str());//convert string to double
                 int id = atoi(onGoString.c_str());//convet string with integers

                if(id>0 || myFloa>0){//we only need to insert values that is greter then zero/
                    if(int(myFloa) != myFloa){//checking if the giving number is float or not to get its attrbuit
                        ItsNumber.push_back(myFloa);//inset if a number is float
                    }
                    ItsNumber.push_back(id);
                }
            }
        }

        //prining out the result
    myWords<<endl<<endl;
    myWords<<"NUM\t\tIndex\t\tAttribute"<<endl;
    myWords<<"-----------------------------------------"<<endl;
    //cout<<endl<<endl;
    //cout<<"NUM\t\tIndex\t\tattrbuite"<<endl;
    for(int i=0;i<ItsNumber.size();i++){
        myWords<<ItsNumber[i]<<"\t\t"<<i+1;
        //cout<<ItsNumber[i]<<"\t\t"<<i+1;
        if(int(ItsNumber[i]) != ItsNumber[i]){
            //cout<<"\t\tFloat"<<endl;
            myWords<<"\t\tFloat"<<endl;
        }else{

            myWords<<"\t\tInteger"<<endl;
            //cout<<"\t\tInteger"<<endl;

        }
    }
}

void findToken(string source){

    readFile.seekg(0, ios_base::beg); //reads the file again after it already hit the last line eof
    string tokenWords[] ={"gcd","output","input","u","v","x","y","s"};
    vector<string>saveToken;

    myWords<<endl<<endl;
    myWords<<"\nToken\t\tClass\t\tIndex"<<endl;
    myWords<<"-------------------------------------"<<endl;
    for(int x=0;x<8;x++){
        string wordLook = tokenWords[x];//assign wordLook for the word we want to look for
        string::size_type keyWordFound = source.find(wordLook);//look for the word in our source code
        while (keyWordFound != string::npos)//keeps loop for evey single letters in source code
        {
            keyWordFound = source.find(tokenWords[x], keyWordFound + 1);//will keep go to the next one

            if(saveToken.empty()){//first we check if our vector has something saved so that we do not repeat word again
                saveToken.push_back(tokenWords[x]); //insert if the vector is empty
            }else{
                for(int j=0;j<saveToken.size();j++){//loops through the vector and check if a word reserve is  already found on the saveKyeword
                    if(find(saveToken.begin(), saveToken.end(), tokenWords[x]) != saveToken.end()){
                        //do noting just skip
                        //if not saved in the keyWord then
                    }else{
                        saveToken.push_back(tokenWords[x]);//we inset the to the vectory of new saved keyWords
                    }
                }
            }
        }
    }

    int x=0;

    //printing out the result
    for(int i =0;i<saveToken.size();i++){
        x++;
        myWords<<saveToken[i]<<"\t\tid\t\t"<<i+1<<endl;
    }

    for(int i=0;i<saveKeyWord.size();i++){
        x++;
        myWords<<saveKeyWord[i]<<"\t\tkw\t\t"<<x<<endl;
    }

    for(int i=0;i<ItsNumber.size();i++){
        x++;
        myWords<<ItsNumber[i]<<"\t\tnum\t\t"<<x<<endl;
    }
}





























