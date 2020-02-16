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
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

string S, T;
int N;


bool A_win(int L, int s, char p, char m) {
  int l = 0, r = L - 1;
  rep(i, N) {
    if (T[i] == m)
      r = min(r + 1, L - 1);
    else if (T[i] == p)
      l = max(l - 1, 0);

    if (S[i] == m)
      l++;
    else if (S[i] == p)
      r--;

    if (l > r)
      return false;
  }
  if (l <= s && s <= r)
    return true;
  else
    return false;
}

signed main() {
  int H, W;
  cin >> H >> W;
  cin >> N;
  int sr, sc;
  cin >> sr >> sc;
  sr--, sc--;
  cin >> S >> T;
  reverse(all(S));
  reverse(all(T));


  if (A_win(H, sr, 'D', 'U') && A_win(W, sc, 'R', 'L'))
    cout << "YES\n";
  else
    cout << "NO\n";
}