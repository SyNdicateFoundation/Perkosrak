#include "CUtils.h"
#include "logger.h"
#include<math.h>

void dos(void* index) {
    if (index == NULL)
        throw();

    info("RUN", (char *) index);
}
float colonCalc(float Q1, float Q2, float R){
    return (9* pow(10, 9)) * ((Q1 * Q2) / (R * R));
}
int main() {
   /* char strings[][maxStringLength] = {
            "privet\n",
            "test\n",
            "test2\n"
    };
    int i = 1;

    for(printf("hi\n"); i == 1;
    i = 0, printf("done\n")){

    }

    foreachstring(NULL, sizeof(strings) / sizeof(strings[0]), dos);*/

   printf("%f", colonCalc(3,-6, 30));


    return 0;
}

float colonCalcwithQs(float Q1, float Q2){

}