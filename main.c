#include "cutils.h"
void test (lambda x){
    printf("yes no\n");
    void* t = (void *) 2;
    x(t);
}
void yesno(void*){
    printf("no?\n");
}
MAINARG
    def(int, x, 1);
    printf("%d\n", x);
    test(yesno);
ENDMAIN
