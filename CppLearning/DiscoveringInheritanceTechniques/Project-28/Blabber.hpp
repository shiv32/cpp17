#pragma once

#include "Secret.hpp"

class Blabber : public Secret
{
public:
    //virtual void tell();
    //virtual void dontTell() override;
     using Secret::dontTell;
};