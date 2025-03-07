#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int calculateListSize(ListNode* list) {
        int size = 0;
        while (list != nullptr) {
            size++;
            list = list->next;
        }
        return size;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
        {
            return list2;
        }
        else if(list2 == nullptr)
        {
            return list1;
        }
        int list1size = calculateListSize(list1);
        int list2size = calculateListSize(list2);

        int size = list1size + list2size;

        ListNode* mergedList = new ListNode(0);
        ListNode* prevNode = nullptr;
        ListNode* mergedListStart = mergedList;

        for (int i = 0; i < size; i++) {
            if (list1 == nullptr) {
                prevNode->next = list2;
                break;
            } else if (list2 == nullptr) {
                prevNode->next = list1;
                break;
            }

            mergedList->next = new ListNode(0);

            if (list1->val < list2->val) {
                mergedList->val = list1->val;
                list1 = list1->next;
            } else {
                mergedList->val = list2->val;
                list2 = list2->next;
            }

            prevNode = mergedList;
            mergedList = mergedList->next;
        }

        return mergedListStart;
    }
};

int main()
{
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3));
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2); 

    while (mergedList != nullptr)
    {
        cout << mergedList->val << endl;
        mergedList = mergedList->next;
    }
    return 0;
}