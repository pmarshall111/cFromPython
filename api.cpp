#include <api.h>

#include <iostream>

namespace peter {
    ReturnObj someComplexFuncThatPrints(int& ref) {
        ReturnObj rObj{false, ref};
        if (ref % 2 == 0) {
            rObj.isChanged = true;
            ref /= 2;
        } 
        std::cout << "original=" << rObj.copyOfUnchangedRef 
                    << " changed=" << ref 
                    << " isChanged=" << rObj.isChanged 
                    << std::endl;
        return rObj;
    }

}

void printUsage(const char* tsk) {
    std::cout << "Usage: " << tsk << " <int>" << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printUsage(argv[0]);
        return 1;
    }

    int convertedInt = atoi(argv[1]);

    std::cout << "The arg: " << convertedInt << std::endl;
    peter::someComplexFuncThatPrints(convertedInt);
    std::cout << "The arg after call: " << convertedInt << std::endl;
    return 0;
}