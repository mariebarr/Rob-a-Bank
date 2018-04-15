#include<string>
#include<unordered_map>
#include<ctime>
#include<cmath>
#include "head.h"
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int level1 = 0;
int MaxTime = 60; //max time to rob bank is 1 min

string uppercaseify(string s) {    //function that uppercaseifies inputs so case will not affect outcome
	for (int i = 0; i < s.size(); i++) {
		s.at(i) = toupper(s.at(i));
	}
	return s;
}

void die() {
	cout << "Not an option. You've been arrested for ignorance." << endl;
	exit(0);
}

//globals
char c;
string name1, name2;
int main() {
cout<<R"(
 _______  ______   _______
 \------\ \-----\  \\-----\				
   -----/  \    \\  \\____/    _______	
  \  \\ \   \    \\  \\_____  /______/
   \  \\ \   \____\\  \\___\\
    --- --/   -----/   \----/
	   
	   
	  )"<<endl;
	//HOLD PLAYER 1 AND PLAYER 2'S DATA IN A HASH TABLE
	unordered_map<string, Competitor>map;
	cout << "WELCOME TO ROB-A-BANK. THIS IS A 2 PLAYER RPG. ENTER YOUR NAMES TO START." << endl;
	int a = 0;
	while (cin) {
		//enter players name
		if (a == 0) {
			cout << "PLAYER 1: " << endl;
			getline(cin, name1);
			Competitor c;
			c.set_name(name1);
			c.set_score(0);
			pair<string, Competitor>mymap(c.get_name(), c);
			map.insert(mymap);
		}
		a++;
		if (a == 1) {
			cout << "PLAYER 2: " << endl;
			getline(cin, name2);

			Competitor c;
			c.set_name(name2);
			c.set_score(0);
			pair<string, Competitor>mymap(c.get_name(), c);
			map.insert(mymap);
			break;
		}
	}




	//srand(time(0));
	Spot bank(0, 0);

	/*-------------------BANK PART---------------------------------*/
	//clock() and CLOCKS_PER_TICK 
	int start_time = time(0); //time begins ticking at bank
	MaxTime = time(0) + 120;
	srand(time(0));
	int x_treas = rand() % 230 + 1;
	int money_value = rand() % 100000 + 150;
	Treasure money1(0, x_treas, 0, 0, money_value);


	auto it1 = map.find(name1);
	auto it2 = map.find(name2);


	cout << "LEVEL 1: SHALLOW FIN-ANCES" << endl;
	cout << "YOUR FIRST TASK IS TO ROB A LOAN SHARK IN THE DEAD OF NIGHT. EASY, RIGHT?" << endl;
	cout << "YOU WILL HAVE 2 MIN TO DO SO." << endl;


//int start_time = time(0);
	cout << "                                       " << endl; //space to make it easier to read
	cout << "                                       " << endl; 
	cout << "LET'S ASSUME YOU BROKE INTO THE STORE, BUT SET OFF THE SECURITY ALARM. YOU SEE THE SAFE WITH THE MONIES." << endl;
	cout << "THE LOCAL ALLYING GANG IS ON THEIR WAY. YOU HAVE 1 MIN TO BREAK INTO THE SAFE." << endl;
	cout << "WHAT WOULD YOU LIKE TO DO? TIME STARTED WHEN YOU WERE READING." << endl;
	cout << "a) burn it off with thermite" << endl;
	cout << "b) guess the combo" << endl;
	cout << "c) clip the lock off with some industrial lock cutters" << endl;

	//have the user cin an answer
	
	MaxTime = time(0) + 60;
	char choice;
	cin >> choice;
	int current_time = time(0); 

	if(current_time > MaxTime){
		cout << "You took too long to decide. The gang has caught you. GAME OVER." << endl; 
		exit(0); 
	} 
	if (choice != 'a' && choice != 'b' && choice != 'c') die();
	if (choice == 'a') {
		cout << "You accidentally burn away some of the money." << endl;
		//collect da money
		int score1 = money1.loot();
		//set score to 30% of score would have gotten
		map.at(it1->first).set_score(.70 * score1);
		cout << "Money salvaged: " << "$" << score1 << endl; //fix to actual
	} else if (choice == 'b') {
		cout << "Guess a three digit number. You have till time runs out." << endl;
		while (true) {
			int current_time = time(0);
			cout << "Time left: " << MaxTime - current_time << endl;
			if (current_time > MaxTime) {
				cout << "You were too slow. The allying loan shark gang caught you. YOU LOSE." << endl;
				return 0;
			}

			const int combo = 123;
			int guess_num = 0;
			cin >> guess_num;
			if (!cin) {
				cout << "Not a number" << endl;
				return 0;
			}
			if (guess_num == combo) {
				cout << "That's the combo! PLAYER TWO'S TURN." << endl;
				//collect money
				int score1 = money1.loot();
				map.at(it1->first).set_score(score1);
				cout << "Money collected: " << "$" << score1 << endl; //fix to actual
				break;
			}
		}
	} else if (choice == 'c') {
		int score1 = money1.loot();
		map.at(it1->first).set_score(score1);
		cout << "Money collected: " << "$" << score1  << endl; //fix to actual
	}

//	}
//}

	/*-------------------GETAWAY PART------------------------------*/

//Player 2 starts w/ player 1's ending score
//int score2=score1;
map.at(it2->first).set_score(map.at(it1->first).get_score()/2);
int score2=map.at(it2->first).get_score();
//DECLARATION OF IMPORTANT VARIABLES.
//generate a random velocity btwn 50 and 75mph for the police car
	int police_veloc = rand() % 100 + 75;

