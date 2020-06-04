#pragma region head
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
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

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
#pragma endregion

signed main() {
  int N, L, T;
  cin >> N >> L >> T;
  vector<int> X(N), W(N);
  vector<int> Y(N);


  rep(i, N) {
    cin >> X[i] >> W[i];
    Y[i] = X[i] + T * (W[i] == 1 ? +1 : -1);
    Y[i] = ((Y[i] % L) + L) % L;
  }

  int Y0 = Y[0];
  sort(all(Y));

  int temp = 0;
  repp(i, 1, N - 1) {
    if (W[0] == W[i])
      continue;

    int diff;
    if (W[0] == 1) {
      diff = X[i] - X[0];
    } else {
      diff = L + X[0] - X[i];
    }

    if (T * 2 < diff)
      continue;

    temp++;

    int d = T * 2 - diff;
    temp += d / L;
  }

  if (W[0] == 2)
    temp = N - temp;
  temp = (temp % N + N) % N;

  vector<int> ans(N);

  int ind;
  rep(i, N) {
    if (Y[i] == Y0) {
      ind = i;
      if (Y[(i + 1) % N] == Y0 && W[0] == 1)
        ind++;
      break;
    }
  }

  rep(i, N) {
    ans[(temp + i) % N] = Y[(ind + i) % N];
  }

  rep(i, len(ans)) {
    cout << ans[i] << endl;
  }
}