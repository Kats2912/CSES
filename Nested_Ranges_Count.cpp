#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define MOD 1000000007
#define MOD1 998244353
#define ll long long
#define int ll
#define ld long double
#define INF 1e18
#define nline '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define fo(i,a,b) for(int i = a; i < b ; i ++)
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vst;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
bool cmp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
    if(a.first.first==b.first.first)return a.first.second>b.first.second;
    return a.first.first<b.first.first;
}
void solve()
{
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> vec(n);
    fo(i,0,n){
        int a,b;
        cin>>a>>b;
        vec[i] = {{a,b},i};
    }
    sort(vec.begin(),vec.end(),cmp);
    vector<int> isContaining(n,0),isContained(n,0);
    pbds prevEnds;
    for(int i=n-1;i>=0;i--){
        pair<pair<int,int>,int> p = vec[i];
        isContaining[p.second] = prevEnds.order_of_key({p.first.second,n});
        prevEnds.insert({p.first.second,p.second});
    }

    prevEnds.clear();
    for(int i=0;i<n;i++){
        pair<pair<int,int>,int> p = vec[i];
        isContained[p.second] = prevEnds.size()-prevEnds.order_of_key({p.first.second,-1});
        prevEnds.insert({p.first.second,p.second});
    }

    fo(i,0,n)cout<<isContaining[i]<<' ';
    cout<<endl;
    fo(i,0,n)cout<<isContained[i]<<' ';
    cout<<endl;
    
}

signed main() 
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    int tc = 1;
    fo(i, 1, tc + 1)
    {
        solve();
    }
}