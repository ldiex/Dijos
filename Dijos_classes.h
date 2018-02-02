//
// Created by diex on 18-2-1.
//

#ifndef UJ_DIJOS_CLASSES_H
#define UJ_DIJOS_CLASSES_H

#include "System_functions.h"
#include "Dijos_consts.h"

class Results {
private:
    int IsChanged;
    double Score;
    std::vector<int> Res;

    void ComputeScore() {
        double SubScore = Consts::DefaultScore / double(Res.size());
        Score = 0;
        for (int &Re : Res) Score += (Re ? 0 : SubScore);
        IsChanged = 0;
    }

public:
    int Count() {
        return int(Res.size());
    }

    double GetScore() {
        if (IsChanged) ComputeScore();
        return Score;
    }

    std::string GetResultName(int ID) {
        return Consts::ResultName[Res[ID]];
    }

    Results &AddResult(int ResultID) {
        Res.emplace_back(ResultID);
        IsChanged = 1;
        return *this;
    }

    Results() : IsChanged(0), Score(0) {};
};

class TestIO {
private:
    std::vector<std::string> InputFile, OutputFile;
    std::string Folder;
    int DataCount;
public:
    int Count() {
        return DataCount;
    }

    std::string GetInputFile(int ID) {
        return Folder + Consts::Backslash + InputFile[ID];
    }

    std::string GetOutputFile(int ID) {
        return Folder + Consts::Backslash + OutputFile[ID];
    }

    TestIO &Init(const std::string &IOFolder) {
        std::vector<std::string> FileList;
        System::ScanDir(IOFolder.c_str(), FileList);
        sort(FileList.begin(), FileList.end());
        __gnu_cxx::__normal_iterator<std::string *, std::vector<std::string>> it;
        for (it = FileList.begin(); it != FileList.end(); ++it) {
            if (it->find(std::string(Consts::DefaultInputFileType)) != it->npos) InputFile.emplace_back(*it);
            if (it->find(std::string(Consts::DefaultOutputFileType)) != it->npos) OutputFile.emplace_back(*it);
        }
        DataCount = System::Math::Min(int(InputFile.size()), int(OutputFile.size()));
        Folder = IOFolder;
        return *this;
    }

};

class SourceCode {
private:
    std::string Name;

    int SubTest(const std::string &InputFile, const std::string &OutputFile) {
        std::string Command =
                Consts::TestLunchProgLeft + InputFile + Consts::TestLunchProgRight + Consts::DefaultOutputFileName;
        if (system(Command.c_str())) return 2;
        Command = Consts::System::Differ;
        Command += Consts::DefaultOutputFileName;
        Command += Consts::Space + OutputFile;
        return system(Command.c_str()) ? 1 : 0;
    }

public:

    void Test(TestIO IO, Results &Res) {
        for (int i = 0; i < IO.Count(); i++)
            Res.AddResult(SubTest(IO.GetOutputFile(i), IO.GetOutputFile(i)));
    }

    int Build() {
        std::string Command = Consts::System::Compiler;
        Command += Name;
        return system(Command.c_str());
    }

    SourceCode &Init(std::string name) {
        Name = std::move(name);
        return *this;
    }

};

#endif //UJ_DIJOS_CLASSES_H
