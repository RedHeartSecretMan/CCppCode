#include<iostream>
#include<cstdlib>

using namespace std;
 
int fa[100005];
int la[100005];
int w[100005];
int n, m;
 
int uf_find(int x) {
    if (fa[x] != x) {
        int _fa = fa[x];
        fa[x] = uf_find(fa[x]);
        w[x] += w[_fa];
    }
 
    return fa[x];
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        fa[i] = la[i] = i;
        w[i] = 0;
    }
 
    while (m--) {
        int a, b;
        char c;
        getchar();
        scanf("%c %d %d", &c, &a, &b);
        if (c == 'C') {
            fa[a] = la[b];
            la[uf_find(b)] = la[a];
            w[a] = 1;
        }
        else {
            if (uf_find(a) == uf_find(b)) {
                printf("%d\n", max(0, abs(w[a] - w[b]) - 1));
            }
            else {
                printf("-1\n");
            }
        }
    }
 
    return 0;
}