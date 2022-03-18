#ifndef CSVWRITER_H
#define CSVWRITER_H
#include <QString>
#include <fstream>
#include <iostream>

#include<les.h>

class csvwriter
{
    std::fstream f;
public:
    csvwriter(const QString &filename);
   ~csvwriter();
    void write(const les new_les);
    bool is_open() const{return f.is_open();}
};

#endif // CSVWRITER_H
