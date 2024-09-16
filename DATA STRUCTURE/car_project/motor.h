#ifndef motor.h
#define motor.h
enum
{
    motor_idle,
    motor_busy
}motor_state_id;
void motor_init_state();
void motor_idle_state();
void motor_busy_state();
void (*motor_function)();

#endif // motor.h


