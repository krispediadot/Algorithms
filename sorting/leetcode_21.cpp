// 14.8MB, 15ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// 15.9MB, 21ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        
        if (list1 == nullptr) return new ListNode(list2->val, mergeTwoLists(list1, list2->next));
        if (list2 == nullptr) return new ListNode(list1->val, mergeTwoLists(list1->next, list2));
        
        ListNode* target = (list1->val < list2->val) ? list1 : list2;
        ListNode* next1 = (target == list1) ? list1->next : list1;
        ListNode* next2 = (target == list2) ? list2->next : list2;
        
        return new ListNode(target->val, mergeTwoLists(next1, next2));
    }
};
