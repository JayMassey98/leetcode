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

# The time complexity of this function is O(n), where n is the length of the
# input string numeral. The function loops through each character in the input
# string exactly once, performing constant-time operations for each character.

# The space complexity of this function is O(1), as it uses a constant amount
# of space regardless of the size of the input string. The one character and
# two integer variables used have a constant size, so the space used by the
# function does not depend on the size of the input string.

# Convert a numeral into its integer form.
def roman_to_int(self, numeral: str) -> int:

    symbols = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000}

    reductions = {
        ('I', 'V'): 2,
        ('I', 'X'): 2,
        ('X', 'L'): 20,
        ('X', 'C'): 20,
        ('C', 'D'): 200,
        ('C', 'M'): 200}

    output = 0
    last_symbol = None

    for symbol in numeral:

        # Check the symbol is valid.
        if symbol not in symbols:
            return 0

        # Increase the integer output, checking for any required reductions.
        output += symbols[symbol] - reductions.get((last_symbol, symbol), 0)

        # Store for the next loop.
        last_symbol = symbol

    return output