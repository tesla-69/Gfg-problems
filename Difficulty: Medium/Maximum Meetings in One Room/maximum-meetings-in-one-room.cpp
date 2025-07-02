class Solution {
  public:
    struct Meeting {
        int start;
        int end;
        int pos;
    };
    
    static bool comp (Meeting m1, Meeting m2) {
        return m1.end < m2.end;
    }
    
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        vector<Meeting> arr(N);
        
        for (int i = 0; i < N; i++) {
            arr[i].start = S[i];
            arr[i].end = F[i];
            arr[i].pos = i+1;
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        int freetime = arr[0].end;
        
        vector<int> meetings;
        meetings.push_back(arr[0].pos); //Meeting 1 will always occur
        
        for (int i =1; i < N; i++) {
            if (arr[i].start > freetime) {
                freetime = arr[i].end;
                meetings.push_back(arr[i].pos);
            }
        }
        sort(meetings.begin(), meetings.end());
        return meetings;
    }
};