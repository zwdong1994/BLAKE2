//
// Created by victor on 1/3/18.
//

//
// Created by victor on 1/3/18.
//

#include "blake2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	uint8_t buf[4096];
	size_t  out_length = 16;
	uint8_t key[BLAKE2B_KEYBYTES];
	uint8_t  hash[out_length];
	double stat_time = 0.0;
	double end_time = 0.0;
	for( int i = 0; i < BLAKE2B_KEYBYTES; ++i )
		key[i] = ( uint8_t )i;
	for( int i = 0; i < 4096; ++i ){
		buf[i] = 'a' + i % 26;
	}
	stat_time = get_time();
	blake2b( hash, out_length, buf, 4096, key, BLAKE2B_KEYBYTES );
	end_time = get_time();
	printf("%lf\n", (end_time -stat_time) * 1000);
	printf("%s\n", hash);

	return 1;
}