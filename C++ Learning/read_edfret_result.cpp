////this code should be in main.cpp in order to execute it 
////file input.txt should be in the same dir as main.cpp
//#include <iostream>
//#include <fstream>
//#include <string>
//
//int main() {
//    std::ifstream file("edfret_result.txt");
//    bool value = false;
//    std::string str;
//
//    if (file >> str) {
//        if (str == "true" || str == "1") {
//            value = true;
//        }
//        else if (str == "false" || str == "0") {
//            value = false;
//        }
//        else {
//            std::cerr << "Invalid boolean value in file." << std::endl;
//            return 1;
//        }
//        // std::cout << "Read boolean: " << std::boolalpha << value << std::endl;
//        std::cout << std::boolalpha << value << std::endl;
//    }
//    else {
//        std::cerr << "Failed to read from file." << std::endl;
//        return 1;
//    }
//
//    return 0;
//}


#include <iostream> //For cout
#include <fstream>
#include <string>
#include <cstdlib> // For system()
#include <sstream> // For std::ostringstream
#include <cstdlib> // For getenv

int main(int argc, char* argv[]) {
    char* tempEnv = nullptr;
    size_t len = 0;
    if (_dupenv_s(&tempEnv, &len, "TEMP") != 0 || tempEnv == nullptr) {
        std::cerr << "TEMP environment variable not found." << std::endl;
        return 1;
    }
    std::string result_file_path = std::string(tempEnv) + "\\edfret_result.txt";
    // std::cout << "edfret_result path: " << result_file_path << std::endl;
    free(tempEnv); // Don't forget to free the memory!

    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <edfret_test_launcher_path> <ctvlab_nxg_path> <ctvlab_seq_path>" << std::endl;
        return 1;
    }

    // Launch edfret_test_launcher using cmd.exe /C to handle spaces in paths
    std::ostringstream cmd;
    cmd << "cmd.exe /C \""
        << "\"" << argv[1] << "\""
        << " \"" << argv[2] << "\""
        << " \"" << argv[3] << "\""
        << "\"";
    int app = system(cmd.str().c_str());
    if (app != 0) {
        std::cerr << "Failed to launch edfret_test_launcher." << std::endl;
    }

    std::ifstream infile(result_file_path);
    bool value = false;
    std::string str;

    if (infile >> str) {
        if (str == "true" || str == "1") {
            value = 1;
        }
        else if (str == "false" || str == "0") {
            value = 0;
        }
        else {
            std::cerr << "Invalid boolean value in file." << std::endl;
            return 1;
        }
        std::cout << value << std::endl;
    }
    else {
        std::cerr << "Failed to read from file." << std::endl;
        return 1;
    }

    return 0;
}