#ifndef INCLUDED_API_H
#define INCLUDED_API_H

namespace peter {
    bool connect2();

    struct ReturnObj {
        bool isChanged;
        int copyOfUnchangedRef;
    };
    ReturnObj someComplexFuncThatPrints(int& ref);
}

// Use extern "C" so names are not garbled for python
extern "C" bool peterConnectGlobalFunc() {
    return peter::connect2();
}

extern "C" peter::ReturnObj peterComplexGlobalFunc(int& arg) {
    return peter::someComplexFuncThatPrints(arg);
}

#endif