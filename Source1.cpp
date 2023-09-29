#include "Garage.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// main function
int main()
{
	Garage<car> Garage;
	//read in the file
	fstream input;
	//open the text file
	input.open("Garage.txt");
	if (!input)
	{
		cout << "ERROR ! file can not open !" << endl;
		input.close();
		system("pause");
		return 0;
	}
	cout << " \n     WELCOME  TO  THE  PARKING  GARAGE !!!!  " << endl;
	cout << "............................................... " << endl << endl;

	while (!input.eof())
	{
		car newcar;//make a newcar
		input >> newcar.code >> newcar.Name;//to get the car's status and the plate number
		//find the car status is departing or arriving.
		switch (newcar.code)
		{
		case 'A':
			Garage.arrive(newcar);
			break;
		case 'D':
			Garage.depart(newcar);
			break;
		default:
			cout << "This car doesn't exist" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
