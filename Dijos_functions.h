//
// Created by diex on 18-2-1.
//

#ifndef UJ_DIJOS_FUNCTIONS_H
#define UJ_DIJOS_FUNCTIONS_H

#include "System_functions.h"
#include "Dijos_consts.h"
#include "Dijos_classes.h"

namespace Dijos {
    SourceCode Source;
    TestIO IO;
    Results Res;

    void InputSource() {
        std::cout << Consts::InputSource;
        std::string name;
        std::cin >> name;
        Source.Init(name);
    }

    void ShowAppInfo() {
        std::cout << Consts::AppName << Consts::Space << Consts::AppVersion << std::endl;
        std::cout << Consts::Copyright << std::endl;
    }

    void SolveSource() {
        InputSource();
        while (Source.Build()) InputSource();
    }

    void Test() {
        std::cout << Consts::InputDir;
        std::string Folder;
        std::cin >> Folder;
        IO.Init(Folder);
        Source.Test(IO, Res);
    }

    void ShowResults() {
        for (int i = 0; i < Res.Count(); i++) std::cout << Res.GetResultName(i) << Consts::Space;
        std::cout << std::endl << Consts::InfoScore << Res.GetScore() << std::endl;
    }

    void AppStart() {
        System::CleanScreen();
        ShowAppInfo();
        SolveSource();
        Test();
        ShowResults();
    }
}

#endif //UJ_DIJOS_FUNCTIONS_H
