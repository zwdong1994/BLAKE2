//
// Created by victor on 1/3/18.
//

//
// Created by victor on 1/3/18.
//

#include "blake2.h"

#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <string.h>


int main(){
    size_t buf_length = 32;
	uint8_t buf[buf_length];
	size_t  out_length = 64;
	uint8_t  hash[out_length];
	double stat_time = 0.0;
	double end_time = 0.0;

    memset(hash, 0, out_length);
	for( int i = 0; i < buf_length; ++i ){
		buf[i] = 'a' + i % 26;
	}
	stat_time = get_time();
	blake2b( hash, out_length -1, buf, buf_length, NULL, 0 );
	end_time = get_time();


    printf("blake2b:\t%lf\n", (end_time -stat_time) * 1000);
    memset(hash, 0, out_length);
    //printf("%s\n", hash);
    stat_time = get_time();
    MD5((unsigned char *)buf, (size_t)buf_length, (unsigned char *)hash);

    end_time = get_time();
    printf("    md5:\t%lf\n", (end_time -stat_time) * 1000);
    memset(hash, 0, out_length);
    stat_time = get_time();
    SHA256((unsigned char *)buf, (size_t)buf_length, (unsigned char *)hash);

    end_time = get_time();
    printf(" sha256:\t%lf\n", (end_time -stat_time) * 1000);
    memset(hash, 0, out_length);
    stat_time = get_time();
    SHA1((unsigned char *)buf, (size_t)buf_length, (unsigned char *)hash);
    memset(hash, 0, out_length);
    end_time = get_time();
    printf("   sha1:\t%lf\n", (end_time -stat_time) * 1000);

	return 1;
}