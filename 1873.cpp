#include<iostream>
#include<algorithm>
using namespace std;
const long long N = 1e6+10;

long long a[N];
long long n = 0;
long long m = 0;
long long checkout(int mid){
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        if(mid < a[i]) sum += a[i] - mid;
    }
    return sum;
}

int main(){
    
    cin >> n >> m;
    for(long long i = 0; i < n; i++){
        scanf("%lld",&a[i]);
    }
    sort(a, a + n);
    long long  l = 0;
    long long r = a[n-1];
    while(l < r){
        long long mid = (l+r+1)/2;
        if(checkout(mid) >= m){
            l = mid;
        }
        else r = mid - 1;
    }
    cout << l;
    return 0;
    
}