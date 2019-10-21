#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  vector<string> J = {"月", "火", "水", "木", "金"};
  vector<string> E = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

  vector<string> S;

  while (1) {
    string temp;
    getline(cin, temp);
    if (cin.eof())
      break;

    S.pb(temp);
  }

  cout << endl;
  int i = 0, j = 0;
  while (j < 5) {
    if (S[i] == J[j]) {
      i++;
      cout << "Exclude" << E[j] << "=" << S[i] << endl;
      i++;
      j++;
    } else
      i++;
  }
}