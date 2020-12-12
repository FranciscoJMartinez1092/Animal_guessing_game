#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h> 
using namespace std;


void Print(vector<string> input)
{
	for( int i = 0; i < input.size(); i ++)
	{

			cout << i << ": " << input[i] << "\n";

	}
}

int Randomgenerator(int lowerbound, int upperbound)	
{
	int randomnumber;
	randomnumber = lowerbound + rand()%(upperbound-lowerbound + 1);
	return randomnumber;
}

int main()
{
	srand(time(0));
	vector<string> names;
	vector<string> namelist;
	string nameinput;
	string concatnator;
	string animalpicks;
	
	int randname;

	cout << "Enter at least five animal names, e.g., cat, dog, etc...";
	
	
	

	
	do
	{
		getline(cin, nameinput);
		for( int i = 0; i < nameinput.size(); i ++)
		{
			if(nameinput[i] != ' ')
			{
				concatnator +=  nameinput[i];
			}
			else
			{	
				if(nameinput[i - 1] != ' ' && i != 0)
				{
					names.push_back(concatnator);
					concatnator = "";
				}
			}
			
		}	
		if(concatnator != "")
		{	
			names.push_back(concatnator);
			concatnator = "";
		}
	}while(nameinput != "");






	int spoints = 0;
	int fpoints = 0;
	int underscore = 0;
	Print(names);
	while(true)
	{	
		int nameamount = Randomgenerator(1,3);
		vector<int> numberlog;
		int namechoice;
		string output;
		int amountcount = 0;
		int unique = 0;
		
		
		
		while(numberlog.size()  < nameamount)
		{	
			unique = 0;
			namechoice = Randomgenerator(0, names.size() - 1);
			
			
			if(numberlog.size() == 0)
			{	
				numberlog.push_back(namechoice);
				
				
				output += names[namechoice];
				
			}
			for(int j = 0; j <numberlog.size(); j++)
			{
				if(numberlog[j] == namechoice)
				{	
					break;
				}
				else
				{
					unique++;
					
				}
			}
			if(unique >= numberlog.size())
			{
				numberlog.push_back(namechoice);
				
				output += names[namechoice];
				unique = 0;
				
				
			}
		
			
		}
	
		
		
		random_shuffle(output.begin(), output.end());
		int underscorecounter = 0;
		int underscorechoice;
		int save;
		int position = 0;
		
		if(underscore > 0)
		{ if(underscore > output.size())
			{
				save = underscore;
				underscore = output.size();
				position ++;
				
			}
			while(underscorecounter < underscore)
			{
			
				underscorechoice = Randomgenerator(0, output.size() - 1);
				if(output[underscorechoice] != '_')
				{	
					underscorecounter ++;
					output[underscorechoice] = '_';
					
				}
				
			
			}
			if(position == 1)
			{
				underscore = save;
				position = 0;
			}
		}	
			
		
		cout << "\nWhat are " << nameamount << " animals in " << '\"' << output << '\"' << " ? ";
		vector<string> guessvector;
		int match = 0;
		
		string nameguess;
		concatnator = "";
		
		do
		{
			getline(cin, nameguess);
			if(nameguess == "?")
			{	
				Print(names);
				cout << "Enter again: ";
				guessvector.clear();
				match = 0;
				
			}
		
			if(nameguess == "quit")
			{
				cout << "Bye...";
				exit(0);
			}
			
			else
			{	
				for( int i = 0; i < nameguess.size(); i ++)
				{
					if(nameguess[i] != ' ')
					{
						concatnator +=  nameguess[i];
					}
					else
					{	
						if(nameguess[i - 1] != ' ' && i != 0)
						{
							guessvector.push_back(concatnator);
							concatnator = "";
						}
					}
					
				}	
				if(concatnator != "")
				{	
					guessvector.push_back(concatnator);
					concatnator = "";
				}
			
				
				for(int i = 0; i < numberlog.size(); i++)
				{	
					for(int j = 0; j < guessvector.size(); j++)	
					{
						if(guessvector[j] == names[numberlog[i]])
							match++;
					}
				}
			}
			if(guessvector.size() < numberlog.size() && nameguess != "?")
			{
				cout << "Your number of input is incorrect. Enter again: ";
				guessvector.clear();
				match = 0;
			}
		}while( guessvector.size() < numberlog.size());
			
				 if(match == numberlog.size())
				{	
					
					spoints ++;
					fpoints = 0;
					cout << "Yes!\n";
					if(spoints == 2)
					{	
						cout << "Succeeded two consecutive times, challenge goes up!\n";
						underscore ++;
						spoints = 0;
						
					}
				}
				else
				{
					cout << "Nope!\n";
					fpoints ++;
					spoints = 0;
					if(fpoints == 2 && underscore > 0)
					{
						cout << "Missed two consecutive times, challenge goes down!";
						underscore --;
						fpoints = 0;
					}
				}
			
		
		
	}
	return 0;
}