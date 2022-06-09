#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <algorithm>
using namespace std;
#define N 30
#define MIN_SD 1
#define MAX_SD 5

//given struct of a customer information
struct Customer_Info {
	int customer_number;
	int arrive_time;
	int service_duration;
};

Customer_Info customers[N]; //array of customer infos

int customNUM = 1;


int main() {

	queue < Customer_Info > Q ; //the queue of customers
	
	srand(time(0)); //to work random functions properly
	
	printf("SIMULATION LOOP STARTED. \n \n");
	
	for (int sim_time=0; sim_time<=N; sim_time++) {
		
		//deside if customer comes or not
		int customer_comes = rand()%2; 
		// printf("%d \n", customer_comes); 
		
		if (customer_comes==0) {
			//no customer comes at this loop
		}
		if (customer_comes==1) {
			//a customer arrives at that loop
			
			//generate a new customer info
			customers[sim_time].arrive_time = sim_time;
			customers[sim_time].customer_number = customNUM;
			customers[sim_time].service_duration = ( rand() % MAX_SD ) + MIN_SD ;
			
			printf("TIME %d : Customer %d arrived. \n", sim_time, customNUM);
			
			//put this customer to queue
			Q.push( customers[sim_time] );
			
			customNUM++;
		}
		
		//Check if there is a departure
		if ( Q.size() != 0 ) { //if there are customers in the queue
			//if service duration of the first customer in line is finished
			if ( ( Q.front().arrive_time + Q.front().service_duration ) <= sim_time ) {
			
				
				printf("TIME %d : Customer %d departed. Service duration : %d \n", sim_time, Q.front().customer_number, Q.front().service_duration);
				
				Q.pop(); //customer departures		
			}
			
		}
		
	}
	
	printf("\nSIMULATION LOOP FINISHED. \n");
	printf("REMOVING REST OF THE CUSTOMERS FROM QUEUE. \n");
	
	int sim_time=31;
	
	//remove all remained customers in the queue
	while ( Q.size() != 0 ) {
		
		if ( ( Q.front().arrive_time + Q.front().service_duration ) <= sim_time ) {
		
		printf("TIME %d : Customer %d departed. Service duration : %d \n", sim_time, Q.front().customer_number, Q.front().service_duration);
		
		Q.pop(); 
		
		}
		
		sim_time++;
	}
	
	printf("\nPROGRAM ENDED.\n");
}

