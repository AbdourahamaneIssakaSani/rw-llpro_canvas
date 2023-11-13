/**
* Q2.
*  You have an array of 100 elements which are required to be summed up
* together while observing the system performance. In order to maximize
* the performance, your program will have 2 threads that are dividing the
* array into two halves such that one thread handles one half and then the
* second thread handles the remaining halve concurrently.
*
* Tasks to be completed
* Each thread will take part of the array and add all elements in it.
* The values computed by both threads will be added together to print
* the sum of the entire array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>


#define ARRAY_SIZE 100
#define NUM_THREADS 2

int array[ARRAY_SIZE];

/**
* sum_run - thread function
* @arg: argument
* Return: void
*/
void *sum_run(void *arg)
{
	int index = *(int *)arg;

	int segment = ARRAY_SIZE / NUM_THREADS;

	int sum = 0;

	for (int i = index * segment; i < (index + 1) * segment; i++)

	{

		sum += array[i];
	}

	printf("Sum of segment %d is %d\n", index + 1, sum);

	return ((void *)(intptr_t)sum);
}

/**
* main - entry point
* @argc: argument count
* @argv: argument vector
* Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int main(int argc, char **argv)
{
	pthread_t tid[NUM_THREADS];

	int final_sum = 0;

	int thread_index[NUM_THREADS];

	for (int i = 0; i < ARRAY_SIZE; i++)

	{

		array[i] = rand() % 100;
	}

	for (int i = 0; i < NUM_THREADS; i++)

	{

		thread_index[i] = i;
		pthread_create(&tid[i], NULL, sum_run, &thread_index[i]);
	}

	void *thread_sum_ptr;

	/*wait until the thread is doing its work*/
	for (int i = 0; i < NUM_THREADS; i++)

	{

		pthread_join(tid[i], &thread_sum_ptr);
		int thread_sum = (int)(intptr_t)thread_sum_ptr;

		final_sum += thread_sum;
	}

	printf("The sum is %d\n", final_sum);

	return (0);
}
