### INSTALL
`make`

### HOW TO USE
- `b64_t` struct for save encode/decode data and length
- Encode a message : `b64_encode(const unsigned char *in, size_t len)` or `b64url_encode(const unsigned char *in, size_t len)`
    - Return a b64_t pointer
    - b64_encode will output **base64** format string
    - b64url_encode will output **base64URL** format string
- Decode a message : `b64_decode(const char *in)` or `b64url_encode(const char *in)`
    - Return a b64_t pointer
    - Use b64_decode, if your input is **base64** format
    - Use b64url_decode, if your input is **base64URL** format
- When you finish the work, please use `b64_free(b64_t *ptr)` to free the memory