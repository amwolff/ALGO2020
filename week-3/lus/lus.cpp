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
  const int t = parseint();

  for (int i = 0; i < t; i++) {
    const int n = parseint();

    struct dimensions {
      int w_1;
      int w_2;
      int h_1;
      int h_2;
    };

    vector<dimensions> d(n);

    int min_w = 1e9;
    int max_w = 1;
    int min_h = 1e9;
    int max_h = 1;

    for (dimensions &x : d) {
      x.w_1 = parseint();
      x.w_2 = parseint();
      x.h_1 = parseint();
      x.h_2 = parseint();
      min_w = min(min_w, x.w_1);
      max_w = max(max_w, x.w_2);
      min_h = min(min_h, x.h_1);
      max_h = max(max_h, x.h_2);
    }

    for (const dimensions x : d) {
      if (min_w == x.w_1 && max_w == x.w_2 && min_h == x.h_1 &&
          max_h == x.h_2) {
        printf("TAK\n");
        goto cnt;
      }
    }

    printf("NIE\n");

  cnt:;
  }

  return 0;
}
