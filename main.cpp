#include <iostream>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <vector>
using namespace std;

const int SIZE = 10;
const int CYCLES = 10;

struct Node
{
    string name;
    string order;
    Node *next;

    Node(string new_name, string new_order)
    {
        name = new_name;
        order = new_order;
        next = nullptr;
    }
};

struct Muffin
{
    string name;
    string order;

    Muffin()
    {
        string names[SIZE] = {"James", "Jared", "Dominc", "Bob", "Jeffery", "Jessica", "Lisa", "Eric", "Jess", "Willy"};
        string orders[SIZE] = {"Reg Muffin", "Pumpkin Spice Muffin", "Latte Muffin", "Hot Coco Muffin", "Expresso Muffin", "Blueberry Muffin", "Cotton Candy Muffin", "Peppermint Muffin", "Mocha Muffin", "Strawberry Muffin"};
        int ran1 = rand() % 10;
        int ran2 = rand() % 10;
        name = names[ran1];
        order = orders[ran2];
        cout << "       " << name << " has ordered a " << order << endl;
    }
};

struct Bracelets
{
    string name;
    string order;

    Bracelets()
    {
        string names[SIZE] = {"James", "Jared", "Dominc", "Bob", "Jeffery", "Jessica", "Lisa", "Eric", "Jess", "Willy"};
        string orders[SIZE] = {"Rainbow bracelet", "Blue bracelet", "Red bracelet", "Yellow bracelet", "Pink bracelet", "Orange bracelet", "Green bracelet", "Purple bracelet", "Black bracelet", "White bracelet"};
        int ran1 = rand() % 10;
        int ran2 = rand() % 10;
        name = names[ran1];
        order = orders[ran2];
        cout << "       " << name << " has ordered a " << order << endl;
    }
};


Node* addCustomer(Node *&);
void serveCustomer(Node *&);

int main()
{
    Node *head = nullptr;
    deque<Muffin> muffinBooth;
    vector<Bracelets> braceletBooth;
    
    int prob;
    int count = 1;

    cout << "Cycle #" << count << ":" << endl;

    cout << "   Coffee Booth:" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        head = addCustomer(head);
    }

    cout << "   Muffin Booth:" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        muffinBooth.push_back(Muffin());
    }
    

    for (size_t i = 0; i < CYCLES-1; i++)
    {
        count++;
        cout << "Cycle #" << count << ":" << endl;

        cout << "   Coffee Booth:" << endl;
        prob = rand() % 100 + 1;

        if (prob <= 50)
        {
            head = addCustomer(head);
        }
        serveCustomer(head);

        cout << "   Muffin Booth:" << endl;
        prob = rand() % 100 + 1;

        if (prob <= 50)
        {
            muffinBooth.push_back(Muffin());
        }
        if (!muffinBooth.empty())
        {
            cout <<  "       " << muffinBooth.front().name << " was served" << endl;
            muffinBooth.pop_front();
        }
        else
        {
            cout << "       Line is empty" << endl;
        }
        
    }
    
}

//the addNodeToTail function
Node* addCustomer(Node * &hd)
{
    //Declares and initilizes variables
    string names[SIZE] = {"James", "Jared", "Dominc", "Bob", "Jeffery", "Jessica", "Lisa", "Eric", "Jess", "Willy"};
    string orders[SIZE] = {"Coffee", "Pumpkin Spice Latte", "Latte", "Hot Coco", "Expresso", "Water", "Cotton Candy Latte", "Peppermint Coco", "Mocha", "Strawberry Mocha"};
    int ran1 = rand() % 10;
    int ran2 = rand() % 10;

    //creates new_node
    Node* new_node = new Node(names[ran1], orders[ran2]);
    cout << "       " << names[ran1] << " has ordered a " << orders[ran2] << endl;
    //checks if list is empty
    if (hd == nullptr)
    {
        return new_node;
    }
    //creates last
    Node * last = hd;
    //iterates through the list in till it reachs the end
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = new_node;

    return hd;
}

void serveCustomer(Node *&head) {
    if (head == nullptr) {
        cout << "       Line is empty" << endl;
        return;
    }

    Node *temp = head;

    head = head->next;

    cout << "       " << temp->name << " was served" << endl;
    delete temp;
}