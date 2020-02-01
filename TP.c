#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Objet{
	char nom[30];
	int prix;
};
typedef struct Objet item;

void inventory(item * inventaire, int perso){
	int i = 0;
	if(perso == 0){
		while(strcmp(inventaire[i].nom,"") >0){
			int nbCase = i + 1;
			printf("Case n %d : %s\n",nbCase,inventaire[i].nom);
			i += 1;
		}
		printf("\n");
	}else{
		while(strcmp(inventaire[i].nom,"") >0){
			int nbCase = i + 1;
			printf("Case : %d : Prix : %d ------ %s\n",nbCase,inventaire[i].prix, inventaire[i].nom);
			i += 1;
		}
		printf("\n");
	}
};

void triObj(item * object,int perso){
	
	char tamponNom[30];
	int tamponPrix;
	
	if(perso == 0){
	//verif tab obj
		for(int i = 0; i < 49; i++){
			
			for(int j = (i+1); j < 50; j++){ 
				
				//vérif tab nom
				if(strcmp(object[j].nom,"") > 0){
					
					for(int k = 1; k < 30; k++){
						
						if(strncmp(object[i].nom, object[j].nom, k) > 0){
							strcpy(tamponNom, object[j].nom);
							strcpy(object[j].nom, object[i].nom);
							strcpy(object[i].nom, tamponNom);
							
							tamponPrix = object[j].prix;
							object[j].prix = object[i].prix;
							object[i].prix = tamponPrix;
							
							k=30;
						}
						
					}	
					
				}
				
			}
		}
	}else{
		for(int i = 0; i < 49; i++){
	
			for(int j = (i+1); j < 50; j++){ 
			
				if(strcmp(object[j].nom,"") > 0){
					
					if(object[i].prix > object[j].prix){
						
						strcpy(tamponNom, object[j].nom);
						strcpy(object[j].nom, object[i].nom);
						strcpy(object[i].nom, tamponNom);
						
						tamponPrix = object[j].prix;
						object[j].prix = object[i].prix;
						object[i].prix = tamponPrix;
						
					}
				}
			
			}
		}
	}
	
};

void addObj(item * object,int perso){
	char nameObj[30];
	int priceObj;
	
	printf("\nQuel objet souhaitez vous donner au Marchand ? (ecirvez le nom)\n");
	scanf("%s", &nameObj);
	printf("\nQu'elle est la valeur de cet objet ? (le prix)\n");
	scanf("%d", &priceObj);
	
	for(int i = 0; i < 50; i++){
		if(strcmp(object[i].nom, "") == 0){
			strcpy(object[i].nom, nameObj);
			object[i].prix = priceObj;
			
			i = 50;
		}
	}
	
	triObj(&object[0], perso);
};

void buyItem(item * inventaire, item * object, int posItem){
	for(int i = 0; i < 50; i++){
		if(strcmp(inventaire[i].nom, "") > 0){
			strcpy(inventaire[i].nom, object[posItem].nom);
			inventaire[i].prix, object[posItem].prix;
			
			i = 50;
		}
	}
};

int main() {
	
	//initialisation des variables
	int action;
	int choix;
	//booléen pour les fonctions
	int perso;
	
	int end = 0;
	int share;
	
	//inventaire de base du joueur
	item joueur[50] = {{"minerai d'or", 100},{"minerai d'argent", 50}, {"trompette", 25}, {"lutte", 30}, {"potion", 5}};
	//inventaire de base du marchand
	item marchand[50] = {{"neige", 100},{"herbe", 50}, {"champignon", 25}, {"mediator de la destine", 30}, {"deter'gens", 5}};
	
	//printf("pointeur du tableau : %d\n", &obj);
	
	printf("Vous voici au carrefour.\nEn observant les alentours vous remarquez un marchand et decidez d'aller à sa rencontre.\n");
	printf("\nMarchand : \"Bonjour Voyageur !\n");
	
	
	
	while(end == 0){
		
		share = 0;
		
		printf("J'ai plein de produits pour toi ! Que veux tu ? Il y a des prix, mais pour toi ce sera cadeau !\n1 : regarder votre inventaire\n2 : regarder ce que vend le marchand ");
		scanf("%d", &action);
		
		while(action != 1 && action != 2){
			printf("\nMarchand : \"Ne te moque pas de moi petit ! \nJ'ai plein de produits pour toi ! Que veux tu ? Il y a des prix, mais pour toi ce sera cadeau !\n");
			printf("\n1 : regarder votre inventaire\n2 : regarder ce que vend le marchand\n");
			scanf("%d", &action);
		}
		
		if(action == 1){
			perso = 0;
			//tri de l'inventaire du joueur
			triObj(&joueur[0],perso);
		
			//voir son inventaire
			inventory(&joueur[0],perso);
		}
		
		if(action == 2){
			
			
			perso = 1;
			
			while(share == 0){
				
				triObj(&marchand[0],perso);
				
				inventory(&marchand[0], perso);
				
				printf("mMarchand : \"Tu veux acheter un truc, ou me filer un objet ?\"\n1 : Acheter \n2 : Donner\n3 : Rien\n");
				scanf("%d", &choix);
				
				while(choix != 1 && choix != 2 && choix != 3){
					printf("mMarchand : \"Ne te moque pas de moi ! Tu veux acheter un truc, ou me filer un objet ?\"\n1 : Acheter \n2 : Donner\n3 : Rien\n");
					scanf("%d", &choix);
				}
				
				if(choix == 1){
					printf("Qu'est ce que tu veux ? (entre la case)");
					scanf("%d", &choix);
					buyItem(&joueur[0], &marchand[0], choix);
				}
				
				if(choix == 2){
					addObj(&marchand[0], perso);
				}
				
				if(choix == 3){
					printf("\nMarchand : \"Tout ca pour ca ? Arrete de me faire perdre du temps !\"\n");
				}
			
			
				printf("\nT'as encore besoin d'un truc ?\n1 : Oui / 2 : Non\n");
				scanf("%d", &action);
				
				while(action != 1 && action != 2){
					printf("Arrete de repondre a cote ! T'as encore besoin d'un truc ?\n1 : Oui / 2 : Non\n");
					scanf("%d", &action);
				}
				
				if(action == 2){
					share = 1;
				}
				
			}
		}
		printf("\nTu veux continuer avec le marchand ?\n1 : Oui / 2 : Non\n");
		scanf("%d", &action);
		
		while(action != 1 && action != 2){
			printf("Arrete de repondre a cote ! Tu veux continuer avec le marchand ?\n1 : Oui / 2 : Non\n");
			scanf("%d", &action);
		}
		
		if(action == 2){
			end = 1;
		}
	}
	return 0;
}