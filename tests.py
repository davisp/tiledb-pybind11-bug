import errortest

class Derived(errortest.ErrorTest):
    pass

def test_new():
    g = Derived.__new__(Derived)
    print(repr(g))

if __name__ == "__main__":
    test_new()
