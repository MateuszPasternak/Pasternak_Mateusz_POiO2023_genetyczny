// Algorytm_Genetyczny.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
#include "TGen.h"
#include "TCandidate.h"
#include "TPopulation.h"
#include "TAlgorithm.h"

int main()
{
    srand(time(NULL));
    /*TGen param1{1, 4, 0.5 ,"Gen1"};
    param1.set_description();
    param1.info();
    std::cout << "\nName of this gene is: " << param1.get_name() <<std::endl;*/
    /*TGen param2{0, 25, 1, 5, "Gen2", "Gen2 - zabawa genami - doktor zlo w akcji"};

    //param1.info();
    param1.set_value(2.75);
    param1.info();

    param2.info();*/

    //TCandidate cand1{};
    //cand1.rate();
    //cand1.info();

    /*TPopulation pop{10};
    TPopulation pop2{ 20 };
    pop.info();
    std::cout << "\n\n";
    pop.calculate();
    pop.info();
    std::cout << "\n\n";
    std::cout << "BEST CANDIDATE";
    pop.best_candidate().info();

    pop2.info();*/

    TAlgorithm alg1(5,50,4);
    alg1.alg();
}
