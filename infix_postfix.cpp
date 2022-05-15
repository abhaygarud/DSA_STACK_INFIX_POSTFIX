#include <iostream>
#include <cstring>
using namespace std;

#define M 50

int size=M;
char arr[M];
int top=-1;
int i=0;

int stacktop()
{
    return arr[top];
}

int Isfull()
{
    if(top=size-1)
    {
       
        return 1;
    }return 0;
}

int Isempty()
{
    if(top==-1)
    {
       
        return 1;
    }return 0;
}
void push(char val)
{
       if (!Isfull())
    {
        // top++;
        arr[++top] = val;
    }
    else
    {
        cout << "stack is oveflow push operation cannot perform" << endl;
    }
}
char pop()
{
    if(!Isempty()){
        return arr[top--];
    }
   
    return '#';
}

int Precedence(char ch)
{
    if(ch=='*'|| ch=='/'){
        return 3;
    }
    else if(ch=='+'||ch=='-')
    {
        return 2;
    }
    return 1;
}

int Isoperaotr(char ch)

{
    if(ch=='*'||ch=='/'||ch=='+'||ch=='-'){
      return 1;
    }return 0;
}
// void read(){

//     char infix[M];
//     cout<<"Enter the expression :"<<endl;
//     cin>>infix;

int InfixtoPostfix(char infix[M],char postfix[M])
{

    int i=0;
    int j=0;
    // char infix[M];
    // char postfix[M];

    while(infix[i]!='\0')
    {
        if(!Isoperaotr(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else
        {
            if(Precedence(infix[i])>Precedence(stacktop()))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop();
            }
        }
    }
     while (infix[j]!='\0')    
    {
      postfix[j]= pop();
        j++;
    }
    postfix[j] = '\0';
    return postfix[j];
      
 
    

}


int main(){
   char infix[M],postfix[M];
	cout<<"Enter Infix notation: "<<endl;;
	cin>>infix;
	
	InfixtoPostfix(infix,postfix);
	// cout<<"Infix: ",infix<<endl;
	cout<<"Postfix: "<<postfix<<endl;
    
}