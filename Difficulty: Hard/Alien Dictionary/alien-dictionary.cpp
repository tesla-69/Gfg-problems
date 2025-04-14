//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        if(words.size() == 1) {
            string ans;
            int vis[26] = {0};
            string s = words[0];
            for(int i=0;i<words[0].length();i++){
                if(!vis[s[i]-'a']) ans+=s[i];
                vis[s[i]-'a'] = 1;
            }
            return ans;
        }
        vector<int> adj[26];
        int n = words.size();
        string ans;
        int f = 1;
        vector<int> indegree(26,-1);
        for(int i =0;i <n-1;i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            
            int len = min(s1.length(), s2.length());
            
            for(int i = 0;i<s1.length();i++) 
                if(indegree[s1[i] - 'a'] == -1) indegree[s1[i]-'a'] = 0;
            for(int i =0;i<s2.length();i++) 
                if(indegree[s2[i] - 'a'] == -1) indegree[s2[i]-'a'] = 0;
            
            int update = 0;
            
            for(int j=0;j<len;j++){
                if(s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    indegree[s2[j]-'a']++;
                    update = 1;
                    break;
                }
            }
            if(update == 0 && s2.length() == len && s1.length() != s2.length()) {
                ans = "";
                f = 0;
            }
        }
        if(!f){
            return ans;
        }
        vector<int> topo;
        queue<int> q;
        for(int i = 0; i<26; i++) if(indegree[i] == 0) q.push(i);
        // for(int i =0;i<26;i++) cout<<indegree[i]<<" ";
        // cout<<endl;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        int cnt = 0;
        for(int i =0; i< 26;i++){
            if(indegree[i]!=-1) cnt++;
        }
        // for(int i =0;i<26;i++) cout<<indegree[i]<<" ";
        // cout<<endl;
        // cout<<"hey"<<endl;
        if(topo.size() < cnt) return "" ;
        for(auto ch : topo){
            ans += ch + 'a';
        }
        // cout<<ans<<endl;
        return ans;
    }
};



//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends