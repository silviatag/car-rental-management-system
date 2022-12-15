#include <iostream>
#include <string>
#include "CVehicle.h"
using namespace std;

class CBUS : public CVehicle{ //inheriting from class CVehicle
    //private data members
    private:
        int Num_of_passengers;
        string driver_Name;

    public:
        //SETTERS
        void set_num_of_pass(int num){
            Num_of_passengers = num;
        }
        void set_driver_name(string name){
            driver_Name = name;
        }

        //GETTERS
        int get_num_of_pass(){
            return Num_of_passengers;
        }
        string get_driver_name(){
            return driver_Name;
        }

        //FUNCTION TO RETRIVE INFORMATION
        void add_extra_info(CBUS bus){
            cout<<"Number of passengers of bus? ";
            cin>>bus.Num_of_passengers;
            set_num_of_pass(bus.Num_of_passengers);

            cout<<"What is the Name of the Driver? "<<endl;
            getchar();//to make getline work
            getline (cin,bus.driver_Name); //to retrive full name from user
            set_driver_name(bus.driver_Name);
        }

        //FUNCTION TO OUTPUT THE INFORMATION
        void get_extra_info(CBUS bus){
            cout<<"Number of passengers : "<<bus.get_num_of_pass()<<endl;
            cout<<"Driver Name : "<<bus.get_driver_name()<<endl;
        }
};