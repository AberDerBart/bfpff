#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static char default_o_file[]="out.bf";

int checkSyntax(char* code){
	int brackets=0;
	int index=0;
	while(code[index]){
		if(code[index]=='['){
			brackets++;
		}else if(code[index]==']'){
			brackets--;
			if(brackets<0){
				fprintf(stderr,"Error at %d: missing '['\n",index);
				return index;
			}
		}else if(code[index]=='-'||code[index]=='.'||code[index]==','){
			fprintf(stderr,"Error at %d: forbidden symbol: '%c'\n",index,code[index]);
			return index;
		}
		index++;
	}
	if(brackets){
		fprintf(stderr,"Error at %d: missing ']'\n",index);
		return index;
	}
	return 0;
}

int compile(FILE* inputFile, FILE* outputFile){
	long len;
	char* inputCode;

	fseek(inputFile,0,SEEK_END);
	len=ftell(inputFile);
	rewind(inputFile);

	inputCode=malloc(len+1*sizeof(char));

	fread(inputCode,sizeof(char),len,inputFile);

	if(checkSyntax(inputCode)==0){
		fprintf(outputFile,",[>,]<%s[.>]\n",inputCode);
		return 0;
	}else{
		return 1;
	}
}

int main(int argc,char** argv){
	char* outputFileName=default_o_file;
	char* inputFileName=NULL;
	int c;
	FILE* inputFile;
	FILE* outputFile;
	
	//parse command line arguments
	while((c=getopt(argc,argv,"o:")) != -1){
	    switch(c){
	        case 'o':
	            //the argument following "-o" specifies the output file
	            outputFileName=optarg;
	            break;
	        default:
	            break;
	    }
	}
	
	//get input file name
	if(optind==argc-1){
		inputFileName=argv[optind];
		
		inputFile=fopen(inputFileName,"r");
		if(!inputFile){
			fprintf(stderr,"Error: could not open file for reading: %s\n",inputFileName);
			return -3;
		}

		outputFile=fopen(outputFileName,"w");
		if(!outputFile){
			fprintf(stderr,"Error: could not open file for writing: %s\n",outputFileName);
			fclose(inputFile);
			return -4;
		}
		
		compile(inputFile,outputFile);

		fclose(inputFile);
		fclose(outputFile);
	}else if(optind>argc-1){
		fprintf(stderr,"Error: expected filename\n");
		return -1;
	}else{
		fprintf(stderr,"Error: too many arguments\n");
		return -2;
	}
	
	return 0;
	
	if(argc>=2){
		if(!checkSyntax(argv[1])){
			printf(",[>,]<%s[.>]\n",argv[1]);
			return 0;
		}else{
			return 1;
		}
	}else{
		fprintf(stderr,"Usage: %s [-o OUTPUTFILE] INPUTFILE\n",argv[0]);
		return 2;
	}
}

