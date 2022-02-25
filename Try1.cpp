#include <bits/stdc++.h>
using namespace std;
#define unit __int128  //Will not compile in PC
#define ll long long int
#define pii pair<ll,ll>
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define rrep(i,st,en) for(ll i=en-1;i>=st;i--)
#define vi vector<int>
#define vii vector<pii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define eb emplace_back
#define yes cout<<"YES"<<endl; return;
#define no cout<<"NO"<<endl; return;
#define flus fflush(stdout);
#define debug(x) cerr<<#x<<" : "<<x<<" ";
#define fin cerr<<endl;
#define ff first
#define ss second
#define sz size
#define pb push_back
#define np next_permutation
#define inf 1e18
#define Mod 1000000007
#define NewMod 998244353
#define set_bits __builtin_popcountll
#define PI 3.14159265358979323846
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
#define maxpq priority_queue<ll> 
#define nline '\n'
#define endl '\n'
// #define int long long int
// #define N 200005

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll mod_pow(ll a, ll x, ll p) { ll res = 1; while(x > 0) { if( x % 2 != 0) { res = (res * a) % p; } a = (a * a) % p; x /= 2; } return res; }
string decToBinary(ll n){ string t =""; for (ll i = 28; i >= 0; i--) { ll k = n >> i; if (k & 1) t+="1";else t+="0";} return t; }
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vi divisors(ll n){vi div;for(ll i=1;i*i<=n;i++){ if(n%i==0) { div.pb(i); if(n/i!=i) div.pb(n/i); }} return div;}
ll dx[]={1,0,0,-1};
ll dy[]={0,-1,1,0}; 
/*--------------------------------------------------------------------------------------------------------------------------*/

struct  project
{
    string name;
    int days;
    ll score;
    int day_before;
    int skills_num;
    vector<pair<string,int>> skills;
};

struct  person
{
    string name;
    int skills_num;
    vector<pair<string,int>> skills;
};





bool comp1(project p1,project p2){
    if(p1.score>p2.score){
        return true;
    }else if(p1.score==p2.score){
        if(p1.day_before<p2.day_before){
            return true;
        }
    }
    return false;
}



void solve(){
    int per,pro;
    cin>>per>>pro;

    vector<person> conter(per);
    vector<project> proj(pro);

    rep(i,0,per){
        string pname;
        cin>>pname;
        int skills;
        cin>>skills;

        vector<pair<string,int>> temp;
        rep(j,0,skills){
            string skill_name;
            cin>>skill_name;
            int level;
            cin>>level;
            temp.pb({skill_name,level});
        }
        conter[i].skills=temp;
        conter[i].name=pname;
        conter[i].skills_num=skills;
    }


    rep(i,0,pro){
        string pname;
        cin>>pname;
            
        int days;
        int score;
        int day_before;
        int skills_num;

        cin>>days>>score>>day_before>>skills_num;

        proj[i].name=pname;
        proj[i].skills_num=skills_num;
        proj[i].days=days;
        proj[i].score=score;
        proj[i].day_before=day_before;

        vector<pair<string,int>> temp;
        rep(j,0,skills_num){
            string skill_name;
            cin>>skill_name;
            int level;
            cin>>level;
            temp.pb({skill_name,level});
        }
        proj[i].skills=temp;
    }

    sort(all(proj),comp1);

    queue<project> q;

    rep(i,0,pro){
        q.push(proj[i]);
    }


    int sz = pro;

    ll score = 0;

    int totaldays =0;

    vector<pair<string,vector<string>>> ans;

    do{
        sz = q.size();

        rep(i,0,sz){
            project pro1 = q.front();
            q.pop();

            vector<pair<string,int>> temp = pro1.skills;

            vector<string> DoneBy;

            bool vis[per]{false};

            rep(k,0,temp.size()){
                rep(j,0,per){
                    person per1=conter[j];
                    vector<pair<string,int>> per_skills = per1.skills;
                    bool milgya=false;
                    rep(l,0,per_skills.size()){

                        if(temp[k].first==per_skills[l].first && temp[k].second<=per_skills[l].second && !vis[j]){
                            DoneBy.pb(per1.name);
                            vis[j]=true;
                            milgya=true;
                            break;
                        }
                    }

                    if(milgya){
                        break;
                    }
                }
            }

            if(temp.size()==DoneBy.size()){
                totaldays+=pro1.days;
                if(totaldays>pro1.day_before){
                    score+=(max(0ll,pro1.score-(totaldays-pro1.day_before)));
                }else{
                    score+=(pro1.score);
                }
                ans.pb({pro1.name,DoneBy});
            }else{
                q.push(pro1);
            }
        }

    }while(sz!=q.size());


    cout<<score<<endl;
    cout<<ans.size()<<endl;

    rep(i,0,ans.size()){

        cout<<ans[i].first<<endl;
        rep(j,0,ans[i].second.size()){
            cout<<ans[i].second[j]<<" ";
        }
        cout<<endl;
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t t1=clock();
    int t=1;
    // cin>>t;
    
    while(t--){
        solve();
    }
    cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
    
}











