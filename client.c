#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msg.h"

/*
 * Client-side function prototypes for the remote procedures.
 */
int * proc1_1(int *, CLIENT *);
float * proc2_1(parameter *, CLIENT *);
char ** proc3_1(int *, CLIENT *);

int main(int argc, char *argv[])
{
    printf("Client started\n");
    CLIENT *cl;
    int param1 = 25;
    parameter param2;
    param2.x = 15;
    param2.y = "2.5";
    int param3 = 7;

    /* Create a client handle for the server */
    cl = clnt_create(argv[1], MYPROG, MYVERS, "tcp");
    if (cl == NULL)
    {
        printf("error: could not connect to server.\n");
        exit(1);
    }

    /* Call procedure 1 */
    int procOneResult = *proc1_1(&param1, cl);
    printf("Result from procedure 1: %d\n", procOneResult);

    /* Call procedure 2 */
    float procTwoResult = *proc2_1(&param2, cl);
    printf("Result from procedure 2: %f\n", procTwoResult);

    /* Call procedure 3 */
    char* result_string = *proc3_1(&param3, cl);
    printf("Result from procedure 3: %s\n", result_string);

    /* Clean up and exit */
    clnt_destroy(cl);
    return 0;
}
