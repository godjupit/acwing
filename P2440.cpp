#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6+10;
int a[N];

int n,m;

int main(){
    cin >> n >> m;
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    
    int mid = 0;
    int q = 0;
   
    for(int i =0; i < m; i++){
        int l = 0;
        int r = n - 1;
        scanf("%d",&q);
        while(l < r){
            mid = (l + r ) / 2;
            if(a[mid] >= q){
                r = mid;
            }else{
                l = mid + 1;
            }
            
        }
        if(a[l] == q) printf("%d ",l+1);
        else printf("-1 ");
    }
    
    
   
    return 0;
}