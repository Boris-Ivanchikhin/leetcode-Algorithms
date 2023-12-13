#include <Windows.h>
#include <iostream>

#include "Timer.h"

using namespace std;

/* Driver Function to test other function */
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Timer T("Go!");
    T.print();

    return 0;
}
