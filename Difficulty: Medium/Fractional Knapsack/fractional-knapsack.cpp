// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<int, int>> items;

        for (int i = 0; i < n; i++) {
            items.push_back({val[i], wt[i]});
        }

        sort(items.begin(), items.end(), [](pair<int, int> a, pair<int, int> b) {
            double r1 = (double)a.first / a.second;
            double r2 = (double)b.first / b.second;
            return r1 > r2;
        });

        double totalValue = 0.0;
        int currWeight = 0;

        for (int i = 0; i < n; i++) {
            if (currWeight + items[i].second <= capacity) {
                currWeight += items[i].second;
                totalValue += items[i].first;
            } else {
                int remain = capacity - currWeight;
                totalValue += ((double)items[i].first / items[i].second) * remain;
                break;
            }
        }

        return totalValue;
    }
};