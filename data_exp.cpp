#include <fstream>
#include <cstdint>
#include <iostream>

int main(int argc, char *argv[]) {
    std::ifstream file(argv[1], std::ios::binary);
    uint16_t raw[8];
    while (file.read(reinterpret_cast<char*>(raw), sizeof(raw))) {
        for (int i = 0; i < 8; i++) {
            uint16_t w = raw[i];
            int layer = w & 0x7;
            int wire = (w >> 3) & 0x7;
            int tdc = w >> 6;
            std::cout << "layer: " << layer << ", wire: " << wire << ", tdc: " << tdc << "\n";
        }
    }
}