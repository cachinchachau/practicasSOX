#include <iostream>

//#include "TutorialThreads/ThreadTutorial.h"
#include "Utils/consoleControl.h"

#include <functional>
#include <string>
#include <list>

typedef std::function<int(int, int)> SumaFunction;

void TestLambdasMolonas(std::function<int(int, int)> funcionMolona)
{
    std::cout << "Voy a ejecutar una funcuion que estaba en una variable" << std::endl;

    int number = funcionMolona(9, 10);

    std::cout << "Ya la he ejecutado" << std::endl;
}

int main()
{
    std::string name = "Pepe";

    std::list<std::list<int>> listaDeListas;

    SumaFunction funcionQueHaceCosasPeroEsUnaVariable = [name](int a, int b) {

        std::cout << "Esto no se como pero funciona y me dice mi nombre --> " << name << std::endl;
        return a + b;
        };
     

    TestLambdasMolonas(funcionQueHaceCosasPeroEsUnaVariable);
    

    return 9;
}
