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
// input string numeral. The function loops through each character in the input
// string exactly once, performing constant-time operations for each character.

// The space complexity of this function is O(1), as it uses a constant amount
// of space regardless of the size of the input string. The one character and
// two integer variables used have a constant size, so the space used by the
// function does not depend on the size of the input string.


#include <cstddef>
#include <string>

// Allow specified code to be optimised in compilation.
#define optimize __attribute__((optimize("O3"))) const


optimize int get_symbol_value(const char symbol)
{
    switch (symbol)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;

        // This path should never occur. In safety critical systems,
        // this would require an error log, however for simple cases
        // like this, this path can be justifiably ignored instead.
        default : return 0;
    }
}

optimize int check_order_reduction(
    const char last_symbol,
    const char symbol)
{
    switch (last_symbol)
    {
        case 'I': if (symbol == 'V' || symbol == 'X') { return 2; }
        case 'X': if (symbol == 'L' || symbol == 'C') { return 20; }
        case 'C': if (symbol == 'D' || symbol == 'M') { return 200; }
        default : return 0;
    }
}

// Convert a given numeral into its integer form.
optimize int roman_to_integer(const std::string numeral)
{    
    int output = 0;
    char last_symbol = 0;
    const size_t numeral_length = numeral.length();

    // Loop until there are no more symbols in the numeral number.
    for (size_t position = 0; position < numeral_length; position++)
    {        
        // Store the current character symbol.
        const char symbol = numeral[position];
        
        // Determine the correct increase.
        output += get_symbol_value(symbol);

        // Check if symbol ordering causes a value reduction.
        output -= check_order_reduction(last_symbol, symbol);

        // Store for the next loop.
        last_symbol = symbol;
    }

    return output;
}