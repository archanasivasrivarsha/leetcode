#include <stdlib.h>

// Definition is assumed to be provided by the platform:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* first = dummy;
    struct ListNode* second = dummy;

    // Move first n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    // Move first to the end, second will point to node before target
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // Remove the nth node
    struct ListNode* toDelete = second->next;
    second->next = second->next->next;
    free(toDelete);

    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}
