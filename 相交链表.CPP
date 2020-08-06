/***
如果有NULL返回NULL
如果相交ListA=a+b
ListB=c+b
PA走a+b+c和PB走c+b+a的长度相同
如果不相交最终相遇于NULL
***/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //走过相同的路
        if(headA==NULL||headB==NULL) return NULL;
        ListNode* pA=headA;
        ListNode* pB=headB;
        while(pA!=pB)
        {
            if(pA==NULL)
            {
                pA=headB;
            }
            else
            {
                pA=pA->next;
            }
            if(pB==NULL)
            {
                pB=headA;
            }
            else
            {
                pB=pB->next;
            }
        }
        return pA;
        
    }
};
