class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<>());
        
        int ans = 0;
        for (int i = 0; i < processorTime.size(); i++) {
            int mx = 0;
            for (int j = i * 4; j < 4 * i + 4; j++) mx = max(mx, tasks[j]);
            ans = max(ans, processorTime[i] + mx);
        }
        return ans;
    }
};
