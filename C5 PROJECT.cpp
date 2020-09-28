#include<stdio.h>
#include<string.h>

void reverse(char line[])
{
    int  i;
    int  length;
    char temp;
    if (line == NULL)
        return;
    length = strlen(line);
    for (i = 0 ; i < length / 2 + length % 2 ; ++i)
    {
        if (line[i] == line[length - i - 1])
            continue;
        temp                 = line[i];
        line[i]              = line[length - i - 1];
        line[length - i - 1] = temp;
    }
    return;
}




 int main() 
{ 

    FILE *src_fh, *dst_fh; 
    char src_fn[256+1], dst_fn[256+1]; 


    printf("Enter Source File Name:\n"); 
    fgets(src_fn, sizeof(src_fn), stdin); reverse(src_fn); 


    if( (src_fh = fopen(src_fn, "r")) == NULL ) 
    { 
        printf("ERROR: Source File %s Failed To Open...\n",src_fn); 
        return(-1); 
    } 


    printf("Enter Destination File Name:\n"); 
    fgets(dst_fn, sizeof(dst_fn), stdin); reverse(dst_fn); 


    if( (dst_fh = fopen(dst_fn, "w+")) == NULL ) 
    { 
        fclose(src_fh); 
        printf("ERROR: Destination File %s Failed To Open...\n",dst_fn); 
        return(-2); 
    } 

    int ch; 
    while( (ch = fgetc(src_fh)) != EOF ) 
    { 
        fputc(ch, dst_fh); 
    } 


    fclose(src_fh); 
    fclose(dst_fh); 
    return 0; 
}
