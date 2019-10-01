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

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  map<ll, ll> m;
  rep(i, N) {
    cin >> a[i];
    m[a[i]]++;
  }

  if (m.size() == 3) {
    if (N % 3 != 0) {
      cout << "No" << endl;
      return 0;
    }
    ll X[3];
    ll i = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
      X[i] = (iter->fi);
      if ((iter->se) != N / 3) {
        cout << "No" << endl;
        return 0;
      }
      i++;
    }
    if ((X[0] ^ X[1] ^ X[2]) == 0) {  // ここのカッコは必須
      cout << "Yes" << endl;
      return 0;
    } else {
      cout << "No" << endl;
      return 0;
    }

  } else if (m.size() == 2) {
    if (N % 3 != 0) {
      cout << "No" << endl;
      return 0;
    }
    ll X[2];
    ll cnt[2];
    ll i = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
      X[i] = iter->fi;
      cnt[i] = iter->se;
      i++;
    }
    if (X[0] > X[1]) {
      swap(X[0], X[1]);
      swap(cnt[0], cnt[1]);
    }
    if (X[0] == 0 && cnt[1] == N * 2 / 3) {
      cout << "Yes" << endl;
      return 0;
    } else {
      cout << "No" << endl;
      return 0;
    }

  } else if (m.size() == 1) {
    auto iter = m.begin();
    ll X = iter->fi;
    if (X == 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }

  } else {
    cout << "No" << endl;
  }
}