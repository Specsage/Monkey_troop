#pragma once
/***********************
*	HEADER FILE     *
***********************/
#ifndef A1_Header
#define A1_Header
/*
* STATUS: Complete.
*
*/

#include <iostream>
#include <random>
#include<fstream>
#include<string>
using namespace std;
//GreenMonkey class creation.
class GreenMonkey
{
	//Declared Variables Below:private;
private:
	float weight; string name; char gender;
	int age;
	bool alive; bool mutant;

public://public functions
//remove cout from setter functions

	  //Mutator Fucntions
	void SetG()//setter function for gender.
	{
		cin >> gender;
	}
	void SetG(char gen)
	{
		gender = gen;

	}
	void SetA()//setter function for age.
	{
		cin >> age;
	}
	void SetA(int a)
	{
		age = a;
	}
	void SetN()//Setter function for name.
	{

		cin >> name;
	}
	void SetW()//Setter Function for Weight
	{
		cout << "Enter monkey's weight: " << endl;
		cin >> weight;
	}
	void SetW(float wt)
	{
		weight = wt;
	}
	void SetAlive(bool x)
	{
		alive = x;
	}
	void SetMut(bool x)
	{
		mutant = x;
	}

	//Accessor Functions
	char GetG()//Accessor function fo gender.
	{
		return gender;
	}
	int GetA()//Accessor function for age.
	{
		return age;
	}
	string GetN()//Accessor function for name.
	{
		return name;
	}
	float GetW()//Accessor Function for weight.
	{

		return weight;
	}


	bool GetAlive()//Alive Accessor Function.
	{
		return alive;
	}
	bool GetMutant()//Mutant Accessor Function
	{
		return mutant;
	}

	//Class Constructors
	GreenMonkey()//Default Constructor
	{
		weight = 0.0;
		name = assign_name(assign_gender());
		age = 0;
		gender = assign_gender();
		alive = true;
		mutant = false;
	}
	GreenMonkey(float wt, string nm, int a, char gen)//Paramterized Constructor.
	{
		weight = wt;
		name = nm;
		age = a;
		gender = gen;
		alive = true;
		mutant = false;
	}


	//Memeber Functions

	void print()
	{
		string alive_str;
		string mutant_str;
		string gen_str;

		if (alive == 1)
		{
			alive_str = "alive";
		}
		else
		{
			alive_str = "not alive";
		}

		if (mutant == 1)
		{
			mutant_str = "a mutant";
		}
		else
		{
			mutant_str = "not mutant";
		}
		if (gender == 'F')
		{
			gen_str = "Female";
		}
		else
		{
			gen_str = "Male";
		}

		cout << GetN() << " is " << GetA() << " years old, weighs " << GetW() << "lbs,";
		cout << " is a " << gen_str << " and is " << alive_str << ", " << GetN() << "  is also " << mutant_str << "." << endl;
	}
	void age_me() //monkey dies @ 10x Green monkey's weight.
	{
		int age = GetA();//gives access to monkey's age
		float weight = GetW();//gives access to monkey's weight
		int chance = GetRandomNumber(1, 100);
		/*
		* int random = GetRandomNumber(1,100);
		*int wt = random/100;
		* int dead = weight*wt;
		* add weight to a varibale.
		*/

		int dead = GetRandomNumber(1, 50);//variable to control death
		age++;
		if (dead >= weight * 10)//if random > green monkey's weight monkey dies
		{
			alive = false;
		}
		if (mutant == false)
		{
			if (chance <= 2)
			{
				mutant = true;
			}
		}
	}
	void Fight(GreenMonkey& x)
	{
		float fight_ratio = (weight / x.weight) * 50;
		int random = GetRandomNumber(1, 100);
		if (alive == true && x.alive == true)//test to see if both monkeys are alive
		{
			if (random < fight_ratio)
			{
				x.alive = false;
				cout << x.name << " was defeated by " << name << " in battle " << "and died." << endl;
			}
			if (random > fight_ratio)
			{
				alive = false;
				cout << name << " was defeated by " << x.name << " in battle " << "and died." << endl;
			}

		}
		else
		{
			if (alive == false)//test to see if monkey is dead
			{
				cout << GetN() << " is dead and thus won't be able to participate in this match." << endl;
			}
			if (x.alive == false)//tests if called in monkey is dead
			{
				cout << x.GetN() << " is dead and thus can't participate in this match." << endl;
			}
		}


	}
	int GetRandomNumber(int min, int max)//for integers
	{
		random_device rd;
		mt19937 generator(rd());  // mt19937 is a standard mersenne_twister_engine
		uniform_int_distribution <int> unifrm(min, max);//uniform distribution of ints
		return unifrm(generator);

	}
	float GetRandomNumber(float min, float max)//for floats and any other numbers.
	{
		random_device rd;
		mt19937 generator(rd());
		uniform_real_distribution<float> distribution(min, max);
		return distribution(generator);
	}
	void eat()
	{
		double gen = gender;
		string genstr = "";
		if (gen == 'F')
		{
			genstr = "her";
		}
		if (gen == 'M')
		{
			genstr = "his";
		}
		if (alive == true)//should only work if monkey is alive
		{
			int pop = GetRandomNumber(10, 500);//stores random varition
			if (mutant == false)//mutants weight should not change
			{
				weight = pop / 100 + weight;
			}

		}

	}
	char assign_gender()//Complete.
	{
		int percent = GetRandomNumber(1, 100);
		if (percent <= 50)
		{
			SetG('M');
		}
		if (percent >= 50)
		{
			SetG('F');
		}
		return gender;
	}
	string assign_name(char gen)
	{
		SetG(gen);//set gender
		ifstream troop_monkey_names;//create read object
		string file_names;//1st string to store *.txt file

		if (gen == 'F')
		{
			file_names = "F_names.txt";
		}

		if (gen == 'M')
		{
			file_names = "M_names.txt";
		}
		string names;//2nd string to store
		troop_monkey_names.open(file_names);//open file using object
		if (!troop_monkey_names.is_open())//check if file is not open
		{
			cerr << "Error opening file!!." << endl;
			exit(0);
		}
		//continue
		vector<string> monkey_names;//create vector of monkeys
		while (troop_monkey_names >> names)
		{
			monkey_names.push_back(names);
		}
		/*Private variable*/name = monkey_names[GetRandomNumber(0, monkey_names.size() - 1)];//returns vector of monkey_names with a random number generation of names from 0 - monkey_names.size()-1
		return name;
	}
	auto assign_age_weight(int min_age, int max_age, float min_weight, float max_weight)
	{
		int age = GetRandomNumber(min_age, max_age);
		SetA(age);
		float weight = GetRandomNumber(min_weight, max_weight);
		SetW(weight);
	}
};
#endif