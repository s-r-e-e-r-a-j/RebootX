// Developer: Sreeraj
// GitHub: https://github.com/s-r-e-e-r-a-j

#ifndef REBOOTX_H
#define REBOOTX_H

void log_action(const char *msg);
void send_msg(const char *msg);
void delay_reboot(int sec);
void do_reboot(int force, int safe);
void ask_confirm();

#endif
