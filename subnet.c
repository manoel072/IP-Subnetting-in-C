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
   	
   	/*This array has 4 rows, one for each octet of the IP address,
   	  and 3 columns, one for each digit of the octet.*/
	int oct[4][3];
	
	for( int j = 0; j < 4; j++ )
		for( int q = 0; q < 3; q++)
			oct[j][q] = -1;
   		
   	char *ipnum = argv[1];
   
   	int k = 0;
   	int oct_num = 0;
   	int oct_num_pos = 0;
   	
   	/*This loop separates the 4 octets of an IP address into the multidimensional array and
   	  converts the values from Chars to Int*/
   	while ( k < length ){
   		if ( ipnum[k] != '.' ){
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
	
	int octets[4] = {0,0,0,0};
	
	
	for( j = 0; j < 4; j++ ){/*This loop adds the digits*/
		if ( oct[j][2] != -1){		
			octets[j] = oct[j][2];
			octets[j] += (oct[j][1] * 10);
			octets[j] += (oct[j][0] * 100);	
			}
		else if ( oct[j][2] == -1 && oct[j][1] != -1 ){
			octets[j] += oct[j][1] ;
			octets[j] += oct[j][0] * 10;
			}
		else if ( oct[j][2] == -1 && oct[j][1] == -1 ){
			octets[j] = oct[j][0];
			}
		}
	
	for( j = 0; j < 4; j++ )
		printf("%d\n", octets[j]);
    return 0;
}