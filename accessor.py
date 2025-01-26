import argparse
parser = argparse.ArgumentParser(description='Call C from python!')
parser.add_argument('number', help="Arg to pass into C lib")
args = parser.parse_args()

# 1. Link shared object
from ctypes import *
cpp_so = "build/libcApiLib.so"
cApi = CDLL(cpp_so)

# 2. Create Python object to match returned object from c api
class ReturnObj(Structure):
    _fields_ = [("isChanged", c_bool),
                ("copyOfUnchangedRef", c_int)]
    def __repr__(self):
        return f"[ isChanged={self.isChanged} copyOfUnchangedRef={self.copyOfUnchangedRef} ]"

cApi.peterComplexGlobalFunc.restype = ReturnObj

# 3. Call C api with ctypes vars
a = c_int(int(args.number))
print(f"The arg: {a}")
cApi.peterComplexGlobalFunc(byref(a))
print(f"The arg after the call: {a}")