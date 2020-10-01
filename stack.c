#include<stdio.h>
#include<conio.h>
using namespace std;
void push(int);
int pop(void);
void display();
int isfull();
int isempty();


#define size 5
int stack[size];          // top= 0-size-1
int top=-1;         //stack is empty

void push(int ele)
    {
        top++;
        if(isfull())                  //isfull
        {
                          //top=0 ,top=1
        stack[top]=ele;
        }
        else
        {
            printf("Stack is full");
        }
    }

int isfull()
    {
        if(top<size)
            {
                return 1;
            }
        else
        {
            return 0;
        }
        
    }

int pop()
    {
        if(isempty())
        {
            printf("Element deleted: %d",stack[top]);
        top--;

        }
        else
        {
            printf("Stack is empty");
        }
        return 0;
    }

int isempty()
    {
        if(top==-1)
            {
                return 1;
            }
        else 
        {
            return 0;
        }
    }

void display()
    {
        for(int i=size-1;i>=0;i--)
            {
                printf("|%d|",stack[i]);
                printf("__");
            }
    }



int main()
    {
        int n,num;
        printf("1)push");
        printf("2)pop");
        printf("3)traverse");
        printf("4)exit");
       scanf("%d",&n);
        while(true)
        {
        switch(n)
            {
                case 1:{
                    printf("Enter element : ");
                    scanf("%d",&num);
                    push(num);
                    break;
                }

                case 2:pop();
                break;

                case 3:display();
                break;

                default : printf("Wrong choice");
                break;
            }

        }
        
        return 0;
    }