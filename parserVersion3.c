//Imtiaz Rayman Multi Threaded 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

char* argv [1000]; 

void* fileParser(void * arg){ // Tthe reason why it is a void * it makes it generic which means that it can return and also take in anything.
    //int *iptr = (int * )arg;
      int *iptr = (int*)malloc(sizeof(int));
      *iptr = 0;
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
                                (*iptr)++;
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
          return iptr;
}


int main()
{ 
    pthread_t newThread;
    char* space = "\n ";
      char* myWord=NULL;  
      char* fileName =NULL;
      char* pickupId =NULL;
      char* dropOffId =NULL;
      //char* argv [1000]; 
      char buffer[1000]; 
      int returnValue = 0;
      bool pickup = false;  
      bool dropoff = false;

      // yellow_tripdata_2019-12.csv pickup_id dropoff_id 
      // yellow_tripdata_2019-12.csv 200 123
    while(1)
    {
       printf("\n<<<<<<<<<<<<File Parser>>>>>>>>>>>>\nSingle process (Multi Thread) Version #3\n");
       printf("Program must be invoked in the sequence of:\nfileName.csv pickup_id dropoff_id\n");
       printf("Enter <CTRL + C> TO QUIT\nExample: yellow_tripdata_2019-12.csv 161 237\nEnter >"); 
       
       fgets(buffer, 1000, stdin);
          int i = 0; 

          for (myWord = strtok(buffer, space); myWord; myWord = strtok(NULL, space)) 
          {
            argv[i] = myWord;
            i++;
          }
          //And example run would be
          //./compute files.txt 10 20
    int *result;
    fileName = argv[0];
    pickupId = argv[1];
    dropOffId = argv[2];

  pthread_create(&newThread, NULL, fileParser, &fileName);
  pthread_join(newThread, (void * ) &result); 
  printf("\n<<<<<<Output>>>>>>\nIDs Entered : %s to %s\nPick-up ID Entered : %s\nDropOff Id Entered : %s\nNumber Of Pickups at %s to %s : %d trips.\n", argv[1] , argv[2], argv[1] , argv[2], argv[1], argv[2] ,*result);
}
return 0;
}

