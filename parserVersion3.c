//Imtiaz Rayman 
//multi processes (single thread) program

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

int fileParser(char* myWord[] );

void *entry_point(void *value)
{
	printf("\nHello from the second thread\n");

	int *num = (int *) value;

	printf("The value of value is %d" , *num);
	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t thread;
	// pthread create takes a reference to your pthread, pthread attributes, 
	//function which will be function which will be the entry point for the thread ,
	// and a reference to a value u want to insert into the thread;
	int num = 123;
	printf("\nFirst Thread");

 char* space = "\n ";
      char* myWord=NULL;  
      //char* argv [1000]; 
      char buffer[1000]; 
      int returnValue = 0;
      bool pickup = false;  
      bool dropoff = false;


      // yellow_tripdata_2019-12.csv pickup_id dropoff_id 
      // yellow_tripdata_2019-12.csv 200 123

    while(1)
    {
       printf("\n<<<<<<<<<<<<File Parser>>>>>>>>>>>>\nMulti processes (Single Thread) Version #2\n");
       printf("Program must be invoked in the sequence of:\nfileName.csv pickup_id dropoff_id\n");
       printf("Enter <Exit> or <CTRL + C> TO QUIT\nExample: yellow_tripdata_2019-12.csv 161 237\nEnter >"); 
       
       fgets(buffer, 1000, stdin);
          int i = 0; 
 
          for (myWord = strtok(buffer, space); myWord; myWord = strtok(NULL, space)) 
          {
            argv[i] = myWord;
            i++;
          }
          //And example run would be
          //./compute files.txt 10 20

      char buf[1024];
      int row_count = 0;
      int field_count = 0;
      char * field = NULL;
      int pickupcount = 0;
      int dropoffcount = 0;  
      //int returnvalue = 0;
      int total = 0; 

     
           if(strcmp(argv[0],"Exit") == 0)
           { 
            printf("Exit has been Entered, Program Exiting...\n"); 
            break; 
           } 
            total = fileParser(argv);

            printf("\n<<<<<<Output>>>>>>\nIDs Entered : %s to %s\nPick-up ID Entered : %s\nDropOff Id Entered : %s\nNumber Of Pickups at %s to %s : %d trips.\n", argv[1] , argv[2], argv[1] , argv[2], argv[1], argv[2] ,total);

            
          
       }

	//pthread_create(&thread, NULL, fileParser, argv) // create splits it 

	//pthread_join(thread, NULL); // thie ensure that the main thread will wait till the main thread 

	return 0;
    }



int fileParser(char* myWord[] )
{
      char buf[1024];
      int row_count = 0;
      int field_count = 0;
      char * field = NULL;
      int pickupcount = 0;
      int dropoffcount = 0;  
      int total = 0; 

      FILE *fp = fopen(argv[0], "r"); 
          if (!fp) { // fp would be false if is not found
              printf("Can't open file\n");
              return 1;
          }
          if(fp)
          { // fp would be true if file was found 

            while (fgets(buf, 1024, fp)) 
            {
                field_count = 0;
                row_count++;

                if (row_count == 1) { // skip the headers get to the data we need
                    continue; 
                }
                field = strtok(buf, ",");

                while (field) {
                   if (field_count == 7) 
                   { 
                        if(strcmp(field, argv[1]) == 0){
                            pickupcount++;
                            field = strtok(NULL, ",");
                            field_count++;
                            if (field_count == 8 ) // field count 8 is the Pick up location Id :
                            { 
                              if(strcmp(field, argv[2]) == 0)
                              {
                                total++;
                              }
                            }
                        }
                   }
                    field = strtok(NULL, ",");
                    field_count++;
                }
            }
            fclose(fp);
          }
          return total;
}



