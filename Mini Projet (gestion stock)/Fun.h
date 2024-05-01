#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

class Produit {
protected:
	string ref;
	float prix;
	string fournisseur;
	int qnt;
	string categorie;
public:
	Produit(string r="xxx", float p=00.00, string f="xxx", int q=0,string cat="xxxx")
	{
		this->ref = r;
		this->prix = p;
		this->fournisseur = f;
		this->qnt = q;
		this->categorie = cat;
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

class Magasin {
protected:
	string nom;
	string adresse;
	deque<Produit> liste_p;
public:
	void afficher() {
		cout << "Magasin : " << this->nom << " Adresse : " << this->adresse << endl;
		//Pour afficher la liste des produits propose par une magasin
		cout << "Liste des produits :" << endl;
		for (auto& e : this->liste_p) {
			 e.afficher();
		}
	}
	void gererEntree() {
		// pour que le magasin peut faire une mise a jour a la qnt d'un produit dans la liste des pros sinon ajouter un nouveau a la deque
	}
	void gererSortie() {
		// pour que le magasin peut verifier si la qnt est dispo pour effectuer une sortie sinon un message d'erreur 
	}
	void ajouterProduit() {
		//ajouter un produit au stock
		/*
		Remarque: vous devez vérifier que la référence assignée ne correspond pas à
		un autre produit du magasin.Comme vous pouvez générer aléatoirement des
		références en tenant compte du magasin qui les vend.
        */
	}
	void modifierInfoProd(string ref) {
		//pour modifier les infos d'un produit en utilisant le ref 
	}
	void InfoProduit(string ref) {
		//iterateur pour selectionner le produit avec un condition ensuite
		// p.afficher() 
	}


};