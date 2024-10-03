#include <iostream>
using namespace std;
class Node
{
public:
    int Data;
    Node * Link;
    Node(int data,Node * ptr = NULL)
    {
        Data = data;
        Link = ptr;
    }
};

class Stack
{
//STACK IMPLEMENTATION USING CLASSES SIMILAR TO FUNCTIONS
public:
    int Head = -1;
    Node * arr[100];
    bool Is_Full()
    {
        return Head == 99;
    }
    bool Is_Empty()
    {
        return Head == -1;
    }
    void Push(Node* ptr)
    {
        if(Is_Full())
        {
            cout<<"STACK FULL"<<endl;
            return;
        }
        else
        {
            Head ++;
            arr[Head] = ptr;
        }
    }
    Node* pop()
    {
        Node * ptr = arr[Head];
        Head --;
        return ptr;
    }
};

class Linked_List
{
public:
    Node * Head;
    Linked_List()
    {
        Head = NULL;
    }
    bool Is_Empty()
    {
        return Head == NULL;
    }
    void Add_To_Back(int data)
    {
        Node * temp = new Node(data);
        if(Is_Empty())
        {
            Head = temp;
            return;
        }
        else
        {
            Node * ptr = Head;
            while(ptr->Link !=  NULL)
            {
                ptr = ptr->Link;
            }
            ptr->Link = temp;
        }
    }

    void Add_To_Front(int data)
    {
        Node * temp = new Node(data);
        if(Is_Empty())
        {
            Head = temp;
            return;
        }
        else
        {
            temp -> Link = Head;
            Head = temp;
        }
    }

    void Delete_From_Front()
    {
        if(Is_Empty())
        {
            cout<<"EMPTY LIST"<<endl;
            return;
        }
        else if (Head->Link == NULL)
        {
            delete Head;
            Head = NULL;
            return;
        }
        else
        {
            Node * temp = Head;
            Head = Head->Link;
            delete temp;
        }
    }


     void Delete_From_Back()
    {
        if(Is_Empty())
        {
            cout<<"EMPTY LIST"<<endl;
            return;
        }
        else if (Head->Link == NULL)
        {
            delete Head;
            Head = NULL;
            return;
        }
        else
        {
            Node * temp = Head;
            while(temp->Link != NULL)
            {
                if(temp -> Link -> Link == NULL)
                {
                    delete temp -> Link ;
                    temp -> Link = NULL;
                }
                temp = temp -> Link;
            }
        }
    }

    void Clear()
    {
        while (!Is_Empty())
        {
            Delete_From_Front();
        }
    }

    Linked_List Reverse()
    {
        //REVERSAL USING LINKED LIST CLASS
        //USING ANOTHER LINKED LIST TO REVERSE
        Linked_List l_temp;
        Node * ptr = Head;
        while(ptr != NULL)
        {
            l_temp.Add_To_Front(ptr->Data);
            ptr = ptr->Link;
        }
        Clear();
        return l_temp;
    }
    void Display()
    {
        if(Is_Empty())
        {
            cout<<"EMPTY LIST"<<endl;
            return;
        }
        Node * ptr = Head;
        while(ptr != NULL)
        {
            cout<<"DATA IS "<<ptr->Data<<" AT "<<ptr->Link<<endl;
            ptr = ptr->Link;
        }
    }

    void Reverse_Using_Stack()
    {
        Stack s1;
        Node * temp;
        Node * ptr = Head;
        while(ptr != NULL)
        {
            //INSERTING ADDRESSES OF NODES IN STACK
            s1.Push(ptr);
            ptr = ptr ->Link;
        }
        //CHANGES LOCATION OF HEAD POINTER TO LAST NODE
        Head = s1.pop();
        temp = Head;
        while(! s1.Is_Empty())
        {
            //pops a value and makes link with last inserted value simple
            temp ->Link = s1.pop();
            temp = temp->Link;
        }
        temp->Link = NULL;
    }
    
    int Size()
    {
    	Node * ptr  = this -> Head;
    	int rtn = 0;
    	while(ptr != NULL)
    	{
    		ptr = ptr -> Link;
    		rtn ++;
		}
		return rtn;
	}
    
    void Sort()
    {
    	Node * Next;
    	Node * Current;
    	for(int i = 0 ; i < this -> Size();i++)
    	{
    		Current = Head;
    		Next = Current -> Link;
    		for(int j = 0; j < Size() - i - 1; j++)
    		{
    			if(Current -> Data > Next -> Data)
    			{
    				int temp = Current -> Data;
    				Current -> Data = Next -> Data;
    				Next -> Data = temp;
				}
				Current = Current -> Link;
				Next = Next -> Link;
			}
		}
	}
};
int main()
{
    Linked_List l1;
    l1.Add_To_Back(120);
    l1.Add_To_Back(4);
    l1.Add_To_Back(6);
    l1.Add_To_Back(16);
	cout<<"BEFORE REVERSING \n"<<endl;
    l1.Display();
    /*
	l1.Reverse_Using_Stack();
    cout<<"AFTER REVERSING \n"<<endl;
    l1.Display();
    cout<<"LOOK AT ADDRESSES"<<endl<<"THEY CHANGED ?????"<<endl;
    cout<<"TELL ME ????"<<endl; */
    l1.Sort();
    l1.Display();
	return 0;
}
