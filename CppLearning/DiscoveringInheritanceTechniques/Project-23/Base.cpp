#include "Base.hpp"
#include <iostream>

Base::Base(std::string_view str) : mStr(str) 
{
  std::cout<<__PRETTY_FUNCTION__<<std::endl;

  std::cout<<"mStr : "<<mStr<<std::endl;
}