#include"Sudoku.h"
using namespace std;

void Sudoku::setAnscount(){
anscount=0;}
void Sudoku::giveQuestion(){
	int i;
	int temp[81]={0,4,0,2,5,0,0,0,8,0,3,0,4,0,9,1,7,0,0,0,0,0,8,1,2,0,0,0,0,6,0,0,0,7,2,0,0,0,0,6,0,4,0,0,0,0,1,2,0,0,0,3,0,0,0,0,3,8,1,0,0,0,0,0,6,4,9,0,2,0,1,0,7,0,0,0,4,5,0,9,0};
	for(i=0;i<81;i++)
	{table[i]=temp[i];}
	transform();

}

void Sudoku::readIn(){
	for(int i=0;i<81;i++){
	scanf("%d",&table[i]);
	}

}
bool Sudoku::checksolveable(){
	bool solve;
	solve=true;
	for(int i=0;i<81;i++)
	{
		if(table[i]!=0)
		{
			if(checkrepeat(table[i],i)==true)
			solve=false;
		}
	}

	return solve;


}

bool Sudoku::checkrepeat(int a,int n){

		int i,j,k,init,row,col;
		bool repeat;
		repeat=false;
		row=n/9;
		col=n%9;
		for(i=n-n%9;i<n-n%9+9;i++)
		{
		if(a==table[i]&&i!=n)
		{repeat=true;}
		}
		
		for(i=0;i<9;i++)
		{								
		k=n%9+9*i;
		if(a==table[k]&&k!=n)
	    {repeat=true;}
		}
		
		init=n-(row%3)*9-(col%3);
		for(i=0;i<3;i++)
		{
			if(table[init+i]==a&&(init+i)!=n)
			{repeat=true;}
			if(table[init+9+i]==a&&(init+i+9)!=n)
			{repeat=true;}
			if(table[init+18+i]==a&&(init+i+18)!=n)
			{repeat=true;}

		}																					
		return repeat;
}

void Sudoku::solve_2(int count){
	
	if(count==81)
        {
        anscount++;
	for(int j=0;j<81;j++)
	{temps[j]=table[j];
	}
	return;
	}
        if(table[count]==0)
        {
                for(int i=1;i<=9;++i)
                {table[count]=i;
                if(checkrepeat(table[count],count)==false)
                {solve_2(count+1);}
                }
        table[count]=0;
        }else{
        solve_2(count+1);
        }


}
void Sudoku::checkAnscount(){
	if(anscount==1)
	{printf("1\n");
		for(int j=0;j<81;j++)
        	{printf("%2d",temps[j]);
		if(j%9==8){printf("\n");}
		}
	}
	if(anscount==0)
	{printf("0");}
	if(anscount>=2)
	{printf("2");}
	}
void Sudoku::solve(){
	
	setAnscount();
	if(checksolveable()==true)
	{solve_2(0);}
	checkAnscount();
	return;
}
void Sudoku::changeNum(int a,int b){
	int temp[81];
	int i;
	for(i=0;i<81;i++)
	{
	temp[i]=table[i];
	}
	for(i=0;i<81;i++)
	{
	 if(a==temp[i])
	 {table[i]=b;}
	 if(b==temp[i])
     {table[i]=a;}
	}

}

void Sudoku::changeRow(int a,int b){
	int temp[81];
	int i;
	for(i=0;i<81;i++){temp[i]=table[i];}
	for(i=0;i<27;i++)
		{
			table[i+27*a]=temp[i+27*b];
			table[i+27*b]=temp[i+27*a];

		}
	
}
void Sudoku::changeCol(int a,int b){

	int temp[81];
	int i;
	for(i=0;i<81;i++)
	{temp[i]=table[i];
	}
	for(i=0;i<9;i++)	
	{
		table[3*b+9*i]=temp[3*a+9*i];
		table[3*b+1+9*i]=temp[3*a+1+9*i];
		table[3*b+2+9*i]=temp[3*a+2+9*i];
		table[3*a+9*i]=temp[3*b+9*i];
		table[3*a+1+9*i]=temp[3*b+1+9*i];
		table[3*a+2+9*i]=temp[3*b+2+9*i];
	}

												
}
void Sudoku::rotate(int n){
	
	while(n!=0)
	{
	int temp[81];
	int i,k=72,j=0;
	for(i=0;i<81;i++)
	{temp[i]=table[i];
	}
	for(i=0;i<81;i++)
	{
	table[k-9*j]=temp[80-i];
	j++;
		if(i%9==8)
		{k=k+1;
		j=0;}

	}
	n--;
	}		
}

void Sudoku::flip(int n){

	int temp[81];
	int i;
	for(i=0;i<81;i++)
	{temp[i]=table[i];
	}
	if(n==0)
	{
		for(i=0;i<9;i++)
		{table[0+i]=temp[72+i];
		table[9+i]=temp[63+i];
		table[18+i]=temp[54+i];
		table[27+i]=temp[45+i];	
		table[45+i]=temp[27+i];
		table[54+i]=temp[18+i];
		table[63+i]=temp[9+i];
		table[72+i]=temp[0+i];
		}
	}
	if(n==1)
	{
		for(i=0;i<5;i++)
		{
		table[0+i]=temp[8-i]; table[8-i]=temp[0+i];
		table[9+i]=temp[17-i];table[17-i]=temp[9+i];
		table[18+i]=temp[26-i];table[26-i]=temp[18+i];
		table[27+i]=temp[35-i];table[35-i]=temp[27+i];
		table[36+i]=temp[44-i];table[44-i]=temp[36+i];
		table[45+i]=temp[53-i];table[53-i]=temp[45+i];
		table[54+i]=temp[62-i];table[62-i]=temp[54+i];
		table[63+i]=temp[71-i];table[71-i]=temp[63+i];
		table[72+i]=temp[80-i];table[80-i]=temp[72+i];	
		}
	}

}

void Sudoku::change(){

	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);	
	flip(rand()%2);	
}

void Sudoku::printOut(){

		int i;
		for(i=0;i<81;i++)
		{printf("%2d",table[i]);
		if(i%9==8)
		{printf("\n");}
		}
}

void Sudoku::transform(){

	
	change();
	printOut();
}
