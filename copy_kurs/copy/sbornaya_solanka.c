from main.c

/*
        char* text = read_text();
        if (!text){
                printf("Error reading text.\n");
                return 1;
        }
        int count = 0;
        //char* split_text = text_split(text);
        char** split_text = text_split(text, &count);
        //char* text_new = del_repeat(split_text);
        if (!split_text){
                free(text);
                printf("Error splitting text.\n");
                return 1;
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
                return 1;
        }
        
        put_text(uniq_sents, new_count);

        if (text){
                put_text(uniq_sents, new_count);        
                //put_text(split_text, count);
                free(text);
        } else{
                printf("Error reading text");
        }
        return 0;
*/

from read and put.c

read
 /*size_t len_text = strlen(text);
                if (len_text > 0 && text[len_text - 1] == '.'){
                        text[len_text] = '\0';
                }*/

/*Result text_split(char* text){
        Result result;
        result.text = (char*)malloc(BUFFER * sizeof(char));
        result.count = 0;

        const char* razdel = ".";
        if (!text){
                result.text = NULL;
                return result;
        }
        char* token = strtok(text, razdel);
        int offset = 0;
        int cnt_token = 0;

        while (token){
                token = del_tab(token);
                if (token && strlen(token) > 0){
                        result.count++;
                        int len = strlen(token);
                        if (offset + len +1 >= BUFFER){
                                break;
                        }
                        strcpy(&result.text[offset], token);
                        offset += len;
                        result.text[offset++] = '.';
                }
                token = strtok(NULL, razdel);
        }
        if (offset > 0)
                result.text[offset - 1] = '\0';
        else
                result.text[0] = '\0';

        return result;
}

*/

from text split

                       /* int len = strlen(token);
                        if (offset + len +1 >= BUFFER){
                                break;
                        }
                        strcpy(&time_arr[offset], token);
                        offset += len;
                        time_arr[offset++] = '.';*/

      /*
        if (offset > 0)
                time_arr[offset - 1] = '\0';
        else
                time_arr[0] = '\0';
        */


from put text

        /*const char *razdel = ".";
        //char* text_copy = strdup(text);
        if (!text){
                //free(text);
                return NULL;
        }

        char* text_copy = strdup(text);
        if (!text_copy){
                return NULL;
                //free(text_copy);
        }

        char* token = strtok(text_copy, razdel);
        while (token){
                token = del_tab(token);
                if (token && strlen(token) > 0){
                        printf("%s%c\n", token, '.');
                }
                token = strtok(NULL, razdel);
        }
        free(text);//_copy);*/

        //*cnt_snt

from func3

               //int count_15 = 0;
                /*if (strlen(sent) < 15){
                        printf("%s%c\n", sent, '.');
                        count_15++;
                }*/
                 /*if (count_15 > 0){
                        if (strlen(sent) < 15){
                                printf("%s%c\n", sent, '.');
                        }
                } else{
                        printf("Error: There is no sentence longer 15.\n");
                        break;
                        printf("Error: There is no sentence longer 15.\n");
                                break;
                        }else {
                                printf("%s%c\n", sent, '.');
                        }
                        }       */
изначально была такая

for (int i = 0; i < new_count; i++){
                char* sent = uniq_sents[i];
                if (strlen(sent) < 15){
                        printf("%s%c\n", sent, '.');
                }
        }


from func1

                /*
        for (int i = 0; i < new_count; i++){
                char* sent = uniq_sents[i];
                int has_banana = strstr(sent, "banana") != NULL;
                int has_apple = strstr(sent, "apple") != NULL;

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
                }  else{
                        printf("Error: There is no banana or apple in sentences.\n");
                        break;
                }

        }*/


from func2

       /*for (int i = 0; i < new_count; i++){
                char* sent = uniq_sents[i];

                for (int j = 0; sent[j] != '\0'; j++){
                        if (isdigit(sent[j])){
                                sent[j] = 'D';
                        } else{
                                sent[j] = tolower(sent[j]);
                        }
                }
                printf("%s%c\n", sent, '.');
        } */

from func4

       /* int multip = 0;

        for (int i = 0; i < new_count; i++){
                char* sent = uniq_sents[i];
                for (int j = 0; sent[i] != '\0'; j++){
                        if (isdigit(sent[j])){
                                multip *= sent[j];
                        } else{
                                printf("Error: no numbers in sentence.");
                        }
                }


        } */


/*
void prim_proces(){
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
}
*/

/*
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
                        strncat(text, input, strlen(input));
                }

        }
        return text;
}
*/









int compare_2(const void* a, const void* b){
        const char** f = (const char**)a;
        const char** s = (const char**)b;
        int product_f = cnt_words(*f);
        int product_s = cnt_words(*s);
        if (product_f > product_s)
                return 1;
        if (product_f < product_s)
                return -1;
        if (product_f == product_s){
                if (strlen(*f) > strlen(*s))
                        return 1;
                if (strlen(*f) == strlen(*s))
                        return 0;
                else
                        return -1;
        }
        //return 0;
}

int cnt_words(const char* str){

        int cnt = 0;
        int in_word = 0;

        for (int i = 0; i < strlen(str); i++){
                if (str[i] != ' '){
                        if (!in_word){
                                cnt++;
                                in_word = 1;
                        }
                } else
                        in_word = 0;
        }

        return cnt;
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

        qsort(uniq_sents, new_count, sizeof(char*), compare_2);
        
        put_text(uniq_sents, new_count);
}

char* function_9();
