#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void fast(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}

class linkedQueue{
    struct node{
    int iteam;
    node *next;
    };
    node *frontptr,*rearptr;
public:
    linkedQueue():frontptr(NULL),rearptr(NULL){}
    bool isEmpty(){
        return frontptr==NULL;
    }
    void enqueue(int newIteam){
        node * newNode= new node;
        newNode->iteam= newIteam;
        newNode->next=NULL;
        if(isEmpty()){
            frontptr=rearptr=newNode;
        }
        else{
            rearptr->next=newNode;
            rearptr=newNode;
        }
    }
    void dequeue(){
        if(isEmpty())
            cout << " queue is empty ";
        if(frontptr==rearptr){
            frontptr=NULL;
            rearptr=NULL;
        }
        else{
            node *temp=frontptr;
            frontptr=frontptr->next;
            temp->next=NULL;
            delete temp;
        }
    }
    int getfront(){
        assert(!isEmpty());
        return frontptr->iteam;
    }
    int getback(){
        assert(!isEmpty());
        return rearptr->iteam;
    }
    void display(){
        node *cur=frontptr;
        while(cur!=NULL){
            cout << cur->iteam << " ";
            cur=cur->next;
        }
    }
    void clearQueue(){
        node *cur;
        while(frontptr!=NULL){
            cur=frontptr;
            frontptr=frontptr->next;
            delete cur;
        }
        rearptr=NULL;
    }
};

int main(){
    fast();
    linkedQueue lq;
    lq.enqueue(10);
    lq.enqueue(20);
    lq.enqueue(30);
    lq.enqueue(40);
    lq.display();
return 0;
}
