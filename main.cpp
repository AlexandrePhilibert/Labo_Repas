// -----------------------------------------------------------------------------------------------
// Demo           : Labo_02_D
// Fichier        : Labo_02_D.cpp
// Auteur(s)      : BEE Gianni & PHILIBERT Alexandre
// But            : Calcul du prix d'un repas en fonction des éléments choisi parmi le menu
// Modifications  :
// Remarque(s)    : Les valeurs de saisi sont contrôlée dans l'intervalle [0,10].
//                  Il est possible pour l'utilisateur de faire déborder les variables d'entrées,
//                  par ex. -65534 = 2, dans ce cas le programme continue son exécution.
//                  Les autres erreurs de saisies ne sont pas gérée.
// -----------------------------------------------------------------------------------------------

#include <iostream>     // cin et cout
#include <cstdlib>      // EXIT_SUCCESS, EXIT_FAILURE
#include <iomanip>      // setprecision
#include <limits>       // numeric_limits<streamsize>

#define VIDER_BUFFER        cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define AFFICHE_MESSAGE_FIN cout << "Pressez ENTER pour quitter"

using namespace std; // Simplification std::cin <=> cin ; std::cout <=> cin

int main() {
   const unsigned int LARGEUR_COLONNE_TICKET = 9,
                      LARGEUR_COLONNE_PRIX = 8,
                      LARGEUR_COLONNE_COMMANDE = 18;

   // Les limites de saisies pour les éléments du repas
   const unsigned int CHOIX_MINIMUM = 0,
                      CHOIX_MAXIMUM = 10;

   const float PRIX_ENTREE = 4.30f,
               PRIX_PLAT_PRINCIPAL = 12.50f,
               PRIX_BOISSON = 3.00f,
               PRIX_DESSERT = 6.00f,
               PRIX_CAFE = 2.80f;

   // Variables d'entrées utilisateur
   unsigned short nombreEntree,
                  nombrePlat,
                  nombreBoisson,
                  nombreDessert,
                  nombreCafe;

   // Définit la précision d'affichage des nombres à virgules (exemple: 2.50)
   cout << setprecision(2) << fixed;

   cout << "bonjour, ce programme calcul le prix d'un repas, voici le prix des elements" << endl
        << "===========================================================================" << endl
        << left << setw(LARGEUR_COLONNE_TICKET) << "- entree"  << " : " << right << setw(LARGEUR_COLONNE_PRIX) << PRIX_ENTREE         << endl
        << left << setw(LARGEUR_COLONNE_TICKET) << "- plat"    << " : " << right << setw(LARGEUR_COLONNE_PRIX) << PRIX_PLAT_PRINCIPAL << endl
        << left << setw(LARGEUR_COLONNE_TICKET) << "- boisson" << " : " << right << setw(LARGEUR_COLONNE_PRIX) << PRIX_BOISSON        << endl
        << left << setw(LARGEUR_COLONNE_TICKET) << "- dessert" << " : " << right << setw(LARGEUR_COLONNE_PRIX) << PRIX_DESSERT        << endl
        << left << setw(LARGEUR_COLONNE_TICKET) << "- cafe"    << " : " << right << setw(LARGEUR_COLONNE_PRIX) << PRIX_CAFE           << endl
        << "NB : limite de saisie [0 - 10]" << endl
        << endl;

   cout << "votre commande" << endl
        << "==============" << endl;

   cout << left;

   cout << setw(LARGEUR_COLONNE_COMMANDE) << " - nbre d'entree " << " : ";
   cin  >> nombreEntree;
   VIDER_BUFFER;

   if (nombreEntree < CHOIX_MINIMUM || nombreEntree > CHOIX_MAXIMUM) {
      AFFICHE_MESSAGE_FIN;
      VIDER_BUFFER;
      return EXIT_FAILURE;
   }

   cout << setw(LARGEUR_COLONNE_COMMANDE) << " - nbre de plat" << " : ";
   cin  >> nombrePlat;
   VIDER_BUFFER;

   if (nombrePlat < CHOIX_MINIMUM || nombrePlat > CHOIX_MAXIMUM) {
      AFFICHE_MESSAGE_FIN;
      VIDER_BUFFER;
      return EXIT_FAILURE;
   }

   cout << setw(LARGEUR_COLONNE_COMMANDE) << " - nbre boisson" << " : ";
   cin  >> nombreBoisson;
   VIDER_BUFFER;

   if (nombreBoisson < CHOIX_MINIMUM || nombreBoisson > CHOIX_MAXIMUM) {
      AFFICHE_MESSAGE_FIN;
      VIDER_BUFFER;
      return EXIT_FAILURE;
   }

   cout << setw(LARGEUR_COLONNE_COMMANDE) << " - nbre de dessert" << " : ";
   cin  >> nombreDessert;
   VIDER_BUFFER;

   if (nombreDessert < CHOIX_MINIMUM || nombreDessert > CHOIX_MAXIMUM) {
      AFFICHE_MESSAGE_FIN;
      VIDER_BUFFER;
      return EXIT_FAILURE;
   }

   cout << setw(LARGEUR_COLONNE_COMMANDE) << " - nbre de cafe" << " : ";
   cin  >> nombreCafe;
   VIDER_BUFFER;

   if (nombreCafe < CHOIX_MINIMUM || nombreCafe > CHOIX_MAXIMUM) {
      AFFICHE_MESSAGE_FIN;
      VIDER_BUFFER;
      return EXIT_FAILURE;
   }

   cout << endl;

   // Calcul des totaux pour chaque elements
   float totalEntree        = nombreEntree  * PRIX_ENTREE,
         totalPlatPrincipal = nombrePlat    * PRIX_PLAT_PRINCIPAL,
         totalBoisson       = nombreBoisson * PRIX_BOISSON,
         totalDessert       = nombreDessert * PRIX_DESSERT,
         totalCafe          = nombreCafe    * PRIX_CAFE;

   // Calcul du total du ticket
   float total = totalEntree + totalPlatPrincipal + totalBoisson + totalDessert + totalCafe;

   cout << "Votre ticket" << endl
        << "============" << endl
        << " - " << nombreEntree  << left  << setw(LARGEUR_COLONNE_TICKET) << " entrees"  << " : " << right << setw(LARGEUR_COLONNE_PRIX) << totalEntree        << endl
        << " - " << nombrePlat    << left  << setw(LARGEUR_COLONNE_TICKET) << " plats"    << " : " << right << setw(LARGEUR_COLONNE_PRIX) << totalPlatPrincipal << endl
        << " - " << nombreBoisson << left  << setw(LARGEUR_COLONNE_TICKET) << " boissons" << " : " << right << setw(LARGEUR_COLONNE_PRIX) << totalBoisson       << endl
        << " - " << nombreDessert << left  << setw(LARGEUR_COLONNE_TICKET) << " desserts" << " : " << right << setw(LARGEUR_COLONNE_PRIX) << totalDessert       << endl
        << " - " << nombreCafe    << left  << setw(LARGEUR_COLONNE_TICKET) << " cafes"    << " : " << right << setw(LARGEUR_COLONNE_PRIX) << totalCafe          << endl
        << " - " << " "           << right << setw(LARGEUR_COLONNE_TICKET) << " total"    << " : " << right << setw(LARGEUR_COLONNE_PRIX) << total              << endl
        << "merci de votre visite" << endl
        << endl;

   AFFICHE_MESSAGE_FIN;
   VIDER_BUFFER;
   return EXIT_SUCCESS;
}
