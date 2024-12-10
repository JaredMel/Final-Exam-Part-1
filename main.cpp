#include <iostream>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <stack>
using namespace std;

const int SIZE = 10;

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

Node* addNodeToTail(Node *&);
void serveCustomer(Node *&);

int main()
{
    Node *head = nullptr;
}

//the addNodeToTail function
Node* addNodeToTail(Node * &hd)
{
    //Declares and initilizes variables
    string names[SIZE] = {"James", "Jared", "Dominc", "Bob", "Jeffery", "Jessica", "Lisa", "Eric", "Jess", "Willy"};
    string orders[SIZE] = {"Coffee", "Pumpkin Spice Latte", "Latte", "Hot Coco", "Expresso", "Water", "Cotton Candy Latte", "Peppermint Coco", "Mocha", "Strawberry Mocha"};
    int ran1 = rand() % 10;
    int ran2 = rand() % 10;

    //creates new_node
    Node* new_node = new Node(names[ran1], orders[ran2]);
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
    //returns hd
    return hd;
}

// Function to delete the head node
void serveCustomer(Node *&head) {
    if (head == nullptr) {
        cout << "Line is empty" << endl;
        return;
    }

    // Store current head in a temporary variable
    Node *temp = head;

    // Move head to the next node
    head = head->next;

    // Delete the old head node
    cout << temp->name << "was served" << endl;
    delete temp;
}