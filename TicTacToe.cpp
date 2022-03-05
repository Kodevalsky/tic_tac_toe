#include <iostream>

#include <conio.h> 

#include <string>

#include <windows.h>

#include <ctime>

 
using namespace std;
 

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);


void rysuj_panel(int square[],int dim1_size);


int check(int dim1_size,int square[]);


int random(int min, int max);


int main(int argc, char** argv) 
{
              int tab_size, dim1_size;
              SetConsoleTextAttribute(console, 15);
              cout << "    ----Welcome to Tic - Tac - Toe!----\n" <<endl;
              cout << "Choose on which board would you like to play? " << endl;
			  cout << "Availble boards include: 3x3 5x5--10x10" << endl << "(To choose, please type the side length)" << endl;
              cin >> dim1_size;
              while (dim1_size==4 || dim1_size<3 || dim1_size>10)
              {
                    system ("cls");
                    cout << "Invalid board value, please insert different length" << endl;
                    cin >> dim1_size; 
              }
              system ("cls");
              cout << "Press 1 if you want to play with another player or press 2 to play with AI" << endl;
              int AIcon;
              cin >> AIcon;
              while (AIcon<1 || AIcon>2)
              {
                    system ("cls");
                    cout << "Invalid gamemode number, please try different value (1==Player vs Player, 2==Player vs AI )" << endl;
                    cin >> AIcon;
              }
              tab_size=dim1_size*dim1_size;
              int *square = new int[tab_size+1];
              for(int i=0;i<tab_size+1;i++)
              {
                           square[i]=i;
              }
///////////////////////////////////////////////////////Player vs Player
              if (AIcon==1)
              {
              system("cls");
			  cout << "PLAYER 1 /// Please insert your name" << endl;
			  string gracz1, gracz2;
			  cin >> gracz1;
			  system("cls");
			  cout << "PLAYER 2 /// Please insert your name" << endl;
			  cin >> gracz2;
			  system("cls");
			  int first=random(0, 1);
              rysuj_panel(square,dim1_size);
              int pole;
              string gracz;
              for(int i=0;i<999;i){
                           if (first==0)
                                gracz=gracz1;
                           else if (first==1)
                                gracz=gracz2;
                           cout<< "Player " << gracz << " where would you like to put a cross?" << endl;
                           cin>>pole;
                           while (square[pole]==-1 || square[pole]==-8 || pole>tab_size || pole<1)
						   {
						   	   	cout << "Invalid field number, please try again." << endl;
						   		cin >> pole;
						   }
						   system("cls");
                           square[pole]=-1;
                           rysuj_panel(square,dim1_size);
                           char con=check(dim1_size, square);
                            if (con=='X')
                           {
                           if (first==0)
                                gracz=gracz1;
                           else if (first==1)
                                gracz=gracz2;
                           cout << "The winner is... " << gracz << endl << "Press any key to end the game...";
                           getch();
                           return 0;
                           }
                           i++;
                           if (i==tab_size)
                           break;
                           if (first==0)
                                gracz=gracz2;
                           else if (first==1)
                                gracz=gracz1;
                           cout<< "Player " << gracz << " where would you like to put a circle?" << endl;
                           cin>>pole;
                           while (square[pole]==-1 || square[pole]==-8 || pole>tab_size || pole<1)
						   {
						   	   	cout << "Invalid field number, please try again" << endl;
						   		cin >> pole;
						   }
                           system("cls");
                           square[pole]=-8;
                           rysuj_panel(square,dim1_size);
                           con=check(dim1_size, square);
                           if (con=='O')
                           {
                            if (first==0)
                                gracz=gracz2;
                           else if (first==1)
                                gracz=gracz1;
                           cout << "The winner is... " << gracz << endl << "Press any key to end the game...";
                           getch();
                           return 0;
                           }
                           i++;
                           if (i==tab_size)
                                break;
              }              
              system("cls");                
              cout << "There is no winner, It's a DRAW!" << endl << "Press any key to exit";
              getch();
              return 0;
              }
//////////////////////////////////////////////////////////////////// AI vs Player
              else if (AIcon==2)
              {
                    system("cls");
                    string gracz;
			        cout << "PLAYER /// Please insert your name" << endl;
			        cin >> gracz;
			        int first=random(0, 1);
			        int pole;
			        system("cls");
                    for (int i=0; i<999;i)
                    {
                           if (first==0)
                           {
                                int move=random(1, tab_size);
                                if (square[move]==-1 || square[move]==-8)
                                {
                                    while (square[move]==-1 || square[move]==-8)
                                        move=random(0, tab_size);
                                }
                                else;
                                square[move]=-1;
                                char con=check(dim1_size, square);
                                if (con=='X')
                                {
                                     cout << "The winner is... AI!" << endl << "Press any key to end the game...";
                                     getch();
                                     return 0;
                                }
                                i++;
                                if (i==tab_size)
                                    break;
                           }
                           if (first==1)
                           {
                                rysuj_panel(square, dim1_size);
                                cout<< "Player " << gracz << " where would you like to put a cross?" << endl;
                                cin>>pole;
                                while (square[pole]==-1 || square[pole]==-8 || pole>tab_size || pole<1)
						        {
						   	   	      cout << "Invalid field number, please try again." << endl;
						   	          cin >> pole;
						        }
                                square[pole]=-1;
                                char con=check(dim1_size, square);
                                if (con=='X')
                                {
                                    system("cls");
                                    cout << "The winner is... " << gracz << endl << "Press any key to end the game...";
                                    getch();
                                    return 0;
                                }
                                i++;
                                if (i==tab_size)
                                    break;
                                system ("cls");
                            }
                            if (first==0)
                            {
                                rysuj_panel(square, dim1_size);
                                 cout<< "Player " << gracz << " where would you like to put a circle?" << endl;
                                cin>>pole;
                                while (square[pole]==-1 || square[pole]==-8 || pole>tab_size || pole<1)
						        {
						   	   	      cout << "Invalid field number, please try again." << endl;
						   	          cin >> pole;
						        }
                                square[pole]=-8;
                                char con=check(dim1_size, square);
                                if (con=='O')
                                {
                                    system("cls");
                                    cout << "The winner is... " << gracz << endl << "Press any key to end the game...";
                                    getch();
                                    return 0;
                                }
                                i++;
                                if (i==tab_size)
                                    break;
                                system ("cls");
                            }
                            if (first==1)
                            {
                                int move=random(1, tab_size);
                                if (square[move]==-1 || square[move]==-8)
                                {
                                    while (square[move]==-1 || square[move]==-8)
                                        move=random(0, tab_size);
                                }
                                    square[move]=-8;
                                    char con=check(dim1_size, square);
                                    if (con=='O')
                                    {
                                        cout << "The winner is... AI!" << endl << "Press any key to end the game...";
                                        getch();
                                        return 0;
                                    }
                                    i++;
                                    if (i==tab_size){
                                    break;}
                                    }
                    }
                    system("cls");                
                    cout << "There is no winner, It's a DRAW!" << endl << "Press any key to exit";
                    getch();
                    return 0; 
              }              
}

 

