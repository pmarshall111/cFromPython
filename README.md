# Calling C from Python

Both tasks call the same c code:

```
peter@chronos:~/Documents/personalProjects/cFromPython$ ./build/cApi.tsk 22
The arg: 22
original=22 changed=11 isChanged=1
The arg after call: 11
peter@chronos:~/Documents/personalProjects/cFromPython$ python3 accessor.py 22
The arg: c_int(22)
original=22 changed=11 isChanged=1
The arg after the call: c_int(11)
```