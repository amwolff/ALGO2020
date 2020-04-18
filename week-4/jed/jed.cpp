#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);

  const size_t s = n;

  vector<int> a(s), b(s), c(s);
  for (size_t i = 0; i < s; i++) {
    scanf("%d", &a[i]);
  }
  for (size_t i = 0; i < s; i++) {
    scanf("%d", &b[i]);
  }
  for (size_t i = 0; i < s; i++) {
    scanf("%d", &c[i]);
  }

  vector<int> distancesAB(s), distancesBC(s);
  for (size_t i = 0; i < s; i++) {
    distancesAB[a[i] - 1] = i;
    distancesBC[b[i] - 1] = i;
  }

  for (size_t i = 0; i < s; i++) {
    distancesAB[b[i] - 1] -= i;
    if (distancesAB[b[i] - 1] < 0) {
      distancesAB[b[i] - 1] += n;
    }
    distancesBC[c[i] - 1] -= i;
    if (distancesBC[c[i] - 1] < 0) {
      distancesBC[c[i] - 1] += n;
    }
  }

  map<pair<int, int>, int> pairCount;
  for (size_t i = 0; i < s; i++) {
    pairCount[make_pair(distancesAB[i], distancesBC[i])]++;
  }

  printf("%d\n", max_element(pairCount.cbegin(), pairCount.cend(),
                             [](const auto &p1, const auto &p2) {
                               return p1.second < p2.second;
                             })
                     ->second);

  return 0;
}
