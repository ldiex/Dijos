//
// Created by diex on 18-2-1.
//

#ifndef UJ_SYSTEM_FUNCTIONS_H
#define UJ_SYSTEM_FUNCTIONS_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>
#include <algorithm>
#include "Dijos_consts.h"

namespace System {
    namespace Math {
        int Max(int x, int y) {
            return (x > y) ? x : y;
        }
        int Min(int x, int y) {
            return (x < y) ? x : y;
        }
    }

    void CleanScreen() {
        system(Consts::System::CleanScreen);
    }

    void PauseToContinue() {
        std::cout << Consts::PauseToContinue << std::endl;
        getchar();
    }

    int ScanDir(const char *path, std::vector<std::string> &FileList) {
        std::string folder = path;
        DIR *d;
        struct dirent *file;
        struct stat buf;
        if (!(d = opendir(folder.c_str()))) {
            std::cout << Consts::CannotOpenDir << std::endl;
            std::cout << Consts::InputDir;
            std::cin >> folder;
        }
        while ((file = readdir(d)) != NULL) FileList.emplace_back(file->d_name);
        closedir(d);
        return 0;
    }
}
#endif //UJ_SYSTEM_FUNCTIONS_H
