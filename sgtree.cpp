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

class SGtree{
    vector<int> seg;
    public:

    SGtree(int n){
        seg.resize(4*n+1);
    }
    void build(int id,int l,int r,vector<int> &a){
    if(r-l==1){
        //base case, reached leaf node
        seg[id]=a[l];
        return;
    }
    


    //when not leaf node
     int mid=((int)l+r)/2;
    
     build(2*id,l,mid,a);
     build(2*id+1,mid,r,a);


     seg[id]=min(seg[(2*id)],seg[(2*id)+1]);

    return;


    //build func->time complexity is same as number of nodes which is at max 4*n
}

int query(int id,int x,int y,int l,int r){
    //three cases



    if(l>=x and r<=y){
        // l and r lies inside
        return seg[id];
    }
    else if(l>=y or r<=x){

        //lies outside range
        int use=INT64_MAX;
        return use;
    }
    //there is an overlap
    int mid=((int)l+r)/2;


    int left=query(2*id,x,y,l,mid);
    int right=query(2*id+1,x,y,mid,r);
    return min(left,right);
}

int update(int id,int l,int r,int index,int value){

    if(r-l==1){
        if(index==l){
            seg[id]=value;
            return seg[id];
        }
    }


    int mid=((int)l+r)/2;
    if(index>=l and index<mid){
        int pos=update(2*id,l,mid,index,value);
        seg[id]=min(pos,seg[2*id+1]);
        return seg[id];
    }
    else{
        //go to the right
        int pos=update(2*id+1,mid,r,index,value);
        seg[id]=min(pos,seg[2*id]);
        return seg[id];


    }
   // return;



}

};
 

 
signed main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /* for(int i=0;i<=100001;i++){
        isprime[i]=true;
    }
    checkprime(isprime,100001); */
    int n;
    cin>>n;
   vector<int> a(n+1,0);
   vector<int> b(n+1,0);
   for (int i = 0; i < n; ++i)
   {
       cin>>a[i];
   }
   for (int i = 0; i < n; ++i)
   {
       cin>>b[i];
   }
   int l1,r1,l2,r2;
   cin>>l1>>r1>>l2>>r2;
   SGtree s1(n);
   SGtree s2(n);
   s1.build(1,0,n,a);
   s2.build(1,0,n,b);

   cout<<s1.query(1,0,1,0,5)<<" "<<s2.query(1,0,5,0,5);



   
 
    return 0;
}

