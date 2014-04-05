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
    int m;
    int *res;
    
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
        
        for(m=0;m<k;++m)
        {
            if(cmp(res[k],res[k-m])==1)
            {
                swap(&res[k],&res[k-m]);
                k=k-m;
            }
        }
    }
    
    return res;
}

int main(int argc, char** argv) {
    
    int *p;
    int *result;
    int i;
    
    int elements=5;
    
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
    
/*
    fill(p, elements);
    
    FILE *f;
    f=fopen("sort.txt","w");
  
    for(i=0;i<elements;++i)
    {
        fprintf(f,"%d %d\n",i, p[i]);
    }
    
    fclose(f);
*/
    
    result = sort(p, elements);
    for(int n=0;n<elements;++n)
    {
        printf("%d\n",result[n]);
    }
    
    free(p);
    free(result);

    return (EXIT_SUCCESS);
}

