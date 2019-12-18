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
#define sz(x) ((ll)(x).size())
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


int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  rep(i, N) {
    rep(j, M) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }

  int ans = INF;
  vector<bool> use(M, true);
  rep(i, M) {
    vector<int> cnt(M);
    rep(j, N) {
      rep(k, M) {
        if (!use[A[j][k]])
          continue;
        cnt[A[j][k]]++;
        break;
      }
    }

    int max_sport;
    int max_num = 0;
    rep(j, M) {
      if (chmax(max_num, cnt[j]))
        max_sport = j;
    }

    chmin(ans, max_num);
    use[max_sport] = false;
  }
  cout << ans << endl;
}