#ifndef __x86_64__

/* System Entry Point for RTEMS Platform */

#include <rtems.h>
#include <stdint.h>
#include <stdio.h>
#include "matrix_test.h"


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


#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_INIT
#include <rtems/confdefs.h>

rtems_task Init(rtems_task_argument argument){
	printf("Starting RTEMS Timing Test\n");

	uint64_t start, stop, int_delta;
	uint32_t loop_count, internal_count;
	loop_count = 10000;

	configure_test();

	/* Begin Test */
	start = rtems_clock_get_uptime_nanoseconds();
	internal_count = execute_matrix_test(loop_count);
	stop = rtems_clock_get_uptime_nanoseconds();

	int_delta = stop - start;
	double delta, average_time;
	delta = (double)int_delta;
	average_time = delta / ( loop_count * internal_count);

	printf("Test took %12.3f s\n", delta/1000000000);
	printf("Iteration Average: %12.3f ns\n", average_time);

	printf("Exiting RTEMS Timing Test\n");
	fflush(stdout);
	exit(0);

}

#endif