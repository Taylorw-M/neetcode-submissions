class Solution {
public:
    void insertionSort(std::vector<std::pair<int, int>>& arr) {
        for (std::size_t i = 1; i < arr.size(); ++i) {
            auto current = arr[i];
            std::size_t j = i;

            while (j > 0 && arr[j - 1].first > current.first) {
                arr[j] = arr[j - 1]; // shift larger first values right
                --j;
            }

            arr[j] = current;
        }
    }


    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }

        vector<pair<int,int>> arr;
        for(const auto& p : count){
            arr.push_back({p.second,p.first});
        }

        insertionSort(arr);
       //sort with function

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(arr[arr.size() - 1 - i].second);
        }

        return ans;
    }
};
