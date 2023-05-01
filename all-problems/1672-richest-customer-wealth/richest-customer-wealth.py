# ---------------
# Code Assumption
# ---------------

# Since this code is written in Python, the assumption is that development time
# is the limiting factor, not the speed of the code at runtime. Therefore, this
# code has been written to be clean, concise, and 'Pythonic', whilst making use
# of modules already built into Python for easier readability and reusability.


# ---------------
# Code Complexity
# ---------------

# The time complexity of this function is O(nm), where n is the total number of
# customers, and m is the total number of accounts. The function loops through
# all array elements exactly once, performing constant-time operations on each
# array element. This is the fastest time complexity for this particular task.

# The space complexity of this function is O(1), as it uses a constant amount
# of space regardless of the input array size. The integer variables used have
# a constant size, so the space does not depend on the size of the input array.


# -------------------
# Problem Description
# -------------------

# You are given nm integer grid accounts, where accounts[i][j] is the amount of
# money the i​​​​​​​​​​​th​​​​ customer has in their j​​​​​​​​​​​th​​​​ account. Return the total wealth that
# the richest customer has. A customer's wealth is the total value they have in
# all their accounts. The richest customer is the one with the maximum wealth.


# The argument 'accounts' is a list of lists of integers. The inner list below
# represents a collection of the customer's bank accounts, whilst the integers
# represent the balances. The outer list represents the customers of the bank.
def richest_customer_wealth(self, accounts: List[List[int]]) -> int:
    return max(sum(customer) for customer in accounts)