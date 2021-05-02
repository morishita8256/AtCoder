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
  vector<string> s(N);
  rep(i, N) cin >> s[i];

  int M;
  cin >> M;
  vector<string> t(M);
  rep(i, M) cin >> t[i];

  int ans = 0;
  rep(i, N) {
    string temp_s = s[i];
    int temp_ans = 0;
    rep(j, N) {
      if (temp_s == s[j]) temp_ans++;
    }
    rep(j, M) {
      if (temp_s == t[j]) temp_ans--;
    }
    chmax(ans, temp_ans);
  }
  cout << ans << endl;
}