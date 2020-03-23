// tp01.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include <string>
using namespace std;

struct fraction {
    int numerateur;
    int denominateur;
};

// Signatures des fonctions
void saisieDesFractions(fraction* lesfractions, int nbreFractions);
void affichageFractons(fraction* lesfractions, int nbreFractions);
void simplifierFraction(fraction& f);
int trouverPgcdStein(int a, int b);


int main() {
    int nbreFractions;
    fraction* lesfractions;

    do {
        cout << "Combien de fractions voulez-vous? " << endl;
        cin >> nbreFractions;
        if (nbreFractions <= 0)
            cout << "Le nombre de fractions doit etre superieur a 0, reessayez!" << endl;
    } while (nbreFractions <= 0);

    lesfractions = new fraction[nbreFractions];  // On cree le tableau de la taille demande par utilisateur
    if (lesfractions == 0)                                 // On verifie si l'allocation a bien fonctionne
        return -1;

    saisieDesFractions(lesfractions, nbreFractions);    // On remplie le tableau par les fractions saisies
    affichageFractons(lesfractions, nbreFractions);     // On affiche les fractions, telles que saisies et simplifiees 
                                        // La fonction de simplification est appellee depuis la fonction d'affichage
    delete[] lesfractions;                              // On libere la memoire
    return 0;
} // main


void simplifierFraction(fraction& f) {
    // Le methode simplifie la fraction passee par reference en parametre
    int pgcd = trouverPgcdStein(f.numerateur, f.denominateur);
    f.numerateur /= pgcd;
    f.denominateur /= pgcd;

} // simplifierFraction

int trouverPgcdStein(int a, int b) {
    // La fonction trouve le PGCD de deux nombres entiers positifs par les moyens de l'algorithme de Stein

    if (a == b)
        return a;
    if ((a == 1) || (b == 1))
        return 1;

    if (a % 2 == 0) {
        if (b % 2 == 0)
            return 2 * trouverPgcdStein(a / 2, b / 2);
        else
            return trouverPgcdStein(a / 2, b);
    }

    if (a % 2 != 0) {
        if (b % 2 == 0)
            return trouverPgcdStein(a, b / 2);
        else {
            if (a > b)
                return trouverPgcdStein((a - b) / 2, b);
            else
                return trouverPgcdStein((b - a) / 2, a);
        }
    }

} // trouverPgcdStein(a, b)

void saisieDesFractions(fraction* lesfractions, int nbreFractions) {
    //Remplir le tableau de fractions
    int num;
    int denom;

    for (int i = 0; i < nbreFractions; i++) {
        cout << endl << "Fraction # " << i + 1 << ": " << endl;
        do {
            cout << "Entrez un numerateur superieur a 0 : " << endl;
            cin >> num;
            if (num <= 0)
                cout << "Le numerateur doit etre superieur a 0, reessayez! " << endl;
        } while (num <= 0);

        do {
            cout << "Entrez un denominateur superieur a 0 : " << endl;
            cin >> denom;
            if (denom <= 0)
                cout << "Le denominateur doit etre superieur a 0, reessayez! " << endl;
        } while (denom <= 0);

        (lesfractions + i)->numerateur = num;
        (lesfractions + i)->denominateur = denom;
        cout << "La fraction saisie est:" << (lesfractions + i)->numerateur << "/" << (lesfractions + i)->denominateur << endl;

    }//for
} // saisieDesFractions

void affichageFractons(fraction* lesfractions, int nbreFractions) {
    //Affichage des fractions et leur simplification
    cout << endl << "Liste des fractions: " << endl;
    for (int i = 0; i < nbreFractions; i++) {
        cout << "Fraction # " << i + 1 << ": " << (lesfractions + i)->numerateur << "/" <<
            (lesfractions + i)->denominateur << "Les fractions simplifiés sont :" << simplifierFraction(fraction& lesfractions);

    }// for

} // affichageFractions





