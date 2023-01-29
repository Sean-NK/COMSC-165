//
//  main.cpp
//  Hyun_Namkoong_165_assign12
//
//  Created by Hyun Namkoong on 5/3/22.
//

#include <iostream>

using namespace std;

struct LinkedList
{
    int value;
    LinkedList* next;
};

void append_node(int a,LinkedList* head);
void insert_node(int a,LinkedList* head);
void delete_node(int a,LinkedList* head);
void search_node(int a,LinkedList* head);
void destroy_list(LinkedList* head);
void printList(LinkedList* head);

int main()
{
    LinkedList* head = new LinkedList;
    head->value = 0;
    head->next = NULL;
    
    int a = 0;
    int n=1;
    while(n==1)
    {
        cout << "Enter the number of initial nodes (must be at least 1): ";
        cin >> a;
        if(a>=1)
        {
            break;
        }
    }
    
    for(int i =0;i<a;i++)
    {
        cout << "Enter a number: ";
        int n =0;
        cin >> n;
        append_node(n,head);
    }
    
    cout << "Enter a number for a new node to insert to the linked list: ";
    int b=0;
    cin >> b;
    cout << endl;
    
    insert_node(b,head);
    
    cout << "Enter the number of the node that you want to delete from the linked list: ";
    int c=0;
    cin >> c;
    cout << endl;
    delete_node(c, head);
    
    int d=0;
    cout << "Enter the number that you want to search for in the list: ";
    cin >> d;
    cout << endl;
    search_node(d, head);
    printList(head);
    
    destroy_list(head);
    
    
    
    
    return 0;
}

void append_node(int a,LinkedList* head)
{
    LinkedList* new_node = new LinkedList;
    new_node -> value = a;
    new_node ->next = nullptr;

    while(head->next != nullptr)
    {
        head = head -> next;
    }
    head->next = new_node;
}

void insert_node(int a, LinkedList* head)
{
    LinkedList* new_node = new LinkedList;
    new_node -> value = a;
    new_node -> next = nullptr;

    while(new_node->value >= head->next->value)
    {
        head=head->next;
        if(head->next==NULL)
        {
            break;
        }
        
    }
        new_node->next = head->next;
        head->next = new_node;
}

void delete_node(int a,LinkedList* head)
{
    while(a!=head->next->value)
    {
        head=head->next;
    }
    LinkedList* ptr=head->next;
    head->next=ptr->next;
    delete ptr;
    ptr=nullptr;
}


void search_node(int a,LinkedList* head)
{
    int num=1;
    while(a!=head->next->value)
    {
        head=head->next;
        num++;
    }
    cout << "Number found at index " << num << " in the linked list" << endl;
}

void destroy_list(LinkedList* head)
{
    LinkedList* ptr;
    LinkedList* ptr2;
    ptr = head;
    ptr2 = ptr -> next;
    int count =0;
    while(ptr2 != nullptr)
    {
        delete ptr;
        ptr = ptr2;
        ptr2=ptr2->next;
        count++;
    }
    head = nullptr;
 
}

void printList(LinkedList* head)
{
    head = head -> next;
    while(head != nullptr)
    {
        cout << head->value << endl;
        head = head -> next;
    }
}
