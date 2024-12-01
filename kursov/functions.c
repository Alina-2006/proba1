#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "read_put_text.h"
#include "functions.h"

#define YELLOW "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[1;0m"


char* to_lower(char* sent){ //нужен const char* или нет?
	int len = strlen(sent);
	char* new_sent = malloc(len*sizeof(char));
	for (int i = 0; i < len; i++){
		new_sent[i] = tolower(sent[i]);
	}
	new_sent[len] = '\0';
	return new_sent;
}

char** del_repeat(char* split_text[], int count, int* new_count){
	char** uniq_arr = malloc(count * sizeof(char*));
	if (!uniq_arr){
	       	free(uniq_arr);
		return NULL;
	}

	int uniq_index = 0;
	for (int i = 0; i < count; i++){
		char* lower_sent = to_lower(split_text[i]);
		int duplics = 0;
		for (int j = 0; j < uniq_index; j++){
			char* lower_uniq = to_lower(uniq_arr[j]);
			if (strcmp(lower_sent, lower_uniq) == 0){
				duplics = 1;
				break;
			}
		}

		if (!duplics){
			uniq_arr[uniq_index] = split_text[i];
			uniq_index++;
		} else{
			free(lower_sent);
		}
	}

	*new_count = uniq_index;
	return uniq_arr;
}

char* function_0(){
	char* text = read_text();
        if (!text){
                printf("Error reading text.\n");
        }
        int count = 0;
        char** split_text = text_split(text, &count);
        if (!split_text){
                free(text);
                printf("Error splitting text.\n");
        }

        int new_count = 0;
        char** uniq_sents = del_repeat(split_text, count, &new_count);
        if (!uniq_sents){
                free(text);
                for (int i = 0; i < count; i++){
                        free(split_text[i]);
                }
                free(split_text);
                printf("Error removing duplicates.\n");
        }
	//char* res_arr = (char*)malloc(new_count * sizeof(char));
        //res_arr =
	put_text(uniq_sents, new_count);
	
	//return res_arr;
}


char* function_1(){
	char* text = read_text();
        if (!text){
                printf("Error reading text.\n");
        }
        int count = 0;
        char** split_text = text_split(text, &count);
        if (!split_text){
                free(text);
                printf("Error splitting text.\n");
        }

        int new_count = 0;
        char** uniq_sents = del_repeat(split_text, count, &new_count);
        if (!uniq_sents){
                free(text);
                for (int i = 0; i < count; i++){
                        free(split_text[i]);
                }
                free(split_text);
                printf("Error removing duplicates.\n");
        }

	char* res_arr = (char*)malloc(new_count * sizeof(char));
	
	//const char* banana = "banana";	
	//const char* apple = "apple";

	/*for (int i = 0; i < new_count; i++){
		char* sent = unic_sents[i];
		if (strchr(sent, banana) != NULL){
			int color_sent_index = strstr(sent, banana);
			printf("%s%c%s", YELLOW, sent[color_sent_index], RESET); 
		}
	}*/

        //put_text(uniq_sents, new_count);
	
	function_0();

	for (int i = 0; i < new_count; i++){
		char* sent = uniq_sents[i];
		int has_banana = strstr(sent, "banana") != NULL;
		int has_apple = strstr(sent, "apple") != NULL;

		if (has_banana || has_apple){
			char* pos;

			pos = strstr(sent, "banana");
			if (pos){
				*pos = '\0';
				printf("%s%s%s", sent, YELLOW, "banana" RESET);
				pos = pos + strlen("banana");
			}
			printf("%s\n", sent);
		}
	}
}
