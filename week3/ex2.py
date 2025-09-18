class A:
    def hello(self):
        print("Hello from A")

class B(A):
    def hello(self):
        print("Hello from B")

class C(A):
    def hello(self):
        print("Hello from C")
        super().hello()

class D(B,C):
    def hello(self):
        print("Hello from D")
        super().hello()

class E(C): pass

class F(B,E): pass

class Error(A,B): pass

print(F.mro()) # F, B, E, C, A, object
print(Error.mro())