#include "shell.h"

extern env_t *env_head;

int add_node(env_t *head, char *name, char *value)
{
	env_t *new, *temp_head;

	temp_head = head;
	new = malloc(sizeof(env_t));

	if (new == NULL)
		return (FAIL);
	new->name = strdup(name);
	new->value = strdup(value);
	new->next = NULL;

	while (temp_head->next != NULL)
		temp_head = temp_head->next;
	temp_head->next = new;

	return (SUCCESS);
}

env_t *build_env_list(char *env[])
{
	env_t *first_node;
	char *name, *value;
	int i = 0;

	first_node = malloc(sizeof(env_t));
	first_node->name = strtok(strcpy(malloc(sizeof(env[i])), env[i]), "=");
	first_node->value = strtok(NULL, "\n");
	first_node->next = NULL;
	first_node;

	while (env[++i])
	{
		name = strtok(env[i], "=");
		value = strtok(NULL, "\n");
		add_node(first_node, name, value);
	}

	return (first_node);
}

char **build_env(void)
{
	static char *new_environ[MAXENV];
	env_t *temp_node;
	int env_len, name_len, value_len, i;

	temp_node = env_head;
	env_len = name_len = value_len = i = 0;

	temp_node = env_head;
	while (temp_node != NULL)
	{
		name_len = strlen(temp_node->name);
		value_len = strlen(temp_node->value);

		new_environ[i] = malloc(sizeof(char) * (name_len + value_len + 2));
		if (new_environ[i] == NULL)
			return (NULL);
		new_environ[i] = strcat(new_environ[i], temp_node->name);
		new_environ[i] = strcat(new_environ[i], "=");
		new_environ[i] = strcat(new_environ[i], temp_node->value);
		/*printf("%s\n", new_environ[i]);*/
		i++;
		temp_node = temp_node->next;
	}

	new_environ[i] = NULL;
	return (new_environ);
}
