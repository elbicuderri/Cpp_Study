#include <iostream>
#include <memory>
#include <utility>
#include "resource.h"

void doSomething()
{
    Resource* res = new Resource;

    std::unique_ptr<Resource> res2 = std::make_unique<Resource>();

    delete res;

    return;
}

int main()
{
    doSomething();

    return 0;
}