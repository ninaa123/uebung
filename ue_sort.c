/* 
 * File:   ue_sort.c
 * Author: nina
 *
 * Created on 5. April 2014, 07:38
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void swap(int *a, int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int *sort(int *p, int elements)
{
        
    for(int k=1;k<elements;++k)
    {
        while(p[k]<p[k-1])
        {
            swap(&p[k],&p[k-1]);
            k=k-1;
        }
    }
    
    return p;
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

//int *sortMove()

int main(int argc, char** argv) {
    
    //sort mit vertauschen
    
    int *p;
    int *result;
    int i;
    
    int elements=20;
    
    p=(int *) malloc(elements*sizeof(int));
    result=(int *) malloc(elements*sizeof(int));
    
    if (p==NULL) 
    {
        perror("Nicht genug Speicher vorhanden. p"); 
        exit(EXIT_FAILURE);                        
    }
    
    if (result==NULL) 
    {
        perror("Nicht genug Speicher vorhanden. result"); 
        exit(EXIT_FAILURE);                        
    }
    
    for(int i=0;i<elements;++i)
    {
        p[i]=rand();
    }
    
    result=sort(p, elements);
    for(int n=0;n<elements;++n)
    {
        printf("%d\n",result[n]);
    }
    
    free(p);
    free(result);
    
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

    return (EXIT_SUCCESS);
}

