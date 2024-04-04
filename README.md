
# stdpragma.h - Custom Header for Pragma Directives in GCC Compiler

This repository contains a custom header file named stdpragma.h that enables fundamental usage of #pragma directives in C programs, specifically tailored for the GCC compiler. If you're looking to leverage #pragma directives such as #pragma startup and #pragma exit, this header file simplifies their usage and integration into your codebase.



## Getting Started

### Deployment
To use stdpragma.h in your project, follow these simple steps:

1. Clone the Repository:
```bash
    git clone https://github.com/devbyaryanvala/custom_stdpragma_header.git
```
2. Copy the Header File:

Copy the stdpragma.h file into your project directory.

3. Include the Header File:

In your C source files, include the custom header file at the beginning:

```c
    #include "stdpragma.h"
```
3. Syntex

pragma_startup syntax:

```c
    pragma_startup(priority number, function name){
        function content
    }
```
pragma_exit syntax:

```c
    pragma_exits(priority number, function name){
        function content
    }
```
### Example
Here's an example demonstrating the usage of stdpragma.h:
```c
#include <stdio.h>
#include "stdpragma.h"

//the first word "pragma_startup" is a function created to execute the ud function at the 2nd priority (as the number 2 before coma denotes) then we have called the fucntion which should be executed as per their priority.
//same rule is applied on "pragma_exit".
 
pragma_startup(2, startup_func1) {
    printf("Startup function 1 called.\n");
}

pragma_startup(1, startup_func2) {
    printf("Startup function 2 called.\n");
}

pragma_exit(2, exit_func1) {
    printf("Exit function 1 called.\n");
}

pragma_exit(1, exit_func2) {
    printf("Exit function 2 called.\n");
}

int main() {
    printf("Main function called.\n");
    return 0;
}
```
In this example, startup_func1 will be executed before startup_func2 due to their priorities (2 and 1, respectively). Similarly, exit_func1 will be executed before exit_func2 at program exit.

The same above program can be found as main.c in this repo!

## Contribution

Contributions are welcome! If you encounter any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

###

Feel free to customize the content further to suit your preferences and provide more detailed explanations if needed.



