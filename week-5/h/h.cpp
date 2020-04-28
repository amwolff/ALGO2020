#include <limits.h>

#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const long long kUnreachable = -1;

int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);

  vector list(n, vector<pair<const int, const int>>());
  for (int i = 0; i < m; i++) {
    int a, b, l;
    scanf("%d %d %d\n", &a, &b, &l);
    list[a - 1].push_back(make_pair(b - 1, l));
  }

  vector d(n, LONG_LONG_MAX);

  d[0] = 0;

  typedef pair<long long, int> plli;

  priority_queue<plli, vector<plli>, greater<plli>> q;

  for (int i = 0; i < n; i++) {
    q.push(make_pair(d[i], i));
  }

  while (!q.empty()) {
    const int u = q.top().second;
    q.pop();

    if (d[u] == LONG_LONG_MAX) {
      replace(d.begin(), d.end(), LONG_LONG_MAX, kUnreachable);
      break;
    }

    for (const auto p : list[u]) {
      if (d[p.first] > d[u] + p.second) {
        d[p.first] = d[u] + p.second;
        q.push(make_pair(d[p.first], p.first));
      }
    }
  }

  for (size_t i = 0, s = d.size(); i < s; i++) {
    if (i == s - 1) {
      printf("%lld\n", d[i]);
      return 0;
    }
    printf("%lld ", d[i]);
  }

  return 0;
}
