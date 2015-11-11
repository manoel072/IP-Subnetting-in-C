/****************************************************/
/* Programmer: Manoel Ricardo de Oliveira           */
/*                                                  */
/* Ip Subnetting based on network requirements      */
/* requirements                                     */
/*                                                  */
/* Approximate completion time: 4:20pm              */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *string) /*Function to calculate length of given string*/
{
    int i;
    for(i=0;string[i]!='\0';i++);
    return i;
}

int main( int argc, char *argv[] ) {
    
   	int length = my_strlen( argv[1] );    
   	
   	char ip[length];
	int oct[4][3];
	for( int j = 0; j < 4; j++ )
		for( int q = 0; q < 3; q++)
			oct[j][q] = -1;
   	
   	strcpy( ip, argv[1] );
   	
   	char *ipnum = argv[1];
   
   	int k = 0;
   	int oct_num = 0;
   	int oct_num_pos = 0;
   	
   	
   	while ( k < length ){
   		
   		if ( ip[k] != '.' ){
   			oct[oct_num][oct_num_pos] = ipnum[k] - '0';
   		oct_num_pos++;
   		k++;
   		}
   		else{
   		k++;
   		oct_num++;
   		oct_num_pos = 0;
   		}
   	
   	}
	
for( j = 0; j < 4; j++ )
		for( q = 0; q < 3; q++)
			printf("%d\n", oct[j][q]);
	
	int octets[4] = {0,0,0,0};
	
	/*octets[0]= oct[0][2] * 1;
	printf("times one:%d\n", octets[0]);
	octets[0]+= oct[0][1] * 10;
	printf("times 10:%d\n", octets[0]);
	octets[0]+= oct[0][0] * 100;
	printf("after times 100:%d\n", octets[0]);*/
	
	for( j = 0; j < 4; j++ ){
		for( q = 2; q >= 0; q--){
			if ( oct[j][q] != -1 )
				switch (q){
					case 2:
						octets[j] = oct[j][q];
					case 1:
						octets[j] += oct[j][q] * 10;
					case 0:
						octets[j] += oct[j][q] * 100;

				} 
		} 	
	}
	
	for( j = 0; j < 4; j++ )
		printf("%d\n", octets[j]);
    return 0;
}