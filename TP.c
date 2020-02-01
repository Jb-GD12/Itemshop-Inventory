#include <stdio.h>
#include <string.h>

struct Objet{
	char nom[30];
	int prix;
};
typedef struct Objet item;

void triObj(){
	
};

void inventory(){
	
};

int main() {
	
	
	item obj[50] = {{"minerai d'or", 100},{"minerai d'argent", 50}, {"trompette", 25}, {"lutte", 30}, {"potion", 5}};
	
	
	printf("pointeur du tableau : %d", &obj);
	//voir son inventaire
	int i = 0;
	
	while(strcmp(obj[i].nom,"") >0){
		int nbCase = i + 1;
		printf("Case n %d : %s\n",nbCase,obj[i].nom);
		i += 1;
	}
	
	//ajouter un élément à son inventaireire
	char nameObj[30];
	int priceObj;
	
	printf("\nQuel objet souhaitez vous rajouter dans votre inventaire ? (ecirvez le nom\n");
	scanf("%s", nameObj);
	printf("\nQu'elle est la valeur de cet objet ?\n");
	scanf("%d", priceObj);
	
	printf("vous avez rajoute l'objet qui a une valeur de a votre inventaire");
	
	
	return 0;
}