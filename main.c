#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define MAX_VOITURES 20
#define MAX_LOCATIONS 100


typedef struct
{
    int idvoiture;
    char marque[50];
    char modele[50];
    char couleur[50];
    char datefabrication[50];
    int kilometrage;
    int nbchevaux;
    int prixlocationjour;
    int disponibilite;       
    int etat;               
} Voiture;

typedef struct
{
    int identifiant_location;
    int idevoiture;    
    char nomlocataire[20];
    char datelocation[11];
    char dateretour[11];
    char dernierereclammation[100];
} Historiquelocation;



int main(){
    int numero;

    printf("Bienvenue chers clients\nChoisissez le numero du service :\n");
    printf("1. Louer une voiture\n");
    printf("2. Afficher la description d'une voiture\n");
    printf("3. Supprimer une voiture en panne\n");
    printf("4. Modifier la description et l'etat d'une voiture\n");
    printf("5. Afficher l'historique de location\n");
    printf("6. Retour d'une voiture en cas de reclamation\n");
    printf("7. Ajout d'une voiture\n");
    scanf("%d",&numero);
    switch (numero) {
            case 1:
                Louer();
                break;
            case 2:
                description();
                break;
            case 3:
                supprimer();
                break;
            case 4:
                modifier();
                break;
            case 5:
                historique();
                break;
            case 6:
                retour();
                break;
            case 7:
                Ajout();
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }

    return 0;
}

int nombreVoitures = 0;
Voiture listeVoitures[MAX_VOITURES];

void Ajout(){
    printf("Ajout d'une voiture: \n");
    if (nombreVoitures < MAX_VOITURES) {        
        printf("Identifiant de la voiture : ");
        scanf("%d", &listeVoitures[nombreVoitures].idvoiture);
        printf("Marque : ");
        scanf("%s", listeVoitures[nombreVoitures].marque);
        printf("Modele : ");
        scanf("%s", listeVoitures[nombreVoitures].modele);
        printf("Couleur : ");
        scanf("%s", listeVoitures[nombreVoitures].couleur);
        printf("Date de fabrication : ");
        scanf("%s", listeVoitures[nombreVoitures].datefabrication);
        printf("Kilometrage : ");
        scanf("%d", &listeVoitures[nombreVoitures].kilometrage);
        printf("Nombre de chevaux : ");
        scanf("%d", &listeVoitures[nombreVoitures].nbchevaux);
        printf("Prix de location par jour : ");
        scanf("%d", &listeVoitures[nombreVoitures].prixlocationjour);
        listeVoitures[nombreVoitures].disponibilite = 1; 
        listeVoitures[nombreVoitures].etat = 1; 
        nombreVoitures++;
        printf("Voiture ajoutee\n");
    } else {
        printf("Le nombre maximal de voitures a ete atteint.\n");
    }
}

int nombreLocations = 0;
Historiquelocation historiqueLocations[MAX_LOCATIONS];


void Louer() {
    int idVoiture;
    printf("Entrez l'identifiant de la voiture que vous souhaitez louer : ");
    scanf("%d", &idVoiture);
    
    if (listeVoitures[idVoiture - 1].disponibilite == 0) {
        printf("Cette voiture n'est pas disponible pour location.\n");
        return;
    }

    
    historiqueLocations[nombreLocations].identifiant_location = nombreLocations + 1;
    historiqueLocations[nombreLocations].idevoiture = idVoiture;
    printf("Nom du locataire : ");
    scanf("%s", historiqueLocations[nombreLocations].nomlocataire);
    printf("Date de location : ");
    scanf("%s", historiqueLocations[nombreLocations].datelocation);
    printf("Date de retour : ");
    scanf("%s", historiqueLocations[nombreLocations].dateretour);
    nombreLocations++;

    listeVoitures[idVoiture - 1].disponibilite = 0;
    printf("Voiture louee avec succes.\n");
}



