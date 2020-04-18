#include <cstdio>
#include <map>

using namespace std;

int main() {
  int p, k, n;
  scanf("%d %d\n%d\n", &p, &k, &n);

  map<const int, int> moments;

  moments[p] = 0;
  moments[k] = 0;

  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d\n", &a, &b);
    moments[a]++;
    moments[b + 1]--;
  }

  int current = 0;
  int maximum = 0;
  int minimum = 1e9 + 1;
  for (const auto m : moments) {
    current += m.second;
    if (m.first >= p && m.first <= k) {
      maximum = max(maximum, current);
      minimum = min(minimum, current);
    }
  }

  printf("%d %d\n", minimum, maximum);

  return 0;
}
