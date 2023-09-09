#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Classes.h"
#include "DemoClass.h"

int GetValue_TestClass_cwc_impl() {
    return 20;
}

struct TestClass_cwc {
    int id;
    int (*GetValue)(void);
} TestClass_cwc_default = {3, GetValue_TestClass_cwc_impl};

typedef struct TestClass_cwc TestClass;

int main()
{
    TestClass* test = malloc(sizeof(TestClass));
    memcpy(test, &TestClass_cwc_default, sizeof(TestClass));


    //int value = test->GetValue();
    //printf("Value: %d", value);

    MyClass* myClass = new(MyClass);
    default_class(MyClass, myClass);
    
    int returnValue = myClass->Add(25, 25);
    printf("Addition Value: %d\n", returnValue);
    int valueOne = call(myClass, IncAndGetInternal);
    int valueTwo = myClass->IncAndGetInternal(myClass);
    printf("Value 1: %d, Value 2: %d", valueOne, valueTwo);
}
