# include <iostream>
# include <vector>
using namespace std;

/*给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-size-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

// 法一 暴力求解 时间复杂度O(n^2) LeetCode不通过

// 两层循环 更新子列和的起始位置
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        for (int i = 0 ; i < nums.size(); i++)
            sum += nums[i];
        if (sum < target)
            return 0;
        else
        {
            sum = 0;
            int length = nums.size();
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j=i; j < nums.size(); j++)
                {
                    sum += nums[j];
                    if (sum >= target)
                    {
                        if (length >= j-i+1)
                        {
                            length = j-i+1;
                        }
                        break;
                    }
                }
                sum = 0;
            }
            return length;
        }
    }
};


// 法二 滑动窗口法
/*窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组。

窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。

窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，也就是for循环里的索引。

解题的关键在于 窗口的起始位置如何移动*/


class Solution2
{
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size();i++)
        {
            sum += nums[i];
        }
        if (sum < target) 
            return 0;
        else
        {
            sum = 0;
            int i = 0;          // 滑动窗格的起始位置
            int subarray = 0 ; // 设置初始的滑动窗口子数组
            int result = nums.size();  // 除去整个数组和小于target情况下的result最大值 
            // 遍历数组 sum >= target确定滑动窗格的末位置j 
            for ( int j = 0; j < nums.size(); j++)
            {
                // 先求和 sum >= target时进入缩减窗格操作
                sum += nums[j];
                // 接下来需要缩小窗格大小，并且向前移动起始位置
                // 这个while不做遍历 每次for循环只对一个j操作 避免O(n^2)
                while(sum >= target)
                {
                    // 记录滑动窗格的大小 也是此时符合条件子列的长度
                    // 下面只要找到最小的子列长度即可
                    subarray = (j-i+1); 
                    // 一步一步找到result的最小值
                    result = result > subarray ? subarray : result; 
                    // 移动窗格起始位位置i 并且缩减窗格长度 再进入while判断
                    sum -= nums[i++];
 
                }
            }
        return result;
        }
    }
};


/*不要以为for里放一个while就以为是O(n^2)啊， 主要是看每一个元素被操作的次数，
每个元素在滑动窗后进来操作一次，出去操作一次，每个元素都是被操作两次，所以时间复杂度是 2 × n 也就是O(n)。*/