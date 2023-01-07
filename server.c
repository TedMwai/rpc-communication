#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpc.h"

/*
 * Procedure 1 accepts an integer and returns an integer.
 */
int * proc1_1_svc(int argp , struct svc_req *rqstp)
{
    static int result;
    printf("Received request for procedure 1 with argument %d\n", argp);
    result = argp * argp; // Square the argument
    return &result;
}

/*
 * Procedure 2 accepts a string and returns a string.
 */
char *proc2_1_svc(char *argp, struct svc_req *rqstp)
{
    static char result[150];
    printf("Received request to execute Procedure 2 with argument %s\n", argp);
    sprintf(result, "Hello, %s!", argp);
    // strcat(result, argp);
    return result;
}
/*
 * Procedure 3 accepts a string and float and returns a float.
 */
float *proc3_1_svc(char *argp, float arg2, struct svc_req *rqstp)
{
    static float result;
    printf("Received request for procedure 3 with argument %s and %f\n", argp, arg2);
    result = arg2 * atof(argp);
    return &result;
}
