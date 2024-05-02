#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

string rouge = "\033[31m", nc = "\033[0m";
string vert = "\033[32m";
string jaune = "\033[33m";
string bleu = "\033[34m";
string mauve = "\033[35m";
string cyan = "\033[36m";

class Produit {
protected:
	string ref;
	double prix;
	string fournisseur;
	int qnt;
	string categorie;
public:
	Produit(string r="xxx", double p=00.00, string f="xxx", int q=0,string cat="xxxx")
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
	//pour pouvoir chercher les produits en se basant sur leurs ref et modifier les produits
	string getRef() {
		return this->ref;
	}
	void setRef(string r) {
		this->ref = r;
	}
	//pour qu'on peut modifier le prix si qnt>=500
	int getQnt() {
		return this->qnt;
	}
	//pour avoir la possibilite d'ajouter une qnt a celle qui deja existe quand acheter 
	void setQnt(int q) {
		this->qnt += q;
	}
	//pour reduire la qnt vendu par les magasin
	void venteQnt(int q) {
		this->qnt -= q;
	}
	double getPrix() {
		return this->prix;
	}
	void setPrix(double prix) {
		this->prix = prix;
	}
};

class Fournisseur {
protected:
	string nom;
	string adresse;
	deque<Produit> produits;
public:
	Fournisseur(string n,string adr):nom(n),adresse(adr){}
	void afficher() {
		cout << jaune << "Fournisseur : " << this->nom << " Adresse : " << this->adresse << nc << endl;
	}
	void ajouterProduit(Produit& p) {
		this->produits.push_back(p);
	}
	void afficherProduits() {
		if (this->produits.empty()) {
			cout << rouge <<"Il ya aucun produit pour le moment !!" << nc << endl;
		}
		else
		{
			for (auto& p : this->produits) {
				p.afficher();
			}
		}
	}

};

class Magasin {
protected:
	string nom;
	string adresse;
	deque<Produit> liste_p;
	deque<Fournisseur> liste_f;
public:
	Magasin(string n,string adr):nom(n),adresse(adr){}
	void afficher() {
		cout << "Magasin : " << this->nom << " Adresse : " << this->adresse << endl;
		//Pour afficher la liste des produits propose par une magasin
		if (liste_p.empty()) {
			cout << "Cette magasin ne propose aucun produit pour le moment !!" << endl;
		}
		else
		{
			cout << "Liste des produits :" << endl;
			for (auto& e : this->liste_p) {
				e.afficher();
			}
		}
	}
	void ajouterFournisseur(Fournisseur& f) {
		liste_f.push_back(f);
	}
	void afficherFournisseurs() {
		for (auto& f : liste_f) {
			f.afficher();
		}
	}
	void listerProduitsParFournisseur() {
		cout << "La liste des produits qui propose chaque fournisseur :" << endl;
		for (auto& f : liste_f) {
			cout << "++++++++++++++++++++++++++++" << endl;
			f.afficher();
			cout << endl;
			f.afficherProduits();
		}
	}

	void gererEntree(Produit& p) {
		// pour que le magasin peut faire une mise a jour a la qnt d'un produit dans la liste des pros sinon ajouter un nouveau a la deque
		int found = 0;
		for (auto& pp : this->liste_p) {
			if (p.getRef()==pp.getRef()) {
				pp.setQnt(p.getQnt());      //ajouter une qnt produit p a une de pp
				found = 1;
			}	
		}
		if (found == 0 || liste_p.empty()) {
			this->ajouterProduit(p);
		}	
	}
	void gererSortie(string ref,int q) {
		// pour que le magasin peut verifier si la qnt est dispo pour effectuer une sortie sinon un message d'erreur 
		if (liste_p.empty()) {
			cout << rouge << "Pas de produit dans nos stock pour le moment !" << endl;
		}
		else {
			for (auto& p : liste_p) {
				if (p.getRef() == ref) {
					if (p.getQnt() < q) {
						cout << rouge << "La quantite en stock n'est pas suffisante pour repondre a votre besoin !!" << nc << endl;
					}
					else
					{
						cout << vert << "Votre commande de " << q << " du produit " << ref << "est en cour de traitement. Veuiller passer chez la caisse pour la recuperer !!" << nc << endl;
						p.venteQnt(q);
					}
				}
				else
				{
					continue;
				}
			}
		}

	}
	void ajouterProduit(Produit& p) {
		this->liste_p.push_back(p);
	}
	void modifierInfoProd(string ref) {
		for (auto& p : liste_p) {
			if (p.getRef() == ref) {

			}
		}
	}
	void InfoProduit(string ref) {
		//iterateur pour selectionner le produit avec un condition ensuite
		// p.afficher() 
		bool found = false;
		for (auto& pp : this->liste_p) {
			if (pp.getRef() == ref) {
				pp.afficher();
				found = true;
				break;
			}
		}
		if (found == false) {
			cout << "Cet produit n'existe pas !!" << endl;
		}
	}
	void approvisionner() {
		//verifier les stock pour faire des aprovisionnement 
	}
	void passerCmd() {
		// passer une cmd au fournisseur
	}
	void marchandise_inf(int inf) {
		//afficher les produits dont leurs quantite est inferieur a "inf" 
		for (auto& p : liste_p) {
			if (p.getQnt() < inf) {
				p.afficher();
			}
		}
	}
	void filtrePrix(double min, double max) {
		//les produits dont leurs prix est entre min et max
		cout << "Pour les produits entre " << min << " et " << max << " on a :" << endl;
		for (auto & p : liste_p) {
			if (p.getPrix() > min && p.getPrix() < max) {
				p.afficher();
			}
		}
	}
};