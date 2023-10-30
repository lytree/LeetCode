#include "../header.h"
namespace two_sum
{

  class Solution
  {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
      std::unordered_map<int, int> hashtable;
      for (int i = 0; i < nums.size(); ++i)
      {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end())
        {
          return {it->second, i};
        }
        hashtable[nums[i]] = i;
      }
      return {};
    }
  };
#define two_sum_fun(func) exc.registerMemberFunction(#func, &two_sum::Solution::func);
} // namespace two_sum
int main()
{
  Excecutor<two_sum::Solution, false> exc("../resource/all/1.txt");
  exc.instance = exc.createInstance<void>();
  two_sum_fun(twoSum);
  exc.run();
}