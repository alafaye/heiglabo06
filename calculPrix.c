/* Fichier : angle.c
 * Auteur  : Alexandre Lafaye
 * Date    : 08.10.2015
 *
 * But     :  Labo05: Calcul d'un montant d'une commande de pieces electroniques.
 *
 *
 * Remarque(s) : 
 *
 *
 * Compilateur : g++
 * Debuggueur : gdb
 */
//Pour Windows
//#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    printf("Programme calculant un prix total à partir d'une liste de composants.\n");
    //Les termes de petit/grand sont en rapport avec la quantité.
    const double PRIX_PETIT_CIRCUIT=.15, PRIX_GRAND_CIRCUIT=.12;
    const double PRIX_DIODE_PETIT=1, PRIX_DIODE_MOYEN=.8, PRIX_DIODE_GRAND=.7;
    const double PRIX_CONDO_PETIT=1.55, PRIX_CONDO_GRAND=1.25;
    const double PRIX_PAQUET_RESI=1.8;
    const double TVA=8;

    int qte_diode, qte_condo, qte_resi, nbre_paquet_resi;
    double surface_circuit, longueur_circuit, largeur_circuit; 
    double prix_tva=0, prix_ht=0, prix_ttc=0, prix_surface=0;
    double prix_diode=0, prix_condo=0, prix_resi=0;

    //Entrée des valeurs par l'utilisateur.
    printf("Pour effectuer une commande, entrez les quantités à chaque étape.\n");
    printf("Longueur du circuit demandé: ");
    scanf("%lf", &longueur_circuit);
    fflush(stdin);
    printf("Largeur du circuit demandé: ");
    scanf("%lf", &largeur_circuit);
    fflush(stdin);
    printf("Quantité de diodes souhaitées: ");
    scanf("%d", &qte_diode);
    fflush(stdin);
    printf("Quantité de condensateurs souhaités: ");
    scanf("%d", &qte_condo);
    fflush(stdin);
    printf("Quantité de résistances souhaitées: ");
    scanf("%d", &qte_resi);

    surface_circuit = largeur_circuit*longueur_circuit;

    //Analyse des cas pour déterminer les prix
    if(surface_circuit<200)
	prix_surface = PRIX_PETIT_CIRCUIT * surface_circuit;
    else if(surface_circuit>=200)
	prix_surface = PRIX_GRAND_CIRCUIT * surface_circuit;

    if(qte_diode<10)
	prix_diode = PRIX_DIODE_PETIT * qte_diode;
    else if(qte_diode>=10 && qte_diode<20)
	prix_diode = PRIX_DIODE_MOYEN * qte_diode;
    else if(qte_diode>=20)
	prix_diode = PRIX_DIODE_GRAND * qte_diode;

    if(qte_condo<10)
	prix_condo = PRIX_CONDO_PETIT * qte_condo;
    else if(qte_condo>=10)
	prix_condo = PRIX_CONDO_GRAND * qte_condo;

    nbre_paquet_resi = ceil((double)qte_resi/10.);
    prix_resi = PRIX_PAQUET_RESI * nbre_paquet_resi;

    prix_ht = prix_surface + prix_diode + prix_condo + prix_resi;
    prix_tva = prix_ht * TVA/100;
    prix_ttc = prix_ht + prix_tva;

    printf("=============================================================\n");
    printf("Quantite composants:                     Prix HT\n\n");
    printf("%10.2f cm2 circuit imprime:          %10.2f\n", surface_circuit, prix_surface);
    printf("%10d Diodes:                       %10.2f\n", qte_diode, prix_diode);
    printf("%10d Condensateurs:                %10.2f\n", qte_condo, prix_condo);
    printf("%10d Paquets resistances:          %10.2f\n", nbre_paquet_resi, prix_resi);
    printf("                                    + -------------\n");
    printf("Prix total hors taxes:                   %10.2f\n", prix_ht);
    printf("TVA a %.2f%:                             %10.2f\n", TVA, prix_tva);
    printf("                                    + -------------\n");
    printf("Prix total toutes taxes comprises:       %10.2f\n\n\n", prix_ttc);

    system("PAUSE");
    return EXIT_SUCCESS;
}
