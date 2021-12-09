#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void fast(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}
class linkedList{
    struct Node{
        int item;
        Node *next;
};
    Node *first,*last;
    int length;
public:
    linkedList():first(NULL),last(NULL){}
    bool isEmpty(){
        return length==0;
    }
    void insertFirst(int item){
        Node *newNode= new Node;
        newNode->item=item;
        if(length==0){
            first=last=newNode;
            newNode->next=NULL;
        }
        else{
            newNode->next=first;
            first=newNode;
        }
        length++;
    }
    void insertLast(int item){
        Node *newNode= new Node;
        newNode->item=item;
        if(length==0){
            first=last=newNode;
            newNode->next=NULL;
        }
        else{
            last->next=newNode;
            newNode->next=NULL;
            last=newNode;
        }
        length++;
    }
    void insertAtPos(int pos,int item){

        if(pos<0|| pos>length)  cout << "out of range\n";

        else{
            Node *newNode= new Node;
            if(pos==0)  insertFirst(item);
            else if(pos==length)    insertLast(item);
            else{
                Node *cur=new Node;
                for(int i=1 ;i<pos;i++)
                {
                   cur=cur->next;
                }
                newNode->next=cur->next;
                cur->next=newNode;
                length++;
            }
        }

    }
    void print(){
        Node *cur=first;
        while(cur!=NULL){
            cout << cur->item <<" ";
            cur=cur->next;
        }
    }
};
int main(){
fast();
  linkedList l;
  l.insertFirst(10);
  l.insertFirst(20);
  l.insertLast(30);
  l.print();
return 0;
}

