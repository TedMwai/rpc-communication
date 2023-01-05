#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msg.h"

/*
 * Procedure 1 accepts an integer and returns an integer.
 */
int *proc1_1_svc(int *argp, struct svc_req *rqstp)
{
    static int result;
    printf("Received request for procedure 1 with argument %d\n", *argp);
    result = *argp * *argp; // Square the argument
    return &result;
}

/*
 * Procedure 2 accepts a structure and returns a float.
 */
float *proc2_1_svc(parameter *argp, struct svc_req *rqstp)
{
    static float result;
    printf("Received request for procedure 2 with arguments %d and %c\n", argp->x, *argp->y);
    result = (float)argp->x / atof(argp->y); // convert the string and int to a float and divide them
    return &result;
}

/*
 * Procedure 3 accepts an integer and returns a string.
 */
char **proc3_1_svc(int *argp, struct svc_req *rqstp)
{
    static char result[16];
    printf("Received request for procedure 3 with argument %d\n", *argp);
    sprintf(result, "Result: %d", *argp * 3); // Perform some operation on the argument
    return &result;
}
