#include "shell.h"

extern env_t *env_head;

/**
 * add_node - adds a new node to the linked list
 * @head: head node
 * @name: name of the environment variable
 * @value: value of the environment variable
 *
 * Return: 1 on success -1 on failure
 */
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

/**
 * build_env_list - build a linked list of environment variables
 * @env: pointer to environment variables
 *
 * Return: pointer to the head of the linked list
 */
env_t *build_env_list(char *env[])
{
	env_t *first_node;
	char *name, *value, **l_env;
	int i = 0;

	l_env = clone_environ(env);
	first_node = malloc(sizeof(env_t));
	first_node->name = strtok(strcpy(malloc(sizeof(l_env[i])), l_env[i]), "=");
	first_node->value = strtok(NULL, "\n");
	first_node->next = NULL;

	while (l_env[++i])
	{
		name = strtok(l_env[i], "=");
		value = strtok(NULL, "\n");
		add_node(first_node, name, value);
	}

	return (first_node);
}

/**
 * clone_env - clone the environment varaibles
 * @environ: the pointer to the evironment variables
 * 
 * Return: the pointer to the environment variables
 */
char **clone_environ(char **env)
{
	static char *clone[MAXENV];
	char **p;
	int i;
	
	p = env;
	i = 0;
	while (*p)
	{
		clone[i] = malloc(sizeof(char) * (strlen(*p) + 1));
		clone[i] = strcpy(clone[i], *p);
		i++;
		p++;
	}
	clone[i] = NULL;
	return (clone);
}
