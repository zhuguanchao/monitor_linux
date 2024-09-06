#include "utils/read_file.h"

namespace monitor {
bool ReadFile::ReadLine(std::vector<std::string>* args){
    std::string line;
    std::getline(ifs_, line);
    if(ifs_. eof() || line.empty())
    { 
        return false; 
    }
    std::istringstream line_ss(line);
    while(!line_ss.eof())
    {
         std::string word;
         line_ss >> word; // 从流中提取字符
         if(!word.empty()) //防止推入空字符串
         {
            args->push_back(word); // 将字符添加到 vector 中
         }

    }
    return true;
}

}
