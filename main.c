#include <stdio.h>
#include "stdpragma.h"

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

