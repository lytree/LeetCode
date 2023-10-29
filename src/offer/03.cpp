#include "../header.h"
/**
算法链接
https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/description/
*/

/*
算法复杂度
空间复杂度 O(1)
时间复杂度 O(n)

算法详解





*/
namespace Offer03V1 {
class Solution {
  public:
  int findRepeatNumber(std::vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] == i) {
        i++;
        continue;
      }
      if (nums[nums[i]] == nums[i]) {
        return nums[i];
      }
      std::swap(nums[i], nums[nums[i]]); // 将num[i] 的值切换到 以值为下标的位置
    }
    return -1;
  }
};
} // namespace Offer03V1
/*

算法复杂度
空间复杂度 O(n)
时间复杂度 O(1)
算法详解



*/
namespace Offer03V2 {
class Solution {
  public:
  int findRepeatNumber(std::vector<int> &nums) {
    std::unordered_map<int, bool> map;
    for (int num : nums) {
      if (map[num]) {
        return num;
      }
      map[num] = true;
    }
    return -1;
  }
};
} // namespace Offer03V2