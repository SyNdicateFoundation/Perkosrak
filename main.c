#include "cutils.h"
#include "logger.h"
#include "dynamicarray.h"
#include "garbagecollector.h"

/*void dos(void* index) {
    if (index == NULL)
        throw();

    info("RUN", (char *) index);
}*/

int main() {
/* c(array(array, ), )har strings[][maxStringLength] = {
            "privet\n",
            "test\n",
            "test2\n"
    };
    int i = 1;

    for(printf("hi\n"); i == 1;
    i = 0, printf("done\n")){

    }

    foreachstring(NULL, sizeof(strings) / sizeof(strings[0]), dos);*/
    allocate(sizeof(int));
    allocate(sizeof(int));

    gc_call();
    return 0;
}