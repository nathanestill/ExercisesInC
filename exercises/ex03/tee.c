#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*
3. I used the HFC book a lot to get most of the argument, file opening, etc stuff and it helped a lot.
I used the pdf and I think I should have used my hard copy and it would've gone faster.
4. That implementation has a lot of code, and uses many warnings that I don't really understand, but the 
command line argument handling seems to largely be the same.

*/

int main(int argc, char *argv[]){
	int aFlag = 0;
	char ch;
	while((ch = getopt(argc, argv, "a")) != EOF)
		switch(ch) {
			case 'a':
				aFlag = 1;
				break;
			default:
				fprintf(stderr, "Unknown Option '%s'\n", optarg);
				return 1;
		}
	argc -= optind;
	argv += optind;
	FILE *out_file;
	if(aFlag){
		out_file = fopen(argv[0], "a");
	} else {
		out_file = fopen(argv[0], "w");
	}
	char input[50]; 

    while(fgets(input, 50, stdin) != NULL){
	    fprintf(stdout, "%s", input);
	 	fprintf(out_file, "%s", input);
	}
    
    fclose(out_file); 
    return 0;  
}