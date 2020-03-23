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
  int n, t;
  scanf("%d %d\n", &n, &t);

  if (n == 1) {
    printf("%lld\n", (long long)(parseint() * ((t + 1) / 2)));
    return 0;
  }

  int s = n;
  if (s > t) {
    s = t + 1;
  }

  vector<int> a;
  for (int i = 0; i < s; i++) {
    a.push_back(parseint());
  }

  long long sum;
  long long maximum = 0;
  long long progress = 0;
  for (size_t i = 0; i < a.size() - 1; i++) {
    sum = (long long)((a[i] + a[i + 1]) * ((t - i + 1) / 2)) + progress;
    if ((t - i + 1) % 2 > 0) {
      sum += a[i];
    }
    maximum = max(sum, maximum);
    progress += a[i];
  }

  printf("%lld\n", maximum);

  return 0;
}
