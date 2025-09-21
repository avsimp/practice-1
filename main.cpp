#include <iostream>
#include <cstring>
#include <fstream>

int main(int argc, char* argv[]) {
	char* word = "0";
	char* file_name = "0";
	

	for (int i = 0; i < argc; i++){
		if (strcmp(argv[i], "--word") == 0){
			word = argv[i+1];
			i++;
		}
		else if (strcmp(argv[i], "--file") == 0){
			file_name = argv[i+1];
			i++;
		}
	}
	if (strcmp(word, "0") == 0 || strcmp(file_name, "0") == 0){
		std::cout << "FAILED --word and --file arguments are required" << std::endl;
		return 0;
	}

	FILE* file = fopen(file_name, "r");
	if (!file)
    {
        std::cout << "FAILED cant open file" << std::endl;
		return 0;
    }
	const int WORD_LENGTH = 32;
	char cur_word[WORD_LENGTH] = {};
	int counter = 0;
	while (fscanf(file, "%s", cur_word) == 1){
		bool contain_let = true;
		for (int i = 0; word[i]!='\0';i++){
			bool flag = false;
			for (int j = 0; j < WORD_LENGTH && cur_word[j]!='\0'; j++){
				//std::cout << word[i] << " " << cur_word[j] << std::endl;
				if (word[i] == cur_word[j]){
					flag = true;
					break;
				}
			}
			if (!flag){
				contain_let = false;
				break;
			}
		}
		if (contain_let){
			counter++;
		}
	}
	fclose(file);
	std::cout << counter << std::endl;
	return 0;
}
