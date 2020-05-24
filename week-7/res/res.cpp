#include <limits.h>

#include <cstdio>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int n, k, m;
  scanf("%d %d %d\n", &n, &k, &m);

  vector<int> r;
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d\n", &x);
    r.push_back(x - 1);
  }

  vector list(n, vector<pair<const int, const int>>());
  for (int i = 0; i < m; i++) {
    int a, b, l;
    scanf("%d %d %d\n", &a, &b, &l);
    list[a - 1].push_back(make_pair(b - 1, l));
    list[b - 1].push_back(make_pair(a - 1, l));
  }

  vector d(k, vector(n, INT_MAX));

  for (size_t i = 0; i < r.size(); i++) {
    d[i][r[i]] = 0;

    typedef pair<int, int> pii;

    priority_queue<pii, vector<pii>, greater<pii>> q;

    for (int j = 0; j < n; j++) {
      q.push(make_pair(d[i][j], j));
    }

    while (!q.empty()) {
      const int u = q.top().second;
      q.pop();

      if (d[i][u] == INT_MAX) {
        break;
      }

      for (const auto p : list[u]) {
        if (d[i][p.first] > d[i][u] + p.second) {
          d[i][p.first] = d[i][u] + p.second;
          q.push(make_pair(d[i][p.first], p.first));
        }
      }
    }
  }

  const unordered_set r_lookup(r.cbegin(), r.cend());

  int maximum = 0;
  for (int i = 0; i < n; i++) {
    if (r_lookup.count(i) != 0) {
      continue;
    }
    int minimum = INT_MAX;
    for (int j = 0; j < k; j++) {
      minimum = min(minimum, d[j][i]);
    }
    maximum = max(maximum, minimum);
  }

  printf("%d\n", maximum);

  return 0;
}
