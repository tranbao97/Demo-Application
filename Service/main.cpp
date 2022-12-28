#include <iostream>
#include "ShareMem.h"

using namespace std;

int main()
{
    // init share memory
    ShareMem shMem;
    shMem.writeDataToShareMem();
    return 0;
}
