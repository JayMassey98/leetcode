// ---------------
// Code Assumption
// ---------------

// Since this code is written in C, the assumption is that it would be run on an
// embedded device with limited resources. Therefore, this code has been written
// to slightly lean towards efficiency over readability. However, a fair balance
// has been aimed for, whilst making sure to follow good code practices overall.


// ---------------
// Code Complexity
// ---------------

// The time complexity of this function is O(nm), where n is the total number of
// customers, and m is the total number of accounts. The function loops through
// all array elements exactly once, performing constant-time operations on each
// array element. This is the fastest time complexity for this particular task.

// The space complexity of this function is O(1), as it uses a constant amount
// of space regardless of the input array size. The integer variables used have
// a constant size, so the space does not depend on the size of the input array.


// -------------------
// Problem Description
// -------------------

// You are given nm integer grid accounts, where accounts[i][j] is the amount of
// money the i​​​​​​​​​​​th​​​​ customer has in their j​​​​​​​​​​​th​​​​ account. Return the total wealth that
// the richest customer has. A customer's wealth is the total value they have in
// all their accounts. The richest customer is the one with the maximum wealth.


// Required headers.
#include <stddef.h>

// Allow specified code to be optimised in compilation.
#define optimize __attribute__((optimize("O3"))) const


optimize int richest_customer_wealth(
    const int** accounts,
    const int   accounts_size,
    const int*  accounts_column_size)
{

// Optimised out for LeetCode.
#ifdef SAFETY_CRITICAL_REQUIRED

    if (accounts == NULL || accounts_size == 0 || accounts_column_size == NULL)
    {
        // Invalid parameter(s).
        return -1;
    }
    
#endif

    int max_wealth = 0;

    for (size_t customer = 0; customer < accounts_size; customer++)
    {
        int account_total = 0;

        for (size_t account = 0; account <
            accounts_column_size[customer]; account++)
        {
            account_total += accounts[customer][account];
        }

        if (account_total > max_wealth) { max_wealth = account_total; }
    }

    return max_wealth;
}