#define ll long long
class Solution {
  public:
    int countNumbers(int n) {
        vector<ll> a(100005, 0);
        for(ll i=0; i<100005; i++) 
            a[i] = i;
        
        for(ll i=2; i<100005; i++) {
            if(a[i] == i) {
                for(ll j=2*i; j<100005; j+=i) {
                    if(a[j] == j) {
                        a[j] = i;
                    }
                }
            }
        }

        vector<ll> p;
        for(ll i=2; i<100005; i++)
            if(a[i] == i) p.push_back(a[i]);
            
        ll ans = 0;
        for(int i=0; i<p.size(); i++) {
            for(int j=0; j<p.size(); j++) {
                if(i == j) continue;
                if((p[i]*p[i]*p[j]*p[j]) <= (1LL*n)) {
                    ans++;
                } else {
                    break;
                }
            }
        }
        
        ans /= 2;
        
        vector<int> zz{256, 6561, 390625, 5764801, 214358881, 429981696};
        for(int i=0; i<6; i++) {
            if(zz[i] <= n) {
                ans++;
            }
            else break;
        }
            
        return ans;
        
    }
};