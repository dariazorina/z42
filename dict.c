#include <fcntl.h>   // open, O_RDONLY
#include <unistd.h>  // read, close, ssize_t
#include <stdlib.h>  // malloc, free, NULL

#include "dict.h"

//t_entry	*ft_parse_dict(char *buffer, size_t *count);

char *ft_read_file(const char *path) 
{
    int fd;

    char    chunk[1024];
    ssize_t n;
    size_t file_size, file_pointer;
    char *buffer; 

    file_size = 0;
    file_pointer = 0;    
    
    //calc the size
    fd = open(path, O_RDONLY);
    while (1 == 1) 
    {
        n = read(fd, chunk, sizeof(chunk));

        if (n == -1) {             // read error
            close(fd);
            return NULL;
        } else if (n == 0) {        //file end
            close(fd);
            break;
        } else {
            file_size += n; 
        }
    }

    buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        return NULL;
    }

    if (file_size > 0) {
        //read the data
        fd = open(path, O_RDONLY);
        while (1 == 1) 
        {
            n = read(fd, buffer + file_pointer, file_size - file_pointer);

            if (n == -1) {
                close(fd);
                return NULL;
            } else if (n == 0) {
                close(fd);
                break;
            } else {
                file_pointer += (size_t)n;
            }
        }
        close(fd);
    }
    buffer[file_pointer] = '\0';
    return buffer;
}

size_t	count_lines(const char *buffer)
{
	size_t	count;

	count = 1;
	while (*buffer)
	{
		if (*buffer == '\n')
			count++;
		buffer++;
	}
	return (count);
}

char	*get_line(char **buffer)
{
	char	*line;
	char	*end;

	line = *buffer;
	end = line;
	while (*end && *end != '\n')
		end++;
	*buffer = end;
	if (*end == '\n')
	{
		*end = '\0';
		*buffer = end + 1;
	}
	return (line);
}

char	*parse_value(char *value)
{
	char	*end;

	while (*value == ' ')
		value++;
	end = value;
	while (*end)
	{
		if (*end < ' ' || *end > '~')
			return (NULL);
		end++;
	}
	while (end > value && *(end - 1) == ' ')
		end--;
	*end = '\0';
	if (end == value)
		return (NULL);
	return (value);
}

int	parse_entry(char *line, t_entry *entry)
{
	char	*key_end;
	char	*colon;

	key_end = line;
	while (*key_end >= '0' && *key_end <= '9')
		key_end++;
	if (key_end == line)
		return (0);
	colon = key_end;
	while (*colon == ' ')
		colon++;
	if (*colon != ':')
		return (0);
	entry->value = parse_value(colon + 1);
	if (entry->value == NULL)
		return (0);
	*key_end = '\0';
	entry->key = line;
	return (1);
}

t_entry	*ft_parse_dict(char *buffer, size_t *count)
{
	t_entry	*dict;
	char	*line;
	size_t	i;

	*count = 0;
	if (buffer == NULL)
		return (NULL);

	dict = malloc(count_lines(buffer) * sizeof(*dict));
	
	if (dict == NULL)
		return (NULL);
	
	i = 0;
	while (*buffer)
	{
		line = get_line(&buffer);
		if (*line)
		{
			if (!parse_entry(line, &dict[i]))
			{
				free(dict);
				return (NULL);
			}
			i++;
		}
	}
	*count = i;
	return (dict);
}