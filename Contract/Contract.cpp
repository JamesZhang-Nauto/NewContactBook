#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Contacts
{
	string firstName;
	string lastName;
	string emailID;
	string phoneNumber;
	ofstream myfilewriter;
	ifstream myfilereader;
public:
	Contacts() 
	{ //constructor
		firstName = "";
		lastName = "";
		emailID = "";
		phoneNumber = "";
	}

	void createContact() 
	{
		cout <<"Enter first name:" << endl;
		cin >> firstName;

		cout <<"Enter last name:" << endl;
		cin >> lastName;

		cout << "Enter email address" << endl;
		cin >> emailID;

		cout << "Enter phone number" << endl;
		cin >> phoneNumber;
	}

	void displayContact() 
	{
		cout <<"---------------Display contact information---------------" << endl;
		cout << "1. First name: " << firstName << endl;
		cout << "2. Last name:" << lastName << endl;
		cout << "3. Email ID: " << emailID << endl;
		cout << "4. Phone Number: " << phoneNumber << endl
			<<"----------------------------------------------------------" << endl <<endl;
	}

	void editContact() 
	{
		displayContact();
		cout << "Choose one that you want to edit (1-4): ";
		int editItem =0;
		cin >> editItem;
		switch(editItem)
		{
		case 1:
			cout << "enter new first name:" << endl;
			cin >> firstName;
			break;
		case 2:
			cout << "enter new last name:" << endl;
			cin >> lastName;
			break;
		case 3:
			cout << "enter new email address:" << endl;
			cin >> emailID;
			break;
		case 4:
			cout << "enter new phone number:" << endl;
			cin >> phoneNumber;
			break;
		default:
			cout << "Wrong choice, please enter again..." << endl;
			
		}
	}


};

int main ()
{

	Contacts ourAddressBook;

	cout <<"Creating a new contact" << endl;

	ourAddressBook.createContact();



	while(1) 
	{
		cout <<endl;
		cout << "1. Display contact" << endl;
		cout << "2. Edit contact" << endl;
		cout << "3. Exit" << endl;
		int choice;
		cin >> choice;

		switch(choice) {
		case 1: 
			ourAddressBook.displayContact();
			break;
		case 2: 
			ourAddressBook.editContact();
			break;
		case 3:
			exit(1);		
		}
	}

	cin.get();
	cin.get();
	return 1;
}