#include <iostream>

//#include "TutorialThreads/ThreadTutorial.h"
#include "Utils\ConsoleControl\ConsoleControl.h"
#include "2InputSystem\InputSystem.h"


int main()
{
 
    InputSystem* iS = new InputSystem();

    InputSystem::KeyBinding* kb1 = iS->AddListener(K_1, []() {
        CC::Lock();
        std::cout << "pressed 1" << std::endl;
        CC::Unlock();
        });


    iS->StartListen();

    while (true)
    {

    }

    return 9;
}
