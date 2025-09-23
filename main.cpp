#include <iostream>
#include <cstring>
#include <fstream>

const int kWorldLength = 32;

bool WordHasAllLetters(char word[], char* base_word) {
	for (int i = 0; base_word[i] != '\0';i++){
		bool flag = false;
		for (int j = 0; j < kWorldLength && word[j] != '\0'; j++){
			if (base_word[i] == word[j]){
				flag = true;
				break;
			}
		}
		if (!flag){
			return false;
		}
	}
	return true;
}

int CountWords(FILE* file, char* base_word) {
	int counter = 0;
	char cur_word[kWorldLength] = {};
	while (fscanf(file, "%s", cur_word) == 1){
		if (WordHasAllLetters(cur_word, base_word)){
			counter++;
		}
	}
	return counter;
}

int main(int argc, char* argv[]) {
	char* base_word = NULL;
	char* file_name = NULL;

	for (int i = 0; i < argc; i++){
		if (strcmp(argv[i], "--word") == 0 && i < argc - 1){
			base_word = argv[i+1];
			i++;
		}
		else if (strcmp(argv[i], "--file") == 0 && i < argc - 1){
			file_name = argv[i+1];
			i++;
		}
	}
	//if (strcmp(word, '\0') == 0 || strcmp(file_name, '\0') == 0){
	if (base_word == NULL || file_name == NULL){
		std::cerr << "FAILED --word and --file arguments are required" << std::endl;
		return 10;
	}

	FILE* file = fopen(file_name, "r");
	if (!file){
        std::cerr << "FAILED cant open file" << std::endl;
		return 20;
    }

	std::cout << CountWords(file, base_word) << std::endl;
	fclose(file);

	return 0;
}
