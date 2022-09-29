#ifndef _TPROGRESS_T_
#define _TPROGRESS_T_

#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdio.h>
using namespace std;

struct XY
{
   int x;
   int y;
};

void gotoXY(int x,int y)
{
   HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD dwPos;
   dwPos.X=x;
   dwPos.Y=y;
   SetConsoleCursorPosition(hCon,dwPos);
}

XY getXY()
{
   HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO pcsbi;
   GetConsoleScreenBufferInfo(hCon,&pcsbi);
   int x = pcsbi.dwCursorPosition.X;
   int y = pcsbi.dwCursorPosition.Y;
   return {x,y};
}

void setX(int x)
{
   XY p = getXY();
   gotoXY(x,p.y);
}

void setXRel(int rel)
{
   XY p = getXY();
   p.x+=rel;
   setX(p.x);
}

void setY(int y)
{
   XY p = getXY();
   gotoXY(p.x,y);
}

void setYRel(int rel)
{
   XY p = getXY();
   p.y+=rel;
   setY(p.y);
}

void showCursor(bool b)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = b?TRUE:FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void _showProgress1(string mssg,int p)
{
   static char barr[]={'/','-','\\','|'};
   static int i=0;
   char c=barr[i++%4];

   cout << c <<lpad(intToString(p),2,' ') << "%";
   setXRel(-4);

}

void _showProgress2(string mssg,int p,char c,int size)
{
   static int max=0;

   int div = ((double)p/100)*size;
   if( div>max )
   {
      max=div;
      cout << c;
   }
}

int currTimeInSeconds()
{
   time_t t;
   time(&t);

   struct tm tmm=*localtime(&t);

   int h=tmm.tm_hour*60*60;
   int m=tmm.tm_min*60;
   int s=tmm.tm_sec;
   return h+m+s;
}

// ----------------------------------------------
// ----------------------------------------------

// TAD
struct Progress
{
   int progressType; // tipo de progress
   string mssg;      // mensaje a mostrar
   int barSize;      // en caso de tipo=2, largo de la barra
   char fillChar;    // en caso de tipo=2, caracter de relleno
   int initTime;     // tiempo de inicio del progress
};

Progress progress(string mssg)
{
   int PROGRESS_TYPE=1;
   return {PROGRESS_TYPE,mssg,0,0,1};
}

Progress progress(string mssg,int barSize,char fillChar)
{
   int PROGRESS_TYPE=2;
   return {PROGRESS_TYPE,mssg,barSize,fillChar,1};
}

void progressInit(Progress& p)
{
   p.initTime=currTimeInSeconds();
   showCursor(false);
   if( p.progressType==1 )
   {
      cout << p.mssg << " ";
   }
   else
   {
      string barr = "["+replicate(' ',p.barSize)+"]";
      cout << p.mssg << " " << barr;
      setXRel(-(p.barSize+1));
   }
}

void progressDestroy(Progress& p)
{
   int endTime = currTimeInSeconds();
   if( p.progressType==1)
   {
      setXRel(-1);
      if(p.progressType==1)
      {
         cout << "100% ";
      }
   }
   else
   {
      cout << p.fillChar;
      setXRel(2);
   }

   cout << "(" <<endTime-p.initTime<<" seconds) ";


   showCursor(true);
}

void progressShow(Progress& p,int curr)
{
   if( p.progressType==1)
   {
      _showProgress1(p.mssg,curr);
   }
   else
   {
      _showProgress2(p.mssg,curr,p.fillChar,p.barSize);
   }
}

void _heavyProcess(int n)
{
   for(int i=0;i<n;i++);
}

void progressDemo()
{
   // PROGRESS TIPO 1
   Progress p1 = progress("Demo progress tipo 1:");
   progressInit(p1);
   for(int i=0; i<100; i++)
   {
      progressShow(p1,i);
      _heavyProcess(15000000);
   }
   progressDestroy(p1);

   cout << endl;

   // PROGRESS TIPO 2
   Progress p2 = progress("Demo progress tipo 2:",30,'#');
   progressInit(p2);
   for(int i=0; i<100; i++)
   {
      progressShow(p2,i);
      _heavyProcess(48452294);
   }
   progressDestroy(p2);
}

#endif
