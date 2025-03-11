// example.cpp
#include "simplecpp.h"


int main() {
    simplecpp::print("Hello, SimpleCPP!");

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    simplecpp::print("Somme : " + std::to_string(simplecpp::sum(numbers)));
    simplecpp::print("Moyenne : " + std::to_string(simplecpp::average(numbers)));

    std::string text = "Hello World!";
    simplecpp::print("Uppercase : " + simplecpp::toUpper(text));
    simplecpp::print("Lowercase : " + simplecpp::toLower(text));

    std::vector<std::string> words = { "Hello", "SimpleCPP", "World" };
    simplecpp::print("Joined words: " + simplecpp::join(words, ", "));

    auto doubled = simplecpp::map(numbers, [](int x) { return x * 2; });
    simplecpp::print("Doubled: " + simplecpp::join({ std::to_string(doubled[0]), std::to_string(doubled[1]) }, ", "));
    
    int* ptr = simplecpp::safeNew<int>();
    if (ptr) {
        *ptr = 42;
        simplecpp::print("Allocated value: " + std::to_string(*ptr));
        delete ptr;
    }

    std::string filename = "test.txt";

    // 1. Écrire dans un fichier
    if (simplecpp::writeToFile(filename, "Bonjour, ceci est un test.\n")) {
        std::cout << "Fichier écrit avec succès !\n";
    }

    // 2. Lire le contenu du fichier
    std::string content = simplecpp::readFromFile(filename);
    std::cout << "Contenu du fichier :\n" << content << "\n";

    // 3. Ajouter du contenu au fichier
    if (simplecpp::appendToFile(filename, "Ligne ajoutée.\n")) {
        std::cout << "Contenu ajouté au fichier !\n";
    }

    // 4. Vérifier si le fichier existe
    if (simplecpp::fileExists(filename)) {
        std::cout << "Le fichier existe.\n";
    }
    else {
        std::cout << "Le fichier n'existe pas.\n";
    }

    // 5. Lire ligne par ligne
    std::vector<std::string> lines = simplecpp::readLinesFromFile(filename);
    std::cout << "Lecture ligne par ligne :\n";
    for (const auto& line : lines) {
        std::cout << line << "\n";
    }

    // 6. Écrire plusieurs lignes dans un fichier
    std::vector<std::string> newLines = {
        "Première ligne.",
        "Deuxième ligne.",
        "Troisième ligne."
    };
    if (simplecpp::writeLinesToFile(filename, newLines)) {
        std::cout << "Plusieurs lignes écrites avec succès !\n";
    }

    // 5.bis Lire ligne par ligne après modification du fichier
    std::vector<std::string> updatedLines = simplecpp::readLinesFromFile(filename);
    std::cout << "Lecture ligne par ligne :\n";
    for (const auto& line : updatedLines) {
        std::cout << line << "\n";
    }

    // 7. Supprimer le fichier
    if (simplecpp::deleteFile(filename)) {
        std::cout << "Le fichier a été supprimé !\n";
    }
    else {
        std::cout << "Erreur lors de la suppression du fichier.\n";
    }




    simplecpp::HttpClient client;
    client.setDefaultHeaders({ {L"User-Agent", L"MyCustomAgent/1.0"} });

    std::string response = client.get(L"https://jsonplaceholder.typicode.com/todos/1");
    simplecpp::print("GET Response: " + response);

    std::map<std::wstring, std::wstring> headers = {
    {L"Content-Type", L"application/json"}
    };

    std::string postData = R"({"title":"foo", "body":"bar", "userId":1})";
    std::string postResponse = client.post(L"https://jsonplaceholder.typicode.com/posts", postData, headers);

    simplecpp::print("POST Response: " + postResponse);
    std::string putData = R"({"id": 1, "title":"updated title", "body":"updated body", "userId":1})";
    std::string putResponse = client.put(L"https://jsonplaceholder.typicode.com/posts/1", putData, headers);

    simplecpp::print("PUT Response: " + putResponse);
    std::string deleteResponse = client.del(L"https://jsonplaceholder.typicode.com/posts/1");
    simplecpp::print("DELETE Response: " + deleteResponse);
    client.setTimeouts(10000, 15000, 15000); // Connexion : 10s, Envoi : 15s, Réception : 15s

    std::string slowResponse = client.get(L"https://jsonplaceholder.typicode.com/todos/2");
    simplecpp::print("GET with timeout Response: " + slowResponse);


   
    
  
    

    



    return 0;
}
