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

vector<vector<int>> sub;
int dfs(int now) {
  vector<int>& subs = sub[now];
  int nsub = subs.size();
  if (nsub == 0) {
    return 1;
  } else {
    vector<int> sub_salary(nsub);
    int Max = 0;
    int Min = INF;
    rep(i, nsub) {
      int temp = dfs(subs[i]);
      chmax(Max, temp);
      chmin(Min, temp);
    }
    return Max + Min + 1;
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> B(N);
  sub = vector<vector<int>>(N);
  repp(i, 1, N - 1) {
    cin >> B[i];
    B[i]--;
    sub[B[i]].pb(i);
  }

  cout << dfs(0) << endl;
}