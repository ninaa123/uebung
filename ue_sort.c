/* 
 * File:   ue_sort.c
 * Author: nina
 *
 * Created on 5. April 2014, 07:38
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void sort(int *p, int elements)
{
    for(int k=1;k<elements;++k)
    {
        while(p[k]<p[k-1])
        {
            swap(&p[k],&p[k-1]);
            if(k>1)
                k=k-1;
        }
    }
}

int findElement(int *a, int links, int rechts, int element)
{
    int mid;
    
    do
    {
        mid=(rechts+links)/2;
        if(a[mid]==element)
            return mid;
        else if(a[mid]>element)
        {
            rechts=mid-1;
        }
        else if(a[mid]<element)
        {
            links=mid+1;
        }
    }    
    while(links<=rechts);
    return -1;
}

/*
int *sortMove(int *a, int elements)
{    
    int tmp;
    int counter;
    for(int i=1;i<elements;++i)        //iterates over all positions
    {
        tmp=a[i];
        counter=0;
        
        for(int j=i-1;j=0;--j)
        {
            if(a[j]>a[i])
            {
                ++counter;
                a[i]=a[j];
            }
        }
        a[i-counter]=tmp;
    } 
    
    return a;
}
*/

int main(int argc, char** argv) {
    
    //sort mit vertauschen
    
/*
    int *p;
    
    int elements=20;
    
    p=(int *) malloc(elements*sizeof(int));
    
    int t[20]={100,10,8,19,4,5,1,200,50,40,31,17,2,99,3,101,1000,552,300,299};
    
    if (p==NULL) 
    {
        perror("Nicht genug Speicher vorhanden. p"); 
        exit(EXIT_FAILURE);                        
    }
    
    for(int i=0;i<elements;++i)
    {
        p[i]=rand();
    }
    
    sort(t, elements);
*/
    
/*
    for(int n=0;n<elements;++n)
    {
        printf("%d\n",t[n]);
    }
    
*/
    
    //findElement
    
/*
    int n=100;
    int *a=(int *) malloc(100*sizeof(int));
    
    if (a==NULL) 
    {
        perror("Nicht genug Speicher vorhanden. a"); 
        exit(EXIT_FAILURE);                        
    }
    
    for(int i=0;i<100;++i)
    {
        a[i]=i;
    }
    
    printf("%d",findElement(a, 0, 99, 51));
    
    free(a);
*/
    
    //sortMove
    
    int a[5]={15, 13, 5, 1, 3};
    
    int tmp;
    int counter;
    for(int i=1;i<5;++i)        //iterates over all positions
    {
        tmp=a[i];
        counter=0;
        
        for(int j=i-1;j==0;--j)
        {
            if(a[j]>tmp)
            {
                a[i-counter]=a[j];
                ++counter;
            }
        }
        a[i-counter]=tmp;
    } 
          
    for(int i=0;i<5;++i)
    {
        printf("%d ",a[i]);
    }
    
/*
    int a[10];
    int * b = a;
    printf("sizeof(a) = %d\nsizeof(b) = %d\n", sizeof(a), sizeof(b));
    printf("sizeof(int) = %d\nsizeof(int *) = %d\n", sizeof(int), sizeof(int *));
*/

    return (EXIT_SUCCESS);
}

