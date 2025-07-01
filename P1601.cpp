#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B){
    int size_A = A.size();
    int size_B = B.size();
    vector<int> ans;
    int add = 0;
    int left = 0;
    int min_size = min(size_A,size_B);
    //cout << "size: " << min_size << " " <<endl;
    
    for(int i = 0; i < min_size;i++){ 
        //cout << A[i] << endl;
        left = (A[i] + B[i] + add) % 10;
        add = (A[i] + B[i] + add)/10;
        //cout << left << endl;
        ans.push_back(left);  
    }
    

    int i = min(size_A,size_B);

    while(i < max(size_A,size_B)){
        if(size_A > size_B){
            left = (A[i] + add) % 10;
            add = ( A[i] + add)/10;
            ans.push_back(left); 
            //cout << left << endl;
            i++;
        }else{
            left = (B[i] + add) % 10;
            add = ( B[i] + add)/10;
            ans.push_back(left); 
            //cout << left << endl;
            i++;
        }
        
    }
    if(add > 0){
        ans.push_back(1);
    }

    
    return ans;
}


int main(){
    string a,b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i = a.size()-1; i>=0; i--){
        A.push_back(a[i] - '0');
    }
    for(int i = b.size()-1; i>=0; i--){
        B.push_back(b[i] -'0');
    }
    auto ans = add(A,B);
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i];
    }
    return 0;


}