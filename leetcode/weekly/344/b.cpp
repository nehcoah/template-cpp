// https://leetcode.cn/problems/frequency-tracker/

class FrequencyTracker {
    vector<int> f, nums;
public:
    FrequencyTracker() {
        f.resize(100001, 0);
        nums.resize(100001, 0);
    }
    
    void add(int number) {
        f[nums[number]++]--;
        f[nums[number]]++;
    }
    
    void deleteOne(int number) {
        if (nums[number] > 0) {
            f[nums[number]--]--;
            f[nums[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return f[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
