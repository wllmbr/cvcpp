#ifdef __x86_64__
/* Test setup on x86 Linux Platform */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "matrix_test.h"

int main(void){

	struct timespec start, stop;

	printf("Starting Linux Matrix Test\n");

	uint64_t int_delta;
	uint32_t loop_count, internal_count;
	loop_count = 3600000000;

	configure_test();

	/* Begin Test */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	internal_count = execute_matrix_test(loop_count);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

	int_delta = (stop.tv_nsec + (stop.tv_sec * 1000000000)) - 
						(start.tv_nsec + (start.tv_sec * 1000000000));


	double delta, average_time;
	delta = (double)int_delta;
	average_time = delta / ( loop_count * internal_count);

	printf("Test took %12.3f s\n", delta/1000000000);
	printf("Iteration Average: %12.3f ns\n", average_time);

	display_results();

	printf("Exiting RTEMS Timing Test\n");
	fflush(stdout);

	return 0;
}

#endif
