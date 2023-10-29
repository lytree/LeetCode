#include "../header.h"

namespace Offer05V1 {
class Solution {
  public:
  std::string replaceSpace(std::string s) {
    int count = 0;
    int len = s.size();
    for (char c : s) {
      if (c == ' ') {
        count++;
      }
    }
    s.resize(len + 2 * count);
    for (int i = len - 1, j = s.size() - 1; i < j; j--, i--) {
      if (s[i] != ' ') {
        s[j] = s[i];
      } else {
        s[j] = '0';
        s[j - 1] = '2';
        s[j - 2] = '%';
        j -= 2;
      }
    }
    return s;
  }
};
} // namespace Offer05V1