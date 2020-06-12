#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);

  vector<pair<int, int>> pk(n + 1);

  pk[0] = make_pair(0, 0);

  for (size_t i = 1; i < pk.size(); i++) {
    scanf("%d %d\n", &pk[i].first, &pk[i].second);
  }

  sort(pk.begin(), pk.end(),
       [](const auto &p1, const auto &p2) { return p1.second < p2.second; });

  vector<int> prev(n + 1);

  prev[0] = 0;

  for (size_t i = 1, s = pk.size(); i < s; i++) {
    size_t lo = 0;
    size_t hi = s;
    while (lo < hi) {
      const size_t mid = (lo + hi) / 2;
      if (pk[mid].second <= pk[i].first) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    if (pk[lo].second == pk[i].first) {
      prev[i] = lo;
    } else {
      prev[i] = max(0, int(lo) - 1);
    }
  }

  vector<int> m(n + 1);

  m[0] = 0;

  for (size_t i = 1; i < m.size(); i++) {
    m[i] = max((pk[i].second - pk[i].first) + m[prev[i]], m[i - 1]);
  }

  printf("%d\n", m.back());

  return 0;
}
