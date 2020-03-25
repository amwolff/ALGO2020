#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

inline int parseint(void) {
  int c, n;

  n = getchar_unlocked() - '0';
  while ((c = getchar_unlocked()) >= '0') n = 10 * n + c - '0';

  return n;
}

int main() {
  vector<int> n;
  for (;;) {
    const int n_i = parseint();
    if (n_i > 0) {
      n.push_back(n_i);
    } else {
      break;
    }
  }

  sort(n.begin(), n.end());

  for (size_t i = 0, j = 1, k = 2; k < n.size(); i++, j++, k++) {
    if (n[i] + n[j] > n[k]) {
      printf("%d %d %d\n", n[i], n[j], n[k]);
      return 0;
    }
  }

  printf("NIE\n");

  return 0;
}
