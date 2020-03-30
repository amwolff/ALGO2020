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
  const int n = parseint();
  const int m = parseint();

  vector<int> red_indegress(n);
  for (int i = 0; i < m; i++) {
    red_indegress[parseint() - 1]++;
    red_indegress[parseint() - 1]++;
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += red_indegress[i] * (n - 1 - red_indegress[i]);
  }

  printf("%d\n", (2 * n * (n - 1) * (n - 2) - 6 * sum) / 12);

  return 0;
}
