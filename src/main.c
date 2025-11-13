// Developer: Sreeraj
// GitHub: https://github.com/s-r-e-e-r-a-j

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/rebootx.h"

int main(int argc, char *argv[]) {
    int force = 0, safe = 0, delay = 0;
    char *msg = NULL;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--help")) {
            printf("Usage: rebootx [--force] [--safe] [--delay <sec>] [--msg <text>]\n\n");
            printf("Options:\n");
            printf("  --safe         Perform a safe reboot by syncing and unmounting file systems.\n");
            printf("  --force        Force an immediate reboot without confirmation.\n");
            printf("  --delay <sec>  Wait specified seconds before rebooting.\n");
            printf("  --msg <text>   Broadcast a message to logged-in users.\n");
            printf("\nWithout options, prompts for confirmation before rebooting.\n");
            return 0;
        } 
        else if (!strcmp(argv[i], "--force")) force = 1;
        else if (!strcmp(argv[i], "--safe")) safe = 1;
        else if (!strcmp(argv[i], "--delay") && i + 1 < argc) delay = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--msg") && i + 1 < argc) msg = argv[++i];
        else {
            printf("Usage: rebootx [--force] [--safe] [--delay <sec>] [--msg <text>]\n");
            return 0;
        }
    }

    if (getuid() != 0) {
        printf("Run as root.\n");
        return 1;
    }

    if (msg) {
       send_msg(msg);
       if (delay == 0) {
          printf("Waiting 5 seconds for message delivery...\n");
          sleep(5);
       }
    }

    if (delay > 0) delay_reboot(delay);

    if (force) {
        log_action("Force reboot executed");
        do_reboot(1, safe);
    } else if (safe) {
        log_action("Safe reboot executed");
        do_reboot(0, 1);
    } else {
        ask_confirm();
    }

    return 0;
}
