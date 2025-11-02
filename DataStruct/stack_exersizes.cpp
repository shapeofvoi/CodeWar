#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using std::vector;
using std::unordered_map;
using std::stack;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 496. 下一个更大元素
        int n2 = nums2.size();
        unordered_map<int, int> nextGreater;  // 存储下一个最大元素的映射
        stack<int> stk;  // 单调栈存储候选值

        for (int i = n2 - 1; i >= 0; --i){
            while (!stk.empty() && nums2[i] > stk.top()){
                // 将小于当前元素中的栈中元素全部弹出，因为最新最大的已经来了，后面轮不到他们上场了
                stk.pop();
            }

            // 对于每个元素，判断他是否有下一个更大元素，只需要判断栈顶中是否有元素就行了，因为比他小的已经被弹出了
            nextGreater[nums2[i]] = stk.empty() ? -1 : stk.top();

            // 对于每个元素，都需要压入栈
            stk.push(nums2[i]);
        }

        // 在映射中查找答案
        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i){
            ans.push_back(nextGreater[nums1[i]]);
        }
        return ans;
    }
};