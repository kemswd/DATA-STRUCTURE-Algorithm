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
   void heapify(int arr[],int n,int i){
        int l= i*2+1;
        int r= i*2+2;
        int max=i;
        if(l<n&& arr[l]>arr[max])
            max=l;
        if(r<n&& arr[r]>arr[max])
            max=r;
        if(max!= i)
        {
          swap(arr[i],arr[max]);
          heapify(arr,n,max);
        }

   }
   void buildHeap(int arr[],int n){
    for (int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
   }

   void heapSort(int arr[],int n){
       buildHeap(arr, n);
	for (int i = n-1; i >=0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
   }
int main(){
fast();
        int arr[] = { 90,10,20,5,60,70 };
		int n = sizeof(arr) / sizeof(arr[0]);//24/4=6
       heapSort(arr,n);
        for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }

return 0;
}
