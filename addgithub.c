# include <stdio.h>
/*

# include <stdio.h>

int main(){
    int i,j,k=1,rows;
    printf("Enter the number (>=5): ");
    scanf("%d",&rows);
    if(rows>=5){
    for(i=0;i<rows;i++){
        for(j=0;j<rows;j++){
            if(i==j||i+j==rows-1){
                if(k>9){
                    k=1;
                }
                
                printf("%d",k);
            k++;
           }
           else
                printf(" ");
        }
        printf("\n");

    } 
    }


    else
    printf("n is less than 5.it is invalid.");
    return 0;
    Enter the number (>=5): 13
1           2
 3         4 
  5       6  
   7     8   
    9   1    
     2 3     
      4      
     5 6     
    7   8    
   9     1   
  2       3  
 4         5 
6           7
}*/

int main(){
    int i,j,k=1,rows;
    printf("Enter the number (>=5): ");
    scanf("%d",&rows);
    if(rows>=5){
    for(i=0;i<rows;i++){
        for(j=0;j<rows;j++){
            if(i==j||i+j==rows-1){
                printf("*");
            
           }
           else
                printf(" ");
        }
        printf("\n");

    } 
    }


    else
    printf("n is less than 5.it is invalid.");
    return 0;
}

/*
Enter the number (>=5): 6
*    *
 *  * 
  **  
  **  
 *  * 
*    **/