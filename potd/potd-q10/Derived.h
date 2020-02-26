#include "Base.h"

#pragma once

class Derived:public Base{
    public:
        const char* foo();
        const char* bar();
        ~Derived();


};