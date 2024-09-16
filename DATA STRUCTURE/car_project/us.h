#ifndef us.h
#define us.h
enum
{
    us_busy
}us_state_id;

void (*us_function)();
int generateRandomNumber(int x, int y);
void us_busy_state();
void us_idle_state();

#endif // us.h

