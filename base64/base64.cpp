#include<iostream>
#define VERSION 1

	void split_version_totalsize(std::string &origin, uint32_t &version, uint64_t &totalsize)
    {
        std::string::size_type pos;

        pos = origin.find("~");
        version = atoi(origin.substr(0, origin.size() - pos).c_str());
		totalsize = std::stoull(origin.substr(pos+1), nullptr, 10);
    }

	void encode_base64(std::string &base64_code)
    {
        const std::string _base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        int num = 0,bin = 0,i;
        std::string _encode_result;
        const std::string current=base64_code;
        int lenth=base64_code.size();
        std::size_t curr_index=0;
        base64_code.clear();
        while(lenth > 2) {
        base64_code += _base64_table[current[curr_index] >> 2];
        base64_code += _base64_table[((current[curr_index] & 0x03) << 4) + (current[curr_index+1] >> 4)];
        base64_code += _base64_table[((current[curr_index+1] & 0x0f) << 2) + (current[curr_index+2] >> 6)];
        base64_code += _base64_table[current[curr_index+2] & 0x3f];

        curr_index += 3;
        lenth -= 3;
    }
    if(lenth > 0)
    {
        base64_code += _base64_table[current[curr_index] >> 2];
        if(lenth%3 == 1) {
            base64_code += _base64_table[(current[curr_index] & 0x03) << 4];
            base64_code += "==";
        } else if(lenth%3 == 2) {
            base64_code += _base64_table[((current[curr_index] & 0x03) << 4) + (current[curr_index+1] >> 4)];
            base64_code += _base64_table[(current[curr_index+1] & 0x0f) << 2];
            base64_code += "=";
        }
    }
    return ;
    }

    void decode_base64(std::string &base64_code)
    {
        const char base64_pad = '=';
        const signed char DecodeTable[] =
        {
            static_cast<char>(-2), -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -2, -2, -1, -2, -2,
            -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
            -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 62, -2, -2, -2, 63,
            52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -2, -2, -2, -2, -2, -2,
            -2,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
            15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -2, -2, -2, -2, -2,
            -2, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
            41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -2, -2, -2, -2, -2,
            -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
            -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
            -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
            -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
            -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
            -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
            -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
            -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2
        };
        int bin = 0, i = 0;
        int length = base64_code.size();
        std::uint32_t curr_index=0;
        const std::string current = base64_code;
        base64_code.clear();
        char ch;
        while( (ch = current[curr_index++]) != '\0' && length-- > 0 )
        {
            if (ch == base64_pad) {
                if (current[curr_index] != '=' && (i % 4) == 1) {
                    return;
                }
                continue;
            }
            ch = DecodeTable[(uint16_t)ch];
            if (ch < 0 ) { 
                continue;
            }
            switch(i % 4)
            {
                case 0:
                    bin = ch << 2;
                    break;
                case 1:
                    bin |= ch >> 4;
                    base64_code += bin;
                    bin = ( ch & 0x0f ) << 4;
                    break;
                case 2:
                    bin |= ch >> 2;
                    base64_code += bin;
                    bin = ( ch & 0x03 ) << 6;
                    break;
                case 3:
                    bin |= ch;
                    base64_code += bin;
                    break;
            }
            i++;
        }
        return;
    }

int main()
{
    std::string str = "0";
    //string normal,encoded;
    //int i,len = sizeof(str)-1;
    //Base64 *base = new Base64();
    encode_base64(str);
    std::cout << "base64 encode : " << str << std::endl;
    //len = encoded.length();
    //const char * str2 = encoded.c_str();
    decode_base64(str);
    //normal = base->Decode(str2,len);
    std::cout << "base64 decode : " << str <<std::endl;
	std::uint32_t version=0;
	std::uint64_t totalsize=0;
	split_version_totalsize(str,version,totalsize);
	std::cout << "version is "<<version;
	std::cout <<"total size is "<<totalsize;
	//int
	//std::cout <<"marco version is "<<VERSION;
	//std::string temp = VERSION;
    return 0;
}
