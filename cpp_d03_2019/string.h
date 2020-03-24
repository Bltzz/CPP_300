/*
** EPITECH PROJECT, 2020
** d03_strings
** File description:
** header for all exercises
*/


#pragma once
#include <stddef.h>

typedef struct string_t {
    char *str;
    void (*assign_s)(struct string_t *this, const struct string_t *str);
    void (*assign_c)(struct string_t *this , const  char *s);
    void (*append_s)(struct string_t *this, const struct string_t *ap);
    void (*append_c)(struct string_t *this, const char *ap);
    char (*at)(const struct string_t *this , size_t  pos);
    void (*clear)(struct string_t *this);
    int  (*size)(const struct string_t *this);
    int  (*compare_s)(const struct string_t *this, const struct string_t *str);
    int  (*compare_c)(const struct string_t *this, const char *str);
    size_t (*copy)(const struct string_t *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const struct string_t *this);
    int (*empty)(const struct string_t *this);
    int (*find_s)(const struct string_t *this, const struct string_t *str, size_t pos);
    int (*find_c)(const struct string_t *this, const char *str, size_t pos);
    void (*insert_c)(struct string_t *this, size_t pos, const char *str);
    void (*insert_s)(struct string_t *this, size_t pos, const struct string_t *str);
    int (*to_int)(const struct string_t *this);
    struct string_t **(*split_s)(const struct string_t *this, char separator);
    char **(*split_c)(const struct string_t *this, char separator);
    void (*print)(const struct string_t *this);
    void (*join_c)(struct string_t *this, char delim, const char * const *tab);
    void (*join_s)(struct string_t *this, char delim, const struct string_t * const *tab);
    struct string_t *(*substr)(const struct string_t *this, int offset, int length);
} string_t;

//ex00
void string_init(string_t *this , const  char *s);
void string_destroy(string_t *this);

//ex01
void assign_s(string_t *this , const  string_t *str);
void assign_c(string_t *this , const  char *s);

//ex02
void append_s(string_t *this , const  string_t *ap);
void append_c(string_t *this , const  char *ap);

//ex03
char at(const string_t *this, size_t pos);

//ex04
void clear(string_t *this);

//ex05
int size(const  string_t *this);

//ex06
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);

//ex07
size_t copy(const string_t *this, char *s, size_t n, size_t  pos);

//ex08
const char *c_str(const string_t *this);

//ex09
int empty(const string_t *this);

//ex10
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);

//ex11
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);

//ex12
int to_int(const string_t *this);

//ex13
string_t **split_s(const string_t *this, char separator);
char **split_c(const string_t *this, char separator);

//ex14
void print(const string_t *this);

//ex15
void join_c(string_t *this, char delim, const char * const *tab);
void join_s(string_t *this, char delim, const string_t * const *tab);

//ex16
string_t *substr(const string_t *this, int offset, int length);