#include "shell.h"

extern env_t *env_head;

#define SETOWD(V) (V = _strdup(_getenv("OLDPWD")))
/**
 * change_dir - changes directory
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number will returned
 */
int change_dir(sh_t *data)
{
	char *home;

	home = _getenv("HOME");
	if (data->args[1] == NULL)
	{
		SETOWD(data->oldpwd);
		if (chdir(home) < 0)
			return (FAIL);
		return (SUCCESS);
	}
	if (_strcmp(data->args[1], "~") == 0)
	{
		SETOWD(data->oldpwd);
		if (chdir(home) < 0)
			return (FAIL);
		return (SUCCESS);
	}
	if (_strcmp(data->args[1], "-") == 0)
	{
		if (data->oldpwd == 0)
		{
			SETOWD(data->oldpwd);
			if (chdir(home) < 0)
				return (FAIL);
		}
		else
		{
			SETOWD(data->oldpwd);
			if (chdir(data->oldpwd) < 0)
				return (FAIL);
		}
	}
	else
	{
		SETOWD(data->oldpwd);
		if (chdir(data->args[1]) < 0)
			return (FAIL);
	}
	return (SUCCESS);
}
#undef GETCWD
/**
 * abort_prg - exit the program
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number will returned
 */
int abort_prg(sh_t *data __attribute__((unused)))
{
	int code, i = 0;

	if (data->args[1] == NULL)
	{
		free_data(data);
		exit(errno);
	}
	while (data->args[1][i])
	{
		if (_isnumber(data->args[1][i++]) < 0)
		{
			data->error_msg = _strdup("Illegal number\n");
			return (FAIL);
		}
	}
	code = _atoi(data->args[1]);
	free_data(data);
	exit(code);
}
/**
 * display_help - display the help menu
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number will returned
 */
int display_help(sh_t *data)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(data->args[1], O_RDONLY);
	if (fd < 0)
	{
		data->error_msg = _strdup("no help topics match\n");
		return (FAIL);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			data->error_msg = _strdup("cannot write: permission denied\n");
			return (FAIL);
		}
	}
	PRINT("\n");
	return (SUCCESS);
}
/**
 * _setenv - set an environment variable
 * @data: a pointer to the command data structure
 * 
 * Return: (Success) 0 is returned
 * ------  (Fail) -1
 */
int _setenv(sh_t *data)
{
	env_t *temp_node;

	if (data->args[1] == NULL)
	{
		data->error_msg = _strdup("Usage: setenv VARIABLE VALUE\n");
		return (FAIL);
	}

	if (data->args[2] == NULL)
	{
		data->error_msg = _strdup("Usage: setenv VARIABLE VALUE\n");
		return (FAIL);
	}
	
	temp_node = env_head;
	while (temp_node->next != NULL)
	{
		if (strcmp(temp_node->name, data->args[1]) == 0)
		{
			temp_node->value = data->args[2];
			return (SUCCESS);
		}
		temp_node = temp_node->next;
	}
	add_node(env_head, data->args[1], data->args[2]);
	return (SUCCESS);
}

/**
 * _unsetenv - unset an environment variable
 * @data: a pointer to the command data structure
 *
 * Return: (Success) 0 is returned
 * ------  (Fail) -1
 */
int _unsetenv(sh_t *data)
{
	env_t *temp_node, *prev_node;

	if (data->args[1] == NULL)
	{
		data->error_msg = _strdup("Usage: setenv VARIABLE\n");
		return (FAIL);
	}

	temp_node = env_head;
	while (temp_node->next != NULL)
	{
		if (strcmp(temp_node->name, data->args[1]) == 0)
		{
			if (temp_node == env_head)
				env_head = env_head->next;
			else
			{
				temp_node = temp_node->next;
				prev_node->next = temp_node;
			}
			return (SUCCESS);
		}
		prev_node = temp_node;
		temp_node = temp_node->next;
	}
	if (strcmp(temp_node->name, data->args[1]) == 0)
	{
		if (temp_node == env_head)
			env_head = NULL;
		else
		{
			temp_node = temp_node->next;
			prev_node->next = temp_node;
		}
		return (SUCCESS);
	}
	data->error_msg = _strdup("Environment variable does not exist\n");
	return (FAIL);
}

/**
 * _env - prints the environment variables
 * @data: data structure of command
 *
 * Return: (SUCCESS) 1
 */
int _env(sh_t *data)
{
	env_t *temp_node;

	temp_node = env_head;
	if (data->args[0] == NULL)
	{
		data->error_msg = _strdup("invalid command");
		return (FAIL);
	}
	while (temp_node->next != NULL)
	{
		printf("%s=%s\n", temp_node->name, temp_node->value);
		temp_node = temp_node->next;
	}

	printf("%s=%s\n", temp_node->name, temp_node->value);
	return (SUCCESS);
}
/**
 * handle_builtin - handle and manage the builtins cmd
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number will returned
 */
int handle_builtin(sh_t *data)
{
	blt_t blt[] = {
		{"exit", abort_prg},
		{"cd", change_dir},
		{"help", display_help},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"env", _env},
		{NULL, NULL}
	};
	int i = 0;

	while ((blt + i)->cmd)
	{
		if (_strcmp(data->args[0], (blt + i)->cmd) == 0)
			return ((blt + i)->f(data));
		i++;
	}
	return (FAIL);
}
