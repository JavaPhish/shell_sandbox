#ifndef SANDBOX_H
#define SANDBOX_H

int _contains(char *str, char *keyword);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *str_concat(char *s1, char *s2);
char **cmd_parser(char *cmd);
char *_strdup(char *str);
char *find_path(char *envp[]);
int execution_handler(char *raw_cmd, char *envp[]);
char *_strcpy(char *dest, char *src);
int sizeof_string(char *str);
char **envp_cpy(char *envp[]);

#endif
