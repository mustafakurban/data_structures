/*Dining philosophers problem */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>

//shared parameters(allocate stack)
int access_permission = 1;
int chopstick[] = {1,1,1,1,1};

struct philosopher
{
	int state;
	//left and right hand definitions, if value = 0 it means no stick in that hand
	int left_hand;
	int right_hand;
	//hungry or full? if value = 0 it means philosopher are hungry
	int hof;
};


void * eat(struct philosopher * phl_obj)
{
	while(1){

		if(phl_obj -> hof == 0)
		{
			if(access_permission == 1)
			{	
				int i = phl_obj-> state;
				access_permission = 0;

				
				//get chopsstick
				phl_obj -> left_hand  = chopstick[i];
				phl_obj -> right_hand = chopstick[(i+1)%5];
				chopstick[i] 		  = 0;
				chopstick[i+1]		  = 0;

				if(phl_obj->left_hand && phl_obj->right_hand){

					phl_obj-> hof = 1;
					printf("%d %s\n",phl_obj->state,"eating");

					phl_obj -> left_hand  = 0;
					phl_obj -> right_hand = 0;

					//giv back all
					chopstick[i] 		  = 1;
					chopstick[(i+1)%5]	  = 1;
					access_permission 	  = 1;

				}					
			

			}	

		}
		
		//*************************************************************
		if(phl_obj -> hof == 0)
		{
			printf("My name is %d and i am hungry\n",phl_obj -> state);
		}
		if(phl_obj -> hof == 1)
		{
			printf("My name is %d and i am full :)\n",phl_obj -> state);
		}
		
		sleep(1);
	}
	
}
void create_philosopher(struct philosopher * phl_obj,int state)
{
	phl_obj-> state 	 		= state;
	phl_obj-> left_hand  		= 0;
	phl_obj-> right_hand		= 0;
	phl_obj-> hof				= 0;
}

int main(int argc, char const *argv[])
{

	pthread_t thread_id;


	struct philosopher * philosopher_list;
	philosopher_list = (struct philosopher*)malloc(5 * sizeof(struct philosopher));
	
	for(int i = 0;i < 5;i++)
	{
		//set default parameters at struct 
		create_philosopher(&philosopher_list[i],i);
		//call thread func
	    pthread_create(&thread_id, NULL, eat,(struct philosopher *)&philosopher_list[i]);
		
	}

	pthread_exit(NULL);
	return 0;
}
