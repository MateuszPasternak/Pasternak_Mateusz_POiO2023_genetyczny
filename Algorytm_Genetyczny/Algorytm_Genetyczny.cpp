// Algorytm_Genetyczny.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "TGen.h"

int main()
{
    TGen param1{ 1, 4, 1 ,"Gen1"};
    //TGen param2{ 0, 25, 0.5, 5, "Gen2", "Gen2 - zabawa genami - doktor zlo w akcji" };

    //param1.info();
    param1.set_value(2.5);
    param1.info();

    //param2.info();
}
