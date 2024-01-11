//shinzo_wo_sasageyo!!
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define int long long
#define endl "\n"
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
typedef long long ll;
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}


ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}


//use INT_MAX as LLONG_MAX

/*-------------------------------------------------------------------------
//FOR DP OR ELSE
//vector<vector<int>>(n+1,vector<int>(m+1,-1)) dp;memset(dp,-1,sizeof(dp));
-------------------------------------------------------------------------
//FOR FLAG->(YES/NO)
if(){
   cout<<"yes"<<endl;
}
else{
   cout<<"no"<<endl;
}
--------------------------------------------------------------------------
*/
/* void checkprime(bool isprime[],int n){
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i*i<=n;i++){//logic of iterating till sqaure root of n and not n
        if(isprime[i]==true){//if a number is prime it's multiples will not be prime
            for(int j=i*i;j<=n;j=j+i){//observation step
                isprime[j]=false;
            }
        }
    }
}

bool isprime[100001];*/
void calc_depth(vector<vector<int>> &v,vector<int> &depth,int n,int source){
    depth[source]=0;
    queue<int> q;
    q.push(source);
    vector<int> vis(n+1,0);
    vis[source]=1;
    while(q.size()!=0){
        int curr=q.front();
        q.pop();
        vector<int> children=v[curr];
        vis[curr]=1;
        for (int i = 0; i < children.size(); ++i)
        {
            int child=children[i];
            if(vis[child]==1){
                continue;
            }
            vis[child]=1;
            depth[child]=depth[curr]+1;
            q.push(child);
        }

    }
    return;

}



 void rec(int root,int par,vector<vector<int>> &parent,vector<vector<int>> &v){//for every node 2^0th par is calculated

    parent[root][0]=par;//2^0th parent
    vector<int> children=v[root];
    for(int i=0;i<children.size();i++){
        int child=children[i];
        if(child!=par){
            rec(child,root,parent,v);
        }
    }

}
int lca(int a,int b,vector<vector<int>> &parent,int pos,vector<int> &depth,vector<vector<int>> &v){
    if(depth[a]>depth[b]){
        swap(a,b);
    }
    int diff=depth[b]-depth[a];

    for(int i=21;i>=0;i--){
        if(diff<=0){
            break;

        }

        int mask=(int)1<<i;
        if((mask&diff)>0){

            b=parent[b][i];

            diff=diff-mask;
        }

    }


    if(a==b){
        return a;
    }
    for(int i=pos;i>=0;i--){
        if(parent[a][i]!=-1 and parent[a][i]!=parent[b][i]){
            a=parent[a][i];
            b=parent[b][i];
        }
    }
    return parent[a][0];
}





signed main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
    /* for(int i=0;i<=100001;i++){
        isprime[i]=true;
    }
    checkprime(isprime,100001); */

 int t;
 cin>>t;
 while(t--){
   int n;
   cin>>n;

   vector<int> a(n+1,0);
   for(int i=1;i<=n;i++){
    cin>>a[i];
}
vector<vector<int>> v(n+1);

for(int i=2;i<=n;i++){
    int c;
    cin>>c;
    v[i].push_back(c);
    v[c].push_back(i);
}
vector<int> depth(n+1,0);
calc_depth(v,depth,n,1);

int pos=20;


vector<vector<int>> parent(n+1,vector<int> (pos+1,-1));
rec(1,-1,parent,v);


for(int i=1;i<=pos;i++){

    for(int j=1;j<=n;j++){

        int par=parent[j][i-1];
        if(par!=-1){
            parent[j][i]=parent[par][i-1];
        }
    }
}









}















return 0;
}