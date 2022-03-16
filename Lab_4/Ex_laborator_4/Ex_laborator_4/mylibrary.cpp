#define _CRT_SECURE_NO_WARNINGS
#include "myLibrary.h"
#include <stdarg.h>
#include <cstdio>
#include <string.h>


MyLibrary::MyLibrary(std::ostream& output_stream): output_stream(output_stream)
{
    books_count = 0;
    books = nullptr;
}

MyLibrary::MyLibrary(MyLibrary const& lib): output_stream(lib.output_stream)
{
    this->books = new int[lib.books_count];
    this->books_count = lib.books_count;
    for (unsigned i = 0; i < books_count; i++)
    {
        this->books[i] = lib.books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream)
{
    this->books = new int[books_count];
    this->books_count = books_count;
    for (unsigned i = 0; i < books_count; i++)
    {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream)
{
    books = new int[books_count];
    this->books_count = books_count;
    for (unsigned i = 0; i < books_count; i++)
    {
        this->books[i] = rand() % max + min;
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream)
{
    unsigned cnt = 1;
    for (unsigned i = 0; i < strlen(books_values); i++)
    {
        if (books_values[i] == ';')
        {
            cnt++;
        }
    }
    books = new int[cnt];
    books_count = cnt;
    char* sir = new char[(strlen(books_values) + 1) * sizeof(char)];
    strcpy(sir, books_values);

    unsigned poz = 0;
    char* p = strtok(sir, ";");
    while (p)
    {
        int nr = atoi(p);
        books[poz] = nr;
        poz++;
        p = strtok(nullptr, ";");
    }
    delete[] sir;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream)
{
    int val;
    va_list args;
    va_start(args, books_count);
    books = new int[books_count];
    this->books_count = books_count;
    for (unsigned i = 0; i < books_count; i++)
    {
        val = va_arg(args, int);
        books[i] = val;
    }
    va_end(args);

}

MyLibrary::~MyLibrary() {
    delete[] books;
}

void MyLibrary::print_books() const
{
    if (books_count > 0)
    {
        output_stream << books_count << "\n";
        for (unsigned i = 0; i < books_count; i++)
        {
            output_stream << books[i] << " ";
        }
    }
    else
    {
        output_stream << "-1";
    }
    output_stream << "\n";
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) const
{
    if (book_index < books_count)
    {
        books[book_index] = book_id;
    }
}

unsigned MyLibrary::get_books_count() const
{
    if(books_count > 0)
        return books_count;
    return -1;
}

unsigned MyLibrary::get_book_id_by_index(unsigned books_index) const
{
    if (books_index < books_count)
    {
        return books[books_index];
    }
    return -1;
}
