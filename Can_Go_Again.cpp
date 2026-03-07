#include <bits/stdc++.h>

using namespace std;
#define f for (int i = 0; i < n; i++)
#define f1 for (int i = 1; i < n; i++)
#define fj for (int j = 0; j < n; j++)
#define s(x) sort(x.begin(), x.end());
#define ll long long
class edge
{
public:
    ll int a, b, c;
    edge(ll int a, ll int b, ll int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
ll int dis[1005];
ll int n, e;
vector<edge> edge_list;
void bellman(ll int scr)
{
    for (int i = 0; i <= n; i++)
        dis[i] = LLONG_MAX;
    dis[scr] = 0;
    for (auto i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }
    bool cycle = false;
    for (auto &ed : edge_list)
    {
        if (dis[ed.a] != LLONG_MAX && dis[ed.a] + ed.c < dis[ed.b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        exit(0);
    }
}

int main()

{

    cin >> n >> e;
    while (e--)
    {
        /* code */
        ll int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(edge(a, b, c));
    }
    ll int scr;
    cin >> scr;
    bellman(scr);
    int q;
    cin >> q;
    while (q--)
    {
        /* code */
        ll int disx;
        cin >> disx;
        if (dis[disx] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dis[disx] << endl;
    }

    return 0;
}