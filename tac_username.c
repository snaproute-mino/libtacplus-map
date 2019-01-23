#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "map_tacplus_user.h"

void usage() {
        printf("USAGE: tac_username <localname>");
}

int main (int argc, char **argv) {
        char *name;

        if (argc < 2) {
                usage();
                return -1;
        }

        name = lookup_logname(argv[1], -1, -1, NULL, NULL);
        if (name == NULL) {
                return -1;
        }

        printf("%s\n", name);

        /* lookup_logname allocates string only if username is different */
        if (strcmp(name, argv[1]))
                free(name);

        return 0;
}

