// Developer: Sreeraj
// GitHub: https://github.com/s-r-e-e-r-a-j

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/reboot.h>
#include <linux/reboot.h>
#include <sys/mount.h>
#include "../include/rebootx.h"

void do_reboot(int force, int safe) {
    sync();
    if (safe) {
        system("umount -a >/dev/null 2>&1");
    }
    if (!force) {
        printf("Rebooting system now...\n");
    }
    if (reboot(LINUX_REBOOT_CMD_RESTART) != 0) {
        perror("reboot");
        exit(1);
    }
}

void ask_confirm() {
    char c;
    printf("Confirm reboot (y/n): ");
    scanf(" %c", &c);
    if (c == 'y' || c == 'Y') {
        do_reboot(0, 0);
    } else {
        printf("Aborted.\n");
        exit(0);
    }
}
