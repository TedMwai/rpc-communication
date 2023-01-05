struct parameter {
    int x;
    string y<>;
};

program MYPROG {
    version MYVERS {
        int PROC1(int) = 1;
        float PROC2(parameter) = 2;  
        string PROC3(int *x) = 3;
    } = 1;
} = 0x20000001;