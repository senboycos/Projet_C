/*
 * Ce fichier ne fait pas partie du projet, il sert juste à
 * tester la gestion du fichier de configuration
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "service.h"

#include "config.h"

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <fichier config>\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

void test_config(const char *filename)
{
    int nb;

    // un appel ici à config_getNbServices, .., config_exit doit planter
    config_init(filename);
    // ici, un autre appel à config_init doit planter
    nb = config_getNbServices();
    printf("Il y a %d service(s) (SERVICE_NB = %d)\n", nb, SERVICE_NB);
    printf("L'exécutable s'appelle \"%s\"\n", config_getExeName());
    for (int i = 0; i < nb; i++)
    {
        printf("service %d : %s\n",
               i,
               (config_isServiceOpen(i) ? "ouvert" : "ferme "));
    }
    config_exit();
    // ici, un appel à config_getNbServices, ..., config_exit doit planter
}

int main(int argc, char * argv[])
{
    if (argc != 2)
        usage(argv[0], NULL);

    test_config(argv[1]);

    return EXIT_SUCCESS;
}
