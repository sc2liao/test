#include<iostream>
#define DECLARE_LOGGER_FMT_IMPL(FUNC, LEVEL) \
    void fmt_##FUNC(::fmt::string_view format, ::fmt::format_args args){ \
            this->write_(LEVEL, ::fmt::vformat(format, args)); \
    } \
    template <typename... Args>
#define version 1
#define versionchar(verison) {"version"};
int main()
{
  //DECLARE_LOGGER_FMT_IMPL(temp,temp2);
  std::cout<<version<<std::endl;
  //char testversion=versionchar;
  
  std::cout<<versionchar(10);

}
