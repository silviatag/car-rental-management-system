//including libraries
#include <iostream>
#include <string>
#include <iomanip>
//including header files
#include "CCustomer.h"
#include "CVehicle.h"
#include "CBus.h"

using namespace std;

//function prototypes
int instruction();
int login(int customer_num, CCustomer* customers);

int main()
{
	//names
	//Silvia Hassan  211001721
    //Nesma Hegazy   211001626
    //Mariam Attia   211000533
    //Nada Othman    202001964
    //Arwa Sameh     211001892

	cout << setw(80); 
	cout << "WELCOME TO OUR CAR RENTAL SYSTEM"<<endl;
	cout << setw(80); 
	cout << "--------------------------------" << endl;

	//class objects
	static CVehicle *vehicles;
	static CCustomer* customers;
	static CBUS* bus;

	//variables in main
	int choice;
	static int bus_num;
	static int car_num;
	static int customer_num;
	string temp;
	string temp2;
	string temp3;

	//condition to see what the user's choice is, if 1 or 2 go to switch statement
	//if 3 break out of while loop and end program.

	while ( !( (choice=instruction())==3 ))
	{	
		//switch statement between choice 1 and 2
		switch (choice)
		{
			//choice 1 : enter car/bus details and customer details
			case 1:
			{
				string entry;
				cout << "\ndo you want to enter data? (yes/no)" << endl;
				cin >> entry;//if no then display cars information

				if (entry == "yes") 
				{

					cout << "\nIs the Vehicle a car or a bus?" << endl;
					cin >> temp;

					if (temp == "bus")//if the vehicle is a bus
					{
						cout << "\nenter number of buses: ";
						cin >> bus_num;

						bus = new CBUS[bus_num];//create array of CBus objects
						for (int i = 0; i < bus_num; ++i)
						{
							bus[i].Add_Car_Details(bus[i]);//get car info
							bus[i].add_extra_info(bus[i]);//get the bus info
						}
					}

					else//if the vehicle is a car
					{
						cout << "\nenter number of cars: ";
						cin >> car_num;

						vehicles = new CVehicle[car_num];//create array of CVehicle objects
						for (int i = 0; i < car_num; ++i)
						{
							vehicles[i].Add_Car_Details(vehicles[i]);//get car info
						}
					}

					cout << "\nWould you like to add customers\' details?(yes/no)" << endl;
					cin >> temp2;//if no display car info

					if (temp2 == "yes")
					{
						cout << "\nenter number of customers: ";
						cin >> customer_num;

						customers = new CCustomer[customer_num];//create array of CCustomer objects
						for (int i = 0; i < customer_num; ++i)
						{
							customers[i].add_customer_info(customers[i]);//get customers info
						}
					}
				}

				//displaying car/bus details
				if (temp == "bus")//if vehicle is a bus
				{
					for (int i = 0; i < bus_num; ++i)
					{
						bus[i].Get_All_Details(bus[i]);
						bus[i].get_extra_info(bus[i]);
					}
				}

				else//if the vehicle is a car
				{
					for (int i = 0; i < car_num; ++i)
					{
						vehicles[i].Get_All_Details(vehicles[i]);
					}
				}

			break;//break out of case 1 switch statement
			}

			//choice 2 : user wants to login and rent a vehicle
			case 2:
			{
				while (true)
				{
					int login_user = login(customer_num, customers);//getting login info

					if (login_user)//correct login info
					{
                        if(temp=="bus")//if vehicles are buses
                        {
                            for(int i=0;i<bus_num;++i)
                            {
                                bus[i].Get_All_Details(bus[i]);
                                bus[i].get_extra_info(bus[i]);

                                cout << "\ndo you want to rent this car?(yes/no) ";
							    cin >> temp3;

                                if (temp3 == "yes")//rent this specific vehicle
							    {
								    bus[i].Rent_car(bus, customers, i, login_user - 1);//rent car function
								    cout << "\n\n";

                                    cout<<"Rented Vehicle Details: "<<endl;
								    bus[i].Get_All_Details(bus[i]);//display info after vehicle is rented
                                    bus[i].get_extra_info(bus[i]);//displaying the extra bus info that is rented

								    break;//break out of loop when a vehicle is picked
							    }
                            }
                        }

                        else//if vehicles are cars
                        {
                            for (int i = 0; i < car_num; ++i)
						    {
							    vehicles[i].Get_All_Details(vehicles[i]);//display vehicles to pick from
							    cout << "\ndo you want to rent this car?(yes/no) ";
							    cin >> temp3;

							    if (temp3 == "yes")//rent this specific vehicle
							    {
								    vehicles[i].Rent_car(vehicles, customers, i, login_user - 1);//rent car function
								    cout << "\n\n";
                                    cout<<"Rented Vehicle Details: "<<endl;

								    vehicles[i].Get_All_Details(vehicles[i]);//display info after vehicle is rented
								    break;//break out of loop when a vehicle is picked
							    }
						    }
                        }
						
					break;//break out of if statement
					}

					else//incorrect login info
					{
						string temp4;
						cout << "Password or email is incorrect. \nDo you want to try again?(yes/no) ";
						cin >> temp4;

						if (temp4 == "yes")//enter info again to login
						{
							continue;
						}

						else//end program
						{
							choice = 3;
							break;
						}
					}
				}

			break;//break out of case 2 switch statement
			}

		}
	}
}

//function to see if the user wants to enter data or login
int instruction() 
{
	int choice;
	cout << "\nenter your choice:\n"
		"1\tif you want to add data into the system\n"
		"2\tlog in and rent a car\n"
		"3\tend program\n>> ";
	cin >> choice;
	return choice;
}

//login function
int login(int customer_num, CCustomer *customers)
{
	//the login info
	string email, password;
	cout << "email: ";
	cin >> email;
	cout << "password: ";
	cin >> password;

	for (int i = 0; i < customer_num; ++i)//loop through customer details
	{
		if (email == customers[i].get_email() && password == customers[i].get_password())//correct login info
		{
			return i+1;//if index is 0 
		}

		else{continue;}
	}

	return 0;
}