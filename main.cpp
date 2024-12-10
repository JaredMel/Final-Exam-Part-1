#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

//Initilize and Declare Variables
const int SIZE = 10;
const int CYCLES = 10;
//Node struct
struct Node
{
    //Declare attributes
    string name;
    string order;
    Node *next;
    //Node Constructor
    Node(string new_name, string new_order)
    {
        name = new_name;
        order = new_order;
        next = nullptr;
    }
};
//Muffin struct
struct Muffin
{
    //Declare attributes
    string name;
    string order;
    //Muffin Constructor
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

struct Games
{
    string name;
    string order;

    Games()
    {
        string names[SIZE] = {"James", "Jared", "Dominc", "Bob", "Jeffery", "Jessica", "Lisa", "Eric", "Jess", "Willy"};
        string orders[SIZE] = {"Mario", "Sonic", "GTA", "Elden Ring", "Mario Kart", "Mario Party", "Fortnight", "COD", "Doom", "Bloodborne"};
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
    list<Games> gameBooth;
    
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

    cout << "   Bracelet Booth:" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        braceletBooth.push_back(Bracelets());
    }

    cout << "   Game Booth:" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        gameBooth.push_back(Games());
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

        cout << "   Bracelet Booth:" << endl;
        prob = rand() % 100 + 1;

        if (prob <= 50)
        {
            braceletBooth.push_back(Bracelets());
        }
        if (!braceletBooth.empty())
        {
            cout <<  "       " << braceletBooth.front().name << " was served" << endl;
            rotate(braceletBooth.begin(), braceletBooth.begin()+1, braceletBooth.end());
            braceletBooth.pop_back();
        }
        else
        {
            cout << "       Line is empty" << endl;
        }

        cout << "   Game Booth:" << endl;
        prob = rand() % 100 + 1;

        if (prob <= 50)
        {
            gameBooth.push_back(Games());
        }
        if (!gameBooth.empty())
        {
            cout <<  "       " << gameBooth.front().name << " was served" << endl;
            gameBooth.pop_front();
        }
        else
        {
            cout << "       Line is empty" << endl;
        }
    }
}

Node* addCustomer(Node * &hd)
{
    string names[SIZE] = {"James", "Jared", "Dominc", "Bob", "Jeffery", "Jessica", "Lisa", "Eric", "Jess", "Willy"};
    string orders[SIZE] = {"Coffee", "Pumpkin Spice Latte", "Latte", "Hot Coco", "Expresso", "Water", "Cotton Candy Latte", "Peppermint Coco", "Mocha", "Strawberry Mocha"};
    int ran1 = rand() % 10;
    int ran2 = rand() % 10;

    Node* new_node = new Node(names[ran1], orders[ran2]);
    cout << "       " << names[ran1] << " has ordered a " << orders[ran2] << endl;

    if (hd == nullptr)
    {
        return new_node;
    }
    
    Node * last = hd;
    
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