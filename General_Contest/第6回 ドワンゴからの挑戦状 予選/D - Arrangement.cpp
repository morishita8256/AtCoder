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
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

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


int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) {
    cin >> a[i];
    a[i]--;
  }

  if (N <= 5) {
    vector<int> v(N);
    iota(v.begin(), v.end(), 0);
    do {
      bool ok = true;
      rep(i, N - 1) {
        if (a[v[i]] == v[i + 1])
          ok = false;
      }

      if (ok) {
        rep(i, len(v)) {
          cout << (v[i] + 1) << ((i == len(v) - 1) ? "\n" : " ");
        }
        return 0;
      }
    } while (next_permutation(v.begin(), v.end()));
    puts("-1");
    return 0;
  }

  vector<int> in(N);
  rep(i, N) {
    in[a[i]]++;
  }

  set<int> s;
  rep(i, N) {
    s.insert(i);
  }

  vector<int> ans(N);
  int NG = -1;
  rep(i, N - 4) {
    int x;
    for (auto cand : s) {
      if (NG == cand)
        continue;
      x = cand;
      break;
    }

    if (in[a[x]] == N - 1 - i)
      x = a[x];

    ans[i] = x;
    NG = a[x];
    in[x] = -1;
    in[a[x]]--;
    s.erase(x);
  }

  vector<int> v;
  for (auto elem : s) {
    v.pb(elem);
  }

  do {
    rep(i, 4) {
      ans[N - 4 + i] = v[i];
    }
    bool ok = true;

    rep(i, 4) {
      if (a[ans[N - 5 + i]] == ans[N - 5 + i + 1])
        ok = false;
    }
    if (ok) {
      rep(i, len(ans)) {
        cout << (ans[i] + 1) << ((i == len(ans) - 1) ? "\n" : " ");
      }
      return 0;
    }
  } while (next_permutation(v.begin(), v.end()));

  puts("-1");
  return 0;
}