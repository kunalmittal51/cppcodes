#include<iostream>
int main()
{
       int B[] = {1,1,1,3,3,3,20,4,4,4};
       int    ones = 0 ;
       int    twos = 0 ;
       int not_threes;
       int x ;
       int i;

   for( i=0; i< 10; i++ )
   {
   	x =  B[i];
        twos |= ones & x ;
        ones ^= x ;
        not_threes = ~(ones & twos) ;
        ones &= not_threes ;
        twos &= not_threes ;
        printf("%d"   "%d"   "%d\n",ones,twos,not_threes);
    }

    printf("\n unique element = %d \n", ones );
 
    return 0;

}
