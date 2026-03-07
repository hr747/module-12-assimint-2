#include <bits/stdc++.h>

using namespace std;
#define f for (int i = 0; i < n; i++)
#define f1 for (int i = 1; i < n; i++)
#define fj for (int j = 0; j < n; j++)
#define s(x) sort(x.begin(),x.end());
#define ll long long

 int main()

{
    int t;
    cin>>t;
    while (t--)
    {
        /* code */
        int n;
        cin>>n;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)
        {
            cin >> v[i].first; 
            v[i].second = i;
        }
        sort(v.begin(),v.end());
        int l=v[n-1].second;
        int r=v[n-2].second;
        if(l>r)
        swap(l,r);
        cout<<l<<" "<<r<<endl;
    }
    

    return 0;
}