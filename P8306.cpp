#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


struct trie{
    int tree[100000][26],cnt;
    bool exist[100000];

    void insert(char *s, int l){
        int p = 0;
        for(int i = 0; i < l; i++){
            int num = s[i] - 'a';
            if(!tree[i][num]){
                tree[i][num] = ++cnt;
                p = tree[i][num];
            }
            exist[p] = true;
        }
    }

    int find(char *s, int l){

        for(int i = 0; i < l; i++){
            if(!tree[i][s[i] - 'a']){
                return 0;
            }
        }

        return tree[l-1][s[l-1] - 'a'];
    }
}Trie;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    trie T;

    int n;
    static char buf[100000 + 5];  

    for(int i = 0; i < n; i++){
        // 限定最大输入长度，防止缓冲区溢出
        scanf("%100000s", buf);
        int len = strlen(buf);
        T.insert(buf, len);
    }

    // …后续查询或其他操作…

  

    return 0;
}