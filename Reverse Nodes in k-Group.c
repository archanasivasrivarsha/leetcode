#include <stdlib.h>

// Definition of ListNode is assumed to be provided by the platform
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

// Helper to reverse `k` nodes starting from `head`
struct ListNode* reverseK(struct ListNode* head, int k) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    for (int i = 0; i < k; i++) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* curr = head;
    int count = 0;

    // Count k nodes
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }

    if (count < k) return head; // less than k nodes, no reversal

    // Reverse k nodes
    struct ListNode* newHead = reverseK(head, k);

    // head is now the last node of reversed part, recursively reverse next
    head->next = reverseKGroup(curr, k);

    return newHead;
}
