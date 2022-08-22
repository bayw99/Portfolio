#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char name_in[]  = "input.txt";
    char name_out[] = "copy.txt";
    
    FILE * infile  = fopen(name_in, "rb");
    FILE * outfile = fopen(name_out, "wb");
     
    char  buffer[1024];
    
    fseek(infile, 8, SEEK_SET); /* omit first 8 bytes */

    size_t count_in;

    /* copy from input to output */
    while (count_in = fread(buffer, 1, sizeof(buffer), infile))
        fwrite(buffer, 1, count_in, outfile);

    fclose(infile);    
    fclose(outfile);
    
    return 0;
}