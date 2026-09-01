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

## Part 12: Encapsulation

* private stops name and age being accessed directly from outside the class, trying to do so is now a compile error
* getters and setters, like getAge and setAge, are the only way to read or change private data from outside, and being functions they can include validation
* the constructor now calls setAge instead of setting age directly, so the same validation applies even when the object is first created
* encapsulation exists to stop a class's data from being set to an invalid state from outside

## Part 13: Structs vs Classes

* a struct is public by default, a class is private by default, that is the only real difference
* anyone can access a struct's members directly, since they are public by default, unless private is deliberately added inside it
* struct or class is just the default you get if you write nothing, both can do everything the other can, constructors, functions, all of it
* structs are useful for simple data with no rules to enforce, like a Point with just x and y, since writing getters and setters for it would just be extra typing for no benefit
* using struct also signals intent, it tells anyone reading the code this is just data with no hidden behaviour, while class signals there is logic or validation worth being careful with

## Part 14: Classes Interacting and Basic Inheritance

* classes can reference and use each other, not just exist in isolation, Library's checkOut function takes a Book object as a parameter
* checkOut used pass by reference, Book& book, so the change made inside the function to isCheckedOut actually affected the original object back in main, reusing the idea from Part 8
* inheritance lets one class build on another, class Dog : public Animal means Dog inherits everything Animal has
* the child class constructor can call the parent's constructor directly, using : Animal(dogName), so shared setup logic like setting name only needs to exist once
* a child class gets full access to the parent's public members for free, bark could use name even though name was declared in Animal, not Dog

## Part 15: Library/Inventory System (OOP mini project)

* Library holds a std::vector<Book>, a class managing a collection of other class objects, a very common real pattern
* addBook takes a Book object by value and pushes it into the vector with push_back, reusing vector methods from Part 5
* checkOut loops through the vector searching by title, using getTitle and getIsCheckedOut rather than reaching into Book's private members directly, encapsulation from Part 11 enforced even while one class is working with another
* handled three cases correctly, checking out an available book, trying to check out an already checked out book, and searching for a book that does not exist
* this project combined encapsulation, a class holding a vector of another class, and searching/looping, tying together everything from Parts 10 to 13 into one working program

## Part 16: Vector Sorting, Searching, and Iterators

* std::sort sorts a vector in place using .begin() and .end() to mark the range, no need to write a sorting algorithm from scratch
* std::greater<int>() as a second argument to sort flips it to descending order
* std::find searches for a value and returns an iterator pointing to it, or .end() if not found, checked with it != numbers.end()
* an iterator is a more general, safer version of a pointer, built specifically for walking through STL containers, * dereferences it the same way * dereferences a pointer from Part 7
* auto lets the compiler work out the type itself, useful once types get long and verbose like std::vector<int>::iterator

Needed because writing sorting and searching by hand every time would
be repetitive and error prone, these are extremely common operations
so the STL provides tested, efficient versions ready to use.

Real life example: sorting a list of patients by enrollment date to
find who joined first, or searching a large dataset for a specific
patient ID rather than checking every record one by one manually.

## Part 17: std::map

* std::map<int, std::string> stores key value pairs, declared with the key type then the value type
* patients[101] = "name" adds a new entry or updates an existing one if the key already exists
* .find() works the same way as on a vector but is genuinely fast on a map, not a slow check every element search
* looping over a map with a range based for gives pairs, .first is the key and .second is the value
* a map keeps entries sorted by key automatically, without being asked to
* .erase(key) removes an entry by key
* useful any time a fast lookup by ID is needed, like looking up a patient record by patient ID rather than searching through every record

## Part 18: File I/O

* std::ofstream writes to a file, std::ifstream reads from one, both from <fstream>
* always check .is_open() before using a file, it fails silently otherwise
* file streams use << the same way std::cout does, just pointed at a file instead of the console
* std::getline reads one line at a time and returns false once the file runs out, which is why it works as a while loop condition
* always close a file when done, same idea as delete for heap memory
* useful for reading and writing CSV data directly

## Part 19: <random>

* Previously we've used rand() for generating random numbers, however this gives you no control over the distribution
* <random> lets you generate numbers from specific statistical distributions
* this is something we'll need when going onto model Brownian motion, monte carlo integration methods, or stochastic processes generally, for example the spread of disease in epidemiology
* a seed is the starting point a random number generator uses to produce its sequence, the same seed always produces the same sequence, std::random_device gets a genuinely random seed from the OS so the sequence differs each run
* std::mt19937 is the engine, the actual source of randomness once seeded, distributions like uniform_int_distribution or normal_distribution are applied on top of it

## Part 20: Function Templates

* template<typename T> lets one function work for multiple types, instead of writing a separate near identical function for int, double, string, etc
* T is just a placeholder name for whichever type is actually used, the compiler works this out automatically and generates the right version behind the scenes at compile time, costing nothing at runtime
* needed to actually understand syntax already being used since Part 5, std::vector<int> and std::normal_distribution<double> are themselves templates, <int> and <double> are just telling the compiler which type to generate

