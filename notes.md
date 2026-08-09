# Learning Notes

## Day 2: Hello World & Compilation
C++ is a compiled language, not interpreted like R. Before the program
can run, the compiler (cl.exe) translates the .cpp source file into an
.exe. This means errors get caught at compile time rather than only
showing up when a specific line runs, different from R, where a
mistake might not surface until you actually hit that code.

Learned the basic structure every C++ program needs: #include to pull
in libraries, int main() as the entry point, std::cout to print output,
and return 0 to signal the program finished successfully.

## Day 3: Variables & Static Typing
Unlike R, where a variable can hold any type and change freely, C++
requires declaring a variable's type up front (int, double, char, bool,
string), and that type is fixed for the variable's lifetime. This is
checked at compile time, so a type mismatch is caught before the
program ever runs, rather than causing a runtime surprise like it might
in R.

Also noticed bool prints as 1/0 by default in C++, not true/false.

## Day 4: Control Flow & Functions
Learned how loops and functions look in C++ compared to R. The for loop
syntax is more explicit than R's `for (i in 1:5)` you spell out the
start value, the condition to keep looping, and how to increment, all
in one line: `for (int i = 1; i <= 5; i++)`.

Functions require declaring both the parameter types and the return
type up front. e.g., `bool isEven(int number)`. A function that
doesn't return anything uses `void` as its return type, which R
doesn't really have an equivalent for since R functions always
return something.

Also hit my first real debugging lesson: an extra closing brace `}`
ended main() early, leaving the rest of the code floating outside any
function. This caused a cascade of confusing errors (redefinition,
missing semicolons) that were really all just one root cause - always
check that braces are matched when the compiler gives a wall of
unrelated-looking errors.

## Day 5: Vectors, Strings & Input
std::vector<int> is the closest thing to an R vector, but unlike R,
every element must be the same declared type, no mixing types in
one vector. Declared with the type in angle brackets, e.g.
std::vector<int>, so C++ knows what it holds.

Indexing starts at 0, not 1 like R/MATLAB, scores[0] is the first
element. Worth being deliberate about this since it's an easy source
of off-by-one mistakes coming from R.

Learned the range-based for loop (for (int score : scores)) as a
cleaner way to loop over a vector without manually tracking an index.

std::string supports concatenation with + and has a .length() method.
std::cin >> reads a single word of input (stops at whitespace),
different from reading a full line.
