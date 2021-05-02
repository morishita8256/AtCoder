#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define sz(x) ((ll)(x).size())
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
  vector<int> a(N - 1), b(N - 1);
  rep(i, N - 1) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }

  vector<int> cnt(N);
  rep(i, N - 1) {
    cnt[a[i]]++;
    cnt[b[i]]++;
  }

  int K = 0;
  rep(i, N) {
    chmax(K, cnt[i]);
  }

  cout << K << endl;

  vector<vector<int>> G(N);
  rep(i, N - 1) {
    G[a[i]].pb(b[i]);
  }


  vector<int> color(N);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int now = q.front();
    int now_c = color[now];
    q.pop();
    for (int to : G[now]) {
      now_c++;
      if (now_c > K)
        now_c -= K;
      color[to] = now_c;
      q.push(to);
    }
  }

  rep(i, N - 1) {
    cout << color[b[i]] << endl;
  }
}
