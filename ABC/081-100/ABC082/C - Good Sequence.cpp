#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  map<int, int> m;
  vector<int> m_elem;

  rep(i, N) {
    if (m.find(a[i]) == m.end()) {
      m[a[i]] = 1;
      m_elem.pb(a[i]);
    } else
      m[a[i]]++;
  }

  int ans = 0;
  rep(i, m_elem.size()) {
    int num = m_elem[i];
    int cnt = m[num];

    if (cnt < num)
      ans += cnt;
    else
      ans += cnt - num;
  }
  cout << ans << endl;
}