#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void fast(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}
struct Node{
        int item;
        Node *next;
};
class linkedList{
    Node *first,*last;
    int length;
public:
    linkedList():first(NULL),last(NULL),length(0){}
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
            newNode->item=item;
            if(pos==0)  insertFirst(item);
            else if(pos==length)    insertLast(item);
            else{
                Node *cur=first;
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
    void popFront(){
        if(length ==0)  cout <<"empty list can`t remove\n" ;
        else if(length==1){
            delete first;
            first=last=NULL;
            length--;
        }
        else{
        Node *cur= first;
        first=first->next;
        delete cur;
        length--;
        }

    }
    void popBack(){
        if(length ==0)  cout <<"empty list can`t remove\n" ;
        else if(length==1){
            delete first;
            first=last=NULL;
            length--;
        }
        else
        {
        Node *cur=first->next;
        Node *prev=first;
        while(cur!=last){
            prev=cur;
            cur=cur->next;
            }
        delete cur;
        prev->next=NULL;
        last=prev;
        length--;
        }
    }
    void Remove(int element){
        if(length ==0)  {cout <<"empty list can`t remove\n";}
        Node *cur,*prev;
        if(first->item==element){
            cur=first;
            first=first->next;
            delete cur;
            length--;
            if(length==0)   last=NULL;
        }
        else{
            cur=first->next;
            prev=first;
            while(cur!=NULL){
                if(cur->item== element) break;
                prev=cur;
                cur=cur->next;
            }
            if(cur==NULL)   cout << "The item is not there\n";
            else {
                prev->next=cur->next;
                if(last==cur)    {last=prev;}
                delete cur;
                length--;
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
    void Reverse(){
        Node *prev,*cur,*next;
        prev=NULL;
        cur=first;
        next=cur->next;
        while(next!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        first=prev;
    }
    int Search(int item){
        Node *cur=first;
        int pos=0;
        while(cur!=NULL){
            if(cur->item==item) return pos;
            cur=cur->next;
            pos++;
        }
        return -1;
    }
};
int main(){
fast();
  linkedList l;
  l.insertAtPos(0,10);
  l.insertFirst(0);
  l.insertLast(30);
  l.insertLast(50);
  l.insertLast(60);
  l.popBack();
  l.popFront();
  l.Remove(50);
  l.print();
return 0;
}
