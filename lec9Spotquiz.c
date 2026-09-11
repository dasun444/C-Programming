#include <stdio.h> 

int main (){
int arr[20];
int c1=0,c2=0,c3=0,count=0,max=0,invalid=0;
int *ptr=arr;
printf("\tStudent Council Election\t\n");
printf("Enter the 20 votes \n1 for Candidate 1\n2 for Candidate 2\n3 for Candidate 3\n\n");
for(int i=0;i<20;i++){
printf(" vote number %d: ",i+1);
scanf("%d",(ptr+i));
}
for(int i=0;i<20;i++){
if(*(ptr + i)==1)
c1++;
else if(*(ptr + i)==2)
c2++;
else if(*(ptr + i)==3)
c3++;
else
invalid++;
/* or we can use switch case*/
}

if(c1>max)
max=c1;
if(c2>max)
max=c2;
if(c3>max)
max=c3;

printf("votes received by candidate 1: %d\n",c1);
printf("votes received by candidate 2: %d\n",c2);
printf("votes received by candidate 3: %d\n",c3);
printf("Total invalid votes: %d\n",invalid);

if(max==c1)
    printf("Election winner is candidate 1!");
else if(max==c2)
printf("Election winner is candidate 2!");
else if(max==c3)
printf("Election winner is candidate 3!");
else if ((max==c1 && max==c2 )|| (max==c2 && max==c3 )||(max==c3 && max==c1 ))
printf("Election Tied");


return 0;
}
