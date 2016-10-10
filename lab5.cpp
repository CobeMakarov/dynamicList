/*
    Shacobe Johnson
    Computer Science 340
    Section 02
    Lab 5
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;
#include "dynamicList.h"


void print_insert(int number, bool inserted);
void print_search(int number, bool found);
void print_removed(int number, bool found);
void print_getlast(int number, bool found);

int  main (void)
{
	dynamicList  testArray(10);

	bool inserted=false, found=false;
	int number,i;
	int temp;

	srand(time(0)% INT_MAX);

	// Testing insert into the testArray
	cout<<"\n---------INSERTING AT NEXT AVAILABLE LOCATION---------------------\n";
	for (i=0;i<20;i++)
	{
		number=rand()%20;
		inserted=testArray.Insert(number);
		print_insert(number,inserted);
	}
	cout<<"\nPress any key to continue";
	cin.ignore();

	// Testing print by Printing testArray
	cout << "\n---------PRINTING---------------------\n";
	testArray.Print();

	cout << "\nPress any key to continue";
	cin.ignore();
	cout << "-------------------------------------------------------------\n";
	cout << "The array has " << testArray.currentSize() << " currently!\n";
	cout << "-------------------------------------------------------------\n";

	cout << "\nPress any key to continue";
	cin.ignore();

	//Testing getLast function by getting the last number in testArray
	number = 0;
	testArray.Getlast(number, found);
	if (found)
		cout << "\n\nThe last number in the array is " << number << endl;

	cout<<"\nPress any key to continue";
	cin.ignore();

	//Testing remove function that only takes a number not knowing wether exist
	cout<<"\n------------------REMOVING BY NUMBER----------------------------\n";
	int count = 0;
	while (count != 5)
	{
		number = rand() % 20;
		testArray.Remove(number,found);
		if (found)
			count++;
		print_removed(number,found);

	}

	cout << "\nPress any key to continue";
	cin.ignore();

	// Testing print by Printing testArray
	cout << "\n---------PRINTING---------------------\n";
	testArray.Print();

	cout << "\nPress any key to continue";
	cin.ignore();
	cout << "-------------------------------------------------------------\n";
	cout << "The array has " << testArray.currentSize() << " currently!\n";
	cout << "-------------------------------------------------------------\n";

	cout << "\nPress any key to continue";
	cin.ignore();

	//Testing insert by location on testArray
	cout << "\n---------INSERTING AT SPECIFIC LOCATION---------------------\n";
	for (i=0;i<12;i+=2)
	{
		number=rand()%100;
		inserted=testArray.Insert(number,i);
		print_insert(number,inserted);
	}

	cout<<"Press any key to continue";
	cin.ignore();

	// Testing print by Printing testArray
	cout << "\nPRINTING\n";
	testArray.Print();


	cout << "-------------------------------------------------------------\n";
	cout << "The array has " << testArray.currentSize() << " currently!\n";
	cout << "-------------------------------------------------------------\n";

	cout << "Press any key to continue";
	cin.ignore();

	//Testing remove by location on testArray
	cout << "\n---------REMOVING FROM A SPECIFIC LOCATION---------------------\n";
	for (i = 1; i<12; i += 2)
	{
		testArray.Remove(number, found,i);
		print_removed(number, found);
	}

	cout << "\nPress any key to continue";
	cin.ignore();


	// Testing print by Printing testArray
	cout << "\nPRINTING\n";
	testArray.Print();


	cout << "-------------------------------------------------------------\n";
	cout << "The array has " << testArray.currentSize() << " currently!\n";
	cout << "-------------------------------------------------------------\n";

	cout << "Press any key to continue";
	cin.ignore();

	//Testing Array insert at location that is not within the length
	number=rand() %100;
	inserted = testArray.Insert(number,9);
	print_insert(number,inserted);

	testArray.Print();


	cout << "-------------------------------------------------------------\n";
	cout << "The array has " << testArray.currentSize() << " currently!\n";
	cout << "-------------------------------------------------------------\n";

	cout << "Press any key to continue";
	
	cin.ignore();
	testArray.Clear();

	cout << "-------------------------------------------------------------\n";
	cout << "The array has " << testArray.currentSize() << " currently!\n";
	cout << "-------------------------------------------------------------\n";
	return 0;

}

void print_insert(int number, bool inserted)
{
	if (inserted==true)
		cout<<"Number "<<number<<" was INSERTED into the array\n";
}

void print_search(int number, bool found)
{
	if (found==true)
		cout<<"Number "<<number<<" was FOUND in the array\n";
	else
		cout<<"Number "<<number<<" was NOT FOUND in the array\n";
}

void print_removed(int number, bool found)
{
	if (found==true)
		cout<<"Number "<<number<<" was REMOVED from the array\n";
}

void print_getlast(int number, bool found)
{
	if (found==true)
		cout<<"Number "<<number<<" was at the TOP of the array\n";
}
