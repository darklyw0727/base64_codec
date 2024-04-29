#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "b64_codec.h"

int main(int argc, char **argv)
{
	const char *str = "This is origin msg!";
	size_t len;
	char *buf_64;
	char *buf_url;

	len = b64_encoded_size(strlen(str));
	char b64e[len+1];
	memset(b64e, 0, len+1);
	len = b64_encode(str, strlen(str), b64e);
	printf("Encode message after base64 encode (length = %ld) : \n%s\n\n", len, b64e);

	if((buf_url = malloc(strlen(b64e)+1)) == NULL){
		printf("Malloc failed\n");
		return -1;
	}
	memset(buf_url, 0, sizeof(b64e)+1);
	b64_turn(1, b64e, buf_url);
	printf("Base64 to base64URL : \n%s\n\n", buf_url);

	size_t a = 4-(strlen(buf_url)%4);
	if((buf_64 = malloc(strlen(buf_url)+1+a)) == NULL){
		printf("Malloc failed\n");
		free(buf_url);
		return -1;
	}
	memset(buf_64, 0, strlen(buf_url)+1+a);
	b64_turn(0, buf_url, buf_64);
	printf("Base64URL to base64 : \n%s\n\n", buf_64);
	
	len = b64_decoded_size(buf_64);
	unsigned char b64d[len+1];
	memset(b64d, 0, sizeof(b64d));
	len = b64_decode(buf_64, b64d);
	printf("Decode dessage after base64 decode (length = %ld) : \n%s\n\n", len, b64d);

	if(strcmp(str, b64d) == 0) printf("Origin message == decoded message\n");

	free(buf_url);
	free(buf_64);
	return 0;
}
