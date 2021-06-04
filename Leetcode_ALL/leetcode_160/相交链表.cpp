#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){} 
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headB || !headA) return NULL;
    ListNode *pA = headA, *pB = headB;
    while (pA != pB)
    {
        if(!pA) pA = headB;
        else pA = pA->next;
        if(!pB) pB = headA;
        else pB = pB->next;
    }
    return pA;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0;
    ListNode *pA = headA, *pB = headB;

    while (pA)
    {
        pA = pA->next;
        lenA ++;
    }     
    while (pB)
    {
        pB = pB->next;
        lenB ++;
    } 

    if(lenA >= lenB)
    {
        int i = 0;
        while (i < lenA - lenB) 
        {
            headA = headA->next;
            i++;
        }
    }
    else
    {
        int i = 0;
        while (i < lenB - lenA)
        {
            headB = headB->next;
            i++;
        }
    }

    while(headB)
    {
        if(headB == headA)
            return headB;
        headB = headB->next;
        headA = headA->next;
    }
    return NULL;
}

int main()
{

}