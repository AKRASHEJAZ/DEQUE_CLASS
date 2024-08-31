#include<iostream>
#define SIZE 5

using namespace std;

class Deque
{
private:
    int Front,Rear;
    int arr[SIZE];
public:
    Deque()
    {
        Front = Rear = -1;
    }
    bool is_Empty()
    {
        if(Front == -1)
            return true;
        return false;
    }
    bool is_Full()
    {
        if(0 == Front && SIZE-1 == Rear)
            return true;
        else if(Rear+1 == Front)
            return true;
        else
            return false;
    }
    //INSERT AND REMOVE FROM FRONT

    void insert_At_Back(int value)
    {
        if(is_Full())
        {
            cout<<"DEQUE IS ALREADY FULL"<<endl;
            return;
        }
        else
        {
            if(Front == -1)
            {
                Front = 0;
                Rear = 0;
            }
            else if(Rear == SIZE-1)
            {
                Rear = 0;
            }
            else
            {
                Rear++;
            }
            arr[Rear] = value;
            cout<<"VALUE "<<value<<" HAS BEEN INSERTED AT INDEX "<<Rear<<endl;
        }
    }

    void remove_From_Back()
    {
        if(is_Empty())
        {
            cout<<"DEQUE IS EMPTY"<<endl;
            return;
        }
        else
        {
            cout<<"VALUE REMOVED FROM REAR INDEX "<<Rear<<endl;
            if(Rear == Front)
            {
                Rear = Front = -1;
            }
            else if(Rear == 0)
            {
                Rear = SIZE-1;
            }
            else
            {
                Rear--;
            }

        }
    }

    void remove_From_Front()
    {
        if(is_Empty())
        {
            cout<<"DEQUE IS EMPTY"<<endl;
            return;
        }
        else
        {
            cout<<"VALUE REMOVED FROM FRONT INDEX "<<Front<<endl;
            if(Rear == Front)
            {
                Front = Rear = -1;
            }
            else if(Front == SIZE-1)
            {
                Front = 0;
            }
            else
            {
                Front++;
            }
        }
    }
    void insert_At_Front(int value)
    {
        if(is_Full())
        {
            cout<<"DEQUE IS ALREADY FULL"<<endl;
            return;
        }
        else
        {
             if(Front == -1)
            {
                Front = 0;
                Rear = 0;
            }
            else if(Front == 0)
            {
                Front = SIZE-1;
            }
            else
            {
                Front--;
            }
            arr[Front] = value;
            cout<<"VALUE "<<value<<"HAS BEEN INSERTED AT INDEX "<<Front<<endl;
        }
    }

    void display()
    {
       //FRONT To BACK DISPLAY//
       if(is_Empty())
       {
           cout<<"DEQUE IS ALREADY EMPTY"<<endl;
           return;
       }
       else
       {
            int i=Front;
            while(true)
            {
                cout<<"VALUE AT INDEX "<<i<<" IS "<<arr[i]<<endl;
                if(i==Rear)
                {
                    break;
                }
                if(i == SIZE-1)
                {
                    i = 0;
                }
                else
                {
                    i++;
                }

            }
       }
    }
};

