/*
** EPITECH PROJECT, 2020
** file_size
** File description:
** determine file size
*/

#include "navy.h"

size_t file_size(const char *file)
{
    struct stat st;
    if (stat(file, &st) != 0) {
        return 0;
    }
    return (st.st_size);
}