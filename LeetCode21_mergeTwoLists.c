#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode * now;
    struct ListNode * pointres = (struct ListNode *)malloc(sizeof(struct ListNode));
    now = pointres;

    while(l1 != NULL && l2 != NULL){
        struct ListNode * pointtemp = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(l1->val > l2->val){
            pointtemp->val = l2->val;
            pointtemp->next = NULL;
            now->next = pointtemp;
            l2 = l2->next;
            now = pointtemp;
            printf("testif   %d\n", now->val);
        }
        else{
           // printf("testelse%d  %d\n", l1->val, l2->val);
            pointtemp->val = l1->val;
            pointtemp->next = NULL;
            now->next = pointtemp;
            l1 = l1->next;
            now = pointtemp;
            printf("testelse   %d\n", now->val);
        }
    }

     if(l1 == NULL){
        now->next = l2;
     }

     if(l2 == NULL){
        now->next = l1;
     }

     return pointres->next;
}
int main()
{

    struct ListNode l1no1;
    struct ListNode l1no2;
    struct ListNode l1no3;
    struct ListNode l2no1;
    struct ListNode l2no2;
    struct ListNode l2no3;
    l1no1.val = 1;
    l1no2.val = 2;
    l1no3.val = 4;
    l2no1.val = 1;
    l2no2.val = 3;
    l2no3.val = 4;

    struct ListNode * l1 = &l1no1;
    struct ListNode * l2 = &l2no1;

    l1->next = &l1no2;
    l1->next->next = &l1no3;
    l1->next->next->next = NULL;

    l2->next = &l2no2;
    l2->next->next = &l2no3;
    l2->next->next->next = NULL;

    struct ListNode * res;
    res = mergeTwoLists(l1, l2);

    while(res != NULL){
        printf("result   %d\n", res->val);
        res = res->next;
    }
    return 0;
}