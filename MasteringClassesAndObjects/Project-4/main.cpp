/*
   Handling Moving with Move Semantics
   Rvalue References

    lvalues can appear on the left-hand side of an assignment.
    rvalue is on the right-hand side of an assignment operator.
*/

#include <iostream>
#include <string>

// lvalue reference parameter
void handleMessage(std::string &message)
{
    std::cout << "handleMessage with lvalue reference: " << message << std::endl;
}
// rvalue reference parameter
void handleMessage(std::string &&message)
{
    std::cout << "handleMessage with rvalue reference: " << message << std::endl;
}

void helper(std::string &&message)
{
    std::cout << "helper with rvalue reference: " << message << std::endl;
}

// rvalue reference parameter
void handleMessage2(std::string &&message)
{
    //helper(message); //message, which has a name, so it’s an lvalue, causing a compilation error.
    helper(std::move(message));
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
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

    std::string b = "Hello ";
    std::string c = "World";

    handleMessage(b); // Calls handleMessage(string& value)

    handleMessage(b + c); // Calls handleMessage(string&& value)

    handleMessage("Hello World"); // Calls handleMessage(string&& value)

    handleMessage(std::move(b)); // Calls handleMessage(string&& value)

    handleMessage2("Hello World 2"); // Calls handleMessage2(string&& value)

    return 0;
}