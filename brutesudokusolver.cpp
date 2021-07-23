#include <iostream>
#include<conio.h>
//#include<fstream>
using namespace std;

int checkerror(int[9][9],int,int,int);
int findnext(int[9][9],int&,int&);
int solve(int[9][9],int ,int);

long int backtracks;

int main()
{
    int i,j;
    char line[9];
    int sud[9][9];
/*  fstream fin;
    fin.open("somefile.dat",ios::in);
    for(int g=0;g<9;g++)
    {
        fin>>line;
        for(int h=0;h<9;h++)
        {
            sud[g][h]=(int)line[h]-48;
        }
    }
    fin.close();*/
    cout << "\n enter the sudoku puzzle:\n\n";
    char ch;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cout <<" "; ch=getche();
            if(ch==' ')
            {
                sud[j][i]=0;
            }
            else
            {
                sud[j][i]=(int)ch -48;
            }
        }
        cout <<"\n";
    }

    i=0;j=0;

    solve(sud,i,j);
//  cout <<endl<<((double)(finish-start)/CLOCKS_PER_SEC) <<"\n";
    cout<<"\n the solution is:\n";
    for(j=1;j<=9;j++)
    {
        cout <<endl;
        if ((j==4)||(j==7))
        {
            cout << "-------+-------+-------";
            cout << endl;
        }
        for(i=1;i<=9;i++)
        {
            if(sud[i-1][j-1]!=0)
                cout <<" "<< sud[i-1][j-1];
            else
                cout <<" -";
            if((i==3)||(i==6))
                cout <<" |";
        }
    }
/*  fstream fout;
    fout.open("somefile.dat",ios::out|ios::app);
    for(int g=0;g<9;g++)
    {
        for(int h=0;h<9;h++)
        {
            fout << sud[g][h];
        }
        fout <<"\n";
    }
    fout.close();*/
    getch();
    return 0;
}

int checkerror(int sud[9][9],int i,int j,int n)
{
    int x,s,t,r,u;
    for(x=0;x<9;x++)
    {
        if(sud[i][x]==n)
        {
            return 0;
        }
    }
    for(x=0;x<9;x++)
    {
        if(sud[x][j]==n)
        {
            return 0;
        }
    }
    s=i/3;
    r=j/3;
    for(t=s*3;t<(s*3+3);t++)
    {
        for(u=r*3;u<(r*3+3);u++)
        {
            if(sud[t][u]==n)
            {
                return 0;
            }
        }
    }
    return 1;
}
int findnext(int sud[9][9],int& i, int& j)
{
    for(int x=0;x<9;x++)
    {
        for(int y=0;y<9;y++)
        {
            if(sud[x][y]==0)
            {
                i=x;j=y;
                return 0;
            }
        }
    }
    i=-1;
    return 0;
}
int solve(int sud[9][9],int i,int j)
{
    findnext(sud,i,j);
    if(i==-1)
    {
        return 1;
    }
    for(int n=1;n<=9;n++)
    {
        if(checkerror(sud,i,j,n)==1)
        {
            sud[i][j]=n;
            if(solve(sud,i,j))
            {
                return 1;
            }
            else
            {
                sud[i][j]=0;
                backtracks++;
            }
        }
    }
    return 0;
}
