#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node * next;
};

class linkedlist{
public:
    node * head;
    int sz;
    linkedlist(){
        head = NULL;
        sz = 0;
    }
    
    node* createNewNode(int value){
        node * newnode = new node;
        newnode->data = value;
        newnode->next = NULL;
        
        return newnode;
    }
    
    void insertAtHead(int value){
        node * a = createNewNode(value);
        if(head == NULL){
            head = a;
            return;
        }
        sz++;
        a->next = head;
        head = a;
    }
    
    void insertAtIndex(int value,int index){
        if(index < 0 || index > sz){
            return;
        }
        if(index == 0){
            insertAtHead(value);
            return;
        }
        node * a = head;
        int cur_index = 0;
        while(cur_index != index-1){
            a = a->next;
            cur_index++;
        }
        sz--;
        node * newnode = createNewNode(value);
        newnode->next = a->next;
        a->next = newnode;
    }
    
    void DeleteAtHead(){
        if(head == NULL)
            return;
        sz--;
        node * a = head;
        head = a->next;
        delete a;
    }
    
    void DeletionAtIndex(int index){
        if(index == 0){
            DeleteAtHead();
            return;
        }
        sz--;
        node * a = head;
        int cur_index = 0;
        while (cur_index != index-1){
            a = a->next;
            cur_index++;
        }
        node * b = a->next;
        a->next = b->next;
    }
    
    void traverse(){
        node * a = head;
        while (a != NULL){
            cout<<a->data<<" ";
            a = a->next;
        }
        cout<<"\n";
    }
    
    int search(int value){
        node * a = head;
        int index = 0;
        while (a != NULL){
            if(value == a->data){
                cout<<value<< " found at index "<<index;
            }
            a = a->next;
            index++;
        }
    }
};

int main()
{
    linkedlist l;
    l.insertAtHead(10);
    l.insertAtHead(30);
    l.insertAtHead(20);
    l.insertAtHead(15);
    l.insertAtHead(18);
    
    l.insertAtIndex(33,3);
    
    l.traverse();
    
    l.DeleteAtHead();
    l.DeletionAtIndex(2);
    
    l.traverse();

    l.search(30);
    return 0;
}
