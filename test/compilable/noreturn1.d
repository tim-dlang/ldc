/*
REQUIRED_ARGS: -w
TEST_OUTPUT:
---
noreturn
---
*/

alias noreturn = typeof(*null);
pragma(msg, noreturn);

noreturn exits(int* p) { *p = 3; }

noreturn exit();

noreturn pureexits() @nogc nothrow pure @safe { assert(0); }

noreturn callpureexits() { pureexits(); }

int test1(int i)
{
    if (exit())
        return i + 1;
    return i - 1;
}

