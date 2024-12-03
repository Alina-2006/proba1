#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "read_put_text.h"
#include "functions.h"

#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RESET "\033[1;0m"


char* to_lower(char* sent){
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
	put_text(uniq_sents, new_count);
	
	free(text);

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
	
	int cnt_ban_apl = 0;

	for (int i = 0; i < new_count; i++){
		char* sent = uniq_sents[i];
		int has_banana = strstr(sent, "banana") != NULL;
                int has_apple = strstr(sent, "apple") != NULL;

		if (has_banana || has_apple){
			cnt_ban_apl++;
		}
	}
	
	for (int i = 0; i < new_count; i++){
		char* sent = uniq_sents[i];
                int has_banana = strstr(sent, "banana") != NULL;
                int has_apple = strstr(sent, "apple") != NULL;

                if (!cnt_ban_apl){
			printf("Error: There is no banana or apple in sentences.\n");
                        break;
		} else{
			if (has_banana || has_apple){
                        	char* pos;

                        	pos = strstr(sent, "banana");
                        	if (pos){
                                	*pos = '\0';
                                	printf("%s%s%s%s", sent, YELLOW, "banana", RESET);
                                	sent = pos + strlen("banana");
                        	}
                        
                        	pos = strstr(sent, "apple");
                        	if (pos){
                                	*pos = '\0';
                                	printf("%s%s%s%s", sent, GREEN, "apple", RESET);
                                	sent = pos + strlen("apple");
                        	}
                        	printf("%s%c\n", sent, '.');

			}
		}
	}

	free(text);

	for (int i = 0; i < new_count; i++){
		free(uniq_sents[i]);
	}
	free(uniq_sents);
	
}

char* function_2(){
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

	int has_num_or_cap = 0;

	for (int i = 0; i < new_count; i++){
		char* sent = uniq_sents[i];

		for (int j = 0; j < new_count; j++){
			if (isdigit(sent[j]) || isupper(sent[j])){
				has_num_or_cap++;
			}
		}
	}
	
	for (int i = 0; i < new_count; i++){
                char* sent = uniq_sents[i];

		if (!has_num_or_cap){
			printf("Error: No sentences with capital letters or numbers.\n");
			break;
                } 
		
		for (int j = 0; sent[j] != '\0'; j++){
                        if (isdigit(sent[j])){
                                sent[j] = 'D';
                        } else{
                                sent[j] = tolower(sent[j]);
                        }
		}
		printf("%s%c\n", sent, '.');	
	}
	
	free(text);

	for (int i = 0; i < new_count; i++){
		free(uniq_sents[i]);
	}
	free(uniq_sents);
}


char* function_3(){
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

	int count_15 = 0;

	for (int i = 0; i < new_count; i++){
		char* sent = uniq_sents[i];
		if (strlen(sent) > 15){
			count_15++;
		}	
	}
	for (int i = 0; i < new_count; i++){
                char* sent = uniq_sents[i];

		if (!count_15){
			printf("Error: There is no sentence longer 15.\n");
			break;
		} else{
			if (strlen(sent) < 15){
				printf("%s%c\n", sent, '.');
			}
		}
	}
	free(text);

	for (int i = 0; i < new_count; i++){
		free(uniq_sents[i]);
	}
	free(uniq_sents);
}

int multip_numb(const char* str){
	int product = 1;
	int has_digit = 0;
	for (const char *p = str; *p; p++){
		if (isdigit(*p)){
			product *= (*p - '0');
			has_digit = 1;
		}
	}
	return has_digit ? product : 0;
}


int compare(const void* a, const void* b){
	const char* f = *(const char**)a;
	const char* s = *(const char**)b;
	int product_f = multip_numb(f);
	int product_s = multip_numb(s);
	return product_f - product_s;
}

char* function_4(){
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
	
	int multip = 0;
	
	for (int i = 0; i < new_count; i++){
		char* sent = uniq_sents[i];
		if (multip_numb(sent)){
			multip++;
		}
	}

	for (int i = 0; i < new_count; i++){
                char* sent = uniq_sents[i];
		if (!multip){
			printf("Error: No sentences with numbers.\n");
			break;
		}else{
			qsort(uniq_sents, new_count, sizeof(char*), compare);
		}
	} 

	if (multip){
		put_text(uniq_sents, new_count);
	}
	free(text);
}

void function_5(){
	printf("0: This is a primary text processing function (it outputs each sentence on a new line, removes spaces and removes duplicate sentences).\n");
	printf("1: This function prints all sentences that contain the word banana or apple, coloring banana yellow and apple green.\n");
	printf("2: This function replaces all letters with lowercase and all numbers with D.\n");
	printf("3: This function removes all sentences whose length is greater than 15.\n");
	printf("4: This function sorts sentences in ascending order of the products of all digits in them.\n");
	printf("5: This function shows information about the functions that the program implements.\n");
} 
