#include<iostream>
#include <cmath>
#include<algorithm>
using namespace std;
int m,n;
const int M = 1e5+10;
const int N = 1e5+10;
int a[M];
int b[N];



int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a,a+m);
    int q = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",&q);
        int l= 0;
        int r = m-1;
        int mid = 0;
        while(l < r){
            mid = (l + r)/2;
            if(a[mid] <= q){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        if(q<=a[0])
		{
			ans+=a[0]-q;
		}else if (l == m) {
            // 所有数都 <= q
            ans += abs(a[m - 1] - q);
        } 
		else
		{
			ans+=min(abs(a[l-1]-q),abs(a[l]-q));
		}
    }
    cout << ans;

}