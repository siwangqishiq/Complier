#include "lexical.h"

size_t read_text_file(const char *file_path,char **buffer){
    size_t size = 0;
    FILE *fp = fopen(file_path, "r");
    if(!fp){
        printf("ERROR! read file error\n");
        return 0;
    }
    
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    
    rewind(fp);
    
    *buffer = (char *)malloc((size + 1)*sizeof(char));
    
    if(!(*buffer)){
        printf("ERROR! malloc buffer error\n");
        return 0;
    }
    
    fread(*buffer,size,1,fp);
    
    (*buffer)[size] = '\0';
    
    fclose(fp);

    return size;
}