#include <iostream>

void initialize();
void use_i(const int);
void use_j(const int);
void use_k(const int);

void do_something();

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    do_something();

    return 0;
}

void initialize() 
{
    std::clog<<__PRETTY_FUNCTION__<<std::endl;
}

void use_i(const int) 
{
     std::clog<<__PRETTY_FUNCTION__<<std::endl;
}

void use_j(const int) 
{
     std::clog<<__PRETTY_FUNCTION__<<std::endl;
}

void use_k(const int) 
{
     std::clog<<__PRETTY_FUNCTION__<<std::endl;
}

void do_something()
{
    // Initialize someting.
    initialize();

    // Declare i when using it in use_i().
    const int i = 3;
    use_i(i);

    // Declare j when using it in use_j().
    const int j = 7;
    use_j(j);

    // Declare k in the scope of the for-loop.
    for (int k = 0; k < 10; ++k)
    {
        use_k(k);
    }
};