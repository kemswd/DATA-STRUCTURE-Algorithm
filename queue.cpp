#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void fast(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}
class Queue{
    int rear;
    int front;
    int length;
    int max_size;
    int *arr;
public:
    Queue(int size){
        front=0;
        if (size <= 0)
			max_size = 100;
		else
			max_size = size;
        rear=max_size-1;
        length=0;
        arr = new int[max_size];
    }
    int isempty(){
        return length==0;
    }
    int isfull(){
        return length==max_size;
    }
    void add(int element){
            if(isfull())
                cout << "is full";
            else{
                rear= (rear+1)%max_size;
                arr[rear]= element;
                length++;
            }
    }
    void deletequeue(){
        if(isempty())
            cout << " is empty";
        else{
            front= (front+1)%max_size;
            length--;
        }
    }
    void printqueue(){
        for(int i=front;i!=rear;i=(i+1)%max_size){
            cout << arr[i] << " ";
        }
        cout << arr[rear] << "\n";
    }
    ~Queue(){
        delete arr;
    }

};

int main(){
    fast();
    Queue q(100);
    q.add(10);
    q.add(20);
    q.add(30);
    q.printqueue();
    q.deletequeue();
    q.printqueue();
return 0;
}
