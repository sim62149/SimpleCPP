#include "file_utils.h"
#include <iostream>
#include <cstdio> // Pour std::remove()
#include <fstream> // Ajouté pour utiliser std::ofstream et std::ifstream

namespace simplecpp {

    bool writeToFile(const std::string& filename, const std::string& content) {
        std::ofstream file(filename);
        if (!file) return false;
        file << content;
        return true;
    }

    bool appendToFile(const std::string& filename, const std::string& content) {
        std::ofstream file(filename, std::ios::app);
        if (!file) return false;
        file << content;
        return true;
    }

    std::string readFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) return "";
        return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    }

    bool deleteFile(const std::string& filename) {
        return std::remove(filename.c_str()) == 0; // Supprime le fichier
    }

    bool fileExists(const std::string& filename) {
        std::ifstream file(filename);
        return file.good(); // Vérifie si le fichier est accessible
    }

    std::vector<std::string> readLinesFromFile(const std::string& filename) {
        std::vector<std::string> lines;
        std::ifstream file(filename);
        if (!file) return lines;

        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    bool writeLinesToFile(const std::string& filename, const std::vector<std::string>& lines) {
        std::ofstream file(filename);
        if (!file) return false;

        for (const auto& line : lines) {
            file << line << '\n';
        }
        return true;
    }

} // namespace simplecpp
