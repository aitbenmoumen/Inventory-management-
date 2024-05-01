#pragma once
#include <iostream>
#include <string>
using namespace std;

class Produit {
protected:
	string ref;
	float prix;
	string fournisseur;
	int qnt;
	string categorie;
public:
	Produit(string r="xxx", float p=00.00, string f="xxx", int q=0)
	{
		this->ref = r;
		this->prix = p;
		this->fournisseur = f;
		this->qnt = q;
	}
	void afficher()
	{
		cout << "Ref: " << this->ref << " Prix: " << this->prix << " Fournisseur: " << this->fournisseur << " Qnt: " << this->qnt << " Categorie: " << this->categorie << endl;
	}
};

class Fournisseur {
protected:
	string nom;
	string adresse;
public:
	void afficher() {
		cout << "Fournisseur : " << this->nom << " Adresse : " << this->adresse << endl;
	}
};
