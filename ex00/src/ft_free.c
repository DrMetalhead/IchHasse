#include "../includes/rush.h"


void	ft_free_str(char *str)
{
	free(str);
}

void	ft_free_list(t_list *row)
{
    for (long long i = 0; i < 33; i++)
    {
        free(row[i].str);
    }
    free(row);
}
