# Learning Notes

## Day 2: Hello World & Compilation
C++ is a compiled language, not interpreted like R. Before the program
can run, the compiler (cl.exe) translates the .cpp source file into an
.exe. This means errors get caught at compile time rather than only
showing up when a specific line runs — different from R, where a
mistake might not surface until you actually hit that code.

Learned the basic structure every C++ program needs: #include to pull
in libraries, int main() as the entry point, std::cout to print output,
and return 0 to signal the program finished successfully.

## Day 3: Variables & Static Typing
Unlike R, where a variable can hold any type and change freely, C++
requires declaring a variable's type up front (int, double, char, bool,
string), and that type is fixed for the variable's lifetime. This is
checked at compile time — so a type mismatch is caught before the
program ever runs, rather than causing a runtime surprise like it might
in R.

Also noticed bool prints as 1/0 by default in C++, not true/false.
