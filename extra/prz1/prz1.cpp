#include <limits.h>

#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);

  vector<int> prices(n + 1);
  for (int i = 0; i < n; i++) {
    scanf("%d\n", &prices[i]);
  }
  prices.back() = prices[0];

  int m;
  scanf("%d\n", &m);

  vector list(n + 1, vector<pair<const int, const int>>());
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d\n", &a, &b, &c);
    if (b == 1) {
      list[a - 1].push_back(make_pair(n, c));
    } else {
      list[a - 1].push_back(make_pair(b - 1, c));
    }
  }

  vector dist(n + 1, INT_MAX - prices[0]);

  dist[0] = 0;

  vector cost(prices);

  typedef pair<int, int> pii;

  priority_queue<pii, vector<pii>, greater<pii>> q;

  for (int i = 0; i < n; i++) {
    q.push(make_pair(dist[i], i));
  }

  while (!q.empty()) {
    const int u = q.top().second;
    q.pop();

    if (dist[u] == INT_MAX - prices[0]) {
      break;
    }

    for (const auto p : list[u]) {
      const int c = min(cost[u], prices[p.first] / 2);
      if (dist[p.first] + cost[p.first] > dist[u] + p.second + c) {
        dist[p.first] = dist[u] + p.second;
        cost[p.first] = c;
        q.push(make_pair(dist[p.first], p.first));
      }
    }
  }

  const int ans = dist.back() + cost.back();
  const int alt = prices[0] / 2;
  if (ans < alt) {
    printf("%d\n", ans);
  } else {
    printf("%d\n", alt);
  }

  return 0;
}
