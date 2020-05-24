#include <cstdio>
#include <queue>

using namespace std;

int n;

vector<int> cap, fin;

int encode(const vector<int> &v) {
  int ret = 0;
  for (size_t i = 0; i < v.size(); i++) {
    ret = ret * (cap[i] + 1) + v[i];
  }
  return ret;
}

vector<int> decode(int v) {
  vector<int> ret(n);
  for (int i = n - 1; i >= 0; i--) {
    ret[i] = v % (cap[i] + 1);
    v /= cap[i] + 1;
  }
  return ret;
}

int main() {
  scanf("%d\n", &n);

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

  int cross_cur = 1;
  for (size_t i = 0; i < cap.size(); i++) {
    cross_cur *= cap[i] + 1;
  }

  const int enc_cap = encode(cap);
  const int enc_fin = encode(fin);

  vector dists(cross_cur, -1);

  dists[enc_cap] = 0;

  queue<int> q({enc_cap});

  while (!q.empty()) {
    const int u = q.front();
    q.pop();

    if (u == enc_fin) {
      printf("%d\n", dists[enc_fin]);
      return 0;
    }

    vector<int> d = decode(u);

    int w;
    for (size_t i = 0; i < d.size(); i++) {
      for (size_t j = 0; j < d.size(); j++) {
        if (i != j && d[i] > 0) {
          if (d[i] <= cap[j] - d[j]) {
            w = d[i];
          } else {
            w = cap[j] - d[j];
          }
          d[i] -= w;
          d[j] += w;

          const int e = encode(d);
          if (dists[e] == -1) {
            dists[e] = dists[u] + 1;
            q.push(e);
          }

          d[i] += w;
          d[j] -= w;
        }
      }
    }
    for (size_t i = 0; i < d.size(); i++) {
      if (d[i] > 0) {
        w = d[i];
        d[i] = 0;

        const int e = encode(d);
        if (dists[e] == -1) {
          dists[e] = dists[u] + 1;
          q.push(e);
        }

        d[i] = w;
      }
    }
  }

  printf("NIE\n");

  return 0;
}
