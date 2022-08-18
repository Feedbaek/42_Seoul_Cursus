#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **parse_cmd(char **argv, int *i) {
	int a = *i;
	char **cmd = 0;
	int x = 0;
	int y = 0;

	while (argv[a] && strcmp(argv[a], ";" != 0))
		a++;

}

int main(int argc, char **argv, char **env) {
	char **cmd = 0;
	int i = 1;
	//int last = 0;

	while (i < argc) {
		if (!(cmd = parse_cmd(argv, &i)))
			return fatal(cmd, 1);
		if (!(check_exec_cmd(cmd, env)))
			return 1;
	}
	return 0;
}
