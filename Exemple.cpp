// example.cpp
#include "simplecpp.h"
#include <vector>
#include <string>

int main() {
    // Affichage simplifi�
    simplecpp::print("Hello, SimpleCPP!");

    // Manipulation de fichiers
    if (!simplecpp::writeToFile("example.txt", "Ceci est un test de SimpleCPP!")) {
        simplecpp::handleError("Erreur lors de l'�criture du fichier.");
    }
    simplecpp::print("Contenu du fichier : " + simplecpp::readFromFile("example.txt"));

    // Math�matiques
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    simplecpp::print("Somme : " + std::to_string(simplecpp::sum(numbers)));
    simplecpp::print("Moyenne : " + std::to_string(simplecpp::average(numbers)));

    // Manipulation de cha�nes
    std::string text = "Hello World!";
    simplecpp::print("Uppercase : " + simplecpp::toUpper(text));
    simplecpp::print("Lowercase : " + simplecpp::toLower(text));
    simplecpp::print("Trimmed : " + simplecpp::trim("  Some Text  "));
    simplecpp::print("Formatted String: " + simplecpp::format("Hello {}, welcome to {}!", "User", "SimpleCPP"));

    // Gestion des erreurs
    try {
        simplecpp::handleError("Ceci est un message d'erreur de test.");
    }
    catch (const simplecpp::SimpleCPPError& e) {
        simplecpp::print("Erreur captur�e : " + std::string(e.what()));
    }

    // Manipulation des tableaux
    std::vector<std::string> words = { "Hello", "SimpleCPP", "World" };
    simplecpp::print("Joined words: " + simplecpp::join(words, ", "));

    // Gestion de la m�moire (Pointeur intelligent)
    auto ptr = simplecpp::makePtr<int>(new int(42)); // Allocation automatique
    simplecpp::print("Pointeur intelligent avec valeur : " + std::to_string(*ptr));

    // Exemple d'utilisation de la biblioth�que pour manipuler les r�pertoires
    simplecpp::createDirectory("simplecpp_test_directory");
    simplecpp::print("R�pertoire cr�� : simplecpp_test_directory");

    return 0;
}
