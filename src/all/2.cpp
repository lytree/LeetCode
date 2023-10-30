#include "../header.h"

namespace add_two_numbers
{

  class Solution
  {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
      ListNode *head = nullptr, *tail = nullptr;
      int carry = 0; // 是否进1
      while (l1 != nullptr || l2 != nullptr)
      {
        int n1 = (l1 != nullptr) ? l1->val : 0;
        int n2 = (l2 != nullptr) ? l2->val : 0;
        int sum = n1 + n2 + carry;
        if (head == nullptr)
        {
          head = tail = new ListNode(sum % 10);
        }
        else
        {
          tail->next = new ListNode(sum % 10);
          tail = tail->next;
        }
        carry = sum / 10;
        if (l1 != nullptr)
        {
          l1 = l1->next;
        }
        if (l2 != nullptr)
        {
          l2 = l2->next;
        }
      }
      if (carry > 0)
      {
        tail->next = new ListNode(carry);
      }
      return head;
    }
  };

} // namespace add_two_numbers
#define add_two_numbers_fun(func) exc.registerMemberFunction(#func, &add_two_numbers::Solution::func);

int main()
{
    Excecutor<add_two_numbers::Solution, false> exc("../resource/all/2.txt");
    exc.instance = exc.createInstance<void>();
    add_two_numbers_fun(addTwoNumbers);
    exc.run();
}