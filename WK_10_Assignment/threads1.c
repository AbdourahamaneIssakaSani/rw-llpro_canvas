/**
* Q1.
* Sam has installed one big green house which was divided into four sections.
* The intention to optimize resources in a sense that environmental and water
* management are happening only in the required section instead of unneeded controls
* that may waste some resources.
*
* In each section Sam is using 3 sensors which are temperature, humidity and soil moisture.
* Sam is designing one node with the three sensors for each section, the three values returned
* in each section will be consolidated in one structure such that values for all sections are
* presented on Sam's big screen.
*
* Tasks to be completed:
* Write a C program that will be using threads to complete the work.
* Collecting data for each section will be handled by a respective thread but all threads will be
* running concurrently.
*
* Your program will display values returned from different sections of the green house in the following format:
*
* Section 1. Temp:[value], Hum: [value], Soil Mois:[value]
* Section 2. Temp:[value], Hum: [value], Soil Mois:[value]
* Section 3. Temp:[value], Hum: [value], Soil Mois:[value]
* Section 4. Temp:[value], Hum: [value], Soil Mois:[value]
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUM_SECTIONS 4
#define NUM_SENSORS 3

/**
* struct sensor_data - sensor data
* @temp: temperature
* @hum: humidity
* @soil_moisture: soil moisture
*/
typedef struct sensor_data
{
	int temp;

	int hum;

	int soil_moisture;

} sensor_data_t;

sensor_data_t sensor_data_array[NUM_SECTIONS];

/**
* sensor_run - thread function
* @arg: argument
* Return: void
*/
void *sensor_run(void *arg)
{
	int section = *(int *)arg;

	sensor_data_array[section].temp = rand() % 51;
	sensor_data_array[section].hum = rand() % 101;
	sensor_data_array[section].soil_moisture = rand() % 1024;

	printf("Section %d. Temp: %d, Hum: %d, Soil Mois: %d\n",
		section + 1, sensor_data_array[section].temp,
		sensor_data_array[section].hum, sensor_data_array[section].soil_moisture);

	pthread_exit(0);
}

/**
* main - entry point
* @argc: number of arguments
* @argv: array of arguments
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	pthread_t tid[NUM_SECTIONS];

	for (int i = 0; i < NUM_SECTIONS; i++)
	{
		int *section = malloc(sizeof(int));

		*section = i;
		pthread_create(&tid[i], NULL, sensor_run, section);
	}

	/*wait until the thread is doing its work*/
	for (int i = 0; i < NUM_SECTIONS; i++)
	{
		pthread_join(tid[i], NULL);
	}

	return (0);
}
