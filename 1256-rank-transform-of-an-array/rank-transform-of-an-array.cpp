class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int num : sortedArr) {
            if (!rank.count(num))
                rank[num] = r++;
        }

        for (int &num : arr)
            num = rank[num];

        return arr;
    }
};