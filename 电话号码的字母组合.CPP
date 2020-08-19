/***回溯法
***/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return res;
        backTrace(digits, 0);
        return res;
    }
private:
    unordered_map<char, string> phoneString {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };
    string s;
    vector<string> res;
    void backTrace(string digits, int index)
    {
        // 结束条件
        if(digits.size() == index) {
            res.push_back(s);
        }
        // for 每个位置当下选择的字母 in 每个位置可选择的字母集合 
        for (int i = 0; i < phoneString[digits[index]].size(); ++i) {
            // 第index个位置选择的字母
            s += phoneString[digits[index]][i];
            // 为下个位置选择字母
            backTrace(digits, index+1);
            // 撤销上次位置的字母选择，因为那个位置要重新选字母
            s.pop_back();
        }
    }
};


/*** 回溯递归相当于多重循环：
两重循环如下：
for(int j=0;j< phoneString[digits[index]].size();j++)
      s += phoneString[digits[index]][i];
      for (int i = 0; i < phoneString[digits[index+1]].size(); ++i) 
          s += phoneString[digits[index]][i];
          res.push_back(s);
          s.pop_back();
      s.pop_back();
可以看到 整个过程，第一个位置选择一个值，第二层循环依次选择一个值，完成第二层的所有可能
为了保证每次选择的长度一致，先push_back后pop_back
