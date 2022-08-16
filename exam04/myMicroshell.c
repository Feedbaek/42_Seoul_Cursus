#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int parse_arg(t_list **cmds, char *arg) {

}

int main (int argc, char **argv, char **env) {
	t_list *cmds;
	int i;
	int ret;

	ret = EXIT_SUCCESS;
	cmds = NULL;
	i = 1;
	while (i < argc)
		parse_arg(&cmds, argv[i++]);
	if (cmds)
		ret = exec_cmds(&cmds, env);
	return ret;
}
