#include "csvwriter.h"
#include "les.h"
#include<string>
#include <fstream>


csvwriter::csvwriter(const QString &filename)
{
f.open(filename.toLatin1().data(), std::ios::in | std::ios::out | std::ios::app);

}
csvwriter::~csvwriter(){
    f.close();

}

void csvwriter::write(const les new_les){
   if(f.is_open()){
       std::string temp;
       f>>temp;
       if(temp[temp.size()-1]==';'){
           f<<std::endl;
       }
       f<<new_les.numb<<';'<<new_les.lesname.toLatin1().data()<<';'<<new_les.type_of_les.toLatin1().data()<<';'<<new_les.lesaud<<';';
   }
   }

