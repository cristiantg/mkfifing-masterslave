#include <stdio.h>
#include <stdlib.h>

int main (int na, char *av[]) {

    /* OPEN THE NAMED PIPES (A file created with mkfifo tubo ) */
    FILE *fout = NULL ;
    FILE *finp = NULL ;

static
    char	res[2048] ;


setbuf(stdout, NULL);

    if (na <=2) { fprintf(stderr, "\nUsage: %s to_pipe from_pipe\n\n", av[0]); exit(-1) ; }

    fout = fopen((const char *) av[1], "w") ;
    finp = fopen((const char *) av[2], "r") ;
    //printf("# READY TO START EXCHANGE ....\n"); 

//    for (int i = 0 ; i< 2 ; i++) {
	    //printf(">>>> FICHERO%4.4d.wav\n", i) ;
	    fflush(stdout) ;

	    fprintf(fout, "%s\n", av[3]) ;
	    fflush(fout) ;
	    //printf("\nwaiting for server response...\n");
/* Wait until the server ends the processing */
	    fgets(res, sizeof(res)/sizeof(char), finp) ;
	    fflush(finp) ;
	    //printf("\nserver response finished\n");
	    printf("%s", res) ; 
	    fflush(stdout) ;

  //  }
    fclose(fout) ;
    fclose(finp) ;
}
