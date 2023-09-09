# C-With-Classes
 Why?

## Define a Class
```c
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
```

## Using a Class
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DemoClass.h"

int main()
{
    MyClass* myClass = new(MyClass);
    default_class(MyClass, myClass);
    
    int returnValue = myClass->Add(25, 25);
    printf("Addition Value: %d\n", returnValue);
    int valueOne = call(myClass, IncAndGetInternal);
    int valueTwo = myClass->IncAndGetInternal(myClass);
    printf("Value 1: %d, Value 2: %d", valueOne, valueTwo);
}
```