void supprimer() {
    int idVoiture;
    printf("Entrez l'identifiant de la voiture en panne que vous souhaitez supprimer : ");
    scanf("%d", &idVoiture);

    
    listeVoitures[idVoiture - 1].etat = 0; 

    printf("La voiture a été marquée comme en panne \n");
}

void historique() {
    printf("Historique de location :\n");

    if (nombreLocations == 0) {
        printf("Aucune location enregistree \n");
        return;
    }

    for (int i = 0; i < nombreLocations; i++) {
        printf("Location %d:\n", historiqueLocations[i].identifiant_location);
        printf("ID Voiture: %d\n", historiqueLocations[i].idevoiture);
        printf("Locataire: %s\n", historiqueLocations[i].nomlocataire);
        printf("Date Location: %s\n", historiqueLocations[i].datelocation);
        printf("Date Retour: %s\n", historiqueLocations[i].dateretour);
        printf("Derniere Reclammation: %s\n", historiqueLocations[i].dernierereclammation);

        printf("\n");
    }
}

void description() {
    int idVoiture;
    printf("Entrez l'identifiant de la voiture dont vous souhaitez la description : \n");
    scanf("%d", &idVoiture);

    Voiture voiture = listeVoitures[idVoiture - 1];
    
    printf("Description de la voiture %d :\n", voiture.idvoiture);
    printf("Marque : %s\n", voiture.marque);
    printf("Modele : %s\n", voiture.modele);
    printf("Couleur : %s\n", voiture.couleur);
    printf("Date de fabrication : %s\n", voiture.datefabrication);
    printf("Kilometrage : %d\n", voiture.kilometrage);
    printf("Nombre de chevaux : %d\n", voiture.nbchevaux);
    printf("Prix de location par jour : %d\n", voiture.prixlocationjour);
    printf("Disponibilite : %s\n", (voiture.disponibilite == 1) ? "Disponible" : "Non disponible");
    printf("Etat : %s\n", (voiture.etat == 1) ? "En bon etat" : "En panne");
}

void retour() {
    int idVoiture;
    printf("Entrez l'identifiant de la voiture que vous souhaitez retourner : ");
    scanf("%d", &idVoiture);

    int id;


    
    listeVoitures[idVoiture - 1].disponibilite = 1;

    printf("Veuillez saisir  l'identifiant de location : ");
    scanf(" %d", &id);

    
    printf("Veuillez saisir une description de votre reclamation : ");
    scanf(" %s\n", historiqueLocations[id].dernierereclammation);

    

    printf("La voiture a ete retournée avec succes. Merci pour votre reclamation.\n");
}

void modifier() {
    int idVoiture;
    printf("Entrez l'identifiant de la voiture que vous souhaitez modifier : ");
    scanf("%d", &idVoiture);

    
    
    printf("Informations actuelles de la voiture :\n");
    description(idVoiture);

    
    printf("Entrez les nouvelles informations pour la voiture %d :\n", idVoiture);
    printf("Nouvelle marque : ");
    scanf("%s", listeVoitures[idVoiture - 1].marque);
    printf("Nouveau modele : ");
    scanf("%s", listeVoitures[idVoiture - 1].modele);
    printf("Nouvelle couleur : ");
    scanf("%s", listeVoitures[idVoiture - 1].couleur);
    printf("Nouvelle date de fabrication : ");
    scanf("%s", listeVoitures[idVoiture - 1].datefabrication);
    printf("Nouveau kilométrage : ");
    scanf("%d", &listeVoitures[idVoiture - 1].kilometrage);
    printf("Nouveau nombre de chevaux : ");
    scanf("%d", &listeVoitures[idVoiture - 1].nbchevaux);
    printf("Nouveau prix de location par jour : ");
    scanf("%d", &listeVoitures[idVoiture - 1].prixlocationjour);

    printf("Les informations de la voiture ont ete mises à jour avec succes.\n");
}