#include <cstdio>
#include <map>

using namespace std;

int main() {
  int p, k;
  scanf("%d %d\n", &p, &k);
  int n;
  scanf("%d\n", &n);

  map<int, int> moments;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d\n", &a, &b);

    const auto a_i = moments.find(a);
    if (a_i == moments.cend()) {
      moments[a] = 1;
    } else {
      a_i->second++;
    }

    const auto b_i = moments.find(b + 1);
    if (b_i == moments.cend()) {
      moments[b + 1] = -1;
    } else {
      b_i->second--;
    }
  }

  int current = 0;
  int maximum = 0;
  int minimum = 1e9;
  for (const auto m : moments) {
    if (m.first > k) {
      break;
    }
    if (m.first > p) {
      maximum = max(maximum, current);
      minimum = min(minimum, current);
    }
    current += m.second;
  }
  maximum = max(maximum, current);
  minimum = min(minimum, current);

  printf("%d %d\n", minimum, maximum);

  return 0;
}
