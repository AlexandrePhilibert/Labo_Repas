// PRG1_E
// -----------------------------------------------------------------------------------------------
// Demo           : Labo_02_D
// Fichier        : Labo_02_D.cpp
// Auteur(s)      : BEE Gianni & PHILIBERT Alexandre
// But            : Calcul du prix d'un repas en fonction d'une commande entrée par l'utilisateur
// Modifications  :
// Remarque(s)    : Les valeurs de saisi sont contrôlée dans l'intervalle [0,10]
//                  Les autres erreurs de saisi ne sont pas gérée
// -----------------------------------------------------------------------------------------------

#include <iostream>     // cin et cout
#include <cstdlib>      // EXIT_SUCCESS, EXIT_FAILURE
#include <iomanip>      // setprecision
#include <limits>       // numeric_limits<streamsize>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define CLEAN_EXIT cout << "Pressez ENTER pour quitter"; \
                   EMPTY_BUFFER

using namespace std;    // Simplification std::cin <=> cin ; std::cout <=> cin

int main() {
   const float  PRIX_ENTREE = 4.30f,
                PRIX_PLAT_PRINCIPAL = 12.50f,
                PRIX_BOISSON = 3.00f,
                PRIX_DESSERT = 6.00f,
                PRIX_CAFE = 2.80f;

   unsigned int nombreEntree,
                nombrePlat,
                nombreBoisson,
                nombreDessert,
                nombreCafe;

   cout << "Bonjour," << endl
        << "Ce programme calcul le prix d'un repas" << endl << endl
        << "======================================"         << endl
        << "- Entree  : " << PRIX_ENTREE                    << endl
        << "- Plat    : " << PRIX_PLAT_PRINCIPAL            << endl
        << "- Boisson : " << PRIX_BOISSON                   << endl
        << "- Dessert : " << PRIX_DESSERT                   << endl
        << "- Cafe    : " << PRIX_CAFE                      << endl
        << "NB : Limite de saisie [0 - 10]"                 << endl;

   cout << setprecision(2) << fixed; // Définit l'affichage

   // Commande

   cout << "votre commande" << endl
        << "==============" << endl;

   cout << " - nbre d'PRIX_ENTREE : ";
   cin  >> nombreEntree;
   EMPTY_BUFFER;

   if (nombreEntree < 0 || nombreEntree > 10) {
      CLEAN_EXIT;
      return EXIT_FAILURE;
   }

   cout << " - nbre de plat : ";
   cin  >> nombrePlat;
   EMPTY_BUFFER;

   if (nombrePlat < 0 || nombrePlat > 10) {
      CLEAN_EXIT;
      return EXIT_FAILURE;
   }

   cout << " - nbre PRIX_BOISSON : ";
   cin  >> nombreBoisson;
   EMPTY_BUFFER;

   if (nombreBoisson < 0 || nombreBoisson > 10) {
      CLEAN_EXIT;
      return EXIT_FAILURE;
   }

   cout << " - nbre de PRIX_DESSERT : ";
   cin  >> nombreDessert;
   EMPTY_BUFFER;

   if (nombreDessert < 0 || nombreDessert > 10) {
      CLEAN_EXIT;
      return EXIT_FAILURE;
   }

   cout << " - nbre de cafe : ";
   cin  >> nombreCafe;
   EMPTY_BUFFER;

   if (nombreCafe < 0 || nombreCafe > 10) {
      CLEAN_EXIT;
      return EXIT_FAILURE;
   }

   cout << endl;

   // Calcul des prix pour chaques plats/boissons
   float totalEntree        = nombreEntree  * PRIX_ENTREE,
         totalPlatPrincipal = nombrePlat    * PRIX_PLAT_PRINCIPAL,
         totalBoisson       = nombreBoisson * PRIX_BOISSON,
         totalDessert       = nombreDessert * PRIX_DESSERT,
         totalCafe          = nombreCafe    * PRIX_CAFE;

   // Calcul du total du ticket
   float total = totalEntree + totalPlatPrincipal + totalBoisson + totalDessert + totalCafe;

   cout << "Votre ticket" << endl
        << "============" << endl
        << " - " << nombreEntree   << " entrees : "  << totalEntree        << endl
        << " - " << nombrePlat     << " plats : "    << totalPlatPrincipal << endl
        << " - " << nombreBoisson  << " boissons : " << totalBoisson       << endl
        << " - " << nombreDessert  << " desserts : " << totalDessert       << endl
        << " - " << nombreCafe     << " cafes : "    << totalCafe          << endl
        << " - total : " << total  << endl
        << "merci de votre visite" << endl;

   cout << endl;

   CLEAN_EXIT;
   return EXIT_SUCCESS;
}