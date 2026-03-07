#include <bits/stdc++.h>

using namespace std;
#define f for (int i = 1; i <= n; i++)

#define fj for (int j = 1; j < =n; j++)
#define s(x) sort(x.begin(), x.end());
#define ll long long

int main()

{
    int n, e;
    cin >> n >> e;
   ll int adj_mat[n+5][n+5];
    f 
    for(int j=1;j<=n;j++)
    {
        if (i == j)
        {
            adj_mat[i][j] = 0;
        }
        else
          adj_mat[i][j] = LLONG_MAX;
    }
    while (e--)
    {
        /* code */
       ll int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] =min(adj_mat[a][b], c);
        // adj_mat[b][a] = min(adj_mat[a][b], c);
    }
    for (auto k = 1; k <= n; k++)
        f for(int j=1;j<=n;j++)
        {
            if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
            {
                adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
        int q;
        cin>>q;
    while (q--)
    {
        /* code */
        int a, b;
        cin >> a >> b;
        if (adj_mat[a][b] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[a][b] << endl;
    }

    return 0;
}