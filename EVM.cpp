// EVM using Data Structures
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//============================Class declaration=======================//

// Class for voter
class Voter
{
public:
    int Voter_ID;
    string Name;
    int Vote;
    //Constructor
    Voter(int id, string s, int v)
    {
        Voter_ID = id;
        Name = s;
        Vote = v;
    }
};

// Class for Node of Linked List
class Node
{
public:
    Voter *voter;
    Node *next;

    //Constructor
    Node(Voter *v)
    {
        voter = v;
        next = NULL;
    }
    //Methods
    void Print_data();
};

//Class for Parties
class Parties
{
public:
    int Cong, Bjp, Ncp, Bsp, Cpi;
    //Constructor
    Parties()
    {

        Cong = Bjp = Ncp = Bsp = Cpi = 0;
    }
    //Methods
    void Vote_Count(Node *v);
    void Result();
};

//Class for Voting Queue
class Voting_Queue
{
public:
    Node *front;
    Node *rear;
    int total_count;
    //Constructor
    Voting_Queue()
    {
        front = NULL;
        rear = NULL;
        total_count = 0;
    }

    //Methods
    bool is_empty();
    bool is_full();
    void enqueue(Node *n);
    Node *dequeue();
    void print_queue();
};
//================================================================================//

//====================Methods for Voting Queue==================================//

//Method to Check Whether the Voting Queue is empty
bool Voting_Queue::is_empty()
{
    return rear == NULL;
}
//Method to Check Whether the Voting Queue is full
bool Voting_Queue::is_full()
{
    Voter *v = new Voter(1, "ex", 1);
    return v == NULL;
}

//Method to insert a Voter's Node in Voting Queue
void Voting_Queue::enqueue(Node *n)
{
    if (is_full())
    {
        cout << "\n Sorry the Queue is full!\n";
    }
    if (is_empty())
    {
        front = n;
        rear = front;
        total_count++;
        return;
    }

    if (front == rear && front != NULL)
    {
        rear = n;
        front->next = rear;
        total_count++;
        return;
    }

    else
    {
        rear->next = n;
        rear = rear->next;
        total_count++;
        return;
    }
}

//Method to remove a Voter's Node from the Voting Queue
Node *Voting_Queue::dequeue()
{
    if (is_empty())
    {
        cout << "\nSorry the Queue is Empty\n";
        return NULL;
    }
    Node *temp = front;
    if (front == rear && front != NULL)
    {
        front = NULL;
        rear = NULL;
        total_count--;
        return temp;
    }
    else
    {
        front = front->next;
        total_count--;
    }
    return temp;
}
//=============================================================================//

//====================Methods for Parties==================================//

//Method to count a votr of a voter
void Parties::Vote_Count(Node *v)
{
    int vote = (v->voter)->Vote;

    switch (vote)
    {
    case 1:
    {
        Cong++;
        break;
    }
    case 2:
    {
        Bjp++;
        break;
    }
    case 3:
    {
        Ncp++;
        break;
    }
    case 4:
    {
        Bsp++;
        break;
    }
    case 5:
    {
        Cpi++;
        break;
    }

    default:
    {
        cout << "\n No such party exists !\n";

        break;
    }
    }

    delete v;
}

//Method to Display Result
void Parties::Result()
{
    int arr[5] = {Cong, Bjp, Ncp, Bsp, Cpi};
    /*arr[0] = Cong;
    arr[1] = Bjp;
    arr[2] = Cong;
    arr[3] = Cong;
    arr[4] = Cong;*/

    sort(arr, arr + 5);
    cout << "   \n--------------RESULTS------------\n";
    ///for (int i = 4; i >= 0; i--)
    int i = 4;
    while (i >= 0)
    {

        if (arr[i] == Cong)
        {
            cout << "Cong (INC) :  " << Cong << endl;
            i--;
        }
        if (arr[i] == Bjp)
        {
            cout << "BJP :  " << Bjp << endl;
            i--;
        }
        if (arr[i] == Ncp)
        {
            cout << "NCP :  " << Ncp << endl;
            i--;
        }
        if (arr[i] == Bsp)
        {
            cout << "BSP :  " << Bsp << endl;
            i--;
        }
        if (arr[i] == Cpi)
        {
            cout << "CPI (left) :  " << Cpi << endl;
            i--;
        }
        // cout << arr[i] << endl;
    }
    return;
}

//=================================================================================//

//=========================================Testing====================================//

//Testing
void Node::Print_data()
{
    cout << "\n Name of the Voter : " << voter->Name << "\n Voter ID : " << voter->Voter_ID;
}

//Printing Queue(testing)
void Voting_Queue::print_queue()
{
    cout << "\n Queue : [ ";
    for (Node *i = front; i != rear; i = i->next)
    {
        cout << (i->voter)->Name << " ";
    }
    cout << (rear->voter)->Name << " ]";
}
//===========================================================================================//

//=======================================Driver Program==================================//

//Driver Code
int main()
{
    Voting_Queue *V = new Voting_Queue();

    cout << "\n            /===================Envision your Future...Vote!!===================\\ \n";
    int choice = 0;

    while (choice != 3)
    {

        cout << "\n\n MENU : \n"
             << "1. Vote \n"
             << "   (for admins)\n"
             << "2. Stop Voting\n"
             << "3. Exit\n";
        cout << "  \nEnter your Choice : ";
        cin >> choice;
        system("cls");

        switch (choice)
        {

        case 1:
        {

            cout << "\n            /===================Envision your Future...Vote!!===================\\ \n";

            int id, vote;
            string name;

            cout << "\n Enter your Id :";
            cin >> id;
            cout << "Enter your name : ";
            cin >> name;

            cout << "\n Party List :\n"
                 << "1.INC(Cong)\n"
                 << "2.BJP\n"
                 << "3.NCP\n"
                 << "4.BSP\n"
                 << "5.CPI(left)\n";
            cout << "\n  Enter to vote : ";
            cin >> vote;

            Voter *v = new Voter(id, name, vote);
            Node *n = new Node(v);
            V->enqueue(n);
            cout << "\n ThankYou! your vote has been recorded\n";

            break;
        }
        case 2:
        {
            Parties *p = new Parties();
            while (V->is_empty() == false)
            {
                Node *n = V->dequeue();
                p->Vote_Count(n);
            }
            p->Result();
            choice = 3;

            break;
        }

        case 3:
        {
            exit(0);
        }

        default:
        {
            cout << "\nSorry you entered an invalid operation. ";
            exit(1);

            break;
        }
        }
    }

    //===============================================================================================================
    cout << "\n/******************************************************************************************\\ \n\n\n";
    return 0;
}

//================================End===================================================//

//test
/*for (int i = 0; i < 5; i++)
    {
        int id, vote;
        string name;
        cout << "\nEnter Details : ";
        cin >> id >> name >> vote;
        Voter *v = new Voter(id, name, vote);
        Node *n = new Node(v);
        V->enqueue(n);
        //cout << endl;
    }

    V->print_queue();

    V->dequeue();
    V->dequeue();

    V->print_queue();*/