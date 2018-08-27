#include "ArgumentManager.h"

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Usage: count filename=input1.txt\n";
	}
	ArgumentManager am(argc, argv);
	std::string filename = am.get("filename"); //get the name of the file
	std::ifstream ifs(filename.c_str()); 

	std::string line;
	int numberCount = 0; //initializes the number count to zero 
	int wordCount = 0; //initializes the word count to zero 
	while (getline(ifs, line)) {   //read in the entire file as a string and store it in line 

		int length = line.length(); //get the length of the whole string and store it in length  
		for (int i = 0; i < length; i++) //this loop will replace all of the separators with a space
		{
			if (ispunct(line[i])) //determines if its a separator using the ispunc() function 
				line[i] = ' '; //if it is then replace it with a space
		}

		stringstream ss(line.c_str());  
		std::string str; 

		while (ss >> str)
		{
			if (is_number(str)) //if it is a number then update the number counter 
				numberCount++;
			else
				wordCount++; //else update the word count because if it isn't a number then it's a word 
		}
}
	std::cout << "words=" << wordCount;
	std::cout << " numbers=" << numberCount << std::endl;
	return 0;
}