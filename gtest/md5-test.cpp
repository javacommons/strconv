// https://a4dosanddos.hatenablog.com/entry/2015/03/01/191730
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
    MD5_CTX c;
    const char *data = "hoge";
    unsigned char md[MD5_DIGEST_LENGTH];
    char mdString[33];
    int r, i;
    
    r = MD5_Init(&c);
    if(r != 1) {
        perror("init");
        exit(1);
    }
    
    r = MD5_Update(&c, data, strlen(data));
    if(r != 1) {
        perror("update");
        exit(1);
    }
    
    r = MD5_Final(md, &c);
    if(r != 1) {
        perror("final");
        exit(1);
    }
 
    for(i = 0; i < 16; i++)
         sprintf(&mdString[i * 2], "%02x", (unsigned int)md[i]);
 
    printf("md5 digest: %s\n", mdString);
}
