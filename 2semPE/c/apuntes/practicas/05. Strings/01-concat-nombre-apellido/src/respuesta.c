#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    char name[MAX] = "";
    char last_name[MAX] = "";
    char full_name[2 * MAX + 2] = "";

    puts("Dame tu nombre");
    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        name[0] = '\0';
    }
    else
    {
        size_t name_len = strlen(name);
        if (name_len > 0 && name[name_len - 1] == '\n')
            name[name_len - 1] = '\0';
    }

    puts("Dame tu last_name");
    if (fgets(last_name, sizeof(last_name), stdin) == NULL)
    {
        last_name[0] = '\0';
    }
    else
    {
        size_t last_len = strlen(last_name);
        if (last_len > 0 && last_name[last_len - 1] == '\n')
            last_name[last_len - 1] = '\0';
    }

    if (name[0] != '\0' && last_name[0] != '\0')
    {
        snprintf(full_name, sizeof(full_name), "%s %s", name, last_name);
        printf("Nombre Completo: %s\n", full_name);
    }
    else if (name[0] != '\0')
    {
        printf("Nombre: %s\n", name);
    }
    else if (last_name[0] != '\0')
    {
        printf("Apellido: %s\n", last_name);
    }
    else
    {
        printf("No se proporcionó nombre ni apellido\n");
    }

    return 0;
}
