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
	char* new_sent = malloc((len + 1)*sizeof(char));
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


//int len_cmp

char* longestwrd(char* sent, char* max_len_word){
	char* word = strtok(sent, " ");
	max_len_word[0] = '\0';
	//char new_arr[2024] = "";
	while (word){
		if (strlen(word) > strlen(max_len_word)){
			strcpy(max_len_word, word);
		}
		word = strtok(NULL, " ");
	}
	return max_len_word;
	//strcat(new_arr, max_len_word);
	//strcat(new_arr, " ");
}


char* function_9(){
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

	//char** copy_uniq_sents = uniq_sents;

	//put_text(copy_uniq_sents, new_count);

	char* longest_arr[2048];
/*
	char* longestwrd(char* sent, char* max_len_wd){
		char max_len_sent;
		for (int i = 0; i < new_count; i++){
			char* sent = uniq_sents[i];
		
			char* word = strtok(sent, " ");
			char* max_len_word = '\0';
			while (word){
				if (strlen(word) > strlen(max_len_word)){
					strcpy(max_len_word, word);
				}
				word = strtok(NULL, " ");
			}
		}
	}
*/
	for (int k = 0; k < new_count; k++){
                printf("%s.\n", uniq_sents[k]);
        }

	char end_str[1024];
	for (int i = 0; i < new_count; i++){
		longest_arr[i] = (char*)malloc(1024 * sizeof(char));
		if (longest_arr[i] == NULL){
			printf("Memory allocation error.\n");
			for (int j = 0; j < i; j++){
				free(longest_arr[j]);
			}
			free(text);
			for (int j = 0; j < count; j++){
				free(split_text[j]);
			}
			free(split_text);
		}
		longestwrd(uniq_sents[i], longest_arr[i]);
	}

	//put_text(uniq_sents, new_count);	

	for (int j = 0; j < new_count; j++){
		printf("%s", longest_arr[j]);
		if (j < new_count - 1){
			printf(" ");
		}
	}
	printf(".\n");


		/*
		max_len_sent = uniq_sents[0];
		char arr = (char)malloc(2048 * sizeof(char));
		char word[100];
		for (int j = 0; j < strlen(sent); j++){
			for (int k = i+1; k < strlen(sent) - i-1; k++){
				if strlen(sent[i]) > strlen(sent[j]){
					word = sent[i];
				} else{
					word = sent[j];
				}
			}
			
		}
		*/
	


}

char* swap_places(char* sent){ //char* max_len_word, char* min_len_word){
	char* sent_copy = strdup(sent);
	char* word = strtok(sent_copy, " "); 
	char* max_len_word = NULL;
	char* min_len_word = NULL;
	char* max_len_word_prev = NULL;
	char* min_len_word_prev = NULL;
	//char* max_pos = NULL;
	//char* min_pos = NULL;


	while (word){
		if (max_len_word == NULL || strlen(word) > strlen(max_len_word)){
			//min_len_word = max_len_word;
			//min_len_word_prev = max_len_word_prev;
			max_len_word = word;
			//max_pos = strstr(sent, max_len_word);
			//max_len_word_prev = sent;
		} 
		if (min_len_word == NULL || (strlen(word) < strlen(min_len_word) && word != max_len_word)){
			min_len_word = word;
			//min_len_word_prev = sent;
			//min_pos = strstr(sent, min_len_word);
		}
		word = strtok(NULL, " ");
	}

	if (max_len_word && min_len_word){
		char temp[100];
		strcpy(temp, max_len_word);
		
		char* max_pos = strstr(sent, max_len_word);
		char* min_pos = strstr(sent, min_len_word);
		
		if (max_pos && min_pos){
			strncpy(max_pos, min_len_word, strlen(min_len_word));
			strncpy(min_pos, temp, strlen(temp));
		}
	}
	free(sent_copy);
	return sent;

}

char* function_10(){
	char* text = read_text();
        if (!text){
                printf("Error reading text.\n");
		return NULL;
        }
        int count = 0;
        char** split_text = text_split(text, &count);
        if (!split_text){
                free(text);
                printf("Error splitting text.\n");
		return NULL;
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
		return NULL;
        }


	char* res_arr[2048];
	for (int i = 0; i < new_count; i++){
		res_arr[i] = (char*)malloc(2048 * sizeof(char));
		if (res_arr[i] == NULL){
                        printf("Memory allocation error.\n");
                        for (int j = 0; j < i; j++){
                                free(res_arr[j]);
                        }
                        free(text);
                        for (int j = 0; j < count; j++){
                                free(split_text[j]);
                        }
                        free(split_text);
			return NULL;
                }
		strcpy(res_arr[i], swap_places(uniq_sents[i]));
	}

	for (int j = 0; j < new_count; j++){
		printf("%s.\n", res_arr[j]);
	}


}



char* shortestwrd(char* sent, char* min_len_word){
	char* word = strtok(sent, " ");
	//min_len_word = *sent[0]; //!
	if (word != NULL){
		strcpy(min_len_word, word);
	}
	while (word){
		if (strlen(word) < strlen(min_len_word)){
			strcpy(min_len_word, word);
		}
		word = strtok(NULL, " ");
	}
	return min_len_word;
}


char* function_11(){
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

	char* shortest_arr[2048];

	for (int k = 0; k < new_count; k++){
		printf("%s.\n", uniq_sents[k]);
	}
	
	for (int i = 0; i < new_count; i++){
		shortest_arr[i] = (char*)malloc(1024 * sizeof(char));
		if (shortest_arr[i] == NULL){
                        printf("Memory allocation error.\n");
                        for (int j = 0; j < i; j++){
                                free(shortest_arr[j]);
                        }
                        free(text);
                        for (int j = 0; j < count; j++){
                                free(split_text[j]);
                        }
                        free(split_text);
                }
		shortestwrd(uniq_sents[i], shortest_arr[i]);
	}
	for (int j = 0; j < new_count; j++){
		printf("%s", shortest_arr[j]);
		if (j < new_count - 1){
			printf(" ");
		}
	}
	printf(".\n");

}

char* function_12(){
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

	int N;
	scanf("%d", &N);
	getchar();

	char* res_arr[1024];

	for (int i = 0; i < N; i++){
		for (int j = 0; j < new_count; j++){
			printf("%s", uniq_sents[i]);
		}
	}
	printf(".\n");
	/*
	for (int k = 0; k < new_count; k++){
		printf("%s\n", res_arr[k]);
	}
	*/
	/*
	for (int i = 0; i < N; i++){
		strcat(res_arr[i], uniq_sents[i]);
		if (i < N - 1){
			strcat(res_arr[i], " ");
		} 
		for (int j = 0; j < N; j++){
			printf("%s", uniq_sents[j]);
		}
		//printf(".\n");
	}

	for (int j = 0; j < new_count; j++){
		printf("%s\n", res_arr[j]);
	}
	*/

}
	
