/*
	Morse code translator made to be used in terminal for fun
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Letter
{
	char latin_name;	//'a' , 'b', 'c', etc
	char *morse_name; // ".--" , "-.-." , etc
};

struct Letter alphabet[38]; //26 letters, 10 numbers, 1 whitespace and 1 for array limit safety
int last_index = 0;

/*
	this function does have all the possible failure exits by code
	with it's error message, obviously because idk about errno.h
*/
void failed_exit(int code)
{

}

/*
	this function was made only to debug the addition 
	functionality of the alphabet
*/
void debug_added()
{
	printf("\nWas added:\nLetter : %c",alphabet[last_index - 1].latin_name);
	printf("\nMorse : %s", alphabet[last_index - 1].morse_name);
}

//it adds letters to the alphabet
void add_letter(char letter_name, char* morse_version)
{
	alphabet[last_index].latin_name = letter_name;
	alphabet[last_index].morse_name = malloc(strlen(morse_version) + 1);
	strcpy(alphabet[last_index].morse_name, morse_version);

	last_index++;
	//debug_added();
}

//couldnt be made in a loop because there isno math for the morse string
int create_alphabet()
{
	add_letter('a',".-");
	add_letter('b',"-...");
	add_letter('c',"-.-.");
	add_letter('d',"-..");
	add_letter('e',".");
	add_letter('f',"..-.");
	add_letter('g',"--.");
	add_letter('h',"....");
	add_letter('i',"..");
	add_letter('j',".---");
	add_letter('k',"-.-");
	add_letter('l',".-..");
	add_letter('m',"--");
	add_letter('n',"-.");
	add_letter('o',"---");
	add_letter('p',".--.");
	add_letter('q',"--.-");
	add_letter('r',".-.");
	add_letter('s',"...");
	add_letter('t',"-");
	add_letter('u',"..-");
	add_letter('v',"...-");
	add_letter('w',".--");
	add_letter('x',"-..-");
	add_letter('y',"-.--");
	add_letter('z',"--..");
	add_letter(' ',"-.-.-"); //non standard whitespace character

	printf("\n");
	return 0;
}

int binary_search(bool type, char* target)
{
	int left = 0, right = 37;
	int middle = right / 2;

	if(type == 1) //search by letter
	{
		while(true)
		{
			char source_name = alphabet[middle].latin_name;

			if(left > right)	//doesnt exist, bad letter
				return NULL;
			else if(source_name == target)
				return middle;
			else if(source_name < target)
			{
				left = middle + 1;
				middle = (left + right) / 2;
			}
			else if(source_name > target)
			{
				right = middle - 1;
				middle = (left + right) / 2;
			}
		}
	}
	else if(type == 2) //search by morse code
	{
		while(true)
		{
			//i have to change this to ACTUAL point towards the morses_name ON the array
			char* source_morse = malloc(strlen(alphabet[middle].morse_name) + 1);
			strcpy(source_morse, alphabet[middle].morse_name);

			if(left > right)
				return NULL;
			else if(strcmp(source_morse, target) == 0)
				return middle;
			else if(strcmp(source_morse, target) < 0)
			{
				left = middle + 1;
				middle = (left + right) / 2;
			}
			else if(strcmp(source_morse, target) > 0)
			{
				right = middle - 1;
				middle = (left + right) / 2;	
			}
		}		
	}
	else
	{
		failed_exit(1);
	}
}

int parse_to_morse(char* line)
{
	char* morse_line = malloc(1);

	int i;
	for(i = 0; i < strlen(line); i++)
	{

	}
}

int main()
{
	char* line =  malloc(strlen("fuck you") + 1);
	strcpy(line, "fuck you");

	if(create_alphabet() == 0)
	{
		//parse_to_morse(line);

		int index_result = binary_search(1, 'c');
		printf("\nThe Letter is : %c", alphabet[index_result].latin_name);
		printf("\nThe morse is : '%s'\n\n", alphabet[index_result].morse_name);
	}
	else
		return 1; //standard erroneous exit
}