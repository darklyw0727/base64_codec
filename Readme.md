### INSTALL
`make`

### HOW TO USE
- Encode a message to base64 format
    1. Use `b64_encoded_size(size_t inlen)` to calucate the message length after encode
        - Input is the origin message "length"
    2. Create a buffer that size = "step.1 result + 1" to save the encode output
    3. Use `b64_encode(const unsigned char *in, size_t len, char *out)` to start encode
        - Output will do memcpy on `out`, please make sure you have enought space
        - Return the output length or 0 (error)
- Decode a message to base64 format
    1. Use `b64_decoded_size(const char *in)` to calucate the message length after decode
        - Input is the origin message "string"
    2. Create a buffer that size = "step.1 result + 1" to save the decode output
    3. Use `b64_decode(const unsigned char *in, char *out)` to start decode
        - Output will do memcpy on `out`, please make sure you have enought space
        - Return the output length or 0 (error)
- If the origin string format is base64URL, use `b64_turn(const int url, const char *in, char *out)`
    - Depense `url` is 1 or 0, this function will do "base64 to base64URL" or "base64URL to base64"
    - Make sure your output buffer have enought space.
```c
//Encode, decode example
char str[] = "your message";

size_t len = b64_encoded_size(strlen(str));
char b64e[len+1];
memset(b64e, 0, len+1);
len = b64_encode(str, strlen(str), b64e);
if(len != 0) printf("Encode message after base64 encode (length = %ld) : \n%s\n\n", len, b64e);

len = b64_decoded_size(buf_64);
unsigned char b64d[len+1];
memset(b64d, 0, sizeof(b64d));
len = b64_decode(b64e, b64d);
if(len != 0) printf("Decode dessage after base64 decode (length = %ld) : \n%s\n\n", len, b64d);
```
```c
//Base64 to base64URL
char str[] = "base64 format message";

char url[strlen(str)+1]; 
size_t len;

memset(url, 0, sizeof(url));
len = b64_turn(1, str, url);
if(len != 0) printf("Base64 to base64URL : \n%s\n\n", url);

//Base64URL to base64
char *b64;
size_t b64_size;
size_t a = strlen(url)%4;

if(a != 0) b64_size = strlen(url)+1+4-a; //base64 format string length is multiple of 4
else b64_size = strlen(url)+1;
b64 = malloc(b64_size);
memset(buf_64, 0, b64_size);

len = b64_turn(0, url, b64);
if(len != 0) printf("Base64URL to base64 : \n%s\n\n", b64);
```