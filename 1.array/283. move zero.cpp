# include <iostream>
# include <vector>
using namespace std;

/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。*/



   
// 法一  
// 由题意 按顺序遍历 非零的元素个数放在相应的索引位置即可 最后一个非零数下一个位置到数组末均为0   O(2n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return;
        }
        int index = 0; // 非零的个数
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[index] = nums[i]; // 第index个非零数放到数组下标index处
                index++;
            }
        }

        for (int i = index; i < nums.size(); i++)
        {
            nums [i] = 0;
        }





        
    }
};