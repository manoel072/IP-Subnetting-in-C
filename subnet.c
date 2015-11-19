/****************************************************/
/* Programmer: Manoel Ricardo de Oliveira           */
/*                                                  */
/* Ip Subnetting Calculator                         */
/*                                                  */
/* Approximate completion time: 4:20pm              */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Function to calculate length of given string*/
int my_strlen( char * string ) { 

    int i;
    for(i=0;string[i]!='\0';i++);
    return i;
}
/*Function to separate the IP entered into 4 different octets*/
int * get_ip_octets( char * string ) {

int length = my_strlen( string );    
   	
   	/*This array has 4 rows, one for each octet of the IP address,
   	  and 3 columns, one for each digit of the octet.*/
	int oct[4][3];
	
	for( int j = 0; j < 4; j++ )
		for( int q = 0; q < 3; q++)
			oct[j][q] = -1;
   		
   	char *ipnum = string;
   
   	int k = 0;
   	int oct_num = 0;
   	int oct_digit = 0;
   	
   	/*This loop separates the 4 octets of an IP address into the multidimensional array and
   	  converts the values from Chars to Int*/
   	while ( k < length ){
   		if ( ipnum[k] != '.' ){
   			oct[oct_num][oct_digit] = ipnum[k] - '0';
   			oct_digit++;
   			k++;
   			}
   		else{
   			k++;
   			oct_num++;
   			oct_digit = 0;
   			}
   		}
	
	static int octets[4] = {0,0,0,0};
	
	
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

	return octets;

}

int * default_mask( int ip[4] ) {
    
    static int def_mask[4] = {0,0,0,0};
   
    if ( ip[0] > 224 )
    	exit(EXIT_FAILURE);
	if ( ip[0] > 191 )
		def_mask[2] = 255;
	if ( ip[0] > 127 )
		def_mask[1] = 255;
	if ( ip[0] > 0 )
		def_mask[0] = 255;
    
    return def_mask;
}

int main( int argc, char *argv[] ) {
    
   	int *oct, *def_subnet;
   	
   	oct = get_ip_octets( argv[1] );
   	def_subnet = default_mask( oct ); 
   		
   	printf("Network Address:");	
	for ( int i = 0; i < 4; i++ ) {
      if ( i != 3)
      	printf( "%d.", *(oct + i));
      else 
      	printf( "%d\n", *(oct + i));
   }
   	printf("Default Subnet Mask:");
	for ( i = 0; i < 4; i++ ) {
      if ( i != 3)
      	printf("%d.", *(def_subnet + i));
      else
      	printf("%d\n", *(def_subnet + i));
   }
	
    return 0;
}