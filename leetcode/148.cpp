#include "iostream"
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void adjust(vector<ListNode *> &arr, int len, int index)
{

    int left = 2 * index + 1;  // index的左子节点
    int right = 2 * index + 2; // index的右子节点

    int maxIdx = index;
    if (left < len && arr[left]->val > arr[maxIdx]->val)
        maxIdx = left;
    if (right < len && arr[right]->val > arr[maxIdx]->val)
        maxIdx = right;

    if (maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *combine(ListNode *list1, ListNode *list2)
{
    // 创建一个哑节点，方便操作
    ListNode *head = new ListNode(0);
    ListNode *temp = head;

    // 合并两个有序链表
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // 剩余部分链表直接连接
    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }

    // 返回排序后的链表
    return head->next;
}

ListNode *sortList(ListNode *head)
{
    // 终止条件：如果链表为空或只有一个节点，直接返回
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // 使用快慢指针找到链表的中间点
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 将链表分为两部分
    ListNode *mid = slow->next;
    slow->next = nullptr;

    // 递归地对左右两部分排序，并合并
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);

    // 合并两个排序好的链表
    return combine(left, right);
}
ListNode *sortList(ListNode *head)
{
    vector<ListNode *> st;
    ListNode *tmp = head;
    while (tmp != nullptr)
        st.push_back(tmp);
    int n = st.size();
    for (int i = n / 2 - 1; i > 0; i--)
        adjust(st, n, i);
    ListNode *curr = st[0];
    ListNode *prev = nullptr;
    st[0] = nullptr;
    for (int i = n - 1; i >= 1; i--)
    {

        swap(st[0], st[i]);
        curr = st[i];
        curr->next = prev;
        prev = curr;
        adjust(st, i, 0);
    }
    return prev;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *combine(ListNode *list1, ListNode *list2)
{
    // 创建一个哑节点，方便操作
    ListNode *head = new ListNode(0);
    ListNode *temp = head;

    // 合并两个有序链表
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // 剩余部分链表直接连接
    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }

    // 返回排序后的链表
    return head->next;
}

ListNode *sortList(ListNode *head)
{
    // 终止条件：如果链表为空或只有一个节点，直接返回
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // 使用快慢指针找到链表的中间点
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 将链表分为两部分
    ListNode *mid = slow->next;
    slow->next = nullptr;

    // 递归地对左右两部分排序，并合并
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);

    // 合并两个排序好的链表
    return combine(left, right);
}