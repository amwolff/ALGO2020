#include <cstdio>
#include <vector>

using namespace std;

int n, r;

int dfs(const vector<vector<int>> &W, const int i, const int j, const int c) {
  if (c > r) {
    return 0;
  }

  int ret = W[i][j];

  if (i > 0) {
    ret += dfs(W, i - 1, j, c + 1);
  }
  if (j > 0) {
    ret += dfs(W, i, j - 1, c + 1);
  }

  if (i < n - 1) {
    ret += dfs(W, i + 1, j, c + 1);
  }
  if (j < n - 1) {
    ret += dfs(W, i, j + 1, c + 1);
  }

  if (i > 0 && j > 0) {
    ret += dfs(W, i - 1, j - 1, c + 1);
  }

  if (i < n - 1 && j < n - 1) {
    ret += dfs(W, i + 1, j + 1, c + 1);
  }

  if (i > 0 && j < n - 1) {
    ret += dfs(W, i - 1, j + 1, c + 1);
  }
  if (i < n - 1 && j > 0) {
    ret += dfs(W, i + 1, j - 1, c + 1);
  }

  return ret;
}

int main() {
  scanf("%d %d\n", &n, &r);

  vector F(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &F[i][j]);
    }
  }

  vector W(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      W[i][j] = dfs(F, i, j, 0);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == n - 1) {
        printf("%d", W[i][j]);
      } else {
        printf("%d ", W[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}
