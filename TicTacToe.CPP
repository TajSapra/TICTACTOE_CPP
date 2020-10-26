#include <iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<string>
using namespace std;

char Board [3][3];

int i, j, result=0;

void PrintResult();

class person
{
		 string Name;
		 int grade;
	    public:
		 void getdata(){
			cout<<"Enter your name: "<<endl;
			cin.ignore();
			getline(cin, Name);
			cout<<"Enter your class: "<<endl;
			cin>>grade;
		 }
		 void showdata()
		 {
			cout<<"Name: "<<Name<<endl;
			cout<<"Class: "<<grade<<endl;
		 }
};

class match{
	person a,b;
};


void initializeBoard()
{
	 for(i=0;i<3;i++)
	 {
		for(j=0;j<3;j++)
		{
		 	Board[i][j]='E';
		}
	 }
}

void PrintBoard()
{
	 for(i=0;i<3;i++)
	 {
		for(j=0;j<3;j++)
		{
		 	cout<<Board[i][j]<<" ";
		}
		cout<<endl;
	 }
}

void chance()
{
	 int chancenum=1, row=0, column=0, flag=0;
	 while(result==0)
	 {
	 	if(chancenum%2==0)
			do{	
		 		cout<<"Enter the row number"<<endl;
			 	cin>>row;
				cout<<"Enter the column number"<<endl;
			 	cin>>column;
		 		if(Board[row-1][column-1]=='E')
				{
					Board[row-1][column-1]='X';
					flag=1;
				}
		 	      else 
					cout<<"Incorrect Move! Try Again:\n";
			}while(flag==0);
		 else
			do{
				cout<<"Enter the row number"<<endl;
				cin>>row;
		 		cout<<"Enter the column number"<<endl;
		 		cin>>column;
		 		if(Board[row-1][column-1]=='E')
				{
		 			Board[row-1][column-1]='O';
					flag=1;
				}
		      else 
					cout<<"Incorrect Move! Try Again:\n";
			}while(flag==0);
		chancenum++;
		PrintBoard();
		PrintResult();
	}
}

int CheckTicTacToe()
{
	 int numX=0, numO=0, numE=0; 
	 for(i=0;i<3;i++)                //row check
	 {
		numX=0; numO=0; 
		 for(j=0;j<3;j++)
		{
				if(Board[i][j]=='X')
				{
					numX++;
				}
				if(Board[i][j]=='O')
				{
					numO++;
				}
				if(Board[i][j]=='E')
				{
					numE++;
				}
				if(numX==3)
					return 2; 
				    else if(numO==3)
					 return 1; 
				
					  

		}
	 }

	 for(i=0;i<3;i++) //column check
	 {     numX=0;numO=0;
		  for(j=0;j<3;j++)
		  {
				if(Board[j][i]=='X')
				{
					 numX++;
				}
				if(Board[j][i]=='O')
				{
					 numO++;
				}
	
				if(numX==3)
					return 2; 
				    else if(numO==3)
					 return 1; 
					  


		  }
	 }
	
	numX=0;numO=0;
  	for(i=0;i<3;i++)       //diagonal 1 check
	{	
		if(Board[i][i]=='X')
		{
			numX++;
		}
		if(Board[i][i]=='O')
		{
			numO++;
		}

		if(numX==3)
			return 2; 
		    else if(numO==3)
			 return 1; 
					  

		  
	 }
	numX=0;numO=0;
	for(i=0;i<3;i++)     //diagonal 2 check
	{
		 if(Board[i][2-i]=='X')
		 {
		numX++;
		 }
		 if(Board[i][2-i]=='O')
		 {
		numO++;
		 }

		if(numX==3)
			return 2; 
		    else if(numO==3)
			 return 1; 
	}
      if (numE==0) 
		return 3;
	   else
		return 0;
	 
}

void PrintResult()
{
	 cout<<endl;
	 result=CheckTicTacToe();
	 switch(result)
	 {
		case 0:	cout<<"Continue play";
				break;

		case 1: 	cout<<"O wins the game";
				break;
		
		case 2:	cout<<"X wins the game";
				break;
	
		case 3:	cout<<"Dead lock. Play Again.";
				break;
	 }
	 cout<<endl<<endl;

}

void append()
{
	cout<<"Enter the details of the winner"<<endl;
	
	person P;
	
	P.getdata();

	fstream f1;
	
	f1.open("Winner.DAT",ios::binary|ios::app);
	
		f1.write((char*)&P, sizeof(P));
	
	f1.close();
}

void display()
{
	person P;
	
	fstream f1;
	
	f1.open("WINNER.DAT",ios::binary|ios::in);
	
	while(f1.read((char*)&P,sizeof(P)))
	{
		P.showdata();
	}
	
	f1.close();
}

void file()
{
	 cout<<"Enter the details of the winner:"<<endl;
	 append();
	 cout<<"Details of the winners till date:"<<endl;
	 display();
}

void playmatch(){
	result=0;
	cout<<"Instructions:"<<endl;
	cout<<"1) E represents empty cells."<<endl;
	cout<<"2) First chance is of letter X."<<endl;
	cout<<"3) If a deadlock occurs, the game ends automatically."<<endl;
	cout<<"4) After the game is over, the player, who won will be displayed."<<endl;
	cout<<"5) The column number and row number asked for in the chance, will convert E to"<<endl;
	cout<<" letter O or X respectively as per the chance."<<endl;
	cout<<"6) All the best!"<<endl;
	initializeBoard();
	PrintBoard();
	while (result==0)
	{
		chance();
	}
	if (result==1||result==2)
	{
		file();
	}
}

int main()
{
	playmatch();
	// playmatch();
	return 0;
}

