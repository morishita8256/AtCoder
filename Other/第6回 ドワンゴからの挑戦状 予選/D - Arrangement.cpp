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
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) {
    cin >> a[i];
    a[i]--;
  }

  if ((N == 2) && (a[0] == 1) && (a[1] == 0)) {
    cout << -1 << endl;
    return 0;
  }

  set<int> s;
  rep(i, N - 1) {
    s.insert(a[i + 1]);
  }

  int first = 0;
  if (sz(s) == 1) {
    for (auto i : s)
      first = i;
  }

  priority_queue<int, vector<int>, greater<int>> q;
  rep(i, N) {
    if (i == first)
      continue;
    q.push(i);
  }

  vector<int> ans(N);
  ans[0] = first;
  rep(i, N - 1) {
    int temp = q.top();
    if (temp != a[ans[i]]) {
      ans[i + 1] = temp;
      q.pop();
    } else {
      q.pop();
      int ttemp = q.top();
      ans[i + 1] = ttemp;
      q.pop();
      q.push(temp);
    }
  }

  rep(i, sz(ans)) {
    cout << (ans[i] + 1) << ((i == sz(ans) - 1) ? "\n" : " ");
  }
}