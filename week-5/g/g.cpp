#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);

  vector mat(n, vector(n, false));
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d\n", &a, &b);
    mat[a - 1][b - 1] = true;
  }

  vector col(n, 0);
  vector dis(n, -1);

  col[0] = 1;
  dis[0] = 0;

  queue<int> q({0});

  while (!q.empty()) {
    const int u = q.front();
    q.pop();

    for (size_t i = 0; i < mat[u].size(); i++) {
      if (mat[u][i] && col[i] == 0) {
        col[i]++;
        dis[i] = dis[u] + 1;
        q.push(i);
      }
    }

    col[u]++;
  }

  for (size_t i = 0, s = dis.size(); i < s; i++) {
    if (i == s - 1) {
      printf("%d\n", dis[i]);
      return 0;
    }
    printf("%d ", dis[i]);
  }

  return 0;
}
