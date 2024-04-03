#ifndef STARTUP_EXIT_H
#define STARTUP_EXIT_H

#include <stdlib.h>

#define MAX_STARTUP_FUNCS 10
#define MAX_EXIT_FUNCS 10

//structure to contain function pointers and their priorities
typedef struct {
    void (*func)();
    int priority;
} FuncInfo;

//array to hold startup functions and their priorities
static FuncInfo startup_funcs[MAX_STARTUP_FUNCS];
static int startup_count = 0;

static FuncInfo exit_funcs[MAX_EXIT_FUNCS];
static int exit_count = 0;


#define pragma_startup(priority, func) \
    _Pragma("startup") \
    __attribute__((constructor(priority))) \
    static void func##_startup()


#define pragma_exit(priority, func) \
    _Pragma("exit") \
    __attribute__((destructor(priority))) \
    static void func##_exit()

//register a startup function
static void register_startup(void (*func)(), int priority) {
    if (startup_count < MAX_STARTUP_FUNCS) {
        startup_funcs[startup_count].func = func;
        startup_funcs[startup_count].priority = priority;
        startup_count++;
    }
}

//register an exit function
static void register_exit(void (*func)(), int priority) {
    if (exit_count < MAX_EXIT_FUNCS) {
        exit_funcs[exit_count].func = func;
        exit_funcs[exit_count].priority = priority;
        exit_count++;
    }
}

//startup function to call all registered startup functions
static void call_startup_functions() {
    int i, j;
    //bubble sort the startup functions based on priority
    for (i = 0; i < startup_count - 1; i++) {
        for (j = 0; j < startup_count - i - 1; j++) {
            if (startup_funcs[j].priority > startup_funcs[j + 1].priority) {
                FuncInfo temp = startup_funcs[j];
                startup_funcs[j] = startup_funcs[j + 1];
                startup_funcs[j + 1] = temp;
            }
        }
    }
    //call the sorted startup functions
    for (i = 0; i < startup_count; i++) {
        startup_funcs[i].func();
    }
}

//exit function to call all registered exit functions
static void call_exit_functions() {
    int i, j;
    //bubble sort the exit functions based on priority
    for (i = 0; i < exit_count - 1; i++) {
        for (j = 0; j < exit_count - i - 1; j++) {
            if (exit_funcs[j].priority > exit_funcs[j + 1].priority) {
                FuncInfo temp = exit_funcs[j];
                exit_funcs[j] = exit_funcs[j + 1];
                exit_funcs[j + 1] = temp;
            }
        }
    }
    //call the sorted exit functions
    for (i = 0; i < exit_count; i++) {
        exit_funcs[i].func();
    }
}

#endif //STARTUP_EXIT_H

