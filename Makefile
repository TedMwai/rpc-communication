.SUFFIXES:
.SUFFIXES: .c .o
CLNT = client
SRVR = server
CFLAGS = -g -Wall

SRVR_OBJ = server.o rpc_xdr.o rpc_svc.o
CLNT_OBJ = client.o rpc_xdr.o rpc_clnt.o

.c.o:; gcc -c -o $@ $(CFLAGS) $<

default: $(CLNT) $(SRVR)

$(CLNT): $(CLNT_OBJ) rpc.h
	gcc -o $(CLNT) $(CLNT_OBJ)

$(SRVR): $(SRVR_OBJ) rpc.h
	gcc -o $(SRVR) $(SRVR_OBJ)

clean:
	rm *.o $(CLNT) $(SRVR)
	rm -i *~
	rm core