//1 dimensional world (y is always 0)
//place the police car somewhere initially
//x position is somewhere btwn 1000 and 500m away from bank
	int x = rand() % 1000 + 500;
	Spot police_car(x, 0);

//getaway car starts at bank
	Spot getaway_car(0, 0);

//generates random velocity btwn 65 and 90
	int getaway_veloc = rand() % 90 + 65;

//time when they meet (are caught) 
	double time_caught = abs((getaway_car.distance() - police_car.distance()) / (police_veloc - getaway_veloc));

	//FOR ME
	//	cout<<time_caught;
//PLAYER 2's PART
	cout << "                                                    " << endl; //adding space bc to make it easier to read
	cout << "PLAYER 2: THE GANG IS STILL COMING. YOU MUST NAVIGATE THROUGH THE CITY MOST EFFICIENTLY." << endl;
	cout << "YOU HAVE 2 MIN." << endl;

	MaxTime = time(0) + 120; 	 
	

	cout << "YOU ARE DRIVING. ENTER LETTERS a, b, c TO PICK YOUR ROUTE." << endl;
	cout << "a) left" << endl;
	cout << "b) right" << endl;
	cout << "c) straight" << endl;
	cin >> choice;
	current_time = time(0); 
	cout << "                                        " << endl;//space 

	if (current_time > MaxTime) {
		cout << "You took too long to decide. The gang caught you. GAME OVER." << endl;
		exit(0); 
	}
	if (choice == 'a') {
		//cout<<"You ran into a pedestrian. The cops catch you. You go to jail. Game over."<<endl;
		int escape_time = MaxTime-current_time; 
		cout << "You ran into a pedestrian. You wait 30s for him/her/it to cross." << endl;
		cout << "You have " << escape_time - 30 << "s to escape." << endl;
	//	cout << "The gang has " << time_caught <<"s to catch you." << endl; 
		if(double(escape_time-30) <= time_caught) {
			cout << "Sorry dude, the gang overtook you. GAME OVER." << endl; 
			map.at(it2->first).set_score(0);
		//	cout << "You get $" << score2 << endl; 
	}
	else if(double(escape_time-30) > time_caught)
		cout << "You escaped the gang!"<<endl;// Plus 50 for being awesome."<<endl;// LEVEL 1 COMPLETE." << endl;
		int add=rand()%403003+2000;
		map.at(it2->first).set_score(score2+add);
		cout << "You get: $" << map.at(it2->first).get_score() << endl; 
	}
	else if (choice == 'b') {
		cout << "You encounter steep hills. Bye bye velocity." << endl;
		getaway_veloc -= 20; 
		cout << "Your speed is: " << getaway_veloc <<" m/s" << endl; 
	//	cout << "The gang is travelling at: " << time_caught<< "m/s" << endl;
		if(current_time <= time_caught){
			cout << "Sorry dude, the gang overtook you. GAME OVER." << endl;
			map.at(it2->first).set_score(0);
			cout << "You get: $" << map.at(it2->first).get_score() << endl; 
		//	cout << "You get $" << score2 << endl; 
			exit(0); 
		}
		else{
			cout << "You escaped the gang!"<<endl; // LEVEL 1 COMPLETE." << endl; 
			int add2=rand()%20000+503;
			map.at(it2->first).set_score(score2+add2);
			cout << "You get: $" << map.at(it2->first).get_score() << endl; 
		}
	}

	else if (choice == 'c') {
		cout << "You convieniently found a highway. Your speed has been increased by 20 m/s." << endl;
		getaway_veloc += 20; 
		cout << "Your speed is: " << getaway_veloc << " m/s" << endl; 
		if(current_time <= time_caught){
			cout << "Sorry dude, the gang overtook you. GAME OVER." << endl;
			map.at(it2->first).set_score(0);
			cout << "You get: $" << map.at(it2->first).get_score() << endl; 
			exit(0); 
		}
		else{
			cout << "You escaped the gang!"<<endl; //LEVEL 1 COMPLETE." << endl; 
			int add3=rand()%90000+9034;
			map.at(it2->first).set_score(score2+add3);
			cout << "You get: $" << map.at(it2->first).get_score() << endl; 
		}
	}
	

//END OF PROGRAM. OUTPUT FINAL RESULTS.
//THE HEAP
	vector<int>scores;
	scores.push_back(map.at(it1->first).get_score());
	scores.push_back(map.at(it2->first).get_score());
	make_heap(scores.begin(), scores.end());

//store winner. scores.front() is top score from the heap!
	string winner;
	int winner_score = scores.front();
	if (map.at(it1->first).get_score() == winner_score) {
		winner = map.at(it1->first).get_name();
		winner_score = map.at(it1->first).get_score();
	} else {
		winner = map.at(it2->first).get_name();
		winner_score = map.at(it2->first).get_score();
	}
	cout << "                                        " << endl; 
	cout << "The winner is " << winner << endl;
	cout << "with a score of: $" << winner_score << endl;
	cout << "                         " << endl; 
	cout<<"Final results:"<<endl;
//	cout<<map.at(it1->first).get_name()<<":"<<endl<<"$"<<map.at(it1->first).get_score()<<endl;
//	cout<<map.at(it2->first).get_name()<<":"<<endl<<"$"<<map.at(it2->first).get_score()<<endl;

	cout<<map.at(it1->first).get_name()<<":"<< " $"<<map.at(it1->first).get_score()<<endl;
	cout<<map.at(it2->first).get_name()<<":"<< " $"<<map.at(it2->first).get_score()<<endl;

	
	cout << "GAME OVER." << endl;

}
