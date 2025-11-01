#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>
#include <unordered_map>
#include <array>
#include <cmath>
#include <string_view>

using namespace std;

std::vector<std::string> capMe(const vector<std::string>& strings) {
    vector<string> res;
    string word;
    for (const string& word : strings) {
        string word1 = word;
        if (word1.empty()) {
            res.push_back("");  // 处理空字符
            continue;
        }

        // 首字母大写
        word1[0] = toupper(word1[0]);

        // 其余字母小写
        for (int i = 1; i < word1.length(); ++i) {
            word1[i] = tolower(word1[i]);
        }

        res.push_back(word1);
    }
    return res;
}

string sliceString(string str) {
    string res = "";
    for (int i = 1; i < str.length() - 1; i++) res += str[i];
    return res;
}

long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return factorial(n - 1) * n;
}

std::vector<int> bubbleSortOnce(const vector<int>& input) {
    // 气泡排序  法宝swap获得！！
    std::vector<int> res = input;

    for (size_t i = 0; i < res.size() - 1; i++) {
        if (res[i] > res[i + 1]) {
            swap(res[i],res[i + 1]);  // swap函数交换两个元素，基本什么类型都能用，包括容器
        }
    }
    return res;
}

vector <string> top3(
    const vector<string>& products,
    const vector<int>& amounts,
    const vector<int> & prices){
    
    int n = products.size();
    // 计算销售额最大的三个产品的名称
    vector<tuple<int, int, string>> revenues;

    //计算每个商品的收入，并写入元组向量
    for (int i = 0; i < products.size(); ++i){
        int revenue = amounts[i] * prices[i];
        revenues.emplace_back(revenue, i, products[i]);
    }

    // 用sort函数原地排序 三个参数，第三个参数是定义比较函数的
    sort(revenues.begin(), revenues.end(), [](const auto& a, const auto& b){
        if (get<0>(a) != get<0>(b)){  // get用来获取元组的元素
            return get<0>(a) > get<0>(b);
        }
        return get<1>(a) < get<1>(b);
    });

    //取前三个产品名称
    vector<string> res;
    int count = min(3, n);  // min返回较小的那个，对应商品数少于3个的情况
    for (int i = 0; i < count; ++i){
        res.push_back(get<2>(revenues[i]));  // push_back是vector库的成员函数
    }

    return res;
}

string histogram(vector<int> results){
    // 骰子直方图
    // to_string(数值) 将数值转换为字符串
    // string(count, 字符) 创建一个由指定字符重复指定次数组成的字符串 字符还得是单引号括起来的
    string his;

    for (int i = 6; i > 0; i--){
        his += to_string(i) + "|";
        int count = results[i-1];
        if (count > 0){
            his += string(count, '#') + " " + to_string(count);
        }
        his += "\n";
    }
    return his;
}

int score(const array<unsigned, 5>& dice) {
    // 字典 unordered_map
    // 并且键、值非常灵活，可以是任意类型
    unordered_map <unsigned, int> frequency;
    for (const auto & element : dice){
        frequency[element]++; 
    }  // 以上是一个经典的统计频率的写法

    int res = 0;
    if (frequency[1] >= 3){
        res += 1000;
        frequency[1] -= 3;
    }
    else if (frequency[6] >= 3){
        res += 600;
        frequency[6] -= 3;
    }
    else if (frequency[5] >= 3){
        res += 500;
        frequency[5] -= 3;
    }
    else if (frequency[4] >= 3){
        res += 400;
        frequency[4] -= 3;
    }
    else if (frequency[3] >= 3){
        res += 300;
        frequency[3] -= 3;
    }
    else if (frequency[2] >= 3){
        res += 200;
        frequency[2] -= 3;
    }

    res += frequency[1] * 100 + frequency[5] * 50;
    return res;
}

string duplicate_encoder(const string & word){  // const表示word是不可变的，&表示引用，避免拷贝；组合效果：一个只读的引用
    unordered_map <char, int> freq;

    //使用const auto & 遍历字符串，避免拷贝
    for (const auto & c : word){
        freq[tolower(c)]++;
    }
    string res = "";
    for (const auto& c : word){  //const修饰的是c，表示c不可变；&表示引用，避免拷贝
        if (freq[tolower(c)] > 1)
            res += ")";
        else 
            res += "(";
    }
    return res;
}

vector<unsigned int> sumDigPow(unsigned int a, unsigned int b){
    // 找到满足如下性质的数 89 = 8^1 + 9^2
    vector<unsigned int> res;
    
    for (unsigned int i = a; i <= b; i++){
        unsigned int num = i;
        unsigned int sum = 0;
        vector<unsigned int> digits;

        // 用字符的形式取出各个数字 ！！ 这样是正序的
        string num_str = to_string(num);
        for (int j = 0; j < static_cast<int>(num_str.size()); j++){  // 类型转换，没有必要
            unsigned int digit = num_str[j] - '0';
            sum += pow(digit, j + 1);
            digits.push_back(digit);
        }

        if (sum == i)
            res.push_back(sum);
    }
    return res;
}

