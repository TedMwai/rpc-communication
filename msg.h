/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _MSG_H_RPCGEN
#define _MSG_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct parameter {
	int x;
	char *y;
};
typedef struct parameter parameter;

#define MYPROG 0x20000001
#define MYVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define PROC1 1
extern  int * proc1_1(int *, CLIENT *);
extern  int * proc1_1_svc(int *, struct svc_req *);
#define PROC2 2
extern  float * proc2_1(parameter *, CLIENT *);
extern  float * proc2_1_svc(parameter *, struct svc_req *);
#define PROC3 3
extern  char ** proc3_1(int *, CLIENT *);
extern  char ** proc3_1_svc(int *, struct svc_req *);
extern int myprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define PROC1 1
extern  int * proc1_1();
extern  int * proc1_1_svc();
#define PROC2 2
extern  float * proc2_1();
extern  float * proc2_1_svc();
#define PROC3 3
extern  char ** proc3_1();
extern  char ** proc3_1_svc();
extern int myprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_parameter (XDR *, parameter*);

#else /* K&R C */
extern bool_t xdr_parameter ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_MSG_H_RPCGEN */
