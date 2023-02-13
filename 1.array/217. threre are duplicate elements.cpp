# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
using namespace std;

//给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。

// 法一：利用set容器自动去重 O(n) = 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     return set<int>(nums.begin(),nums.end()).size() != nums.size();
    }
};


// 法二： 先运用sort进行排序 再用一个for循环 O(n) = n
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        for (vector<int>::iterator it = nums.begin(); it != nums.end()-1; ++it)
        {
            if (*it == *++it)
            {
                return true;
            }
            it--;
        }
        return false; 
    }
};
       