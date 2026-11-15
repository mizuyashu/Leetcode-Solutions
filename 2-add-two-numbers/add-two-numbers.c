/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // placeholder box
    struct ListNode one;
    struct ListNode *tail = &one;
    one.next = NULL;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;

        if (l1 != NULL) {

            // add values 
            sum += l1 -> val;

            // reassign l1 to the next node
            l1 = l1-> next;
        }

        if (l2!= NULL){

            // add values
            sum += l2 -> val;

            // reassign l2 to the next node
            l2 = l2-> next;
        }

        // carry is for the next digit
        carry = sum / 10;
        
        // allocating memory for the struct that node points to so that it doesn't get destroyed with the while loop and pointer has nonsense data
        struct ListNode *node = malloc(sizeof(struct ListNode));

        // assigning values to the node
        node -> val = sum % 10;
        node -> next = NULL;

        // setting the tail as the intial node with null pointer and nonsense value
        tail -> next = node;
        tail = node;   

    } 
    return one.next;
    
}