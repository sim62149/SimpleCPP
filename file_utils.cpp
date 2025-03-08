#include "file_utils.h"
#include <filesystem>
namespace simplecpp {

    bool writeToFile(const std::string& filename, const std::string& content) {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Erreur d'ouverture du fichier : " << filename << std::endl;
            return false;
        }
        file << content;
        return true;
    }

    std::string readFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    bool createDirectory(const std::string& directory) {
        return std::filesystem::create_directory(directory);  // Utilisation de filesystem ici
    }

}
