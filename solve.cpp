#include"Sudoku.h"
int main()
{
	Sudoku ss;
	ss.setAnscount();
	ss.readIn();
	ss.solve(0);
	return 0;
}
