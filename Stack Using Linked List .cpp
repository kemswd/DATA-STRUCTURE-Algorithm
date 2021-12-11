#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
template<class t>
class Stack{
    struct node{
        t item ;
        node *next;
    };
    node *top,*cur;

public:
     Stack (): top(NULL),cur(NULL){}
    void push(t newitem){
        node*newitemptr=new node;
        if (newitemptr == NULL)
			cout << "Stack push cannot allocate memory";
        else{
        newitemptr->item=newitem;
        newitemptr->next=top;
        top=newitemptr;
        }
    }
    bool isEmpety(){
        return top=NULL;
    }
    void pop(){
        if(isEmpety())
        {
            cout << "Stack empty on pop";
        }
        else{
        node*temp=top;
        top=top->next;
        temp->next=NULL;
        delete temp;
            }
        }
    void pop(t&stackTop){
        if(isEmpety())
        {
            cout << "Stack empty on pop";
        }
        else{
        stackTop=top->item;
        node temp=top;
        top=top->next;
        temp->next=NULL;
        delete temp;
            }
        }
    void getTop(t&stackTop){
        if(isEmpety())
        {
            cout << "Stack empty on pop";
        }
        else{
            stackTop=top->item;
        }
    }
    void display(){
        cur=top;
        cout << "\nItems in the stack : ";
		cout << "[ ";
		while(cur!=NULL){
            cout << cur->item << " ";
            cur=cur->next;
		}
        cout << " ]\n";
    }


};
void fast(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}
int main()
{
	fast();
	Stack<int>s;
	s.push(100);
	s.push(200);
	s.push(300);
	
	s.display();
	return 0;
}

