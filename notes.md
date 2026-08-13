# Learning Notes

## Part 2: Hello World & Compilation
C++ is a compiled language, not interpreted like R. Before the program
can run, the compiler (cl.exe) translates the .cpp source file into an
.exe. This means errors get caught at compile time rather than only
showing up when a specific line runs, different from R, where a
mistake might not surface until you actually hit that code.

Learned the basic structure every C++ program needs: #include to pull
in libraries, int main() as the entry point, std::cout to print output,
and return 0 to signal the program finished successfully.

## Part 3: Variables & Static Typing
Unlike R, where a variable can hold any type and change freely, C++
requires declaring a variable's type up front (int, double, char, bool,
string), and that type is fixed for the variable's lifetime. This is
checked at compile time, so a type mismatch is caught before the
program ever runs, rather than causing a runtime surprise like it might
in R.

Also noticed bool prints as 1/0 by default in C++, not true/false.

## Part 4: Control Flow & Functions
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

## Part 5: Vectors, Strings & Input
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

## Part 6: Command Line Calculator Project

Built a working calculator combining everything learned in days 3 to 5: variables, control flow, functions, and reading input.

New things used to make it work:
* while loop, used to keep the calculator running in a loop until the user chooses to quit
* a bool flag (running) controlling when the while loop should stop
* std::stod, which converts a string into a double, needed because input is read as a string first so it can be checked against "q"
* continue, which skips the rest of the current loop iteration and jumps back to the while condition, used both for quitting and for handling an unknown operator
* separate functions for each operation (add, subtract, multiply, divide), all sharing the same shape: two doubles in, one double out
* basic error handling inside divide, checking for division by zero before doing the calculation

Next step is moving into memory and pointers, which is the first brand new C++ concept without a direct equivalent already known from R, MATLAB, or SQL.

## Part 7: Memory & Pointers

A normal variable like age has both a name and a box in memory, on the
stack. A pointer is itself a separate box, but instead of holding an
ordinary value, it holds the address (the box number) of another
variable. The & symbol gets the address of a variable, and the *
symbol dereferences a pointer, meaning it follows the address back to
get the actual value stored there.

In today's example the pointer was pointing at a normal named
variable, so it wasn't strictly necessary. The real usefulness comes
later, when memory is requested on the heap using new. That memory
has no name at all, so a pointer is the only way to ever reach it
again. If the pointer holding that address is lost or overwritten,
the memory becomes permanently unreachable but still reserved. This
is what's known as a memory leak.

Definitions:
* Stack: automatic memory, used for normal named variables, created when a variable is declared and destroyed automatically when it goes out of scope
* Heap: manual memory, requested explicitly while the program is running and only freed when explicitly deleted, reached only through a pointer

Unnamed heap memory exists because the amount of memory needed is not
always known until the program is running, and because it can outlive
the function that created it, unlike stack memory. In practice,
std::vector already handles this internally, which is why it can
grow in size.

## Part 8: References, Pass By Value, Pass By Reference

* A reference is a second name for an existing variable, declared with &, but unlike a pointer no * is needed to read or change its value, it behaves exactly like the original variable
* A reference cannot be reassigned to refer to a different variable once set, unlike a pointer which can be pointed elsewhere
* Pass by value copies the argument into the function, so changes made inside the function do not affect the original variable
* Pass by reference, using & in the function parameter, lets the function work directly on the original variable, so changes made inside the function do affect the original
* Every function written so far this week used pass by value without it being named, this is the first time pass by reference has been used deliberately
* Pass by value is used when the function should not affect the caller's variable, such as a calculation like add(a, b) where only the result is needed back, not a modified original
* Pass by reference is used when the function genuinely needs to modify the original variable, such as addTenByReference, or when passing something large where copying it would be wasteful

## Part 9: Dynamic Memory (new and delete)

* new requests memory on the heap while the program is running, and returns a pointer to it, this is the first time memory has genuinely had no name of its own
* delete frees heap memory once it's no longer needed, the heap does not clean up automatically like the stack does, forgetting this causes a memory leak
* setting a pointer to nullptr after deleting it is good practice, since the pointer still holds the old address otherwise, even though that memory is no longer valid to use
* new int[size] is the real payoff from named memory not being possible, size is only known once the program is running, such as from user input, so there is no way this could have been a normal named variable
* deleting an array requires delete[], with square brackets, using plain delete on an array is a bug

### Mini Project: Number Guessing Game

* std::rand() generates a random number, seeded with the current time using std::srand and std::time so the sequence is different each run rather than the same every time
* the % (modulo) operator combined with + 1 restricts the random number to a specific range, here 1 to 100
* the while loop keeps the game running until the guess matches the secret number, reusing the same "loop until a condition is met" pattern from the calculator project
* this project mainly reinforced loops, conditionals, and variables from earlier days, rather than introducing new syntax, the new concept for today was dynamic memory above

## Part 10 addition: GitHub Actions (CI/CD)

* Added a GitHub Actions workflow (.github/workflows/build.yml) that automatically compiles every .cpp file in the repo every time a push is made to main
* This is Continuous Integration, an automated check that code still compiles, rather than relying on manually running the compiler locally and trusting it stays working
* A green checkmark next to a commit means the build succeeded, a red X would mean something in that push does not compile
* Currently compiles each .cpp file separately since each one has its own main function, this will need updating once multi-file projects with CMake are introduced later

## Part 11: Classes and Constructors

* A class bundles data and the functions that operate on that data together into one thing, rather than having separate loose variables and functions like before
* Member variables are the data every object created from the class will have, such as name and age on a Person
* A constructor is a special function that runs automatically when an object is created, it shares the class's name and has no return type, not even void
* public makes the members below it accessible from outside the class, this will be revisited in Part 11 where it becomes clear why that isn't always wanted
* Each object created from a class has its own separate copy of the member variables, alice and bob were both built from the same Person blueprint but hold entirely different data
* Member functions are called using dot notation on a specific object, such as alice.introduce(), rather than passing the object in as a parameter
