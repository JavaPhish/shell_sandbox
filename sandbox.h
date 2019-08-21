#ifndef SANDBOX_H
#define SANDBOX_H

int _contains(char *str, char *keyword);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *str_concat(char *s1, char *s2);
char **cmd_parser(char *cmd);
char *_strdup(char *str);
char *find_path(char *envp[]);

#endif
