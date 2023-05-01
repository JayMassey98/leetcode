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

# The time complexity of this function is O(log(n)), where n is the input
# integer value. This is the fastest time possible for this particular task.

# The space complexity of this function is O(1), as it uses a constant amount
# of space regardless of the input value size. The integer variable used has a
# constant size, so the space does not depend on the size of the input value.


# -------------------
# Problem Description
# -------------------

# Given an integer value, return the number of steps to reduce it to zero.
# In one step, if the current number is even, you have to divide it by 2,
# otherwise, you have to subtract 1 from it.


def number_of_steps(self, value: int) -> int:

    # Add the index of value's MSB to the number of set bits.
    # Handle the cases where value < 0 by using max(... , 0).
    return max(value.bit_length() - 1 + value.bit_count(), 0)