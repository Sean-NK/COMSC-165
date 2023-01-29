//
//  main.cpp
//  leet_easy_21
//
//  Created by Hyun Namkoong on 6/14/22.
//

#include <iostream>

using namespace std;

struct LinkedList
{
    int value;
    LinkedList* next;
};

void appendnode (int a, LinkedList* head);
void combinenode (LinkedList* head, LinkedList* head2);
void shownode(LinkedList* head);

int main()
{
    LinkedList* head = new LinkedList;
    head -> value = 0;
    head -> next = nullptr;
    
    LinkedList* head2 = new LinkedList;
    head2 -> value = 0;
    head2 -> next = nullptr;
    
    
    int a = 0;
    cout << "Enter the num1: ";
    cin >> a;
    for(int i=0; i<a; i++)
    {
        cout << "Enter the node1 num: ";
        int n = 0;
        cin >> n;
        
        appendnode(n, head);
    }
    
    int a2 = 0;
    cout << "Enter the num2: ";
    cin >> a2;
    for(int j=0;j<a2;j++)
    {
        cout << "Enter the node2 num: ";
        int n2=0;
        cin >> n2;
        appendnode(n2, head2);
    }
    
    combinenode(head, head2);
    
    shownode(head);
    return 0;
}

void appendnode (int a, LinkedList* head)
{
    LinkedList* new_node = new LinkedList;
    new_node -> value = a;
    new_node -> next = nullptr;
    
    while(head->next != nullptr)
    {
        head = head -> next;
    }
    head->next = new_node;
    
}


void combinenode (LinkedList* head, LinkedList* head2)
{
    LinkedList* new_node = new LinkedList;
    new_node -> value = 0;
    new_node -> next = nullptr;
    
    new_node -> next = head2;
    
    head -> next -> next -> next = head2-> next -> next;
    head2->next->next = head ->next->next;
    head -> next -> next = head2 ->next;
    head2 -> next = head;
}


void shownode(LinkedList* new_node)
{
    new_node = new_node -> next;
    while(new_node != nullptr)
    {
        cout << new_node->value << endl;
        new_node = new_node -> next;
    }
}
