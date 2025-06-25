
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;


int a[N];
void quick_sort(int a[], int l, int r){
    if(l >= r) return;

    int i = l - 1;
    int j = r + 1;
    int x = a[l];

    while(i < j){
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j){
            int b = a[i];
            a[i] = a[j];
            a[j] = b;
        };
    }
    quick_sort(a,l,j);
    quick_sort(a,j+1,r);
}




int main(){

    for(int i = 0;i < 5; i++) cin >> a[i];
    quick_sort(a,0,4);
    for(int i = 0;i < 5; i++) cout << a[i] << " ";
    
}