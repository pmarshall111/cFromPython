#include <api.h>

#include <iostream>

namespace peter {
    bool connect2() {
        std::cout << "connected!" << std::endl;
        return true; 
    }

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

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <char>";
        return 1;
    }

    int convertedInt = static_cast<int>(*argv[1]);
    std::cout << "The arg: " << convertedInt << std::endl;

    peter::connect2();
    peter::someComplexFuncThatPrints(convertedInt);

    std::cout << "The arg after call: " << convertedInt << std::endl;
    return 0;
}