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


int main()
{
    string names[SIZE] = {"James", "Jared", "Dominc", "Bob", "Jeffery", "Jessica", "Lisa", "Eric", "Jess", "Willy"};
    string orders[SIZE] = {"Coffee", "Pumpkin Spice Latte", "Latte", "Hot Coco", "Expresso", "Water", "Cotton Candy Latte", "Peppermint Coco", "Mocha", "Strawberry Mocha"};
    
}