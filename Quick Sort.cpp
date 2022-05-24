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
   int partition1(int arr[],int l,int h){
    int p=arr[l];
    int i=l;
    int j=h;
    while(i<j){
        do
        {
            i++;
        }while(arr[i]<=p);
        do
        {
            j--;
        }while(arr[j]>p);
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[l],arr[j]);
    return j;
   }
   void quick_sort1(int arr[],int l,int h){
        if(l<h)
        {
          int piv= partition1(arr,l,h);
          quick_sort1(arr,l,piv);
          quick_sort1(arr,piv+1,h);

        }
   }

int main(){
fast();
        int arr[] = { 90,10,20,5,60,70 };
		int n = sizeof(arr) / sizeof(arr[0]);//24/4=6
        quick_sort1(arr,0,n);
        for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }

return 0;
}