/////////////////////////////////////////////////// Drawing board
void rysuj_panel(int square[],int dim1_size){
    int k=1;
	char c;
	cout <<"Tic Tac Toe Game! on board: " <<dim1_size <<"x" << dim1_size << endl << endl << endl << "";
	for(int j=0;j<dim1_size;j++)
	{
        for(int i=1;i<dim1_size+1;i++)
		{
            if(k<10)
			{
                if(i<dim1_size)
				{
                    if(square[k]==-1)
					{
                    	c= '0' + 40;
                    	SetConsoleTextAttribute(console, 10);
                    	cout<<"  "<<c;                     
                    	SetConsoleTextAttribute(console, 15);                                             
                    	cout << " | ";                                                           
                    }
                    else if(square[k]==-8)
					{
                    	c= '0' + 31;
                    	SetConsoleTextAttribute(console, 12);
                    	cout<<"  "<<c;                     
                  	 	SetConsoleTextAttribute(console, 15);                                                                                  
                    	cout << " | ";
                    }
                    else
                        cout<<" 0"<<square[k]<< " | ";
                }
                else
                    if(square[k]==-1)
					{
                        c= '0' + 40;
                        SetConsoleTextAttribute(console, 10);
                        cout<<"  "<<c;
                        SetConsoleTextAttribute(console, 15);
                    }
                    else if(square[k]==-8)
					{
                        c= '0' + 31;
                        SetConsoleTextAttribute(console, 12);
                        cout<<"  "<<c;
                        SetConsoleTextAttribute(console, 15);
                    }
                    else
                        cout<<" 0"<<square[k];
            }
            else			
			{
                if(i<dim1_size)				
				{
                    if(square[k]==-1)					
					{
                        c= '0' + 40;                        
                        SetConsoleTextAttribute(console, 10);
                        cout <<"  " << c;                        
                        SetConsoleTextAttribute(console, 15);                        
                        cout << " | ";
                    }
                    else if(square[k]==-8)					
					{
                    	c= '0' + 31;                    	
                    	SetConsoleTextAttribute(console, 12);
                        cout << "  " << c;                        
                        SetConsoleTextAttribute(console, 15);                       
                        cout << " | ";
                    }
                    else
                        cout<<" "<<square[k]<< " | ";
                }
                else
                    if(square[k]==-1)					
					{
                        c= '0' + 40;                        
                        SetConsoleTextAttribute(console, 10);
                        cout<<"  "<<c;                        
                        SetConsoleTextAttribute(console, 15);
                    }
                    else if(square[k]==-8)					
					{
                   		c= '0' + 31;        		
                  		SetConsoleTextAttribute(console, 12);
                    	cout<<"  "<<c;	
                    	SetConsoleTextAttribute(console, 15);
                    }
                    else
                    	cout<<" "<<square[k];
            }
            k++;
        }
        cout << endl << "" ;       
        if(j<dim1_size-1)
		{
            for(int i=1;i<dim1_size+1;i++)
			{
            	cout<<"------";
            }
        }
        cout<<endl << "";       
	}
}
//////////////////////////////////////Checking for win
int check(int dim1_size,int square[]){

    int k=1, num=1, win=0;
    char winner;
    winner='n';

    for (int i=1; i<=dim1_size; i++)
    {
        num=k;
        for (int j=1; j<=dim1_size; j++)
        {
            if (square[num]==-1)
                win+=-1;
            else if (square[num]==-8)
                win+=-8;
                num=num+dim1_size;
        }
        if (win==-1*dim1_size){
            winner='X';
            return winner;}
        else if (win==-8*dim1_size){
            winner='O';
            return winner;}
        else{
        k++;
        win=0;}
    }
    k=1, num=1, win=0;
    
    for (int i=1; i<=dim1_size; i++)
    {
        num=k;
        for (int j=1; j<=dim1_size; j++)
        {
            if (square[num]==-1)
                win+=-1;
            else if (square[num]==-8)
                win+=-8;
                num++;
        }
        if (win==-1*dim1_size){
            winner='X';
            return winner;}
        else if (win==-8*dim1_size){
            winner='O';
            return winner;}
        else{
        k=k+dim1_size;
        win=0;}
    }
    num=1, win=0;
    
    for (int i=1; i<=dim1_size; i++)
    {
        if (square[num]==-1)
                win+=-1;
        else if (square[num]==-8)
                win+=-8;
        else;
        num+=dim1_size+1;
    }
    if (win==-1*dim1_size){
        winner='X';
        return winner;}
    else if (win==-8*dim1_size){
        winner='O';
        return winner;}
    else;
    num=dim1_size, win=0;
        
    for (int i=1; i<=dim1_size; i++)
    {
        if (square[num]==-1)
                win+=-1;
        else if (square[num]==-8)
                win+=-8;
        else;
        num+=dim1_size-1;
    }
    if (win==-1*dim1_size){
        winner='X';
        return winner;}
    else if (win==-8*dim1_size){
        winner='O';
        return winner;}
    else;
}        

////////////////////////////////////////////////Random Numbers Generator
   
int random(int min, int max)
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); 
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

