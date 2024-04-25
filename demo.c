#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "b64_codec.h"

int main(int argc, char **argv)
{
	const char *str = "This is origin msg!";
	b64_t *enc;
	b64_t *dec;

	enc = b64_encode(str, strlen(str));
	printf("Encode message after base64 encode (length = %ld) : \n%s\n", enc->data_len, enc->data);
	
	dec = b64_decode(enc->data);
	printf("Decode dessage after base64 decode (length = %ld) : \n%s\n", dec->data_len, dec->data);

	b64_free(enc);
	b64_free(dec);

	enc = b64url_encode(str, strlen(str));
	printf("Encode message after base64URL encode (length = %ld) : \n%s\n", enc->data_len, enc->data);
	
	dec = b64url_decode(enc->data);
	printf("Decode dessage after base64URL decode (length = %ld) : \n%s\n", dec->data_len, dec->data);

	b64_free(enc);
	b64_free(dec);

	return 0;
}
