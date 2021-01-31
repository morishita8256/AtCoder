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
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
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

int R, C, N;
bool onEdge(int x1, int y1, int x2, int y2) {
  bool on1 = x1 == 0 || x1 == R || y1 == 0 || y1 == C;
  bool on2 = x2 == 0 || x2 == R || y2 == 0 || y2 == C;
  return on1 && on2;
}

const int offset = 1000000000;

signed main() {
  cin >> R >> C >> N;
  vector<int> x1(N), y1(N), x2(N), y2(N);
  vector<int> X, Y, ID;


  rep(i, N) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    if (onEdge(x1[i], y1[i], x2[i], y2[i])) {
      X.pb(x1[i]), X.pb(x2[i]);
      Y.pb(y1[i]), Y.pb(y2[i]);
      ID.pb(i), ID.pb(i);
    }
  }

  typedef pair<int, int> P;  // pos, id
  vector<P> ps;
  rep(i, len(X)) {
    int id = ID[i];
    int x = X[i], y = Y[i];
    int pos;
    if (x == 0)
      pos = y;
    else if (y == C)
      pos = offset + x;
    else if (x == R)
      pos = offset * 2 + (C - y);
    else
      pos = offset * 3 + (R - x);
    ps.pb(P(pos, id));
  }
  sort(all(ps));

  vector<bool> seen(N, false);

  stack<int> st;
  for (auto p : ps) {
    int id = p.se;
    if (seen[id]) {
      if (id != st.top()) {
        cout << "NO\n";
        return 0;
      } else {
        st.pop();
      }
    } else {
      st.push(id);
      seen[id] = true;
    }
  }
  cout << "YES\n";
}