#include "../header.h"
namespace longest_substring_without_repeating_characters
{
	class Solution
	{
	public:
		int lengthOfLongestSubstring(std::string s)
		{
			std::unordered_set<char> occ;
			int s_length = s.size();
			int res = 0;
			int right_index = -1;
			for (int left_index = 0; left_index < s_length; left_index++)
			{
				if (left_index != 0)
				{
					occ.erase(s[left_index - 1]);
				}
				while (right_index + 1 < s_length && !occ.count(s[right_index + 1]))
				{

					occ.insert(s[right_index + 1]);
					right_index++;
				}
				res = std::max(res, right_index - left_index + 1);
			};

			return res;
		};
		int lengthOfLongestSubstringV2(std::string s)
		{

			std::unordered_map<char, int> dic;
			int i = -1, res = 0, len = s.size();
			for (int j = 0; j < len; j++)
			{
				if (dic.find(s[j]) != dic.end())
					i = std::max(i, dic.find(s[j])->second); // 更新左指针
				dic[s[j]] = j;							// 哈希表记录
				res = std::max(res, j - i);				// 更新结果
			}
			return res;
		};
	};
} // namespace validate_stack_sequences
#define longest_substring_without_repeating_characters_fun(func) exc.registerMemberFunction(#func, &longest_substring_without_repeating_characters::Solution::func);

int main()
{
	Excecutor<longest_substring_without_repeating_characters::Solution, true> exc("D:\\Code\\VS\\LeetCode\\resource\\all\\3.txt");
	exc.instance = exc.createInstance<void>();
	longest_substring_without_repeating_characters_fun(lengthOfLongestSubstringV2);
	exc.run();
}