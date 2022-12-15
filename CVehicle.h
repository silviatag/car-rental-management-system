#include <iostream>
#include <string.h>
#ifndef CVEHICLE_H //to avoid trouble when including this header file in the CBus header file
#define CVEHICLE_H
using namespace std;


class CVehicle
{   private:
      //data members
      int Car_Number; //THE CAR NUMBER
      string Car_Brand; //THE CAR BRAND
      string Car_Model; //THE CAR MODEL
      string Car_Type; //THE CAR TYPE
      float Car_Price; //CAR PRICE

      bool Rented; //RENTED OR NOT
      string Rented_Name; //RENTED BY WHO
      string Rented_Time; //WHEN WAS IT RENTED
      string Return_Time; //WHEN WILL IT BE RETURNED
      

  public:
      //constructor
    CVehicle()
    {
     //initializing all data members to zero and NULL
     Car_Number = 0;
     Car_Brand.clear();
     Car_Model.clear();
     Car_Type.clear();
     Car_Price = 0;
     Rented = 0;
     Rented_Name.clear();
     Rented_Time.clear();
     Return_Time.clear();
    }

    //SETTERS
    //to set individual private data members
    void setCar_number(int number){
        Car_Number = number;                  
    }
    
    void setCar_brand(string brand){
        Car_Brand = brand;
    }
    
    void setCar_model(string model){
        Car_Model = model;
    }
    
    void setCar_type(string type){
        Car_Type = type;
    }

    void setCar_price(float price){
        Car_Price = price;
    }
    
    void setRented(bool rent){
        Rented = rent;
    }
    
    void setRented_name(string name){
        Rented_Name = name;
    }

    void setRented_time(string time){
        Rented_Time = time;
    }

    void setReturn_time(string time){
        Return_Time = time;
    }

    //GETTERS
    //to display individual private data members
    int getCar_number(){
        return Car_Number;                  
    }

    string getCar_brand(){
        return Car_Brand;
    }

    string getCar_model(){
        return Car_Model;
    }

    string getCar_type(){
        return Car_Type;
    }

    float getCar_price(){
        return Car_Price;
    }

    string getRented(){
        if (Rented == true){
            return "True";
        }
        else {return "False";}
    }

    string getRented_name(){
        return Rented_Name;
    }

    string getRented_time(){
        return Rented_Time;
    }

    string getReturn_time(){
        return Return_Time;
    }

   // functions

    //function when the user picks a car to rent
    //takes pointers to the cars and customers arrays and the index of the car and customer in its parameters
    void Rent_car(CVehicle *car,CCustomer *customer, int i_car, int i_customer )
    {   
        car[i_car].setRented(true);
        car[i_car].setRented_name(customer[i_customer].get_name());
        string start, end;
        cout << "start renting on: ";
        cin >> start;
        car[i_car].setRented_time(start);
        cout << "return on: ";
        cin >> end;
        car[i_car].setReturn_time(end);
    }

    //input cars info from user
    void Add_Car_Details(CVehicle car){
            cout<<"Please enter the car details: "<<endl;

            cout<<"Vehicle Number? ";
            cin>>car.Car_Number;
            setCar_number(car.Car_Number);

            cout<<"Vehicle Brand? ";
            cin>>car.Car_Brand;
            setCar_brand(car.Car_Brand);

            cout<<"Vehicle Model? ";
            cin>>car.Car_Model;
            setCar_model(car.Car_Model);

            cout<<"Vehicle Type? ";
            cin>>car.Car_Type;
            setCar_type(car.Car_Type);

            cout<<"Vehicle Price? ";
            cin>>car.Car_Price;
            setCar_price(car.Car_Price);
        }

    //displays all car details
    void Get_All_Details(CVehicle car){
        cout<<"\nVEHICLE DETAILS:"<<endl;

        cout<<"Vehicle Number : "<<car.getCar_number()<<endl;
        cout<<"Vehicle Brand : "<<car.getCar_brand()<<endl;
        cout<<"Vehicle Model : "<<car.getCar_model()<<endl;
            cout<<"Vehicle Type : "<<car.getCar_type()<<endl;
            cout<<"Vehicle Price : "<<car.getCar_price()<<endl;
            cout<<"Rented : "<<car.getRented()<<endl;
            if(Rented==true){
                cout<<"Rented by : "<<car.getRented_name()<<endl;
                cout<<"Rented at : "<<car.getRented_time()<<endl;
                cout<<"Returned at : "<<car.getReturn_time()<<endl;
            }
            else{
                cout<<"Rented by : No One"<<endl;
                cout<<"Rented at : -"<<endl;
                cout<<"Returned at : -"<<endl;
            }
    }

};
#endif