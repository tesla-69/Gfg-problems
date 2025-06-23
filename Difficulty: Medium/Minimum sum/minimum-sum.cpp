class Solution {
public:
    string addStrings(string a, string b) {
        string res = "";
        int carry = 0, i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res += (sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        
        for( i = 0; i < res.size(); i++) {
            if(res[i] != '0') break;
        }
        return res.substr(i, res.size());
    }

    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        string a = "", b = "";

        for (int i = 0; i < arr.size(); ++i) {
            if (i % 2 == 0)
                a += (arr[i] + '0');
            else
                b += (arr[i] + '0');
        }

        return addStrings(a, b);
    }
};
