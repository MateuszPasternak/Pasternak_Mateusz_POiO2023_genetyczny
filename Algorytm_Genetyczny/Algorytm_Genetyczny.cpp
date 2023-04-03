// Algorytm_Genetyczny.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "TGen.h"

int main()
{
    TGen param1{ 1, 4, 1 ,"Gen1"};

    //param1.info();
    param1.set_value(2.5);
    param1.info();
}
