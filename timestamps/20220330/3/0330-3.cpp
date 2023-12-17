#include <stack>
using namespace std;

int main() {
    int m = 4;
    int n = 1;
    stack<int> s;
    while (m--) {
        s.push(1);
        int sum = 1;
        for (int i = 1; i <= n; i++) {
            sum = i * s.top();
            s.push(sum);
        }
        printf("%d\n", s.top());
        n++;
        while (!s.empty())
            s.pop();
    }
}
