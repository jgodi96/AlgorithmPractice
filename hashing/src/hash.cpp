#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

class Student
{
public:
	int key;
	double gpa;
	string name, academic_level;
	Student* next;

	Student(int key, string name, double gpa, string academic_level)
	{
		this->key = key;
		this->name = name;
		this->gpa = gpa;
		this->academic_level = academic_level;
		this->next = NULL;
	}
};

class HASHTABLE
{
private:
	Student * * hash_table;

public:
	HASHTABLE()
	{
		hash_table = new Student*[1000];

		for (int i = 0; i < 1000; i++)
		{
			hash_table[i] = NULL;
		}

	}

	int HASHKEY(int key)
	{
		return key % 1000;
	}

	int CHECKER(int arr[], int key)
	{
		int check = key;
		for (int i = 0; i <= 1000; i++)
		{

			if (arr[i] == key)
			{
				cout << "Please enter another key value: ";
				cin >> check;
				CHECKER(arr, check);
			}
		}
		cout << key << endl;
		return key;
	}

	void INSERT(int key, string name, double gpa, string academic_level)
		// insert the student record x to the table
	{
		int insert_key = HASHKEY(key);
		Student* x = hash_table[insert_key];
		Student* previous = NULL;

		while (x != NULL)
		{
			previous = x;
			x = x->next;
		}

		if (x == NULL)
		{
			x = new Student(key, name, gpa, academic_level);

			if (previous == NULL)
			{
				hash_table[insert_key] = x;
				cout << "\nStudent is inserted at key " << insert_key << "." << endl;
			}
			else
			{
				previous->next = x;
				cout << "\nStudent is inserted at key " << insert_key << "." << endl;
			}
		}
		else
		{
			x->key = key;
			x->name = name;
			x->gpa = gpa;
			x->academic_level = academic_level;
			cout << "\nStudent is inserted at key " << insert_key << "." << endl;
		}
	}

	void DELETE(int key)
		// delete the student record x from the table
	{
		int delete_key = HASHKEY(key);
		Student* x = hash_table[delete_key];
		Student* previous = NULL;

		if (x == NULL || x->key != key)
		{
			cout << "Student not found at key " << key << "." << endl;
			return;
		}

		while (x->next != NULL)
		{
			previous = x;
			x = x->next;
		}

		if (previous != NULL)
		{
			previous->next = x->next;
		}

		delete x;
		cout << "Student at key " << key << " is deleted." << endl;
	}

		int SEARCH(int key)
		// search key k in the hash table
	{
		int search_key = HASHKEY(key);
		Student* k = hash_table[search_key];
		bool tf = false;

		while (k != NULL)
		{
			if (k->key == key)
			{
				cout << k->name << " ";
				tf = true;
			}

			k = k->next;
		}

		if (!tf)
		{
			return -11;
		}
	}

};

int main()
{
	int key, choice, compare_key, arr[1000];
	for int (int i=0; i<=1000; i++)
    {
        arr[i]=-1;
    }

	static int k = 0;
	double gpa;
	string name, academic_level;
	HASHTABLE hash_table;

	while (1)
	{
		cout << "\nHash Table Implementation" << endl;
		cout << "=========================" << endl;
		cout << "1. Insert a Record (user enters the name, GPA, Academic level, Key [Key should be between 0 - 65536])" << endl;
		cout << "2. Search the table (user enters a key for search) Key should be between 0 - 65536" << endl;
		cout << "3. Delete a record (user enters a key of the record to be deleted)" << endl;
		cout << "4. Exit" << endl;
		cout << "enter your choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			cout << "Name: ";
			getline(cin, name);
			cout << "GPA: ";
			cin >> gpa;
			cout << "Academic level: ";
			cin >> academic_level;
			cout << "Key (between 0-65536): ";
			cin >> key;
			if (key >= 0 && key <= 65536)
			{
				compare_key = hash_table.CHECKER(arr, key);
				arr[k] = key;
				k++;
			}
			else
			{
				while (key <= 0 || key >= 65536)
				{
					cout << "ONLY enter a key between 0-65536." << endl;
					cin >> key;
				}
			}
			hash_table.INSERT(key, name, gpa, academic_level);
			break;

		case 2:
			cout << "Enter the key of student (between 0-65536) to search: ";
			cin >> key;
			cout << "Element at key " << key << ": " << endl;
			if (hash_table.SEARCH(key) == -11)
			{
				cout << "No student linked to key " << key << ".";
				cout << endl;
				continue;
			}
			cout << "\nGPA: " << gpa << endl;
			cout << "Academic level: " << academic_level << endl;
			break;

		case 3:
			cout << "Enter the key of student (between 0-65536) to delete: ";
			cin >> key;
			hash_table.DELETE(key);
			break;

		case 4:
			exit(1);

		default:
			cout << "Choose between options 1-4." << endl;
		}
	}
}
