#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

static char s[3000010];

struct trie {
    static const int MAXNODE = 100000;
    int tree[MAXNODE][26];
    bool exist[MAXNODE];
    int cnt;

    trie() : cnt(0) {
        memset(tree,  0, sizeof(tree));
        memset(exist, 0, sizeof(exist));
    }

    void insert(const char *s, int l) {
        int p = 0;
        for (int i = 0; i < l; i++) {
            int idx = s[i] - 'a';
            if (tree[p][idx] == 0) {
                tree[p][idx] = ++cnt;
            }
            p = tree[p][idx];
        }
        exist[p] = true;
    }

    bool find(const char *s, int l) const {
        int p = 0;
        for (int i = 0; i < l; i++) {
            int idx = s[i] - 'a';
            if (tree[p][idx] == 0) {
                return false;
            }
            p = tree[p][idx];
        }
        return exist[p];
    }
} Trie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int m, p;
        cin >> m >> p;

        vector<trie> dict;
        dict.reserve(m);

        for (int i = 0; i < m; i++) {
            scanf("%2999999s", s);
            trie t;
            int len = strlen(s);
            t.insert(s, len);
            dict.push_back(move(t));
        }

        long long ans = 0;
        for (int i = 0; i < p; i++) {
            scanf("%2999999s", s);
            int len = strlen(s);
            for (auto &t : dict) {
                if (t.find(s, len)) {
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}