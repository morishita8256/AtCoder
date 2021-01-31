#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    char S[H + 2][W + 2];
    for (int j = 0; j <= W + 1; j++)
    {
        S[0][j] = '.';
        S[H + 1][j] = '.';
    }

    for (int i = 1; i <= H; i++)
    {
        string S_in;
        cin >> S_in;
        S[i][0] = '.';
        for (int j = 1; j <= W; j++)
        {
            S[i][j] = S_in[j - 1];
        }
        S[i][W + 1] = '.';
    }

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (S[i][j] == '#')
                cout << '#';
            else
            {
                int bombs = 0;
                for (int ii = i - 1; ii <= i + 1; ii++)
                {
                    for (int jj = j - 1; jj <= j + 1; jj++)
                    {
                        if (ii == i && jj == j)
                            continue;
                        else if (S[ii][jj] == '#')
                            bombs++;
                    }
                }
                cout << bombs;
            }
        }
        cout << endl;
    }
}
