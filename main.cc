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


const int MaxTime = 120; //max time to rob bank is 2 min 



//int main(){

//THE HEAP
/*vector<int>scores;
  int num;
  cout<<"Enter numbers into the heap (-999 to end): "<<endl;
  while(cin){
  cin>>num;
  if(num==-999)
  break;
  scores.push_back(num);
  }
  make_heap(scores.begin(),scores.end());
  cout<<"The max element of the heap is: "<<scores.front()<<endl;
  */
//globals
string name1,name2;
int main(){

//HOLD PLAYER 1 AND PLAYER 2'S DATA IN A HASH TABLE
unordered_map<string,Competitor>map;
cout<<"WELCOME TO ROB-A-BANK. THIS IS A 2 PLAYER RPG. ENTER YOUR NAMES TO START, DONE TO END."<<endl;
int a=0;
while(cin){
	//enter players name
	if(a==0){
		cout<<"PLAYER 1: "<<endl;
		getline(cin,name1);
		Competitor c;
		c.set_name(name1);
		c.set_score(0);
		pair<string,Competitor>mymap(c.get_name(),c);
		map.insert(mymap);
	//	continue;
	}
	else cout<<"PLAYER 2: "<<endl;
	//string name;
	getline(cin,name2);

	Competitor c;
	c.set_name(name2);
	c.set_score(0);
	pair<string,Competitor>mymap(c.get_name(),c);
	map.insert(mymap);
	a++;
	if(a==2)
		break;
}




srand(time(0));
//place bank at 0,0. this will not change.
Spot bank(0,0);

/*-------------------BANK PART---------------------------------*/
int start_time = time(0); //time begins ticking at bank
int x_treas=rand()%230+1;
int money_value=rand()%100000+150;
Treasure money(0,x_treas,0,0,money_value);

//Spot robbers_pos(0,0);

auto it=map.find(name1);
auto it2=map.find(name2);
//auto it2=it->second;

//PLAYER 1'S RIDDLE
cout<<"What color are eggs? (riddle)"<<endl;
string ans;
cin>>ans;
if(ans=="white" or ans=="White"){
	int score=money.loot();
	map.at(it->first).set_score(score);
	cout<<"SCORE: "<<score<<endl;
}
else cout<<"no cigar."<<endl;


money_value=rand()%100000+150;
//PLAYER 2'S RIDDLE
cout<<"What color are eggs? (riddle)"<<endl;
//string ans;
cin>>ans;
if(ans=="white" or ans=="White"){
	    int score2=money.loot();
		cout<<score2;
		map.at(it2->first).set_score(score2);
		cout<<"SCORE: "<<score2<<endl;
}
else cout<<"no cigar."<<endl;


	
/*-------------------GETAWAY PART------------------------------*/	
	


//if riddle is solved...
cout<<"Congratulations, you are a riddlemaster. Continue to the getaway car."<<endl;

//srand(time(0));
//generate a random velocity btwn 50 and 75mph for the police car
int police_veloc=rand()%75+50;

//1 dimensional world (y is always 0)
//place the police car somewhere initially
//x position is somewhere btwn 1000 and 500m away from bank
int x=rand()%1000+500;
Spot police_car(x,0);

//getaway car starts at bank
Spot getaway_car(0,0);

//generates random velocity btwn 65 and 90
int getaway_veloc=rand()%90+65;

//time when they meet (are caught)
double time_caught= abs(getaway_car.distance()-police_car.distance())/(police_veloc+getaway_veloc);


}
