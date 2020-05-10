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
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
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

template <typename T>
struct cvector {
  vector<T> vec;
  cvector() : vec(26) {
  }
  cvector(T init) : vec(26, init) {
  }
  T& operator[](char c) {
    return vec[c - 'a'];
  }
};

template <typename T>
ostream& operator<<(ostream& s, const cvector<T>& cvector) {
  s << cvector.vec;
  return s;
}

signed main() {
  int H, W;
  cin >> H >> W;
  cvector<int> cnt;
  vector<vector<char>> a(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> a[i][j];
      cnt[a[i][j]]++;
    }
  }

  for (char c = 'a'; c <= 'z'; c++) {
    cnt[c] %= 4;
  }

  int h = H % 2, w = W % 2;

  bool ok = true;
  if (h + w == 0) {
    for (char c = 'a'; c <= 'z'; c++) {
      if (cnt[c] != 0)
        ok = false;
    }
  } else if (h + w == 1) {
    int can2 = (h ? W : H) / 2;
    for (char c = 'a'; c <= 'z'; c++) {
      if (cnt[c] == 0)
        continue;
      if (cnt[c] == 2 && can2 > 0) {
        can2--;
        continue;
      }
      ok = false;
    }
  } else {
    int can2 = H / 2 + W / 2;
    int can1 = 1;
    for (char c = 'a'; c <= 'z'; c++) {
      if (cnt[c] == 0)
        continue;
      if (cnt[c] == 2 && can2 > 0) {
        can2--;
        continue;
      }
      if (cnt[c] == 1 && can1 > 0) {
        can1--;
        continue;
      }
      ok = false;
    }
  }

  if (ok)
    cout << "Yes\n";
  else
    cout << "No\n";
}