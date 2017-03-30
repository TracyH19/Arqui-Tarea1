#ifndef FILESMANAGER_H
#define FILESMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class filesManager
{
    public:
        filesManager();
        virtual ~filesManager();

        void createFile(char* nombre, vector<int>* vec, int n, int m);
        void createBinFile(char* nombre, vector<int>* vec, int n, int m);

    protected:
    private:
};

#endif // FILESMANAGER_H
