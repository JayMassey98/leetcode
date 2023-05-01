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
#include <numeric>
#include <vector>

// Allow specified code to be optimised in compilation.
#define optimize __attribute__((optimize("O3"))) const


optimize int richest_customer_wealth(std::vector<std::vector<int>>& accounts)
{
    int max_wealth = 0;

    for (const std::vector<int>& customer : accounts)
    {
        max_wealth = std::max(max_wealth, std::accumulate(
            customer.begin(), customer.end(), 0));
    }

    return max_wealth;
}