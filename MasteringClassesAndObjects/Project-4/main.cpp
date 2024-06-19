/*
   Handling Moving with Move Semantics
   Rvalue References

    lvalues can appear on the left-hand side of an assignment.
    rvalue is on the right-hand side of an assignment operator.
*/

#include <iostream>

int main()
{

    /*
     a is an lvalue, it has a name and you can take the address of it with &a.
     4 * 2 on the other hand is an rvalue.
     It is a temporary value that is destroyed when the statement finishes execution.
     A copy of this temporary value is stored in the variable with name "a".
    */

    int a = 4 * 2;

    /*
    An rvalue reference is a reference to an rvalue
    A function can specify an rvalue reference parameter by using && as part of 
    the parameter specification; for example, type&& name.
    */

    return 0;
}