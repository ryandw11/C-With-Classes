#pragma once
#include "Classes.h"

begin_class(MyClass);

int decl_class_func(MyClass, Add, int, int);
int decl_class_svfunc(MyClass, IncAndGetInternal);

class(MyClass) {
    int internalTest;
    int func(Add, int, int);
    int svfunc(MyClass, IncAndGetInternal);
} class_declartions(MyClass)
    class_field(0)
    class_func(MyClass, Add)
    class_func(MyClass, IncAndGetInternal)
end_class(MyClass);

int decl_class_func(MyClass, Add, int x, int y)
{
    return x + y;
}

int decl_class_svfunc(MyClass, IncAndGetInternal)
{
    return self->internalTest++;
}