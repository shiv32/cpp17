OVERLOADING THE ARITHMETIC OPERATORS

    Overloading Unary Minus and Unary Plus

        int i, j = 4;
        i = -j;    // Unary minus
        i = +i;    // Unary plus
        j = +(-i); // Apply unary plus to the result of applying unary minus to i.
        j = -(-i); // Apply unary minus to the result of applying unary minus to i.

    Overloading Increment and Decrement

        i = i + 1;
        i += 1;
        ++i;
        i++;

        SpreadsheetCell& operator++();   // Prefix
        SpreadsheetCell operator++(int); // Postfix
        SpreadsheetCell& operator--();   // Prefix
        SpreadsheetCell operator--(int); // Postfix