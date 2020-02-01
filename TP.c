#include <stdio.h>
#include <string.h>

struct Objet{
	char nom[30];
	int prix;
};
typedef struct Objet item;

void triObj(){
	
};

int main() {
	int i = 0;
	
	item obj[50] = {{"minerai d'or", 100},{"minerai d'argent", 50}, {"trompette", 25}, {"lutte", 30}, {"potion", 5}};
	
	//voir son inventaire
	while(strcmp(obj[i].nom,"") >0){
		int nbCase = i + 1;
		printf("Case n %d : %s\n",nbCase,obj[i].nom);
		i += 1;
	}
	
	
	return 0;
}