#pragma once
#ifndef __FACE_HPP
#define __FACE_HPP

static const char *face1 = "  _______  \n"
                           " /       \\ \n"
                           "/         \\\n"
                           "\\         /\n"
                           " \\_______/ \n";

static const char *face2 = "  _______  \n"
                           " /       \\ \n"
                           "/  O   O  \\\n"
                           "|    V    |\n"
                           "\\         /\n"
                           " \\_______/ \n";

static const char *face3 = "  _______  \n"
                           " /       \\ \n"
                           "/  O   O  \\\n"
                           "|   _^_   |\n"
                           "\\         /\n"
                           " \\_______/ \n";

static const char *face4 = "  _______  \n"
                           " /       \\ \n"
                           "/  O   O  \\\n"
                           "|   _^_   |\n"
                           "\\   _^_   /\n"
                           " \\_______/ \n";

static const char *face5 = "  _______  \n"
                           " /       \\ \n"
                           "/  O   O  \\\n"
                           "|   _^_   |\n"
                           "\\   _^_   /\n"
                           " \\_______/ \n";

static const char *face6 = "Q   Q\n"
                           "  w  \n";

static const char *face7 = "=   =\n"
                           "  w  \n";

static const char *face8 = "^   ^\n"
                           "  w  \n";

static const char *
    faces[] = {face1, face2, face3, face4, face5,
               face6, face7, face8};

void print_face(int face);

void display_face(int face);
#endif // FACE_HPP