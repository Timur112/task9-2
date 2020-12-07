#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    int k,i,j,n,m,**c,d,curn,curm;
    scanf("%d%d", &n, &m);
    c=(int**) malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        c[i]=(int*) malloc(m*sizeof(int));
    }
    for(k=0;(k<n) && (k<m);k++)
    {
        for(i=k;i<n;i++)
        {
            c[i][k]=i+1-k;
        }
        for(j=k;j<m;j++)
        {
            c[k][j]=j+1-k;
        }
    }
    for(i=0;i<n;i++,printf("\n"))
    {
        for(j=0;j<m;j++)
        {
            printf("%4d", c[i][j]);
        }
    }

    k=1;
    curn=n;
    curm=m;
    d=0;
    while(k<=n*m)
    {
        for(j=d;j<curm;j++)
        {
            c[d][j]=k;
            k++;
        }
        for(i=d+1;i<curn;i++)
        {
            c[i][j-1]=k;
            k++;
        }
        for(j=curm-2;j>=d && k<=m*n;j--)
        {
            c[i-1][j]=k;
            k++;
        }
        for(i=curn-2;i>d && k<=m*n;i--)
        {
            c[i][j+1]=k;
            k++;
        }
        d++;
        curn--;
        curm--;
    }
    printf("\n");
    for(i=0;i<n;i++,printf("\n"))
    {
        for(j=0;j<m;j++)
            {
                printf("%4d", c[i][j]);
            }
    }
    return 0;
}
