#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int kLimit = 182;

int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);

  vector<vector<int>> words(n, vector<int>(m));
  for (size_t i = 0; i < words.size(); i++) {
    char word[kLimit];
    scanf("%s\n", word);
    for (size_t j = 0; j < words[i].size(); j++) {
      words[i][j] = word[j] - '0';
    }
  }

  vector<vector<int>> col(n, vector<int>(m, 0));
  vector<vector<int>> dis(n, vector<int>(m, kLimit));

  queue<pair<const int, const int>> q;

  for (size_t i = 0; i < words.size(); i++) {
    for (size_t j = 0; j < words[i].size(); j++) {
      if (words[i][j] == 1) {
        col[i][j] = 1;
        dis[i][j] = 0;
        q.push(make_pair(i, j));
      }
    }
  }

  while (!q.empty()) {
    const auto u = q.front();
    q.pop();

    vector v{vector{u.first - 1, u.second}, vector{u.first, u.second - 1},
             vector{u.first + 1, u.second}, vector{u.first, u.second + 1}};

    for (size_t i = 0; i < v.size(); i++) {
      if (v[i][0] >= 0 && v[i][0] < n && v[i][1] >= 0 && v[i][1] < m &&
          col[v[i][0]][v[i][1]] == 0) {

        col[v[i][0]][v[i][1]]++;
        dis[v[i][0]][v[i][1]] = dis[u.first][u.second] + 1;

        q.push(make_pair(v[i][0], v[i][1]));
      }
    }

    col[u.first][u.second]++;
  }

  for (size_t i = 0; i < dis.size(); i++) {
    size_t j = 0;
    while (j < dis[i].size() - 1) {
      printf("%d ", dis[i][j]);
      j++;
    }
    printf("%d\n", dis[i][j]);
  }

  return 0;
}