int countSmileys(vector<string> arr){
    // int count = 0;
    // for (const auto & str: arr){
    //     int len = str.size();
    //     if (str[0] == ':' || str[0] == ';'){
    //         if (len == 3 && (str[1] == '-' || str[1] == '~') && 
    //             (str[2] == ')' || str[2] == 'D')){
    //             count++;
    //         }
    //         else if(len == 2 && (str[1] == ')' || str[1] == 'D')) {
    //             count++;
    //         }
    //     }
    // }
    // return count;

    /*
    新道具：lambda函数 lambda表达式生成一个匿名的“函数对象” auto isEye = 给这个匿名对象取了一个变量名，isEye是变量名
    不是函数名
        [capture](参数列表) -> 返回类型 { 函数体 }
        [capture] 捕获外部变量（可以为空）
        (参数列表) 函数的输入参数
        ->返回类型： 可省略（编译器自动推断）
        {函数体}： 实际执行的代码
    isEye(c) 等价于 ([](char c){ return c == 'y' || c == 'Y'; })(c);
    */
    auto isEye = [](char c){return c == ':' || c == ';';};
    auto isNose = [](char c){return c == '-' || c == '~';};
    auto isMouth = [](char c){return c == ')' || c == 'D';};

    int count = 0;
    for (const auto & str: arr){
        if (str.size() == 2 && isEye(str[0]) && isMouth(str[1]))
            count++;
        else if (str.size() == 3 && isEye(str[0]) && isNose(str[1]) && isMouth(str[2]) )
            count++;
    }
    return count;
}

vector<int> min_value(const vector<int> & arr, size_t n){
    vector<int> res;
    for (size_t i = 0; i < arr.size() - n + 1; i++){
        auto start = arr.begin() + i;
        auto end = arr.begin() + i + n;

        //法宝： 用min_element查找当前区间最小值
        int min_val = *min_element(start, end);  // 返回一个“迭代器” 需要*取出实际的值
        res.push_back(min_val);
    }
    return res;
}

string to_weird_case(string_view str){
    // string_view是一种只读字符串，不能修改，也没有数据，只是引用；
    // 
    string res_str;
    res_str.reserve(str.size());  // 提前分配空间，避免多次扩容

    int i_in_word = 0;
    for (unsigned char c : str){
        if (c == ' '){
            i_in_word = 0;
            res_str.push_back(' ');
        }
        else {
            char new_c = (i_in_word % 2 == 0)  // 学会使用简化判断
            ? static_cast<char>(toupper(c))  
            : static_cast<char>(tolower(c));
            res_str.push_back(new_c);
            i_in_word++;
        }
    }

    return res_str;
}

static long findMissing(std::vector<long> list){
    /* 题目：找到等差数列中，缺失的那一项
    front() back()是C++STL容器中，用于快速访问第一个元素和最后一个元素 的引用，可修改
    */
    long n = static_cast<long>(list.size());
    long d = (list.back() - list.front()) / n;
    std::cout << list.back() << std::endl
        << list.front()<<std::endl << n << std::endl;
    std::cout << "公差为：" << d << std::endl;
    for (int i = 0; i < static_cast<int>(list.size()) - 1; i++){
        if (list[i+1] - list[i] != d)
            return list[i] + d;
    }
    return list.front();
}

typedef unsigned long long ull;
class SumFct{  // class定义一个类 
    public:  // public表示后面的成员可以被外部访问
    static ull perimeter(int n);  // static表示这个函数不依赖对象（不需要new出类实例）
    /*
    当一个函数是static时，它属于“类本身”，而不是某个对象
        class Example {
    public:
        static void sayHello() {
            std::cout << "Hello\n";
        }
    };
    // 你可以直接这样调用：
    Example::sayHello();  // ✅ 不需要创建对象

    //而非静态函数必须通过对象调用：
    Example e;
    e.sayHello();
    */
};

ull SumFct::perimeter(int n){
    std::vector<ull> fib = {1, 1};
    for (int i = 2; i < n; i++){
        fib.push_back(fib[i-1] + fib[i-2]);
    }

    ull sum = 0;
    for (ull x: fib){
        sum += x;
    }

    return 4 * sum;
}

string range_extraction(vector<int> args){
    string res = "";
    int n = args.size();
    int i = 0;

    for ( ; i < n; ){
        int start = args[i];
        int j = i;

        while(j + 1 < n && args[j+1] - args[j] == 1)  // 重点，先找出截止的位置
            j++;
        
        if (j - i >= 2){
            res += to_string(start) + "-" + to_string(args[j]);
        }
        else if (j - i == 1){
            res += to_string(start) + "," + to_string(args[j]);
        }
        else{
            res += to_string(start);
        }
        i = j + 1;
        if (i < n) res += ",";
    }
    return res;
}

#include <regex>
string pig_it(const string & str){
    /*正则表达式*/
    regex word_re( R"(\b([A-Za-z])([A-Za-z]*)\b)" );
    return regex_replace(str, word_re, "$2$1ay");
}

