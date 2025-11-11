#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <sstream>

using std::vector;
using std::unordered_map;
using std::stack;
using std::string;
using std::stringstream;

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

    int calPoints(vector<string> & operations){
        // 后进先出 用栈记录得分
        vector<int> scores;
        int sum = 0;

        // 遍历操作，写入得分
        for (string & o : operations){
            int score = 0;
            if (o == "D"){
                score = scores.back() * 2;
                scores.push_back(score);
                sum += score;
            }
            else if (o == "C"){
                sum -= scores.back();
                scores.pop_back(); //弹出最后一个元素
            }
            else if (o == "+"){
                score = scores.back() + scores[scores.size() - 2];
                scores.push_back(score);
                sum += score;
            }
            else{
                score = std::stoi(o);
                scores.push_back(score);
                sum += score;
            }
        }

        return sum;
    }

    string makeGood(string s) {
        string res;
        int n = s.size();

        if (n <= 1)
            return s;
        else {
            int i = 0;
            while (i < n - 1){
                if ((isupper(s[i]) && tolower(s[i]) == s[i+1]) || (islower(s[i]) && toupper(s[i]) == s[i+1])){
                    s.erase(i, 2); // 从索引i开始，删除2个字符
                    return makeGood(s);
                }
                ++i;
            }
            return s;
        }
    }

    string makeGood(string s){
        // 用字符串模拟栈 后进先出
        string res;
        
        for (char c : s){
            if (!res.empty() && abs(res.back() - c) == 32){
                res.pop_back();
            }
            else {
                res.push_back(c);
            }
        }
        return res;
    }

    string clearDigits(string s) {
        string res;

        for(auto c : s) {
            if (isdigit(c)){
                res.pop_back();
            }
            else {
                res.push_back(c);
            }
        }

        return res;
    }

    string simplifyPath (string path) {
        vector<string> stk;
        string dir;
        stringstream ss(path);

        while (getline(ss, dir, '/')){ // stringsteam内部有指针，每次读取，指针会向后移动
            if (dir == "" || dir == ".") continue;
            if (dir == "..") {
                if (!stk.empty()) stk.pop_back();
            }
            else {
                stk.push_back(dir);
            }
        }

        // 拼接
        string res = "/";
        for (size_t i = 0; i < stk.size(); ++i) {
            res += stk[i];
            if (i != stk.size() - 1) res += "/";
        }

        return res;
    }
};