## Part 21: CMake and Updating CI

* CMake manages compiling multiple .cpp files together into one program, needed since real projects won't stay single-file like everything up to now
* a header file (.h) declares what exists, a .cpp file defines it, main.cpp only needs to see the header's declarations, not the other file's actual code
* CMakeLists.txt tells CMake which files to build into which executable, using add_executable
* Visual Studio can use CMakeLists.txt directly, enabling the actual green Run/Debug button and debugger for the first time, rather than manually compiling via the command line
* added a second job to the GitHub Actions workflow specifically to build the CMake project, alongside the existing job that compiles loose files, both now run and pass on every push
* YAML is strict about indentation.

## Part 22: CSV Analyser Project

* std::accumulate, from <numeric>, sums a range starting from a given value
* std::min_element and std::max_element return iterators, not values, so * is needed to dereference them
* combined file reading, stod, and vectors with these new stat functions to summarise scores.csv

### Debugging
* accidentally ran cl csv.analyser.cpp instead of csv_analyser.cpp, a dot instead of underscore
* this created a stray analyser.cpp file containing linker error text instead of real code, which got pushed
* CI caught it, build failed on push, details showed the real error
* deleted the stray file, pushed again, back to passing

## Part 23: Linear Algebra Basics

* dot product multiplies corresponding elements and sums the results
* matrix-vector multiply treats a matrix as a vector of vectors, each row, and each output value is that row's dot product with the vector
* const std::vector<double>& passes a vector by reference without copying it, while const stops the function from being able to modify it, the standard way to pass containers into a function in real C++
* std::vector<std::vector<double>> is the plain way to represent a matrix before something like Eigen is introduced later
* verified both results by hand, dot product gave 32, matrix multiply gave [13, 9].

## Part 24: Numerical Integration (Trapezoidal Rule)

* approximates the area under a curve by splitting it into thin trapezoids and summing their areas, instead of solving the integral analytically
* general formula for the trapezoidal rule over n intervals of width h:

$$\int_a^b f(x)\,dx \approx h \left[ \frac{f(a) + f(b)}{2} + \sum_{i=1}^{n-1} f(x_i) \right]$$

where $h = \frac{b-a}{n}$ and $x_i = a + i h$

* the first and last points count as half, every point in between counts as full, that's why the code adds `0.5 * (f(a) + f(b))` before looping through the rest
* std::function<double(double)> lets a function accept any function taking and returning a double, rather than hardcoding one formula
* lambdas, like [](double x) { return x * x; }, define a small anonymous function inline, useful for passing a quick function without writing a separate named one
* more intervals (n) means smaller trapezoids and a more accurate approximation, at the cost of more computation, shown directly by the 10-interval result being noticeably less accurate than the 1000-interval one

### Debugging
* M_PI is not standard C++, it's a compiler extension, and adding #define _USE_MATH_DEFINES before <cmath> still didn't work
* fixed by just hardcoding PI as a constant instead, simpler and more portable across compilers

## Part 25: Plotting Workflow (CSV Export + R)

* C++ has no easy native plotting, so the standard pattern is C++ computes and writes a CSV with clear column headers, then R or Python reads it and plots it
* std::ofstream writing a header row first, then x,y pairs per line, matches a normal CSV structure ready for read.csv in R
* this is the pattern I'll use in future projects, C++ for the heavy computation, R for the plotting and analysis
* tested the full pipeline end to end, C++ generated a sine wave, wrote it to sine_wave.csv, and R plotted it correctly, confirming the whole chain works
* saved the R script itself (plot_sine_wave.R) alongside the C++ file and CSV, so the example is fully reproducible

## Part 26: Eigen Library Setup 

* Eigen is a header-only C++ library for linear algebra, no separate compiled library needed, just point the compiler at the folder containing the Eigen headers
* Eigen::Matrix3d and Eigen::Vector3d replace the vector<vector<double>> approach from Part 23, with * doing actual matrix-vector multiplication in one line instead of a manual loop
* .inverse() computes a matrix inverse, something genuinely painful to implement by hand, exactly why a library like this exists
* checked the matrix-vector multiply result by hand against Part 23's logic, matched correctly

### Debugging: Eigen alignment failure
* first compile ran fine but eigen_test.exe crashed with an assertion failure about scalar alignment
* caused by compiling in 32-bit mode (x86), Eigen's fixed-size types need specific memory alignment that 32-bit builds don't guarantee
* fixed by switching to the x64 Native Tools Command Prompt instead of the regular Developer Command Prompt, compiling for 64-bit removes the issue entirely

### Debugging: CI failure after adding Eigen
* pushing eigen_test.cpp broke the GitHub Actions build check, since the CI runner has no knowledge of Eigen or where it's installed locally
* fixed by adding an install step to build.yml (sudo apt-get install libeigen3-dev) and adding -I /usr/include/eigen3 to the compile command