#include <unordered_set>
using namespace std;
void backtrack(string & s, int start, vector<string> & res);

void backtrack(string & s, int start, vector<string> & res){
    /* 
    首先得理解这个函数的功能，就是通过循环，把每个字符都放在start的位置上，然后递归，将start变成start+1，
    由大问题变成相同规模的小问题，也就是对于s的第start+1个位置，将每个可能的字符放在该位置上；
    递归回溯问题！！！
    */
    if (start == s.size() - 1){
        res.push_back(s);
        return;
    }
    // 无序集合记录每次放在start位置的字符，每次递归，都会创建新的used？
    unordered_set<char> used;

    for (int i = start; i < s.size(); i++){
        // 在循环的过程中，如果start的位置放过该字符，则跳过
        if (used.count(s[i])) continue;
        used.insert(s[i]);

        swap(s[start], s[i]);
        backtrack(s, start + 1, res);
        swap(s[start], s[i]);  // 里层的排列全部完成后，将字符串恢复原状，接着递增i，将下一个字符放在start的位置上
    }
}

vector<string> permutations(string s){
    vector<string> res;
    backtrack(s, 0, res);
    return res;

}

/* 将英文单词转换成数字 */
#include <sstream>
const unordered_map<string, long> str_to_num = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
    {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
    {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
    {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70},
    {"eighty", 80}, {"ninety", 90}, {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}
};

vector<long> split_and_trans(const string & num);

long parse_int(string number){
    vector<long> numsL = split_and_trans(number);
    long a = 0, b = 0; // a表示千位以上的数字，b表示千位以下的数字; 因为最大只有million，所以这样拆分
    for (auto & x: numsL){
        if (x == 100)
            b *= 100;
        else if (x == 1000){
            // 如果达到千位，则将其独立
            a = b * 1000;
            b = 0;
        }
        else if (x == 1000000){
            return x;
        }
        else 
            b += x;
    }
    return a + b;
}

vector<long> split_and_trans(string & num){
    vector<long> nums;
    /* 因为该方法复杂度为O(n^2)，现在重新写一下*/
    /* 
    // 循环拆分单词并转换为long  find_first_of(chars, start) 找到字符窜中第一个属于给定字符集的字符的位置
    size_t start = 0, pend;
    while((pend = num.find_first_of(" -", start)) != string::npos){  // string::npos表示没有找到结果
        if(pend > start){
            string word = num.substr(start, pend - start);
            if (word == "and") continue;
            cout << word << endl;
            nums.push_back(str_to_num.at(word));
        }
        start = pend + 1;
    }
    
    if (start < num.size()){
        nums.push_back(str_to_num.at(num.substr(start)));  // 处理最后一个单词
    }
    */

    
    replace(num.begin(), num.end(), '-', ' '); // 将连字符替换成空格
    istringstream iss(num);
    string word;

    while(iss >> word){
        if (word == "and") continue;
        auto it = str_to_num.find(word); // find(key)的作用是，查找健key，如果找到了，返回一个迭代器，指向这个元素，
        // 如果找不到，返回str_to_num.end() 表示没找到
        if (it != str_to_num.end()){  // it可以看作map内部元素的指针，it->first 键，it->second 值
            // 可以用 *it 得到元素（实际上是 pair<const string,long>）
            //end() 返回 一个迭代器，指向容器末尾的“虚拟位置” 这个位置不指向任何有效元素，只是标记结束
            nums.push_back(it->second);
        }
    }

    return nums;
}


std::string add(const std::string& a, const std::string& b) {
    /* 整数字符串相加 */
    int i = a.size() - 1;
    int j = b.size() - 1;
    string res = "";
    int carry = 0;  // 进位

    while(i >=0 || j >=0 || carry){
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';  // 注意字符串与整数值之间的转换，字符会升级到int
        if (j >= 0) sum += b[j--] - '0';
        res.push_back(sum % 10 + '0');
        carry = sum / 10;  // 更新进位
    }
    reverse(res.begin(), res.end());

    return res;
}

vector< vector<long long> > cofactors(vector<vector<long long>> m, int a, int b){
    // 输入矩阵，和索引i,j得到其代数余子式
    int rows = m.size();
    vector<vector<long long>> res;
    for(int i = 0; i < rows; ++i){
        if(i == a) continue;
        vector<long long> row_temp;

        for (int j = 0; j < rows; ++j){
            if(j == b) continue;
            row_temp.push_back(m[i][j]);
        }

        res.push_back(row_temp);
    }
    return res;
}

long long determinant(vector< vector<long long> > m){
    // 计算行列式的结果 用递归
    int n = m.size();
    if (n == 1) return m[0][0];
    else if (n == 2)
        return m[0][0]*m[1][1] - m[0][1]*m[1][0];
    else{
        long long sum = 0;
        for(int i = 0; i < n; ++i){
            int sign = ((0 + i) % 2 == 0) ? 1:-1;
            sum += sign * m[0][i] * determinant(cofactors(m, 0, i));
        }
        return sum;
    }
}

