# RPC PROJECT
This is a project for the course of Distributed Systems at the University of Nairobi. 
It is an implementation of a simple RPC system in C. The project is based on the [RPCGEN] tool.
It involves 3 procedures:
### Procedure 1
This procedure takes in an integer and returns an integer.
### Procedure 2
This procedure takes in struct made up of an integer and string then it returns a floating point number
### Procedure 3
This procedure takes in a integer by reference and returns a string. 

## Requirements
* [RPCGEN] - RPCGEN is a tool that generates C code from a RPC specification.
* [GNU Make] - GNU Make is a tool which controls the generation of executables and other non-source files of a program from the program's source files.

## How to run
1. Clone the repository
2. Run the following commands
```sh
$ cd rpc
$ rpcgen msg.x
$ make
$ ./server
```
3. Open another terminal and run the following commands
```sh
$ cd rpc
$ ./client localhost
```