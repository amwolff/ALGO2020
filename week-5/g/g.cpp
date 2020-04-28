#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);

  vector list(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d\n", &a, &b);
    list[a - 1].push_back(b - 1);
  }

  vector col(n, 0);
  vector dis(n, -1);

  col[0] = 1;
  dis[0] = 0;

  queue<int> q({0});

  while (!q.empty()) {
    const int u = q.front();
    q.pop();

    for (const int v : list[u]) {
      if (col[v] == 0) {
        col[v]++;
        dis[v] = dis[u] + 1;
        q.push(v);
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
