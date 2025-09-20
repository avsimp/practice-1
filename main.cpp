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

	FILE *file = fopen(file_name, "r");
	char cur_word[32] = {};
	while (fscanf(file, "%s", cur_word) == 1){
		std::cout << cur_word;
	}
	return 0;
}
