#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpc.h"
#include "string.h"

int *proc1_1(int, CLIENT *);
char *proc2_1(char *, CLIENT *);
float *proc3_1(char *, float, CLIENT *);

int main(int argc, char *argv[])
{
    printf("Client started\n");
    CLIENT *cl;
    int param1 = 25;
    char *param2 = "Glitch";
    float param3 = 3.14;
    char *param4 = "3.14";

    /* Create a client handle for the server */
    cl = clnt_create(argv[1], MYPROG, MYVERS, "tcp");
    if (cl == NULL)
    {
        printf("error: could not connect to server.\n");
        exit(1);
    }

    /* Call procedure 1 */
    int procOneResult = *proc1_1(param1, cl);
    printf("Result from procedure 1: %d\n", procOneResult);

    /* Call procedure 2 */
    char *procTwoResult = proc2_1(param2, cl);
    printf("Result from procedure 2: %s\n", procTwoResult);

    /* Call procedure 3 */
    float procThreeResult = *proc3_1(param4, param3, cl);
    printf("Result from procedure 3: %f\n", procThreeResult);

    /* Clean up and exit */
    clnt_destroy(cl);
    return 0;
}