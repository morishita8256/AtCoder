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
template <class T>
T find_max(T l, T r, bool f(T)) {
  T c;
  while (r - l > 1) {
    c = (r + l) / 2;
    if (f(c)) {
      l = c;
    } else {
      r = c;
    }
  }

  return l;
}


signed main() {
  int N;
  cin >> N;
  vector<int> D(N);
  vector<int> cnt(13);
  rep(i, N) {
    cin >> D[i];
    cnt[D[i]]++;
  }

  if (cnt[0] > 0) {
    cout << 0 << endl;
    return 0;
  }


  vector<int> det;
  vector<int> cand;

  repp(i, 1, 12) {
    if (cnt[i] >= 3) {
      cout << 0 << endl;
      return 0;
    } else if (cnt[i] == 2) {
      det.pb(i);
      det.pb(24 - i);
    } else if (cnt[i] == 1) {
      cand.pb(i);
    }
  }
  int M = len(cand);
  int ans = 0;
  /* 2bit */
  rep(b, bit(M)) {
    vector<int> temp = det;
    rep(i, M) {
      if ((b >> i) & 1)
        temp.pb(cand[i]);
      else
        temp.pb(24 - cand[i]);
    }


    int mn = INF;
    int L = len(temp);
    rep(i, L) {
      chmin(mn, temp[i]);
      chmin(mn, 24 - temp[i]);
    }
    rep(i, L) {
      repp(j, i + 1, L - 1) {
        chmin(mn, abs(temp[i] - temp[j]));
        chmin(mn, 24 - abs(temp[i] - temp[j]));
      }
    }
    chmax(ans, mn);
  }
  cout << ans << endl;
}