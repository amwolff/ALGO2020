#include <limits.h>

#include <cstdio>
#include <vector>

using namespace std;

vector<int> cap, fin;

vector visited(49, vector(49, false));

int _forTwo(const vector<int> &cur) {
  if (visited[cur[0]][cur[1]]) {
    return INT_MAX;
  }

  visited[cur[0]][cur[1]] = true;

  if (cur[0] == fin[0] && cur[1] == fin[1]) {
    return 0;
  }

  if (cur[0] == 0 && cur[1] == 0) {
    return INT_MAX;
  }

  int m1 = INT_MAX;
  if (cur[0] > 0) {
    vector newCur(cur);
    newCur[0] = 0;
    m1 = _forTwo(newCur);
  }
  int m2 = INT_MAX;
  if (cur[1] > 0) {
    vector newCur(cur);
    newCur[1] = 0;
    m2 = _forTwo(newCur);
  }
  int m3 = INT_MAX;
  if (cur[0] < cap[0] && cur[1] > 0) {
    vector newCur(cur);
    newCur[0] += newCur[1];
    if (newCur[0] > cap[0]) {
      newCur[1] = newCur[0] - cap[0];
    } else {
      newCur[1] = 0;
    }
    newCur[0] -= newCur[1];
    m3 = _forTwo(newCur);
  }
  int m4 = INT_MAX;
  if (cur[1] < cap[1] && cur[0] > 0) {
    vector newCur(cur);
    newCur[1] += newCur[0];
    if (newCur[1] > cap[1]) {
      newCur[0] = newCur[1] - cap[1];
    } else {
      newCur[0] = 0;
    }
    newCur[1] -= newCur[0];
    m4 = _forTwo(newCur);
  }

  int minimum = min(min(m1, m2), min(m3, m4));
  if (minimum == INT_MAX) {
    return INT_MAX;
  }
  return 1 + minimum;
}

int forTwo() { return _forTwo(vector(cap)); }

int main() {
  int n;
  scanf("%d\n", &n);

  vector<int> cur;
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    cap.push_back(c);
  }
  for (int i = 0; i < n; i++) {
    int f;
    scanf("%d", &f);
    fin.push_back(f);
  }

  if (n == 1) {
    if (fin[0] == cur[0] || fin[0] == 0) {
      printf("%d\n", 1);
    } else {
      printf("NIE\n");
    }
    return 0;
  }

  if (n > 2) {
    return 0;
  }

  int ans = forTwo();
  if (ans == INT_MAX) {
    printf("NIE\n");
    return 0;
  }
  printf("%d\n", ans);
  return 0;
}
