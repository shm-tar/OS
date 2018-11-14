//в компілер опшинзах і лінкер опшинзах -pthread, підрубати .so лібу
#include <stdio.h>
#include <stdlib.h>

void start();

int main()
{
    start();
    return 0;
}
