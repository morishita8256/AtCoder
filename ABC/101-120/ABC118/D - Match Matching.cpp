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
const int MOD = 1000000007;

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

vector<int> cost = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

/* return true if s>t */
bool strcomp(string s, string t) {
  if (s.size() > t.size()) {
    return true;
  } else if (s.size() < t.size()) {
    return false;
  } else {
    return s > t;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  typedef pair<int, int> P;
  vector<P> AB(M); /* A:num, B:cost */

  rep(i, M) {
    cin >> AB[i].fi;
    AB[i].se = cost[AB[i].fi];
  }

  vector<int> dp(N + 1, -INF);
  dp[0] = 0;
  rep(i, N) {
    rep(j, M) {
      int ncost = AB[j].se;
      if (i + ncost <= N)
        chmax(dp[i + ncost], dp[i] + 1);
    }
  }

  int keta = dp[N];
  sort(all(AB), greater<P>());
  string ans;

  int itr = N;
  rep(i, keta) {
    rep(j, M) {
      int num = AB[j].fi;
      int cost = AB[j].se;
      if (itr - cost >= 0 && dp[itr] - 1 == dp[itr - cost]) {
        ans += (char)(num + '0');
        itr -= cost;
        break;
      }
    }
  }
  cout << ans << endl;
}