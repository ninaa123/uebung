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

int *fill(int *a, int elements)
{
    int j;
    for(j=0;j<elements;++j)
    {
        a[j]=rand();
    }
    
    return a;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int cmp(int a, int b)
{
    if(a>b)
        return 0;
    else return 1;
}

int *sort(int *p, int elements)
{
    int k;
    int *res;
    int tmp;
    int m;
    
    res=(int *) malloc(elements*sizeof(int));
    
    if (res==NULL) 
    {
        perror("Nicht genug Speicher vorhanden."); 
        exit(EXIT_FAILURE);                        
    }
    
    res[0]=rand();
    
    for(k=1;k<elements;++k)
    {
        res[k]=rand();
        while(res[k]<res[k-1])
        {
            swap(&res[k],&res[k-1]);
            k=k-1;
        }
    }
    
    return res;
}

int findElement(int *a, int links, int rechts, int element)
{
    int mid;
    
    do
    {
        mid=(rechts+links)/2;
        printf("%d %d %d\n", links, mid, rechts);
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

int main(int argc, char** argv) {
    
    //sort mit vertauschen
    
/*
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
    
    result = sort(p, elements);
    for(int n=0;n<elements;++n)
    {
        printf("%d\n",result[n]);
    }
    
    free(p);
    free(result);
*/
    
    int *a;
    
    for(int i=0;i<100;++i)
    {
        a[i]=i;
    }
    
    //printf("%d",findElement(a, 0, 99, 51));

    return (EXIT_SUCCESS);
}

