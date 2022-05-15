#include<iostream>
#include<string.h>
using namespace std;
#define MAX 50

  char stack[MAX],str[MAX];
  int top=-1,length=0,count=0;

void getString() {
  cout<<"\n Enter a String: ";
  cin.getline(str,MAX);

  length=strlen(str);
}

void push(char temp) {

  if(top==MAX-1)  {
    cout<<"\n Stack Overflow!!!";
    return;
  }

  top++;
  stack[top]=temp;

}

char pop() {
  if(top==-1)  {
    cout<<"\n Stack Underflow!!!";
    char ch='\n';
    return ch;
  }
  char temp=stack[top];
  top--;
  return temp;
}

void palindrome() {
  for(int i=0; i<length; i++)
    push(str[i]);

  for(int i=0; i<length; i++) {
    if(str[i]==pop())
      count++;
  }

  if(count==length) {
    cout<<"\n Entered string is a Palindrome. \n";
  }
  else  cout<<"\n Entered string is not a Palindrome. \n";
}
int main()  {
  getString();
  palindrome();
  return 0;
}
