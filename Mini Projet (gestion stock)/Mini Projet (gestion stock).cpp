// Mini Projet (gestion stock).cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include "Fun.h"
using namespace std;
int main()
{
    Produit p("xxx", 12.2, "alami", 100),p1;
    std::cout << "Hello World!\n";
    p.afficher();
    p1.afficher();
    Fournisseur f1("Fournisseur 1", "Adresse 1");
    Produit p2("Prod1", 10.50, "f1", 1, "Categorie 1");
    Produit p3("Prod2", 15.20, "f1", 2, "Categorie 2");

    f1.ajouterProduit(p1);
    f1.ajouterProduit(p2);
    f1.ajouterProduit(p3);
    f1.ajouterProduit(p);

    f1.afficherProduits();

    cout << "-------------------------" << endl;
    Magasin m1("test", "adr1");
    m1.afficher();
    m1.gererEntree(p2);
    m1.gererEntree(p2);
    m1.gererEntree(p2);
    m1.gererEntree(p2);
    m1.gererEntree(p3);
    m1.afficher();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
