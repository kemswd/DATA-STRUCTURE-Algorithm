#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void fast(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}
struct node{
    int iteam;
    node *next;
    node *previous;
};
class doublyLinkedList{
    node *first,*last;
    int length;
public:
    doublyLinkedList():first(NULL),last(NULL),length(0){}
    bool isEmpty(){
        return (length==0);
    }
    void insertFirst(int iteam){
        node *newNode= new node;
        newNode->iteam= iteam;
        if(length==0){
            newNode->next=newNode->previous=NULL;
            first=last=newNode;
        }
        else{
            newNode->next=first;
            newNode->previous=NULL;
            first->previous=newNode;
            first=newNode;
        }
        length++;
    }
    void insertLast(int iteam){
        node *newNode= new node;
        newNode->iteam= iteam;
        if(length==0){
            newNode->next=newNode->previous=NULL;
            first=last=newNode;
        }
        else{
            newNode->previous=last;
            newNode->next=NULL;
            last->next=newNode;
            last=newNode;
        }
        length++;
    }
    void insertAtpos(int pos,int iteam){
        if(pos<0||pos>length)   cout<< "out of range ...!";
        else{
            node *newNode= new node;
            newNode->iteam= iteam;
            if(pos==0)  insertFirst(iteam);
            else if(pos==length)    insertLast(iteam);
            else{
                node *current=first;
                for(int i=0;i<pos;i++){
                    current=current->next;}
                newNode->next=current->next;
                newNode->previous=current;
                current->next=newNode;
                current->next->previous=newNode;
                length++;
            }
        }
    }
    void removeFirst(){
        if(length==0)   return;
        else if(length==1){//first=last
            delete first;
            first=last=NULL;
        }
        else{
            node *current=first;
            first=first->next;
            first->previous=NULL;
            delete current;
        }
        length--;
    }
    void removeLast(){
        if(length==0)   return;
        else if(length==1){//first=last
            delete first;
            first=last=NULL;
        }
        else{
        node *current=last;
        last=last->previous;
        last->next=NULL;
        delete current;
        }
        length--;
    }
    void removeAtpos(int pos){
        if(pos<0||pos>length)   cout<< "out of range ...!";
        else{
            if(pos==0)  removeFirst();
            else if(pos==length)   removeLast();
            else
            {
                node* current= first;
                for(int i=0;i!=pos;i++)
                {
                    current=current->next;
                }
                current->previous->next=current->next;
                current->next->previous=current->previous;
                delete current;
                length--;
            }
        }
    }
    void removeIteam(int iteam){
        if(length==0)   cout << "list is empty \n";
        if(first->iteam==iteam)
            removeFirst();
        else{
            node *current=first->next;
            while(current!=NULL&& current->iteam!=iteam){
                current=current->next;
            }
            if(current==NULL)   cout << "item not exict \n";
            else if(current->next==NULL)
                removeLast();
            else{
                current->previous->next=current->next;
                current->next->previous=current->previous;
                delete current;
                length--;
            }
        }
    }
    void print(){
        node *current=first;
        while(current!=NULL){
            cout << current->iteam << " ";
            current=current->next;
        }
        cout << "\n";
    }
    void printReverse(){
        node *current=last;
        while(current!=NULL){
            cout << current->iteam << " ";
            current=current->previous;
        }
        cout << "\n";
    }
};

int main(){
    fast();
    doublyLinkedList dl;
	dl.insertAtpos(0,1);
	dl.insertAtpos(1,10);
	dl.insertAtpos(2,20);
	dl.insertAtpos(3,30);
	dl.removeIteam(10);
	dl.print();



return 0;
}
