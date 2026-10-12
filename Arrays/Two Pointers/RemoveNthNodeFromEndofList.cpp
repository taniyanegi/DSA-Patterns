/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // two pointer approach - Fast and Slow Pointer Approach

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
              ListNode* fast=head;
              for(int i=0;i<n;i++){
                fast=fast->next;
              }
              if(fast==NULL)
              return head->next;

              ListNode* slow=head;
               while(fast->next!=NULL){
                slow=slow->next;
                fast=fast->next;
               }

               ListNode* delnode=slow->next;
               slow->next=slow->next->next;

               delete delnode;

               return head;
    }
};


// two pointer approach - Brute Force with two passes


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
       if (head == NULL || n <= 0) 
        return NULL;

    struct ListNode* temp = head;
    int len = 0;
 
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
 
    if (len == 0) {
        return NULL;
    } else if (len == 1) {
        free(head);
        return NULL;
    }
 
    int indexToRemove = len - n;
 
    if (indexToRemove == 0) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }

    
    temp = head;
    for (int i = 0; i < indexToRemove - 1; i++) {
        temp = temp->next;
    }

    
    struct ListNode* ptr = temp->next;
    temp->next = ptr->next;
    free(ptr);

    return head;
     
}
