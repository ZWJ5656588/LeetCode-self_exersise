# include <iostream>
# include <vector>
# include <algorithm>
# include <functional>
using namespace std;

/*给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。*/

// 法一  动态规划算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for(int i =1; i<nums.size(); i++)
        {
            nums[i] = nums[i] + max(nums[i-1],0);
        }
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[0];
    }
};

// 这种写法利用了快排序 O(nlogn+n)->时间复杂度为O(nlogn) 不是很省


// 法二  // 直接找最大值 时间复杂度O(2n) 
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        for(int i =1; i<nums.size(); i++)
        {
            nums[i] = nums[i] + max(nums[i-1],0);
        }

        int max = nums[0];
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] > max)
            max = nums[j];
        }

        return max;
    }
    
};


// 法三 
// 贪心算法 要用到下界常数 INT32_MIN 不是很完美
class Solution3 {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;   // 最小的数为下界限;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            }
            if (count <= 0) count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
        }
        return result;
    }
};


// 法四 贪心算法优化 不使用下界
class Solution4
{
public:
     int maxSubArray(vector<int>& nums) {
        int count = nums[0];             // 记录当前项之前累加的结果
        int result = nums[0];             // 返回值 存放最大子列和

        for (int i = 1; i < nums.size(); i++)
        {
          if (count < 0)
          {
              count = 0;
          }
          count += nums[i];
          if (count > result)
          {
              result = count;
          }
        }
        return result;   
     }

};
