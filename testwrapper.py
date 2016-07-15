from ctypes import cdll
lib = cdll.LoadLibrary('./libsample.so')

def test(angular_bound):
    return lib.test(angular_bound)
