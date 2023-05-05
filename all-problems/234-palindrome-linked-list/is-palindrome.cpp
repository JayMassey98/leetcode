// ---------------
// Code Assumption
// ---------------

// Since this code is written in C++, the assumption is that a greater amount of
// abstraction is possible compared to when only C is used. Therefore, this code
// has been written to be clean, concise, and highly readable overall, utilising
// reusable functions, whilst still producing efficient code after compilation.


// ---------------
// Code Complexity
// ---------------

// The time complexity of this function is O(n), where n is the length of the
// supplied node list. It loops through half of them to find the middle, then
// compares the two halves, performing constant-time operations for each node.

// The space complexity of this function is O(1), as it uses a constant amount
// of space regardless of the size of the supplied node list. All the variables
// required to store the pointer positions have a constant size, therefore the
// space used by this function does not depend on the size of the node list.


// ----------------
// Code Description
// ----------------

// A palindrome is a sequence that reads the same forward and backward. Given a
// head of a singly linked list, return true if it is one, or false if it's not.


// Required headers.
#include <cstddef>

// Allow specified code to be optimised in compilation.
#define optimize __attribute__((optimize("O3"))) const

// A singly-linked list.
struct list_node
{
    int value;
    list_node* next;

    list_node() : value(0), next(nullptr) {}
    list_node(int x) : value(x), next(nullptr) {}
    list_node(int x, list_node* next) : value(x), next(next) {}
};

optimize bool is_palindrome(struct list_node* head)
{
    // Not a palindrome if no nodes exist.
    if (head == nullptr) { return false; }
    
    // initialise the node pointers.
    struct list_node* forward = head;
    struct list_node* double_step = head;
    struct list_node* reverse = nullptr;
    struct list_node* next_step;

    // Imagine a singly-linked list of 1, 2, 3, 4, 3, 2, 1.
    // This will be rewritten as 1a, 2a, 3a, 4, 3b, 2b, 1b. 
    // This provided example would loop a total of 3 times.

    // Example Before Looping:
    // reverse points to nullptr.
    // forward points to 1a->2a->3a->4->3b->2b->1b->nullptr.
    
    // Loop until the middle point is found.
    while (double_step && double_step->next)
    {
        // Step forward by two linked nodes.
        double_step = double_step->next->next;

        // Reverse the left-side nodes.
        next_step = forward->next;
        forward->next = reverse;
        reverse = forward;
        forward = next_step;
        
        // Example After Loop 1:
        // reverse points to 1a->nullptr.
        // forward points to 2a->3a->4->3b->2b->1b->nullptr.

        // Example After Loop 2:
        // reverse points to 2a->1a->nullptr.
        // forward points to 3a->4->3b->2b->1b->nullptr.

        // Example After Loop 3:
        // reverse points to 3a->2a->1a->nullptr.
        // forward points to 4->3b->2b->1b->nullptr.
    }

    // If an odd number of nodes.
    if (double_step)
    {
        // Skip the middle node.
        forward = forward->next;

        // Example Final Result:
        // reverse points to 3a->2a->1a->nullptr.
        // forward points to 3b->2b->1b->nullptr.
    }

    // Loop from the middle.
    while (forward)
    {
        if (reverse->value != forward->value) { return false; }

        reverse = reverse->next;
        forward = forward->next;
    }

    return true;
}