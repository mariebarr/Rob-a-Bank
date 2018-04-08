#include<ctime>
#include<cmath>
#include "head.h"
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

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
int main(){
srand(time(0));
//place bank at 0,0. this will not change.
Spot bank(0,0);

/*-------------------BANK PART---------------------------------*/
int x_treas=rand()%230+1;
int money_value=rand()%100000+150;
Treasure money(0,x_treas,0,0,money_value);

//Spot robbers_pos(0,0);
cout<<"What color are eggs? (riddle)"<<endl;
string ans;
cin>>ans;
if(ans=="white" or ans=="White"){
	cout<<money.loot();
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
