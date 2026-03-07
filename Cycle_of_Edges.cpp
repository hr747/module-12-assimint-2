#include <bits/stdc++.h>

using namespace std;
#define f for (int i = 0; i < n; i++)
#define f1 for (int i = 1; i < n; i++)
#define fj for (int j = 0; j < n; j++)
#define s(x) sort(x.begin(),x.end());
#define ll long long
int par[1000005];
int node_siz[1000005];
int dsa_find(int node)
{
    if (par[node] == -1)
        return node;

    int lider = dsa_find(par[node]);
    par[node] = lider;

    return lider;
}
void dsa_unino(int node1,int node2)
{
    int lider1=dsa_find(node1);
    int lider2=dsa_find(node2);
    if(node_siz[lider1]>=node_siz[lider2])
    {
        par[lider2]=lider1;
        node_siz[lider1]+=node_siz[lider2];
    }
    else
    {
        par[lider1]=lider2;
        node_siz[lider2]+=node_siz[lider1];

    }
    

}

 int main()

{ 
    int n,e;
    cin>>n>>e;
    int count=0;
   for (int i = 0; i <= n; i++) {
        par[i] = -1;
        node_siz[i] = 1;
    }
   
    bool cycle=false;
    while (e--)
    {
        /* code */
        int a,b;
        cin>>a>>b;
        int lidera=dsa_find(a);
        int liderb=dsa_find(b);
        if(lidera==liderb){
        cycle=true;
        count++;}

        else
        dsa_unino(a,b);


    }
    cout<<count<<endl;
   
    

    return 0;
}