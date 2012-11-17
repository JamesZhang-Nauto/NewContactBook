#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
#define MAX_ITEMS 100
class Contacts
{
	string firstName[MAX_ITEMS];
	string lastName[MAX_ITEMS];
	string emailID[MAX_ITEMS];
	string phoneNumber[MAX_ITEMS];
	ofstream myfilewriter;
	ifstream myfilereader;

	int index;	//alwasy points to the last item of contact
public:
	Contacts() 
	{ //constructor
		//firstName = "";
		//lastName = "";
		//emailID = "";
		//phoneNumber = "";
		index = 0;
	}

	void createContact(int _index) 
	{
		cout <<"Enter first name:" << endl;
		cin >> firstName[_index];

		cout <<"Enter last name:" << endl;
		cin >> lastName[_index];

		cout << "Enter email address" << endl;
		cin >> emailID[_index];

		cout << "Enter phone number" <<endl;
		cin >> phoneNumber[_index];
		index++;
	}

	void deleteContact()
	{
		displayContact();
		int delIndex=0;
		char conform;
		do{								//prevent crash
			cout << "which one? (1-" << index << ")  "  ;
			cin.clear();
			cin.sync();  
			cin >> delIndex;
		}while(cin.fail());

		do{							//prevent crash
			cout << "Are you sure? (Y/N) "  ;
			cin.clear();
			cin.sync();  
			cin >> conform;
		}while(cin.fail());

		if(conform=='N'||conform=='n') return ;
		if(conform=='Y'||conform=='y')
		{
			delIndex--;
			for(int i=delIndex; i<index-1; i++) //move the following items, in order to "erase" the item
			{
				firstName[i] = firstName[i+1];
				lastName[i] = lastName[i];
				emailID[i] = emailID[i+1];
				phoneNumber[i] = phoneNumber[i+1];
			}
			index--;
		}
	}

	int getIndex()
	{
		return index;
	}

	void displayContact() 
	{
		cout << setw (12)  << " First Name" << " | " 
			<< setw (12)  << " Last Name " << " | " 
			<< setw (20)  << " Email ID" << " | " 
			<< setw (14)  << " Phone Number" << endl;
		cout << "------------------------------------------------------------------------"<<endl;
		for(int i=0; i<index; i++)
		{
			cout << setw (12)  << firstName[i] << " | " 
				<< setw (12)  << lastName[i]  << " | " 
				<< setw (20)  << emailID[i]   << " | " 
				<< setw (14)  << phoneNumber[i] << endl;
		}
	}

	void editContact() 
	{
		int editItem =0;
		displayContact();
		int editIndex=0;
		do{  //prevent crash
			cout << "which one? (1-" << index << ")  " ;
			cin.clear();
			cin.sync();  
			cin >> editIndex;
		}while(cin.fail());

		editIndex--;
		do{  //prevent crash
			cout << endl<< "Chooce one that you want to edit (1,First Name; 2,Last Name; 3,email; 4, Phone#): ";
			cin.clear();
			cin.sync();  
			cin >> editItem;
		}while(cin.fail());

		switch(editItem)
		{
		case 1:
			cout << "enter new first name:" << endl;
			cin >> firstName[editIndex];
			break;
		case 2:
			cout << "enter new last name:" << endl;
			cin >> lastName[editIndex];
			break;
		case 3:
			cout << "enter new email address:" << endl;
			cin >> emailID[editIndex];
			break;
		case 4:
			cout << "enter new phone number:" << endl;
			cin >> phoneNumber[editIndex];
			break;
		default:
			cout << "Wrong choice, please enter again..." << endl;
		}
	}

	void save()
	{
		char conform;
		do{
			cout << "save? (Y/N) "  ;
			cin.clear();
			cin.sync();  
			cin >> conform;
		}while(cin.fail());
		if(conform=='Y'||conform=='y')
		{
			myfilewriter.open("contact.txt");
			for(int i=0; i<index; i++)
			{
				myfilewriter 	/*<< "First name: "*/ << firstName[i] << endl
					/*<< "Last name:"*/ << lastName[i] << endl
					/*<< "Email ID: "*/ << emailID[i] << endl
					/*<< "Phone Number: "*/ << phoneNumber[i] << endl;
			}
			myfilewriter.close();
		}
	}

	bool load()
	{
		cout << "Loading contact..."<<endl;
		myfilereader.open("contact.txt");
		string d="";
		if(myfilereader.is_open())
		{
			while(!myfilereader.eof())
			{
				getline(myfilereader, firstName[index]);
				getline(myfilereader, lastName[index]);
				getline(myfilereader, emailID[index]);
				getline(myfilereader, phoneNumber[index]);
				index++;
			}
			index--;
			cout << index <<" contact has been loaded!" <<endl;
			myfilereader.close();
			return true;
		}
		else 
		{
			cout << "No contact exists, create a new one..." <<endl;
			return false;
		}
	}
};

int main ()
{

	Contacts ourAddressBook;
	int choice;

	if (!ourAddressBook.load())	//load contact file first. if return ture, don't need to create new contact; if false, call createContact();
		ourAddressBook.createContact(0);

	while(1) 
	{
		cout <<endl;
		do{			//prevent crash
			cout << "1. Display contact" << endl;
			cout << "2. Edit contact" << endl;
			cout << "3. New contact" <<endl;
			cout << "4. Delete contact" <<endl;
			cout << "5. Save and Exit" << endl;

			cin.clear();
			cin.sync();  
			cin >> choice;
		}while(cin.fail());

		switch(choice) {
		case 1: ourAddressBook.displayContact();
			break;
		case 2: ourAddressBook.editContact();
			break;
		case 3: 
			ourAddressBook.createContact(ourAddressBook.getIndex());
			break;
		case 4: 
			ourAddressBook.deleteContact();
			break;
		case 5:
			ourAddressBook.save();
			exit(1);		
		}
	}

	cin.get();
	cin.get();
	return 1;
}