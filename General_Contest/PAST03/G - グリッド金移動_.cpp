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

template <typename T>
struct nvector {
  int edge, tot;
  vector<T> vec;
  nvector(int edge) : edge(edge), tot(edge * 2 + 1), vec(tot) {
  }
  nvector(int edge, T init) : edge(edge), tot(edge * 2 + 1), vec(tot, init) {
  }
  T& operator[](int pos) {
    return vec[pos + edge];
  }
};

template <typename T>
ostream& operator<<(ostream& s, const nvector<T>& nvector) {
  s << nvector.vec;
  return s;
}

signed main() {
  int N, X, Y;
  cin >> N >> X >> Y;

  typedef pair<int, int> P;
  set<P> NG;
  vector<int> x(N), y(N);
  rep(i, N) {
    cin >> x[i] >> y[i];
    NG.insert(P(x[i], y[i]));
  }

  vector<int> dx = {1, 0, -1, 1, -1, 0};
  vector<int> dy = {1, 1, 1, 0, 0, -1};

  map<P, int> dist;
  dist[P(0, 0)] = 0;

  queue<P> q;
  q.push(P(0, 0));

  int cnt = 1000000;
  while (!q.empty() && cnt-- > 0) {
    auto now = q.front();
    q.pop();

    cout << now.fi << ' ' << now.se << endl;


    if (now == P(X, Y)) {
      cout << dist[now] << endl;
      return 0;
    }

    rep(d, 6) {
      P next = P(now.fi + dx[d], now.se + dy[d]);
      if (NG.find(next) != NG.end())
        continue;
      if (dist.find(next) != dist.end() && dist[next] < dist[now] + 1)
        continue;

      dist[next] = dist[now] + 1;
      q.push(next);
    }
  }
  cout << -1 << '\n';
}