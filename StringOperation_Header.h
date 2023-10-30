typedef void MSG(const char* );

int strlen(const char* text);

void strcpy(char* text1,const char* text2, MSG message);

void strcat(char* text1,const char* text2, MSG message);

void strcmp(const char* text1,const char* text2, MSG message);

void strlwr(char* text);

void strcmpi(const char* text1,const char* text2, MSG message);