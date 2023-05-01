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

// The time complexity of this function is O(n), where n is the length of the
// input string numeral. The function loops through each character in the input
// string exactly once, performing constant-time operations for each character.

// The space complexity of this function is O(1), as it uses a constant amount
// of space regardless of the size of the input string. The one character and
// two integer variables used have a constant size, so the space used by the
// function does not depend on the size of the input string.


// Allow specified code to be optimised in compilation.
#define optimize __attribute__((optimize("O3"))) const


// Convert a given numeral into its integer form.
optimize int roman_to_integer(const char* numeral)
{    
    int output = 0;
    char last_symbol = 0;

    // Loop until there are no more symbols in the numeral number.
    for (int position = 0; numeral[position] != '\0'; position++)
    {        
        // Store the current character symbol.
        const char symbol = numeral[position];
        
        // Determine the symbol.
        switch (symbol)
        {
            case 'I':
                output += 1;
                break;

            case 'V':
                output += 5;
                if (last_symbol == 'I') { output -= 2; }
                break;
            
            case 'X':
                output += 10;
                if (last_symbol == 'I') { output -= 2; }
                break;
            
            case 'L':
                output += 50;
                if (last_symbol == 'X') { output -= 20; }
                break;

            case 'C':
                output += 100;
                if (last_symbol == 'X') { output -= 20; }
                break;

            case 'D':
                output += 500;
                if (last_symbol == 'C') { output -= 200; }
                break;

            case 'M':
                output += 1000;
                if (last_symbol == 'C') { output -= 200; }
                break;

            default:
                // This path should never occur. In safety critical systems,
                // this would require an error log, however for simple cases
                // like this, this path can be justifiably ignored instead.
                break;
        }

        // Store for the next loop.
        last_symbol = symbol;
    }

    return output;
}