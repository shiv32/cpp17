#include "test.h"

Test Test::m_Instance;

Test::Test()
{
  std::cout << __FUNCTION__ << std::endl;
  FunRunInCompileTime();
}

Test::~Test()
{
  std::cout << __FUNCTION__ << std::endl;
}

void Test::FunRunInCompileTime()
{
  std::cout << __FUNCTION__ << std::endl;
}