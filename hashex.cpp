#include <iostream>

using namespace std;

typdef struct record {
	string name;
	int GPA;
	int academic level;
	int key;
	record *next;

}* recordptr;

int main()
{	
	recordptr r = new record;
	int choice;
	cout<<"Hash Table Implementation"<<endl;
	cout<<"========================="<<endl;
	cout<<"1. Insert a Record (user enters the name, GPA, Academic level, Key (Key should be between 0-65536))"<<endl;
	cout<<"2. Search the table (user enters a key for search) Key should be between 0-65536"<<endl;
	cout<<"3. Delete a record (user enter a key of the record to be deleted)"<<endl;
	cout<<"enter your choice"<<endl;
	cin>> choice;

	switch(choice)
	{
		case 1: cout<<"Enter name: ";
				cin>>r->name;
				cout<<endl; // try same line
				cout<<"Enter GPA: ";
				cin>>r->name;
				cout<<endl;
				cout<<"Enter Academic level: ";
				cin>>r-> academic level;
				cout<<endl;
				cout<<"Enter key to store data in (0-65536): ";
				cin>>r->key;
				cout<<endl;

		break;	
		case 2: cout<<"Enter Key to search (0-65536): "; //no data entered in this key statement
				cin>>r->key;
		case 3: cout<<"Enter Key to delete (0-65536): ";
				cin>>r->key;


	};


}