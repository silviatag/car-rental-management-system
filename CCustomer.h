#include<iostream>
#include <string>
using namespace std;

class CCustomer {
private:
	//private data members
	int customer_id;
	long long int customer_num;
	long long int emergency_contact;
	string customer_name;
	string customer_email;
	string customer_password;
public:
	//constructor
	CCustomer() {
		//initializing data members to zero and NULL
		customer_id = 0;
		customer_num = 0;
		emergency_contact = 0;
		customer_name.clear();
		customer_email.clear();
		customer_password.clear();
	}
	
	//setters
	//to set individual private data members
	void set_id(int id) {
		customer_id = id;
	}
	void set_num(long long int num) {
		customer_num = num;
	}
	void set_emergency(long long int emergency) {
		emergency_contact = emergency;
	}
	void set_name(string name) {
		customer_name = name;
	}
	void set_email(string email) {
		customer_email = email;
	}
	void set_password(string password) {
		customer_password = password;
	}
	
	//getters
	//to display individual private data members
	int get_id() {
		return customer_id;
	}
	long long int get_num() {
		return customer_num;
	}
	
	long long int get_emergency() {
		return emergency_contact;
	}
	string get_name() {
		return customer_name;
	}
	string get_email() {
		return customer_email;
	}
	string get_password() {
		return customer_password;
	}

	//functions
	//to input all customer info from user
	void add_customer_info(CCustomer customer) {
		cout << "\nenter customer's name: ";//1
		cin >> customer.customer_name;
		set_name(customer.customer_name);
		cout << "enter customer's email: ";//2
		cin >> customer.customer_email;
		set_email(customer.customer_email);
		cout << "enter customer's number: ";//3
		cin >> customer.customer_num;
		set_num(customer.customer_num);
		cout << "enter customer's emergency contact number: ";//4
		cin >> customer.emergency_contact;
		set_emergency(customer.emergency_contact);
		cout << "enter customer's id: ";
		cin >> customer.customer_id;
		set_id(customer.customer_id);
		cout << "enter customer's password: ";
		cin >> customer.customer_password;
		set_password(customer.customer_password);
	}

	//to display all customer info
	void get_customer_info(CCustomer customer)
	{
		cout << endl;
		cout << "name:                  " << customer.get_name() << endl;
		cout << "email:                 " << customer.get_email() << endl;
		cout << "phone number:          " << customer.get_num() << endl;
		cout << "emergency contact:     " << customer.get_emergency() << endl;
		cout << "ID:                    " << customer.get_id() << endl;
		cout << "password:              " << customer.get_password() << endl;

	}
};