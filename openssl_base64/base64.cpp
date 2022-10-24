#include <openssl/buffer.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <iostream>


int main()
{
        BIO *bio, *b64;
 char message[] = "Hello World \n";

 b64 = BIO_new(BIO_f_base64());
 bio = BIO_new_fp(stdout, BIO_NOCLOSE);
 BIO_push(b64, bio);
 BIO_write(b64, message, strlen(message));
 BIO_flush(b64);

 BIO_free_all(b64);
 return 0;
}
