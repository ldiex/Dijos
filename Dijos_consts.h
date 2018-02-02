//
// Created by diex on 18-2-1.
//

#ifndef UJ_DIJOS_CONSTS_H
#define UJ_DIJOS_CONSTS_H

namespace Consts {
    namespace System {
        const auto CleanScreen = "clear";
        //const auto CleanScreen = "cls";
        const auto Compiler = "g++ -Wall -o test ";
        const auto Differ = "diff ";
    }
    const auto AppName = "Dijos Offline Judge";
    const auto AppVersion = "0.2 beta";
    const auto Author = "Diex Lin";
    const auto Copyright = "Powered by Diex Lin 2018";
    const auto InputSource = "Please input your source(e.g. test.cpp): ";
    const auto InputDir = "Please input data dir(e.g. data): ";
    const auto PauseToContinue = "Enter To Continue..";
    const auto CannotOpenDir = "Cannot Open Dir !!!";
    const auto DefaultOutputFileName = "tmp.out";
    const auto DefaultInputFileType = ".in";
    const auto DefaultOutputFileType = ".out";
    const auto Backslash = '/';
    const auto Space = ' ';
    const auto TestLunchProgLeft = "./test<";
    const auto TestLunchProgRight = ">";
    const auto InfoScore = "Score: ";
    const double DefaultScore = 100;
    const std::string ResultName[] = {"AC", "WA", "RE"};

}
#endif //UJ_DIJOS_CONSTS_H

