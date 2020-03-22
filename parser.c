//Imtiaz Rayman 
//single thread single process program
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

int main(void)
{
      char* space = "\n ";
      char* myWord=NULL;  
      char* argv [1000]; 
      char buffer[1000]; 
      int returnValue = 0;
      bool pickup = false;  
      bool dropoff = false;

    // yellow_tripdata_2019-12.csv pickup_id dropoff_id 200

    while(1){
     printf("\n<<<<<<<<<<<<File Parser>>>>>>>>>>>>\nSingle processes (Single Thread) Version #1\n");
     printf("Program must be invoked in the sequence of:\nfileName.csv pickup_id dropoff_id\n");
     printf("Enter <Exit> or <CTRL + C> TO QUIT\nExample: yellow_tripdata_2019-12.csv 161 237\nEnter >"); 
     fgets(buffer, 1000, stdin);
        int i = 0; 

        for (myWord = strtok(buffer, space); myWord; myWord = strtok(NULL, space)) {
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
    int returnvalue = 0;
    int total = 0; 
    if(strcmp(argv[0],"Exit") == 0){ 
      printf("Exit has been Entered, Program Exiting...\n"); 
      break; 
    }

    // sample program entry below 
    //file.csv pickup_id dropoff_id 230
    // yellow_tripdata_2019-12.csv pickup_id dropoff_id 

  FILE *fp = fopen(argv[0], "r"); 
          if (!fp) { // fp would be false if is not found
              printf("Can't open file\n");
              returnValue = 1;
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
    printf("\nIDs Entered : %s to %s\nPick-up ID Entered : %s\nDropOff Id Entered : %s\nNumber Of Pickups at %s to %s : %d trips.\n", argv[1] , argv[2], argv[1] , argv[2], argv[1], argv[2] ,total);
    }
    return 0;
}
/* if (field_count == 0) {
                printf("VendorID:\t");
            }
            if (field_count == 1) {
                printf("tpep_pickup_datetime:\t");
            }
            if (field_count == 2) {
                    printf("tpep_dropoff_datetime:\t");
            }
            if (field_count == 3) {
                printf("passenger_count:\t");
            }
             if (field_count == 4) {
                printf("trip_distance:\t");
            }
             if (field_count == 5) {
                printf("RatecodeID:\t");
            }
             if (field_count == 6) {
                printf("store_and_fwd_flag:\t");
                }
             if (field_count == 9) {
                printf("payment_type:\t");
            }
             if (field_count == 10) {
                printf("fare_amount:\t");
            }
             if (field_count == 11) {
                printf("extra:\t");
            }
             if (field_count == 12) {
                printf("mta_tax:\t");
            }
             if (field_count == 13) {
                printf("tip_amount:\t");
            }
             if (field_count == 14) {
                printf("tolls_amount:\t");
            }
             if (field_count == 15) {
                printf("improvement_surcharge:\t");
            }
             if (field_count == 16) {
                printf("total_amount:\t");
            }
             if (field_count == 17) {
                printf("congestion_surcharge:\t");
            }
             if (field_count == 18) {
                printf("passenger_count:\t");
            }*/
            
