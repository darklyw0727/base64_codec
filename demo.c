#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "b64_codec.h"

int main(int argc, char **argv)
{
	const char *str = "This is origin msg!";
	size_t len;

	len = b64_encoded_size(strlen(str));
	char b64e[len+1];
	len = b64_encode(str, strlen(str), b64e);
	printf("Encode message after base64 encode (length = %ld) : \n%s\n", len, b64e);
	
	len = b64_decoded_size(b64e);
	unsigned char b64d[len+1];
	memset(b64d, 0, sizeof(b64d));
	len = b64_decode(b64e, b64d);
	printf("Decode dessage after base64 decode (length = %ld) : \n%s\n", len, b64d);

	len = b64_encoded_size(strlen(str));
	char urle[len+1];
	len = b64url_encode(str, strlen(str), urle);
	printf("Encode message after base64URL encode (length = %ld) : \n%s\n", len, urle);
	
	len = b64_decoded_size(urle);
	unsigned char urld[len+1];
	memset(urld, 0, sizeof(urld));
	len = b64url_decode(urle, urld);
	printf("Decode dessage after base64URL decode (length = %ld) : \n%s\n", len, urld);

	return 0;
}
