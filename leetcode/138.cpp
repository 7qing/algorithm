#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> map;
        Node *tmp = head;
        Node *res = new Node(0);
        Node *tmp2 = res;
        while (tmp != nullptr)
        {
            if (map.find(tmp) != map.end())
                tmp2->next = map[tmp];
            else
                tmp2->next = new Node(tmp->val);
            if (tmp->random != nullptr)
            {
                if (map.find(tmp->random) != map.end())
                    tmp2->random = map[tmp->random];
                else
                    map[tmp->random] = new Node(tmp->random->val);
            }
            tmp2 = tmp2->next;
            tmp = tmp->next;
        }
        return res->next;
    }
};