### INSTALL
`make`

### HOW TO USE
- Calculate data length after encode/decode : `b64_encoded_size(size_t inlen)` or `b64_decoded_size(const char *in)`
    - Return the length, you can use this to declare a memory
    - Both base64 and base64URL use these function
- Encode a message : `b64_encode(const unsigned char *in, size_t len, char *out)` or `b64url_encode(const unsigned char *in, size_t len, char *out)`
    - Return 0 (error) or the data length after encode
    - b64_encode will output **base64** format string
    - b64url_encode will output **base64URL** format string
- Decode a message : `b64_decode(const char *in, unsigned char *out)` or `b64url_encode(const char *in, unsigned char *out)`
    - Return 0 (error) or the data length after decode
    - Use b64_decode, if your input is **base64** format
    - Use b64url_decode, if your input is **base64URL** format

```c
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
```