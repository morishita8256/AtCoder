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

ll N, K;
vector<ll> A;


template <class T>
T find_min(T l, T r, bool f(T)) {
  T c;
  while (r - l > 1) {
    c = (r + l) / 2;
    if (f(c)) {
      r = c;
    } else {
      l = c;
    }
  }

  return r;
}


ll wari(ll a, ll b) {
  ll res = a / b;
  if (a == 0)
    return 0;

  if (a < 0 && (a % b != 0)) {
    if (b > 0)
      res--;
    else
      res++;
  }
  return res;
}

bool f(ll trial) {
  ll cnt = 0;

  rep(i, N) {
    if (A[i] * A[i] <= trial)
      cnt--;
  }

  rep(i, N) {
    if (A[i] == 0) {
      if (trial >= 0)
        cnt += N;
    } else if (A[i] > 0) {
      auto iter = upper_bound(all(A), wari(trial, A[i]));
      ll pos = distance(A.begin(), iter);
      cnt += pos;
    } else {
      auto iter = lower_bound(all(A), wari(trial, A[i]));
      ll pos = distance(A.begin(), iter);
      cnt += (N - pos);
    }
  }
  cnt /= 2;

  return cnt >= K;
}

signed main() {
  cin >> N >> K;
  A = vector<ll>(N);
  rep(i, N) {
    cin >> A[i];
  }
  sort(all(A));
  cout << find_min(-LINF, LINF, f) << endl;
}