#include <cstdio>

using namespace std;

int main() {
  int n;
  char s[500000];
  scanf("%d\n%s", &n, s);

  // Use a closure here to remember state.
  char prev = '\0';
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == prev) {
      cnt++;
      if (i == n - 1) {
        ans += (cnt + 1) / 2;
      }
    } else {
      ans += (cnt + 1) / 2;
      cnt = 0;
    }
    prev = s[i];
  }

  printf("%d\n", ans);

  return 0;
}
