#include <stdio.h>

int main() {
    // const test 1: const variable
    int x = 1;
    x = 2; // modify x is ok
    printf("first modify x: %d\n", x);

    const int y = 1;
    // compile error: try to modify y
    //y = 2;

    // Test2: const with pointer
    const int *p1 = &x; //data is const, pointer is not const
    // 2.1 data is const, data is pointed by pointer is const
    //(*p1)++;  // compile error, try to modify const data
    //*p1 = 2;  // compile error, try to assign to const data
    printf("%d\n", *p1); //print x: 2;

    int z = 3;
    // change pointer p1 point to different value
    p1 = &z;
    printf("%d\n", *p1); //print z: 3;
    //(*p1)++;  // compile error, try to modify const data
    //*p1 = 30;  // compile error, try to assign to const data

    // Test2.1 
    x = 20;
    z = 30;
    // still can modify x and z by variable name, since they are not declared as const variable.
    printf("still can modify x with name: %d\n", x);
    printf("still can modify z with name: %d\n", z);

    // compile error assign a `const int *` to `int *`
    //int *p2 = p1;

    // change z value by a `non const int *`
    int *p3 = &z;
    *p3 = 300;
    printf("modify z with another non const int pointer: %d\n", z);

    // test 2.2 const variable with non-const pointer
    const int a = 5;
    //int *p5 = &a;
    const int *p6 = &a;

    // test 2.3 pointer is const, data is not

    // test 2.3.1
    // compile error: cannot initialize a variable of type
    // 'int *const' with an rvalue of type 'const int *'
    //int * const p7 = &a;
    int * const p8 = &x;
    (*p8)++;
    printf("modify x with int * const pointer p8: %d\n", x);
    *p8 = 200;
    printf("modify x with int * const pointer p8: %d\n", x);

    // test 2.3.2: const pointer cannot be modified to point to another varibale
    int b = 8;
    //p8 = &b; // compile error


    // test 2.4 data and pointer are both const
    //const int* const p9; // compile error, have to be initialized to some value, since
    const int d = 10;
    const int* const p9 = &d;
}