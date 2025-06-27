#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6+10;
int a[N];
int n,m;

int check(int mid){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i] / mid;
    }
    return sum;
}



int main(){
    cin >> n >> m;
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int l = 0;
    int r = a[n-1];
    int mid = 0;
    if(a[n-1] < 1) cout << "0";
    else{
        while(l < r){
            mid = (l + r + 1) / 2;
            if(check(mid) >= m) l = mid;
            else r = mid -1;
        }
        cout << l;
    }
    
    return 0;
}