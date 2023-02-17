# include <iostream>
# include <string>
# include <algorithm>
using namespace std;


/*给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。*/

//你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？


// 法一 运用STL
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        if (strerase(s) == strerase(t))
        {
            return true;
        }
        else
        {
            return false;
        }
     }
       
    

   string strerase(string &str)
    {
        int pos = str.find("#");
        while (pos != -1)
        {
            if (pos != 0)
            {
                str.erase(pos-1,2);
            }
            else
            {
                str.erase(pos,1);
            }
            pos = str.find("#");
        }
        return str;
    }

    
};

// 法二 运用栈的思想


/*这道题目一看就是要使用栈的节奏，这种匹配（消除）问题也是栈的擅长所

在栈与队列：匹配问题都是栈的强项*/

// 此时空间复杂度是O(n+m)

class Solution2 {
public:
    bool backspaceCompare(string S, string T) {
        // 将strnig当栈来使用
        string s,t;
     
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] != '#')
                s += S[i];
            else if(! s.empty())
                s.pop_back();   // 遇到#，抛出刚刚入栈的S[i] 利用栈的特性
        }

        for (int i = 0; i < T.size(); i++)
        {
            if (T[i] != '#')
            {
                t += T[i];
            }
            else if (! t.empty())
            {
                t.pop_back();
            }
        }
       
       if (s == t)
            return true;
        else
            return false;
    }

};


// 法三

/*当然还可以有使用 O(1) 的空间复杂度来解决该问题。

同时从后向前遍历S和T（i初始为S末尾，j初始为T末尾），记录#的数量，

模拟消除的操作，如果#用完了，就开始比较S[i]和S[j]。*/


class Solution3
{
public:
    bool backspaceCompare(string S, string T)
    {
        int sSkipNum = 0;  // 记录S的#数量
        int tSkipNum = 0;  // 记录S的#数量
        int i = S.size()-1;
        int t = T.size()-1;
        while(true) // 消除后面的#  一个一个字符比较
        {

            // 判断是否要进行回退操作

            // 从后向前 消除S中的#
            while (i>=0)
            {
                if (S[i] == '#')
                    sSkipNum++;
                else
                {
                    if(sSkipNum > 0)
                        sSkipNum--;
                    else
                        break;
                }
                i--;
            }

            // 从后向前 消除T中的#
            while (t>=0)
            {
                if (T[t] == '#')
                    tSkipNum++;
                else
                {
                    if(tSkipNum > 0)
                        tSkipNum--;
                    else
                        break;
                }
                t--;
            }
            
            // # 跳出循环时 证明S[i] T[t]字符后面的#已经消除完毕 
            // 接下来进行字符串比较
            if (i < 0 || t < 0)
                break;  // S或者T 遍历到头了
            if (S[i] != T[t])
                return false; 
            i--; 
            t--;
        }
        // 说明S和T同时遍历完毕
        if (i == -1 && t == -1)
            return true; 
        return false;
    }
};