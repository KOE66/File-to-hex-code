#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::string path = "C:/Users/LS Family/Pictures/Screenshots/Снимок экрана (151).png"; // Put the path to the file
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        std::cerr << "sorry but you dont have this file :(\n";
        return 1;
    }

    std::ofstream out("output.txt");
    if (!out) {
        std::cerr << "i cant create output.txt\n";
        return 1;
    }

    unsigned char byte;
    int count = 0;

    while (file.read(reinterpret_cast<char*>(&byte), 1)) {
        out << "0x"
            << std::hex << std::uppercase
            << std::setw(2) << std::setfill('0')
            << static_cast<int>(byte)
            << " ";

        count++;
        if (count % 16 == 0) out << "\n";
    }

    file.close();
    out.close();

    std::cout << "hex code is in output.txt! (in the zip file where is the project)\n";
    return 0;
}
