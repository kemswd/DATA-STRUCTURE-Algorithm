#include<bits/stdc++.h>
using namespace std;
#define loop(n) for(int  i= 0 ; i< (n) ; i++)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define inf INT_MAX

void fast(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}

                        //80 90 60  30 50 70 40
    void insertion_sort(int arr[],int n){
        int key;
        int j;
        for(int i=1; i<n; i++ )
        {
            key = arr[i];//
            j = i-1;
            while(j>=0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key ;
        }

    }
    void print(int arr[],int n){
        for(int i=1; i<n; i++ ){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

int main(){
fast();
    int arr[] = {80 ,90 ,60 , 30 ,50 ,70 ,40};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr,n);
    print(arr,n);
return 0;
}
