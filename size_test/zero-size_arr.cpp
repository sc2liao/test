#include<iostream>

struct RequestTlv {
    uint32_t    tag:8;
    uint32_t    len:24;
    uint8_t     data[0];
};
struct Request {
    uint8_t                 version;        // resevse for upgrade format
    uint16_t                type;
    uint8_t                 target;
    uint32_t                len;
    struct RequestTlv       tlvs[0];
};
int main() {
	return 0;
}