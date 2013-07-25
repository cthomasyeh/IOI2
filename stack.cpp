#include "stdafx.h"
#include <iostream>
#include < stdlib.h >
#include < stdio.h >
#include <Windows.h>
using namespace std;

class IntStack
{
public:
   IntStack(int num) {  top = 0; maxelem = num; s = new int[maxelem]; }
   void  push(int t)
   {
      if (top == maxelem) return;
      s[top++] = t;
   }

   int pop()
   {
      if (top == 0) return -1;
      return s[--top];
   }
   void display()
   {
     if (top == 0) { cout << "(empty)\n";  return; }
     for (int t=0 ; t < top ; t++) cout << s[t] << " ";
     cout << "\n";
   }
   int   empty()  {  return top == 0;  }
private:
   int *s;
   int top;
   int maxelem;
};

void main()
{
   IntStack *s = new IntStack(100);
   int d;

   s->push(101);
  
   s->display();
   s->empty();
   s->display();

   Sleep(100000);

}