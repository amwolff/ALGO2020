#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);

  vector<int> v(n);
  for (size_t i = 0; i < v.size(); i++) {
    scanf("%d\n", &v[i]);
  }

  vector m(n, 1);
  int maximum = 1;
  for (size_t i = 0; i < v.size(); i++) {
    for (size_t j = 0; j < i; j++) {
      const int t = m[j] + 1;
      if (v[i] > v[j] && m[i] < t) {
        m[i] = t;
        maximum = max(maximum, t);
      }
    }
  }

  printf("%d\n", maximum);

  return 0;
}
