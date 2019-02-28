#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
    char* res = icmpcode_v4(5);
    char *message = "test1 failed: icmpcode_v4(5) should return \"source route failed\"";
    mu_assert(message, !strcmp("source route failed", res));
    return NULL;
}

static char *test2() {
    char* res = icmpcode_v4(7);
    char *message = "test2 failed: icmpcode_v4(7) should return \"destination host unknown\"";
    mu_assert(message, !strcmp("destination host unknown", res));
    return NULL;
}

static char *test3() {
    char* res = icmpcode_v4(13);
    char *message = "test3 failed: icmpcode_v4(13) should return \"communication administratively prohibited by filtering\"";
    mu_assert(message, !strcmp("communication administratively prohibited by filtering", res));
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}