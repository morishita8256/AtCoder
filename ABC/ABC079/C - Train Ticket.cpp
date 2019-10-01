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
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int ctoi(char ch) { return ch - '0'; }

int main() {
  string S;
  cin >> S;
  int ans;
  rep(i, 1 << 3) {
    int temp = ctoi(S[0]);
    vector<int> sign(3);
    rep(j, 3) {
      sign[j] = ((i >> j) & 1) * 2 - 1;
      temp += sign[j] * ctoi(S[j + 1]);
    }

    if (temp == 7) {
      cout << S[0];
      rep(j, 3) {
        char sig = (sign[j] == 1) ? '+' : '-';
        cout << sig << S[j + 1];
      }
      cout << "=7" << endl;
      return 0;
    }
  }
}