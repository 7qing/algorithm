#include "iostream"
#include <set>
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
    bool hasCycle(ListNode *head)
    {
        set<ListNode *> st;
        ListNode *tmp = head;
        while (tmp != nullptr)
        {
            if (st.find(tmp) != st.end())
            {
                return false;
            }
            st.insert(tmp);
            tmp = tmp->next;
        }
        return true;
    }
};