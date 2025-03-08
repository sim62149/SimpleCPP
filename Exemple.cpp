// example.cpp
#include "simplecpp.h"


int main() {
    // Affichage simplifié
    simplecpp::print("Hello, SimpleCPP!");

    // Manipulation de fichiers
    if (!simplecpp::writeToFile("example.txt", "Ceci est un test de SimpleCPP!")) {
        simplecpp::handleError("Erreur lors de l'écriture du fichier.");
    }
    simplecpp::print("Contenu du fichier : " + simplecpp::readFromFile("example.txt"));

    // Mathématiques
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    simplecpp::print("Somme : " + std::to_string(simplecpp::sum(numbers)));
    simplecpp::print("Moyenne : " + std::to_string(simplecpp::average(numbers)));

    // Manipulation de chaînes
    std::string text = "Hello World!";
    simplecpp::print("Uppercase : " + simplecpp::toUpper(text));
    simplecpp::print("Lowercase : " + simplecpp::toLower(text));

    // Gestion des erreurs
    simplecpp::handleError("Ceci est un message d'erreur de test.");

    // Manipulation des tableaux
    std::vector<std::string> words = { "Hello", "SimpleCPP", "World" };
    simplecpp::print("Joined words: " + simplecpp::join(words, ", "));

    return 0;
}