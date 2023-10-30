#include "../header.h"
namespace roman_to_integer
{
    class Solution
    {
    public:
        int romanToInt(std::string s)
        {
            std::unordered_map<std::string, int> map = {
                {"I", 1},
                {"IV", 4},
                {"IX", 9},
                {"X", 10},
                {"XL", 40},
                {"L", 50},
                {"XC", 90},
                {"C", 100},
                {"CD", 400},
                {"D", 500},
                {"CM", 900},
                {"M", 1000},
            };

            int ans = 0;
            for (int i = 0; i < s.length();)
            {
                if (i + 1 < s.length() && map.count(s.substr(i, i + 2)))
                {
                    ans += map[s.substr(i, i + 2)];
                    i += 2;
                }
                else
                {
                    ans += map[s.substr(i, i + 1)];
                    i++;
                }
            }
            return ans;
        }
    };
}
#define roman_to_integer_fun(func) exc.registerMemberFunction(#func, &roman_to_integer::Solution::func);

int main()
{
    Excecutor<roman_to_integer::Solution, true> exc("../resource/all/13.txt");
    exc.instance = exc.createInstance<void>();
    roman_to_integer_fun(romanToInt);
    exc.run();
}