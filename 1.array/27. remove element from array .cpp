# include <iostream>
# include <vector>
using namespace std;


// 1.两个for循环暴力求解   O(n^2)
class Solution { 
public:
    int removeElement(vector<int>& nums, int val) {
    // 1. 暴力求解法
    int size = nums.size();  // 先记录初始的数组长度
    for(int i = 0; i < size; i++)
    {
        if (nums[i] == val)
        {
            for (int j = i+1; j < size; j++)
            {
                nums[j-1] = nums[j];

            }
            size--;  // 此时数组的大小和i在数组当中的位置随着元素删除而减小1
            i--;
        }
        

    }
    return size;
    }
};


/*双指针法
双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。  时间复杂度 O(n)

定义快慢指针

快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
慢指针：指向更新 新数组下标的位置
很多同学这道题目做的很懵，就是不理解 快慢指针究竟都是什么含义，所以一定要明确含义，后面的思路就更容易理解了。

删除过程如下：*/

class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int slowpoint = 0;
        int fastpoint = 0;
        while (fastpoint < size ) {
            if(nums[fastpoint] != val)
            {
                nums[slowpoint++] = nums[fastpoint];
            }
            fastpoint++;
        
        }
        return slowpoint;
    }
};


/**
* 相向双指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
* 时间复杂度：O(n)
* 空间复杂度：O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) {
            // 找左边等于val的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val){
                ++leftIndex;
            }
            // 找右边不等于val的元素
            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
                -- rightIndex;
            }
            // 将右边不等于val的元素覆盖左边等于val的元素
            if (leftIndex < rightIndex) {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
    }
};

    
    
    

