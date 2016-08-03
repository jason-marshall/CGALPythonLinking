from ctypes import cdll
lib = cdll.LoadLibrary('./libsample.so')

def test(angular_bound):
    return lib.test(angular_bound)

def test2(angular_bound):
    return lib.test2(angular_bound)
