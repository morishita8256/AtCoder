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


signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }
  vector<int> B(N);
  rep(i, N) {
    cin >> B[i];
  }


  int ans = INF;

  rep(b, bit(N)) {
    int num = __builtin_popcount(b);  // 裏
    if (num % 2 == 1)
      continue;

    vector<int> o, e;
    vector<int> place(N);
    vector<int> start(N);


    rep(i, N) {
      if ((b >> i) & 1) {  // 裏
        if (i % 2 == 0) {
          e.pb(B[i]);
          start[i] = B[i];
          place[i] = 1;
        } else {
          o.pb(B[i]);
          start[i] = B[i];
          place[i] = 0;
        }
      } else {  // 表
        if (i % 2 == 0) {
          o.pb(A[i]);
          start[i] = A[i];
          place[i] = 0;
        } else {
          e.pb(A[i]);
          start[i] = A[i];
          place[i] = 1;
        }
      }
    }

    if (!(len(o) == len(e) || len(o) == (len(e) + 1)))
      continue;

    auto o_cp = o, e_cp = e;

    sort(all(o));
    sort(all(e));

    int oo = 0, ee = 0;
    vector<int> goal(N);
    rep(i, N) {
      if (i % 2 == 0)
        goal[i] = o[oo++];
      else
        goal[i] = e[ee++];
    }

    bool ok = true;
    rep(i, N - 1) {
      if (goal[i] > goal[i + 1])
        ok = false;
    }
    if (!ok)
      continue;

    int cnt = 0;
    rep(i, N - 1) {
      int k;
      repp(j, i, N - 1) {
        if (goal[i] == start[j] && i % 2 == place[j]) {
          k = j;
          break;
        }
      }
      repr(j, k - 1, i) {
        swap(start[j], start[j + 1]);
        swap(place[j], place[j + 1]);
        cnt++;
      }
    }

    chmin(ans, cnt);
  }

  if (ans == INF) {
    puts("-1");
  } else {
    cout << ans << "\n";
  }
}