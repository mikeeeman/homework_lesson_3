#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 80

void usage(void)
{
  printf("Usage:\n");
  printf(" -f<name>\n");
  printf(" -l<name>\n");
  exit (8);
}

int main(int argc, char *argv[])
{
	setbuf(stdout, NULL);
  char *fnamePtr = NULL;
  char *lnamePtr = NULL;
  printf("Program name: %s\n", argv[0]);

  if(2 > argc)
  {
    printf("Type: %s -h\n", argv[0]);
    printf("To get usage dialogue\n\n");
  }


  while ((argc > 1) && (argv[1][0] == '-'))
  {
    switch (argv[1][1])
    {
      case 'f':
        fnamePtr = &argv[1][2];
        break;

      case 'l':
        lnamePtr = &argv[1][2];
        break;

      case 'h':
        usage();
        break;

      default:
        printf("Wrong Argument: %s\n", argv[1]);
        usage();
    }
    ++argv;
    --argc;
  }

  // read first name
  if (fnamePtr == NULL)
  {
    fnamePtr = (char*)malloc(sizeof(char)*NAME_LENGTH);
    if(fnamePtr == NULL)
    {
      puts("ERROR : memory allocation failed");
      exit(EXIT_FAILURE);
    }
    printf("What is your first name : ");
    fgets(fnamePtr, NAME_LENGTH, stdin);
    // remove carry-return
    strtok(fnamePtr,"\r");
  }

  // read last name
  if (lnamePtr == NULL)
  {
    lnamePtr = (char*)malloc(sizeof(char)*NAME_LENGTH);
    if(lnamePtr == NULL)
    {
      puts("ERROR : memory allocation failed");
      exit(EXIT_FAILURE);
    }
    printf("What is your last name  : ");
    fgets(lnamePtr, NAME_LENGTH, stdin);
    // remove carry-return
    strtok(lnamePtr,"\r");
  }

  printf("\nHello %s your name is: %s %s\n", fnamePtr, fnamePtr, lnamePtr);

  return EXIT_SUCCESS;
}
