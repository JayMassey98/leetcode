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

// The time complexity of this function is O(log(n)), where n is the input
// integer value. This is the fastest time possible for this particular task.

// The space complexity of this function is O(1), as it uses a constant amount
// of space regardless of the input value size. The integer variable used has a
// constant size, so the space does not depend on the size of the input value.


// -------------------
// Problem Description
// -------------------

// Given an integer value, return the number of steps to reduce it to zero.
// In one step, if the current number is even, you have to divide it by 2,
// otherwise, you have to subtract 1 from it.


// Allow specified code to be optimised in compilation.
#define optimize __attribute__((optimize("O3"))) const


// Steps needed to reduce a value to 0.
optimize int number_of_steps(int value)
{
    int steps = 0;

    // Loop until 0.
    while (value)
    {        
        if (value & 1)  { value--; }        // If value is odd.
        else            { value >>= 1; }    // If value is even.

        steps++;
    }

    return steps;
}