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

int main() {
  int S;
  cin >> S;

  int L = S / 100;
  int R = S % 100;

  bool L_is_MM = (1 <= L && L <= 12);
  bool R_is_MM = (1 <= R && R <= 12);

  if (L_is_MM && R_is_MM) {
    cout << "AMBIGUOUS" << endl;
  } else if (L_is_MM && !R_is_MM) {
    cout << "MMYY" << endl;
  } else if (!L_is_MM && R_is_MM) {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }
}