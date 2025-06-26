#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N];
int temp[N];

void merge_sort(int a[],int l, int r){
   if(l >= r) return;
   
   int mid = (l + r) / 2;
   int i = l; int j = mid + 1;
   merge_sort(a,l,mid);
   merge_sort(a,mid+1,r);   
   int k = 0;
   while(i <= mid && j <= r){
        if(a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
   }
   while(i <= mid) temp[k++] = a[i++];
   while(j <= r) temp[k++] = a[j++];

   for(i = l,j = 0; i <= r; i++,j++){
        a[i] = temp[j];
   }

}

int main(){
    for(int i = 0; i < 5; i++){
        scanf("%d",&a[i]);
    }

    merge_sort(a,0,4);
    for(int i = 0; i < 5; i++){
        cout << a[i] << " ";
    }
    return 0;
}
