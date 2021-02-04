#include <openssl/md5.h>
#include <string>

std::string md5(const void *data, unsigned long len)
{
    MD5_CTX c;
    unsigned char md[MD5_DIGEST_LENGTH];
    char mdString[33];
    int r, i;

    r = MD5_Init(&c);
    if (r != 1)
    {
        perror("init");
        return "";
    }

    r = MD5_Update(&c, data, len);
    if (r != 1)
    {
        perror("update");
        return "";
    }

    r = MD5_Final(md, &c);
    if (r != 1)
    {
        perror("final");
        return "";
    }

    for (i = 0; i < 16; i++)
        sprintf(&mdString[i * 2], "%02x", (unsigned int)md[i]);

    return mdString;
}

std::string md5(const std::wstring &s)
{
    return md5((const void *)s.c_str(), s.length() * sizeof(wchar_t));
}

std::string md5(const std::string &s)
{
    return md5((const void *)s.c_str(), s.length());
}

#ifdef __cpp_char8_t
std::string md5(const std::u8string &s)
{
    return md5((const void *)s.c_str(), s.length());
}
#endif
