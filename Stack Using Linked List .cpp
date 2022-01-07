#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void fast(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}
template<class t>
class linkedStack{
    struct node{
    t iteam;
    node *next;
    };
    node *top;
public:
    linkedStack():top(NULL){}
    void push(t newIteam){
        node *newNode= new node;
        newNode->iteam= newIteam;

        newNode->next= top;
        top= newNode;
    }
    bool isEmpty(){
        return top==NULL;
    }
    void pop(){
        if(isEmpty()){
            cout << " stack is empty ";
        }
        else
        {
        node *temp=top;
        top= top->next;
        temp=temp->next= NULL;
        delete temp;
        }
    }
    void pop(t &stackTop){
        if(isEmpty()){
            cout << " stack is empty ";
        }
        else
        {
        stackTop= top->iteam;
        node *temp=top;
        top= top->next;
        temp=temp->next= NULL;
        delete temp;
        }
    }
     void getTop(t &stackTop){
        if(isEmpty()){
            cout << " stack is empty ";
        }
        else
        {
            stackTop= top->iteam;
        }
    }
    void display(){
        node *cur=top;
        while(cur!=NULL){
            cout << cur->iteam << "\n";
            cur=cur->next;
        }
    }
};

int main(){
    fast();
    linkedStack <int> ls;
    ls.push(10);
    ls.push(20);
    ls.push(30);
    ls.push(40);
    ls.display();

return 0;
}
