#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX_V = 200;

int A, B, C;
bool visited[MAX_V + 1][MAX_V + 1];
bool possible[MAX_V + 1];

void dfs(int a, int b) {
    if (visited[a][b])
        return;

    visited[a][b] = true;

    int c = C - a - b;

    if (a == 0)
        possible[c] = true;

    // a -> b
    int mnt = min(a, B - b);
    dfs(a - mnt, b + mnt);

    // a -> c
    mnt = min(a, C - c);
    dfs(a - mnt, b);

    // b -> a
    mnt = min(b, A - a);
    dfs(a + mnt, b - mnt);

    // b -> c
    mnt = min(b, C - c);
    dfs(a, b - mnt);

    // c -> a
    mnt = min(c, A - a);
    dfs(a + mnt, b);

    // c -> b
    mnt = min(c, B - b);
    dfs(a, b + mnt);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> A >> B >> C;

    dfs(0, 0);

    for (int i = 0; i <= C; ++i)
        if (possible[i])
            cout << i << ' ';
    cout << '\n';

    return 0;
}
