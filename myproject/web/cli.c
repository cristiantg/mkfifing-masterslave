#include <stdio.h>
#include <stdlib.h>
//#include <sys/unistd.h> // alpine does not include this library for unlink()

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

	    fflush(stdout) ;

	    fprintf(fout, "%s %s %s %s %s %s %s %s\n", av[3], av[4], av[5], av[6], av[7], av[8], av[9], av[10]) ;
	    fflush(fout) ;
	    //printf("\nwaiting for server response...\n");
/* Wait until the server ends the processing */
	    fgets(res, sizeof(res)/sizeof(char), finp) ;
	    fflush(finp) ;
	    //printf("\nserver response finished\n");
	    printf("%s", res) ; 
	    fflush(stdout) ;

    fclose(fout) ;
    fclose(finp) ;

    /* Remove temporal files, unlink is not include in alpine image-docker*/
    remove(av[1]) ;
    remove(av[2]) ;
    remove(av[10]) ;
}
