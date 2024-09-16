#ifndef ca.h
#define ca.h
enum
{
    ca_waiting,
    ca_driving
}ca_state_id;

void ca_waiting_state();
void ca_driving_state();

void (*ca_function)();
#endif // ca
