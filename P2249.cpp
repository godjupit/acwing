// 二分

#include<iostream>
using namespace std;
const int N = 1e6+10;
const int M = 1e5+10;
int a[N];
int b[M];

int checkout(int mid){
    
}

int main(){
    int n = 0;
    int m = 0;
    cin >> n>> m;

    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d",&b[i]);
    }

    int l = a[0];
    int r = a[n-1];
    int mid = 0;

  
    for(int i = 0; i < m; i++){
        if(b[i] < l){
            printf("-1 ");
        }
        while(l < r){
            mid = (l + r + 1) / 2;
            if(b[i] > mid){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
    }

}