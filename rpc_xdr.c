/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rpc.h"

bool_t
xdr_proc_2_1_argument (XDR *xdrs, proc_2_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->x, ~0))
		 return FALSE;
	return TRUE;
}
