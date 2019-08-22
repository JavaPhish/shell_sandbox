char *_strcpy(char *dest, char *src)
{
    char *pdest = dest;
    char *src1 = src;

    while (*src1 != '\0')
    {
        *pdest = *src1;
        src1++;
        pdest++;
    }
    *pdest = *src1;
    return (dest);
}
