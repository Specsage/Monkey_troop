#pragma once
/*
********************
Status: Working on getStatistics()
Completed:
* showGrid();
* impact(vector<GreenMonkey>&, GreenMonkey&); 
* invasion(int)
* ageAll()
* feedAll()
* printAll();
To be Completed:
getStatistics()
*/
#include  "GreenMonkey.hpp"//inlcude greenmonkey class
#include <iomanip>
class Habitat
{
	private:
		static const int RowCol = 10;//size of rows and columns
		vector<GreenMonkey> grid[RowCol][RowCol] = {};//creates a 10 X 10 grid,each grid cell will have an empty GreenMonkey vector
	public:
		vector <GreenMonkey> create_troop(int x)//x represents group size.
		{
			vector<GreenMonkey> troop;//Create vector of monkeys: troops.
			for (int i = 0; i < x; i++)
			{//for loop initializes troop size;
				GreenMonkey newobj;//create obj of greenmonkey class
				troop.push_back(newobj);//add new element to class vector.	
			}
			int size = troop.size();
			for (int n = 0; n < size; n++)
			{
				troop[n].assign_name(troop[n].assign_gender());
				troop[n].assign_age_weight(1, 5, .4f,3.0f );
			}
			return troop;
		}
		int Random(int min, int max)
			{
				random_device rd{};
				mt19937 generator{rd()};
				uniform_int_distribution <int> uniform(min, max);
				return uniform(generator);
			}
		vector <string> getEmptyCells()
			{
				vector <string> Cell;//string vector to be returned
				string str,str2,str3;
				int size = RowCol;
				for (int i = 0; i < size; i++)
				{
					for (int a = 0; a < size; a++)
					{
						if (grid[i][a].empty())
						{
							str = to_string(i);
							str2 = to_string(a);
							str3 = str + ":" + str2;//update vector with string elements
							Cell.push_back(str3);
							}
					}
				}
				return Cell;
			}
		void initialization(int x)
			{
				int p1, p2, size;
				size = RowCol - 1;//Index of vector usage call for 0-9 indexes
				for(int i=0; i < x; i++)
				{
					p1 = Random(0, 9);
					p2 = Random(0, 9);
					//check if grid positions are empty.
					if (grid[p1][p2].empty())
					{
						GreenMonkey Monkey;
						grid[p1][p2].push_back(Monkey);//add monkey obj to vec
						
						//remove grid from empty grids.
					}
				}
			}
		void showGrid()//complete.
			{

				for (int x = 0; x < RowCol; x++)
				{
					for (int y = 0; y < RowCol; y++)
					{
						if (!grid[x][y].empty())//check if position is occupied
						{
							cout << left << setw(2)<< "[" << grid[x][y].at(0).GetG() << "] ";
						}
						else
						{
							cout << left << setw(1) << "[" << "  " << "] ";
						}
					}
					cout << endl;
				}
			}
		void impact(vector <GreenMonkey> &m1 , GreenMonkey &m2)
			{
			//picks a random GreenMonkey from the vector in the 1st parameter and engage with the GreenMonkey which is the second parameter.
			int s = m1.size();
			int rand = Random(0, s);
			 char gen1, gen2;
			 gen1 = m1[rand].GetG();
			 gen2 = m2.GetG();
			 if (m1[rand].GetAlive() == true && m2.GetAlive() == true)//Checking to see if the monkey is alive because dead monkeys cannot engage.
			 {
				 if (m1[rand].GetMutant() == true || m2.GetMutant() == true)// Check if one or both of the monkeys are mutant
				 {
					 exit(0);// If this is true the program would exit
				 }
				 else// if the monkey are not mutant this code would run.
				 {
					 if (gen1 == gen2) //If the monkeys are the same gender 
					 {
						 m1[rand].Fight(m2); //call fight function within the GreenMonkey class.
					 }

					 if (gen1 == 'F' && gen2 == 'M' || gen2 == 'F' && gen1 == 'M') //Test for male & female
					 {
						 GreenMonkey baby;
						 baby.SetA(0);
						 baby.assign_gender();
						 baby.assign_name(baby.GetG());
						 baby.assign_age_weight(0,2,0.1f,1.0f);//age can change if being outputted
						 baby.SetAlive(true);
						 baby.SetMut(false);
						 m1.push_back(baby); //add baby to troop
					 }
				 }
			 }
			 else // If either of the monkeys are dead 
			 {
				 exit(0);// Exits the program.
			 }

		}
		void invasion(int x)
		{
			vector <GreenMonkey> troop = create_troop(x);

			int size = RowCol - 1; //use of index
			int rand_1 = Random(0,size);// Generating a random index number
			int rand_2 = Random(0,size);
			if (grid[rand_1][rand_2].empty())// Check if grid cells selected are empty
			{
				int size = troop.size();
				for (int i = 0; i < size; i++)
				{
					grid[rand_1][rand_2].push_back(troop[i]); //adds new object to locations
					//cout << grid[rand_1][rand_2].at(i).getGender() << " ";//prints genders of monkey at positions
				}

			}
			else
			{ // Caliing the impact function 
				impact(troop,grid[rand_1][rand_2].at(0));
			}

		}
		void ageAll()
		{
			for (int x = 0; x < RowCol; x++)
			{
				for (int y = 0; y < RowCol; y++)
				{
					if (!grid[x][y].empty())
					{
						grid[x][y].at(0).age_me();
					}
				}
			}
		}
		void feedAll()
		{
			for (int x = 0; x < RowCol; x++)
			{
				for (int y = 0; y < RowCol; y++)
				{
					if (!grid[x][y].empty())
					{
						grid[x][y].at(0).eat();
					}
				}
			}
		}
		void printAll()
		{
			for (int x = 0; x < RowCol; x++)
			{
				for (int y = 0; y < RowCol; y++)
				{
					if (!grid[x][y].empty())
					{
						grid[x][y].at(0).print();
					}
				}
			}
		}
		void getStatistics();

};



