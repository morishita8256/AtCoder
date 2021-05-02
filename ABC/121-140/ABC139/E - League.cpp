#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N - 1));
  rep(i, N) {
    rep(j, N - 1) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }

  int ans = 0;
  int finished = 0;
  vector<int> iter(N);
  queue<int> pq;
  rep(i, N) {
    pq.push(i);
  }

  while (finished < N) {
    ans++;
    vector<bool> play_on_the_day(N, false);
    bool ok = false;
    queue<int> nq;

    while (!pq.empty()) {
      int a = pq.front();
      pq.pop();
      if (iter[a] >= N - 1)
        continue;
      int b = A[a][iter[a]];
      if (iter[b] >= N - 1)
        continue;
      int c = A[b][iter[b]];

      if (a == c && !play_on_the_day[a] && !play_on_the_day[b]) {
        ok = true;
        nq.push(a);
        nq.push(b);
        play_on_the_day[a] = true;
        play_on_the_day[b] = true;
        iter[a]++;
        iter[b]++;
        if (iter[a] == N - 1)
          finished++;
        if (iter[b] == N - 1)
          finished++;
      }
    }
    if (!ok) {
      cout << -1 << endl;
      return 0;
    }

    pq = nq;
  }
  cout << ans << endl;
}