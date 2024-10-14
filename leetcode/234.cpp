#include "iostream"
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
        {
            return true; // 空链表或单节点链表都是回文
        }

        // 使用快慢指针找到链表中点
        ListNode *slow = head;
        ListNode *fast = head;
        stack<int> st;

        // 将前半部分节点的值存入栈中
        while (fast != nullptr && fast->next != nullptr)
        {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // 如果链表长度是奇数，跳过中间节点
        if (fast != nullptr)
        {
            slow = slow->next;
        }

        // 比较栈中的值与后半部分链表的值
        while (slow != nullptr)
        {
            if (st.top() != slow->val)
            {
                return false;
            }
            st.pop();
            slow = slow->next;
        }

        return true;
    }
};