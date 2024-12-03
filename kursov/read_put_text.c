#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 2048


char* del_tab(char* str){
        while (*str == ' ' || *str == '\t' || *str == '\n'){
                str++;
        }
        return str;
}


char* read_text(){
        size_t buffer =  BUFFER;
        char* text = (char*)malloc(buffer * sizeof(char)); 
        if (!text){
                return NULL;
        }
        text[0] = '\0';
        int count_empt_str = 0;
        while (1){
                char input[BUFFER];
                if (!fgets(input, sizeof(input), stdin)){
                        free(text);
                        return NULL;
                }
                if (strcmp(input, "\n") == 0){
                        count_empt_str++;
                        if (count_empt_str == 1){
                                break;
                        }
                } else{
                        count_empt_str = 0;
                        if (strlen(input) > 1){
				if (strlen(text) + strlen(input) + 1 > buffer){
                                	buffer += BUFFER;
                                	text = (char*)realloc(text, buffer * sizeof(char));
                                	if (!text){
                                        	return NULL;
                                	}
                        	}
			}
                        strcat(text, input);
                }

        }
        return text;
}


char** text_split (char* text, int* count){
        char** time_arr = (char**)malloc(BUFFER * sizeof(char*));
        const char* separator = ".";
	char* text_copy = strdup(text);
        if (!text_copy){
		free(time_arr);
                return NULL;
        }

        char* token = strtok(text_copy, separator);
        int cnt_token = 0;

        while (token){
                token = del_tab(token);
                if (token && strlen(token) > 0){
			time_arr[cnt_token] = strdup(token);
                        if (!time_arr[cnt_token]){
				for (int i = 0; i < cnt_token; i++){
					free(time_arr[i]);
				}
				free(time_arr);
				free(text_copy);
				return NULL;
			}
			cnt_token++;
                }
                token = strtok(NULL, separator);
        }
	free(text_copy);
        *count = cnt_token;
        return time_arr;
}



void put_text(char* arr[], int count){
	for (int i = 0; i < count; i++){
		printf("%s.\n", arr[i]);
		free(arr[i]);
	}
	free(arr);
}

