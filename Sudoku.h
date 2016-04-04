#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
using namespace std;
class Sudoku{
	public:
		void giveQuestion();
		void setAnscount();
		void readIn();
		bool checkrepeat(int a,int n);
		bool checksolveable();
		void solve_2(int count);
		void checkAnscount();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void change();
		void printOut();
		void transform();
	private:
	  int table[81];	
	  int temps[81];
	  int anscount;
};
