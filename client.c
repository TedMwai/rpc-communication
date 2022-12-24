#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msg.h"

/*
 * Declare the client-side function prototypes for the remote
 * procedures. These prototypes are generated by RPCGen.
 */
int * proc1_1(int *, CLIENT *);
float * proc2_1(int *, CLIENT *);
char ** proc3_1(int *, CLIENT *);

int main(int argc, char *argv[])
{
    printf("Client started\n");
    CLIENT *cl;
    int result_int;
    float result_float;
    char *result_string;
    int arg1 = 5;
    int arg2 = 10;
    int arg3 = 15;
    int *argp1 = &arg1;

    /* Create a client handle for the server */
    cl = clnt_create(argv[1], MYPROG, MYVERS, "tcp");
    if (cl == NULL)
    {
        printf("error: could not connect to server.\n");
        exit(1);
    }

    /* Call procedure 1 */
    result_int = *proc1_1(argp1, cl);
    printf("Result from procedure 1: %d\n", result_int);

    /* Call procedure 2 */
    result_float = *proc2_1(&arg2, cl);
    printf("Result from procedure 2: %f\n", result_float);

    /* Call procedure 3 */
    result_string = *proc3_1(&arg3, cl);
    printf("Result from procedure 3: %s\n", result_string);

    /* Clean up and exit */
    clnt_destroy(cl);
    return 0;
}
