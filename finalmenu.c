#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE1 5000
#define SIZE2 10000
#define SIZE3 50000
int *readFile(string fileName, int size, int size2);  //pointer to return and int array
int linearSearch(int array[], int guess, int size);  //linear search
int binarySearch(int array[], int guess, int size);
int *bubbleSort(int array[], int size);
int *selectioSort(int array[], int size);
void printArray(int array[], int size); // function to write the sorted array into a file
void Menu();
void writeArray(int array[], int size);

int main(void)
{

    do{
    Menu();
    int choice= get_char("Please enter your choice 1-5");
   } while(choice !=5);
}
int *readFile(string fileName, int size, int size2 )
    {
    FILE* file=(fopen(fileName, "r"));
    char line[size2]; //how many characers per line
    char options[size][size2];//array to put all the numbers from the file
    int  static numbers[SIZE2];  // file to be returned
    for (int i=0; i <size; i++)
    {
        fscanf(file, "%s", options[i]);
        // printf("%s \n", options[i]);
        numbers[i]= atoi(options[i]);
    }
    fclose(file);
   return numbers;
}
int linearSearch(int array[],int guess,int size )
{
    for(int i=0; i < size; i++)
    {
        if (array[i]== guess)
        {
            return i;
        }
    }
    return -1;
}
int *selectioSort(int array[], int size)
{
    int indx=0;
    for(int i=0; i<size ; i++)
    {
        int min= size+1;
        for(int j=i; j< size; j++)
        {
            if( array[j]<min)
            {
                min = array[j];
                indx=j;
            }
        }
        // make the swap
        int temp=array[i];
        array[i]=min;
        array[indx]=temp;
    }
    return array;
}
void printArray(int array[], int size)
{
    for (int i=0; i < size; i++)
    {
        printf(" %i \n",array[i] );
    }
}
void Menu()
{
 
 printf("=====================================\n");
 printf("#               MENU                #\n");
 printf("#   1) Read a file                  #\n");
 printf("#   2) Sort an Array                #\n");
 printf("#   3) Search for a value in array  #\n");
 printf("#   4) Write an array to File       #\n");
 printf("#   5) Exit                         #\n");
 printf("=====================================\n");
}
void writeArray(int sorted[], int size)
{
    string name=get_string("How do you want to call your file? ");
    char filename[10];
    sprintf(filename, "%s.txt", name);
    FILE *file = fopen(filename, "w");
    for (int i=0; i < size; i++)
    {
        fprintf(file,"%d\n",sorted[i]);
    }
}
