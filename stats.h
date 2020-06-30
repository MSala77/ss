/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file <stats.h
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author Mohamed Salah
 * @date 28/6/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
#define SIZE (40)

/* Add Your Declarations and Function Comments here */
void print_array(unsigned char test[])
{
  printf("Array \n");
  for(int i=0; i<SIZE-1; i++)
  {
    printf("%c\t", test[i]);
    if(!(i%8))
    {
      printf("\n");
    }
  }
  printf("\n");
}

unsigned char find_mean(unsigned char test[])
{
  int sum=0;
  unsigned char mean=0;

  for(int i=0; i<SIZE-1; i++)
  {
    sum += test[i];
  }
  mean= sum/SIZE;
  return(mean);
}

void swap(unsigned char* xp, unsigned char* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sort_array(unsigned char test[])
{

    int i, j, max_place;

    for (i = 0; i < SIZE - 1; i++)
    {
        max_place = i;
        for (j = i + 1; j < SIZE; j++)
            if (test[j] > test[max_place])
                max_place = j;

        swap(&test[max_place], &test[i]);
    }
}
unsigned char find_median(unsigned char test[])
{
  sort_array(test);
  int median_place;
  unsigned char median;
  if (!(SIZE%2))
  {
    median_place=SIZE/2;
    median=(test[median_place]+test[median_place+1])/2;
  }
  else
  {
    median_place=round(SIZE/2);
    median=test[median_place];
  }
  return(median);
}
unsigned char find_maximum(unsigned char test[])
{
  unsigned char max=test[0];
  for(int i=0; i<SIZE-1; i++)
  {
    if (test[i] > max)
      max=test[i];
  }
  return(max);
}
unsigned char find_minimum(unsigned char test[])
{
  unsigned char min=test[0];
  for(int i=0; i<SIZE-1; i++)
  {
    if (test[i] < min)
      min=test[i];
  }
  return(min);
}
void print_statistcs(unsigned char maximum, unsigned char minimum, unsigned char median, unsigned char mean)
{
  printf("Maximum: %d\n", maximum);
  printf("Minimum: %d\n", minimum);
  printf("Median: %d\n", median);
  printf("Mean: %d\n", mean);
}
#endif /* __STATS_H__ */
