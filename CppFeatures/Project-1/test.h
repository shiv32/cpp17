#pragma once

#include <iostream>

class Test
{
private:
    static Test m_Instance;
    Test();

public:
    static void FunRunInCompileTime();
    ~Test();
};
