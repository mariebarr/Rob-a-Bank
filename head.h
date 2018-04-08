#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
const int MIN=0;
const int MAX=99;
//implement Spot class to hold location of bank, police, and getaway car
class Spot{
	private:
		int x;
		int y;
	public:
		//initializes both values to zero
		Spot():x(MIN),y(MIN){}
		//constructor
		Spot(int new_x, int new_y){
			x=new_x;
			y=new_y;
			if(x<MIN)
				x=MIN;
			if(x>MAX)
				x=MAX;
			if(y<MIN)
				y=MIN;
			if(y>MAX)
				y=MAX;
		}
		void set_x(int new_x){
			x=new_x;
			if(x<MIN)
				x=MIN;
			if(x>MAX)
				x=MAX;
		}
		void set_y(int new_y){
			y=new_y;
			if(y<MIN)
				y=MIN;
			if(y>MAX)
				y=MAX;
		}
		int get_x(){
			return x;
		}
		int get_y(){
			return y;
		}
		int distance(){
			return sqrt(x*x+y*y);
		}
};

class Treasure{
	private:
		int x_min, x_max, y_min, y_max, value;
	public:
		const int MIN=0;
		const int MAX=99;
		Treasure(int new_x_min, int new_x_max, int new_y_min, int new_y_max, int new_value){
			x_min=new_x_min;
			if(x_min<MIN)
				x_min=MIN;
			x_max=new_x_max;
			if(x_max>MAX)
				x_max=MAX;
			y_min=new_y_min;
			if(y_min<MIN)
				y_min=MIN;
			y_max=new_y_max;
			if(y_max>MAX)
				y_max=MAX;
			value=new_value;
			if(value<MIN)
				value=MIN;
		}
		Treasure():x_min(0),x_max(0),y_min(0),y_max(0),value(0){};
		int get_x_min(){
			return x_min;
		}
		int get_x_max(){
			return x_max;
		}
		int get_y_min(){
			return y_min;
		}
		int get_y_max(){
			return y_max;
		}
		int get_value(){
			return value;
		}
		void set_x_min(int new_x_min){
			x_min=new_x_min;
			if(x_min<MIN)
				x_min=MIN;
			//if user tries to set x_min greater than x_max, x_max will be assigned x_min. Dots on the PC. 
			if(x_min>x_max)
				x_min=x_max;
		}
		void set_x_max(int new_x_max){
			x_max=new_x_max;
			if(x_max>MAX)
				x_max=MAX;
			//
			if(x_max<x_min)
				x_max=x_min;
		}
		void set_y_min(int new_y_min){
			y_min=new_y_min;
			if(y_min<MIN)
				y_min=MIN;
			//
			if(y_min>y_max)
				y_min=y_max;
		}
		void set_y_max(int new_y_max){
			y_max=new_y_max;
			if(y_max>MAX)
				y_max=MAX;
			//
			if(y_max<y_min)
				y_max=y_min;
		}
		void set_value(int new_value){
			value=new_value;
			if(value<MIN)
				value=MIN;
		}
		//within()
		bool within(Spot s){
			//get_x is a function within the Spot class, so you NEED those PARENTHESES!!!!
			if(s.get_x()>=x_min&&s.get_x()<=x_max&&s.get_y()>=y_min&&s.get_y()<=y_max)
				return true;
			else
				return false;
		}
		int loot(){
			int this_value;
			this_value=value;
			//must put value=0 before the return statement cuz then it all ends!!!
			value=0;
			return this_value;

		}

};


