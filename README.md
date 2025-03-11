# SimpleCPP - Version 0.2.1

![GitHub release](https://img.shields.io/github/v/release/sim62149/SimpleCPP)
![GitHub license](https://img.shields.io/github/license/sim62149/SimpleCPP)
![GitHub issues](https://img.shields.io/github/issues/sim62149/SimpleCPP)


SimpleCPP est une librairie C++ conçue pour simplifier la syntaxe et améliorer l'expérience des développeurs en offrant des fonctions intuitives pour la gestion de la mémoire, le traitement des chaînes, les opérations mathématiques, les fichiers et les requêtes réseau.

## 🚀 Fonctionnalités principales

- **📝 Affichage et manipulation de texte** : Fonctions pour transformer et manipuler des chaînes de caractères.
- **➗ Opérations mathématiques** : Somme et moyenne sur des vecteurs d'entiers.
- **📂 Gestion de fichiers** : Lecture, écriture, ajout, suppression et manipulation de fichiers.
- **🌐 Requêtes réseau** : Gestion simplifiée des requêtes HTTP (GET, POST, PUT, DELETE) avec gestion des headers.
- **🔢 Utilitaires pour les tableaux** : Fonctionnalités pour appliquer des transformations et filtres sur les tableaux.
- **🛠️ Gestion sécurisée de la mémoire** : Allocation et libération de mémoire simplifiée.
- **⚠️ Gestion des erreurs** : Affichage d'erreurs formatées.

## 📥 Installation

- . Clonez le dépôt Git :
   
```
   git clone https://github.com/sim62149/SimpleCPP.git
```
- . Ajoutez les fichiers source (.cpp et .h) dans votre projet.
- . Incluez #include "SimpleCPP.h" dans vos fichiers C++.

## 📌 Exemples d'utilisation

### 📝 Affichage et manipulation de texte
```
#include "SimpleCPP.h"
int main() {
    std::string text = "Hello World!";
    SimpleCPP::print("Uppercase: " + SimpleCPP::toUpper(text));
    SimpleCPP::print("Lowercase: " + SimpleCPP::toLower(text));
    return 0;
}
```

### ➗ Opérations mathématiques
```
#include "SimpleCPP.h"
std::vector<int> numbers = {1, 2, 3, 4, 5};
SimpleCPP::print("Somme : " + std::to_string(SimpleCPP::sum(numbers)));
SimpleCPP::print("Moyenne : " + std::to_string(SimpleCPP::average(numbers)));
```

### 📂 Gestion des fichiers
```
#include "SimpleCPP.h"

std::string filename = "test.txt";
SimpleCPP::writeToFile(filename, "Bonjour, SimpleCPP!");
std::string content = SimpleCPP::readFromFile(filename);
SimpleCPP::print("Contenu du fichier : " + content);
```

### 🌐 Requêtes HTTP
```
#include "SimpleCPP.h"
SimpleCPP::HttpClient client;
std::string response = client.get("https://jsonplaceholder.typicode.com/todos/1");
SimpleCPP::print("Réponse GET: " + response);
```

## 🤝 Contribuer
Les contributions sont les bienvenues ! Vous pouvez proposer des améliorations en ouvrant une issue ou en soumettant une pull request.

## 📜 Licence
SimpleCPP est distribué sous la licence MIT.

---
**👨‍💻 Auteur :** Sim62149  
**📌 Dépôt GitHub :** [SimpleCPP](https://github.com/sim62149/SimpleCPP)