#include <iostream>
#include <windows.h>
using namespace std;
int data[5], hm, head, tail;

void show_queue()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

    cout<<endl;
    cout<<"-------------------"<<endl;
    cout<<"QUEUE CONTENT: "<<endl;
    cout<<"-------------------"<<endl;

    if (hm==0)
    {
        cout<<"The queue is empty";
    }

    else
    {
        int index;

        for (int i=0; i<hm; i++)
        {
            index=head+i;
            if (head+i>=5) index=head+i-5;
            cout<<data[index]<<" ";
        }
    }

    cout<<endl<<"-------------------"<<endl<<endl;


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
}

void push()
{
    if (hm>=5)
    {
        cout << "The queue is full!";
        Sleep(1000);
    }
    else
    {
        cout<<endl<< "PUSH (what number should be inserted to the queue): ";
        cin>>data[tail];
        tail=(tail+1)%5;
        hm=hm+1;
    }
}

void pop()
{
    if (hm==0)
    {
        cout<<"The queue is empty!";
        Sleep(1000);
    }
    else
    {
        cout<<endl<<"POP - deleted from the queue will be number: "<<data[head];
        head=(head+1)%5;
        hm=hm-1;
		Sleep(1000);
    }
}

void size()
{
    cout<<endl<<"Number of elements in the queue: "<<hm;
    Sleep(1000);
}

void empty()
{

    if (hm==0) cout<<endl<<"EMPTY (The queue is empty?) ->  TRUE";
    else cout<<endl<<"EMPTY (The queue is empty?) ->  FALSE";
    Sleep(1000);
}

int main()
{

    int choice;
    hm=0;
    head=0;
    tail=0;

    do
    {
        show_queue();

        cout<<"head="<<head<<"   tail="<<tail<<"   howmany="<<hm<<endl<<endl;

        cout << "MAIN MENU:"<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "1. PUSH (add element to the queue) "<<endl;
        cout << "2. POP (delete element from the queue) "<<endl;
        cout << "3. SIZE (how many elements are in the queue) "<<endl;
        cout << "4. EMPTY (Check if the queue is empty?) "<<endl;
        cout << "5. End of program "<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            size();
            break;

        case 4:
            empty();
            break;
        }

    }
    while (choice != 5);

    return 0;
}
