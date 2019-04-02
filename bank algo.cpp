#include<stdio.h>
#include<conio.h>
int main()
{
	int k=0,p=0,q=0;
	int avail[4]={1,5,2,0};
	int max[5][4]={{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};
	int allot[5][4]={{0,0,1,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
	int need[5][4],g[5];
	for(int i=0;i<5;i++)
{
	g[i]=0; 
}	
	for(int i=0;i<5;i++)
{
	for(int j=0;j<4;j++)
	{
		need[i][j]=max[i][j]-allot[i][j];
	}  
} 
	printf("\nSafe Sequence for the processes is : ");
	while(p!=5)
{
	q=p;
	for(int i=0;i<5;i++)
    {
       for(int j=0;j<4;j++)
        {
            if(need[i][j]<=avail[j])
              {
                 k++;
              }   
        }
        if((k==4)&&(g[i]==0))
        {
           printf("P[%d]\t",i);
           g[i]=1;
           for(int j=0;j<4;j++)
            {
               avail[j]=avail[j]+allot[i][j];
        	}
             p++;
        }
         k=0;
    }
        if(p==q)
        {
    		printf("\nDEADLOCK!!!");
        	printf("\nSystem is not in safe state.");
			break; 
        }
 
}
 	printf("\nYES, the system is in safe state.");
	getch();
}
