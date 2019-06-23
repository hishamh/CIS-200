#include <iostream>

using namespace std;




class Vehicle{

    public:
        Vehicle(); //constructor
        int age;
        float price;

        void setAge(int); //function to set the age of the car
        void setPrice(float); //function to set the price of the car

        int getAge();      //return the car age
        float getPrice();  //return the car age
};
Vehicle::Vehicle(){

    age = 0;
    price = 0.0;

}

class Car : public Vehicle {

    public:
        Car();
        void setRaceCarStatus(bool); //function to set if the car is race or not of the car
        string getRaceCarStatus(); //return if the car is race type or not
    private:
        bool RaceCarStatus; //boolean only return 0 or 1

};

class Truck : public Vehicle{
    public:
        Truck();
        void setDieselTypeStatus(bool);// function that check if the Truck is diesel type or not
        string getDieselTypeStatus();//this will return 0 or 1 of the diesel
    private:
        bool DieselTypeStatus; //boolean only return 0 or 1
};

Car::Car(){
    RaceCarStatus = false;
}

Truck::Truck(){
    DieselTypeStatus = false;
}

//------------------------start of getter___________________________

int Vehicle::getAge(){
    return age;
}

float Vehicle::getPrice(){
    return price;
}

string Car::getRaceCarStatus(){
    /*
        compare if the car is a race type of boolen. if its 0 then it is not then
        it will return 0 if it is then it will return 1
    */
    if(RaceCarStatus == false){
      return "No";
    }else
        return "Yes";
}
string Truck::getDieselTypeStatus(){
    /*
        compare if the Truck diesel if Truck run on gas
        if its 0 then it is Diesel if not then it will return Gas
    */
    if(DieselTypeStatus == false){
        return "Diesel";
    }else
        return "Gas";
}

//------------------------start of setter___________________________
/*
 sets the values of what the user enters to the orginal vairables
*/
void Vehicle:: setAge(int vAge){

    age = vAge;
}
void Vehicle::setPrice(float vPrice){
    price = vPrice;
}
void Car::setRaceCarStatus(bool cRaceStatus){

    RaceCarStatus = cRaceStatus;
}
void Truck::setDieselTypeStatus(bool tDieselTypeStatus ){

    DieselTypeStatus = tDieselTypeStatus;
}






int main(int argc, const char * argv[]) {

    //________________________Values for vehicle_______________________________
    //display the initial value
    Vehicle x;
    cout << "Initial value for x: " << endl;
    cout << "Age = " << x.getAge() << " Price= " << x.getPrice() << endl;

    //sets the information that we want to show or display on the screen
    x.setAge(40);
    x.setPrice(20000);
    cout << "Modified value for x: " << endl;
    cout << "Age = " << x.getAge() << " Price= " << x.getPrice() << endl<<endl;

    //____________________________Values for Car_______________________________
    //display the initial value
    Car y;
    cout<<"Initial value for y: "<<endl;
    cout << "Age = " << y.getAge() << " Price= " << y.getPrice() <<" Race car status = "<<y.getRaceCarStatus() << endl;

    //sets the information that we want to show or display on the screen
    y.setAge(20);
    y.setPrice(15000);
    y.setRaceCarStatus(true);
    cout << "Modified value for y: " << endl;
    cout << "Age = " << y.getAge() << " Price= " << y.getPrice()<<" Race car status = "<<y.getRaceCarStatus() << endl;

     //____________________________Values for Truck_______________________________
     //display the initial value
    Truck z;
    cout<<"\n\nInitial value for z: "<<endl;
    cout << "Age = " << z.getAge() << " Price= " << z.getPrice() <<" Disel type = "<<z.getDieselTypeStatus() << endl;

    //sets the information that we want to show or display on the screen
    z.setAge(8);
    z.setPrice(700000);
    z.setDieselTypeStatus(true);
    cout << "Modified value for z: " << endl;
    cout << "Age = " << z.getAge() << " Price= " << z.getPrice()<<" Disel type = "<<z.getDieselTypeStatus() << endl;

    return 0;
}
