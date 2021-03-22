#include<iostream>
#include<cstdlib>
#include<windows.h>

using namespace std;
class graph
{
private:
   int pos1,pos2,r,m;
public:
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void create()
{
  for(int i=0;i<=20;i++)
  {
    int s;
    s=20-i;
      Sleep(300);
      gotoxy(0,i);
      cout<<s;
      gotoxy(2,i);
      cout<<"|";
      gotoxy(58,20);
      cout<<"CREATING GRAPH(25,20)"<<endl;
      gotoxy(60,22);
      cout<<"PLEASE WAIT "<<endl;
      gotoxy(55,23);
      cout<<"KASHIF KHAN(COPYRIGHTS)"<<endl;
  }
  for(int j=0;j<=25;j++)
  {
      int x;
      x=j+3;
      Sleep(300);
      gotoxy(x,21);
      cout<<"-"<<endl;
      gotoxy(x,22);
      cout<<" "<<j;
  }
  gotoxy(0,22);
  cout<<"(0,0)";
  getpos();
}
void getpos()
{
    gotoxy(58,20);
    cout<<"GRAPH CREATED "<<endl;
    gotoxy(60,22);
    cout<<"DRAW ANY POINT "<<endl;
    gotoxy(56,0);
    cout<<"ENTER VALUE FOR X : ";
    cin>>pos1;
    gotoxy(56,2);
    cout<<"ENTER VALUE FOR Y : ";
    cin>>pos2;
    pos2=20-pos2;
    createpoint();
}
void createpoint()
{
    if(pos1<0 || pos1>25)
    {
        gotoxy(56,5);
        cout<<"ERROR CANT DRAW GRAPH "<<endl;
        gotoxy(0,25);
        system("pause");
        exit(0);
    }
    if(pos2<0 || pos2>20)
    {
        gotoxy(56,6);
        cout<<"ERROR CAN'T DRAW GRAPH "<<endl;
        gotoxy(0,25);
        system("pause");
        exit(0);
    }
    Sleep(500);
    gotoxy(pos1+3,pos2);
    cout<<"."<<endl;
    gotoxy(pos1+2,pos2+2);
    cout<<"("<<pos1<<","<<20-pos2<<")"<<endl;
    pos2=20-pos2;
        if(pos1==pos2)
        {
           line_to_origin();
        }
    gotoxy(0,28);
}
void line_to_origin()
{
    pos2=20-pos2;
        for( m=pos2;m<=20;m++)
        {
            if(pos1<0)
            {
            Sleep(300);
            gotoxy(3,21);
            cout<<"."<<endl;
            }
            else
            {
            Sleep(300);
            gotoxy(pos1+3,m);
            cout<<"."<<endl;
            int c=pos1-pos2;
            if(c>3)
            {
            misbehave();
            }
            pos1--;
            }
        }
}
void misbehave()
{
gotoxy(50,9);
cout<<"UNDER PROCESS"<<endl;
gotoxy(0,28);
}
};
int main()
{
    char ret;
    graph g1;
    g1.create();
    g1.misbehave();
    cout<<"DO YOU WANT TO CREATE ANOTHER POINTS(Y/N) : ";
    cin>>ret;
    while(ret=='Y'|| ret=='y')
    {
        g1.getpos();
    }
    return 0;
}
