class Solution{
  public:
    string s0="01",s1="10";
    char nthCharacter(string s, int r, int n) {
        if(r==0) return s[n];
        int t=nthCharacter(s,r-1,n/2)-'0';
        return (t)?s1[n&1]:s0[n&1];
    }
};