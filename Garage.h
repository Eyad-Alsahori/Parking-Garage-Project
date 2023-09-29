#ifndef Garageh
#define Garageh

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

#include"stack.h"
using namespace std;

struct car
{
	int counter = 0;
	char code;
	string Name;
	int number;
	bool operator==(const car& obj2)
	{
		if (Name == obj2.Name)
			return true;
		else
			return false;
	}
};

template<class GarageType>
class Garage
{
public:
	Garage();
	bool isEmpty() const;
	bool isFull() const;
	void arrive(car v);
	void depart(car v);
	int searchCar(car v);
private:
	Stack<car> line1;
	Stack<car> line2;
	Stack<car> street;
	car array[100];
	int carcount = 0;
};

template<class GarageType>
Garage<GarageType>::Garage()
{
	Stack<car> line1();
	Stack<car> line2();
	Stack<car> street(100);
}

template<class GarageType>
int Garage<GarageType>::searchCar(car v)
{
	for (int i = 0; i < 100; i++)
	{
		if (array[i].Name == v.Name)
		{
			return (array[i].number);
		}
	}
	return -1;
}

template<class GarageType>
void Garage<GarageType>::depart(car v)
{
	int carposition = searchCar(v);
	car temp;
	if (carposition == 1)
	{
		while (!line1.IsEmpty())
		{
			if (line1.Top().Name == v.Name)
			{
				v.counter = line1.Top().counter;
				line1.pop();
				cout << endl;
				cout << v.Name << " is taken out from the parking garage" << endl;
				cout << v.Name << " was moved " << v.counter << " times" << endl;
				cout << endl;
				break;
			}
			else
			{
				temp = line1.Top();
				line1.pop();
				temp.counter++;
				street.push(temp);
			}
		}
		while (!street.IsEmpty())
		{
			temp = street.Top();
			street.pop();
			temp.counter++;
			line1.push(temp);
		}
	}
	else if (carposition == 2)
	{
		while (!line2.IsEmpty())
		{
			if (line2.Top().Name == v.Name)
			{
				v.counter = line1.Top().counter;
				line2.pop();
				cout << endl;
				cout << v.Name << " IS BEING  TAKEN OUT  FROM  THE  PARKING  GARAGE !!!!!" << endl;
				cout << v.Name << " WAS MOVED IN  " << v.counter << " TIMES " << endl;
				cout << endl;
			}
			else
			{
				temp = line2.Top();
				line2.pop();
				temp.counter++;
				street.push(temp);
			}
		}
		while (!street.IsEmpty())
		{
			temp = street.Top();
			street.pop();
			temp.counter++;
			line2.push(temp);
		}
	}
	else
	{
		cout << "Car isn't parked here" << endl;
		cout << endl;
	}
}
template<class GarageType>
void Garage<GarageType>::arrive(car v)
{
	if (!line1.IsFull())
	{
		line1.push(v);
		v.number = 1;
		cout << left << setw(10) << v.Name << "HAS BEEN PARKED IN THE LANE  ---->  1" << endl;
		cout << endl;
		array[carcount] = v;
		carcount++;
	}
	else if (!line2.IsFull())
	{
		line2.push(v);
		v.number = 2;
		cout << left << setw(10) << v.Name << "HAS BEEN PARKED IN THE LANE  ---->  2" << endl;
		cout << endl;
		array[carcount] = v;
		carcount++;
	}
	else
	{
		cout << "SORRY!!... BOTH LANE 1 AND LANE 2 ARE FULL.  NO MORE SPACES LEFT. " << endl;
	}
}
#endif
#pragma once
