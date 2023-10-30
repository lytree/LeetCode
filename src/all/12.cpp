#include "../header.h"
/**
 * https://leetcode.cn/problems/integer-to-roman/solutions/87905/tan-xin-ha-xi-biao-tu-jie-by-ml-zimingmeng/
 * 1 <= num <= 3999
 * 贪心法则：我们每次尽量使用最大的数来表示。
 * **/
namespace integer_to_roman
{
    class Solution
    {
    public:
        std::string intToRoman(int num)
        {
            int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            std::string map[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            std::string res;
            for (int i = 0; i < 13; i++)
            {
                while (num >= values[i])
                {
                    num -= values[i];
                    res += map[i];
                }
            }
            return res;
        }
    };
}
#define integer_to_roman_fun(func) exc.registerMemberFunction(#func, &integer_to_roman::Solution::func);

int main()
{
    Excecutor<integer_to_roman::Solution, true> exc("../resource/all/12.txt");
    exc.instance = exc.createInstance<void>();
    integer_to_roman_fun(intToRoman);
    exc.run();
}