#ifndef __x86_64__
#ifndef SYSTEM_H
#define SYSTEM_H

#include <rtems.h>

// Allows the system to use the low level clock and the main console
// Console binds to RPi UART Port (8N1-115200)
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
// Enables the high accuracy clock
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
// Needed for Rate Monotonic
#define CONFIGURE_MICROSECONDS_PER_TICK     100
// How often we switch between tasks
#define CONFIGURE_TICKS_PER_TIMESLICE       1
// Maximum number of RTEMS type tasks
#define CONFIGURE_MAXIMUM_TASKS             100
// Maximum number of RTEMS rate monotonic
#define CONFIGURE_MAXIMUM_PERIODS           100
// Number of user established drivers to be loaded
#define CONFIGURE_MAXIMUM_DRIVERS           10
// Number of allowable timers
#define CONFIGURE_MAXIMUM_TIMERS            10
// Number of allowable barriers
#define CONFIGURE_MAXIMUM_BARRIERS          10
// Configures file system for file access
#define CONFIGURE_USE_IMFS_AS_BASE_FILESYSTEM
#define CONFIGURE_LIBIO_MAXIMUM_FILE_DESCRIPTORS 100
// Semaphore count
#define CONFIGURE_MAXIMUM_SEMAPHORES 3
// Task memory footprint
#define CONFIGURE_INIT_TASK_STACK_SIZE (64 * 1024)

// I don't know what these are exactly for...
#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_INIT
// The example files showed this at the end of the file...
// Don't know why its here, but I'm leaving it
#include <rtems/confdefs.h>

#endif
#endif