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
int MaxTime = 120; //max time to rob bank is 2 min

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




	srand(time(0));
	Spot bank(0, 0);

	/*-------------------BANK PART---------------------------------*/
	//clock() and CLOCKS_PER_TICK 
	int start_time = time(0); //time begins ticking at bank
	MaxTime = time(0) + 120;
	int x_treas = rand() % 230 + 1;
	int money_value = rand() % 100000 + 150;
	Treasure money1(0, x_treas, 0, 0, money_value);


	auto it1 = map.find(name1);
	auto it2 = map.find(name2);


	cout << "LEVEL 1: SHALLOW FIN-ANCES" << endl;
	cout << "YOUR FIRST TASK IS TO ROB A LOAN SHARK IN THE DEAD OF NIGHT. EASY, RIGHT?" << endl;
	cout << "YOU WILL HAVE 2 MIN TO DO SO." << endl;
//	cout << "Press any character to begin" << endl;
//	cin >> c;
	/*
		if(cin) {
			char choice;
			int start_time = time(0);
			cout << "LET'S ASSUME YOU BROKE INTO THE STORE, BUT SET OFF THE SECURITY ALARM. YOU SEE THE SAFE WITH THE MONIES. YOU..." << endl;
			cout << "THE LOCAL ALLYING GANG IS ON THEIR WAY. YOU HAVE 2 MIN TO BREAK INTO THE SAFE." << endl;
			cout << "a) burn it off with thermite" << endl;
			cout << "b) guess the combo" << endl;
			cout << "c) clip the lock off with some industrial lock cutters" << endl;


	cout << "LEVEL 1: SHALLOW FIN-ANCES" << endl;
	cout << "PLAYER 2: SIT TIGHT AND BE READY TO DRIVE." << endl;
	cout << "PLAYER 1: YOUR FIRST TASK IS TO ROB A LOAN SHARK IN THE DEAD OF NIGHT. EASY, RIGHT?" << endl;
	cout << "YOU WILL HAVE 2 MIN TO DO SO." << endl;
	cout << "Press any character to begin" << endl;
	cin >> c;
	*/
//if(cin) {
//char choice=c;
//int start_time = time(0);
	cout << "LET'S ASSUME YOU BROKE INTO THE STORE, BUT SET OFF THE SECURITY ALARM. YOU SEE THE SAFE WITH THE MONIES. YOU..." << endl;
	cout << "THE LOCAL ALLYING GANG IS ON THEIR WAY. YOU HAVE 2 MIN TO BREAK INTO THE SAFE. TIME STARTED WHEN YOU WERE READING" << endl;
	cout << "a) burn it off with thermite" << endl;
	cout << "b) guess the combo" << endl;
	cout << "c) clip the lock off with some industrial lock cutters" << endl;

	//have the user cin an answer
	char choice;
	cin >> choice;
	int current_time = time(0);
	MaxTime = time(0) + 120;
	if (choice != 'a' && choice != 'b' && choice != 'c') die();
	if (choice == 'a') {
		cout << "You accidentally burn away some of the money." << endl;
		//collect da money
		int score1 = money1.loot();
		//set score to 30% of score would have gotten
		map.at(it1->first).set_score(.70 * score1);
		cout << "Money collected: " << "$" << score1 << endl; //fix to actual
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
				cout << "That's the combo!" << endl;
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
	current_time = current_time - start_time;//megan fix 
	cout << "Time completed in: " << MaxTime - current_time - 120 << endl; 
//	}
//}

	/*-------------------GETAWAY PART------------------------------*/

//DECLARATION OF IMPORTANT VARIABLES.
//generate a random velocity btwn 50 and 75mph for the police car
	int police_veloc = rand() % 75 + 50;

//1 dimensional world (y is always 0)
//place the police car somewhere initially
//x position is somewhere btwn 1000 and 500m away from bank
	int x = rand() % 1000 + 500;
	Spot police_car(x, 0);

//getaway car starts at bank
	Spot getaway_car(0, 0);

//generates random velocity btwn 65 and 90
	int getaway_veloc = rand() % 90 + 65;


//PLAYER 2's PART
	cout << "PLAYER 2: THE GANG IS STILL COMING. YOU MUST NAVIGATE THROUGH THE CITY MOST EFFICIENTLY." << endl;
	cout << "YOU HAVE 2 MIN." << endl;
//cout << "Press any character to begin" << endl;
//cin >> c;

//if(cin) {
//	int start_time = 0;
	current_time = time(0);
	MaxTime = time(0) + 120;
	int time_left = MaxTime - current_time; 
	//int time_since_start = current_time - start_time;
	//char choice;
	cout << "YOU ARE DRIVING. ENTER LETTERS a, b, c TO PICK YOUR ROUTE." << endl;
	cout << "a) left" << endl;
	cout << "b) right" << endl;
	cout << "c) straight" << endl;
	cin >> choice;

	if (choice == 'a') {
		//cout<<"You ran into a pedestrian. The cops catch you. You go to jail. Game over."<<endl;
		cout << "You ran into a pedestrian. You wait 1 min for him/her/it to cross." << endl;
		cout << "Time left: " << time_left - 60 << endl;
	}
	else if (choice == 'b') {
		cout << "You encounter steep hills. Bye bye velocity." << endl;
		getaway_veloc -= 20; 
		cout << getaway_veloc << endl; 
	}
	else if (choice == 'c') {
		cout << "Still deciding" << endl;
	}
//}


//if riddle is solved...
	cout << "Congratulations, you are a riddlemaster. Continue to the getaway car." << endl;


//IF time>=time_caught....die...police caught you


//time when they meet (are caught)
	double time_caught = abs(getaway_car.distance() - police_car.distance()) / (police_veloc - getaway_veloc);

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
	cout << "The winner is " << winner << endl;
	cout << "with a score of: " << winner_score << endl;
	cout << "GAME OVER." << endl;

}
