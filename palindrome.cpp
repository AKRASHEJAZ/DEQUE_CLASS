#include<stdio.h>
#define SIZE 100

//DECLERATION OF ARRAY FOR QUEUE
char arr[SIZE];
int Front = -1;
int Back = -1;


//DEFINITION OF FUNCTIONS 
bool Is_Empty();
bool Is_Full();
void Enqueue(char);
char Dequeue();

int main()
{
    char str[SIZE];
    printf("ENTER ANY STRING TO TEST \n");
    scanf("%s",str);
    int i = 0;
    char ch ;
    do
    {
        ch = str[i];
        if(ch == '\0')
            break;
        printf("%c\n",ch);
        Enqueue(ch);
        i++;
    }
    while(ch != '\0');
    bool palindrome = true;
    for(int j = i-1; j >= 0;j--)
    {
        if(str[j] != Dequeue())
        {
            palindrome = false;
            break;
        }
    }
    if (palindrome)
    {
        printf("YOU ENTERED PALINDROME STRING \n");
    }
    else
    {
        printf("YOU ENTERED NON PALINDROME STRING \n");
    }
    int x;
    scanf("%d",&x);
    return 0;
}

bool Is_Empty()
{
    return Back == -1; 
}
bool Is_Full()
{
    return Back == SIZE -1;
}
void Enqueue(char ch)
{
    if(Is_Full())
    {
        printf("QUEUE IS FULL\n");
        return;
    }
    else if(Front == -1)
    {
        Front = Back = 0;
    }
    else
    {
        Back ++;
    }
    arr[Back] = ch;
}

char Dequeue()
{
    char ch;
    if(Is_Empty())
    {
        printf("QUEUE IS FULL\n");
        return '\0';
    }
    else if(Front == Back)
    {
        ch = arr[Front];
        Front = Back = -1;
    }
    else
    {
        ch = arr[Front];
        Front++;
    }
    return ch;
}