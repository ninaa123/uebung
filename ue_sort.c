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

int main(int argc, char** argv) {
    
    int *p;
    int i;
    
    int elements=atof(argv[1]);
    
    p=(int *) malloc(elements*sizeof(int));
    
    if (p==NULL) 
    {
        perror("Nicht genug Speicher vorhanden."); 
        exit(EXIT_FAILURE);                        
    }
    
    fill(p, 100);
    
    FILE *f;
    f=fopen("sort.txt","w");
  
    for(i=0;i<elements;++i)
    {
        fprintf(f,"%d %d\n",i, p[i]);
    }
    
    fclose(f);
    
    free(p);

    return (EXIT_SUCCESS);
}

