#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void iterator(gpointer key, gpointer value, gpointer user_data) {
	printf(user_data, key, *(gint*)value);
	g_free(value);
	g_free(key);
}

int main(){
	GList* list = NULL;
	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
	char newWord[30];
	char bannedCharacters[] = "',.;\"!?()&-_+=[]{}/<>";
	while(scanf("%s", newWord) != EOF){
		char* placeHolder = g_strdup(newWord);
		int* lookup = g_hash_table_lookup(hash,placeHolder);
		if(lookup == NULL){
			int* new = malloc(sizeof(int));
			*new = 1;
			g_hash_table_insert(hash,placeHolder,new);
		} else {
			printf("%d\n", *lookup);
			int* next = malloc(sizeof(int));
			*next = (*lookup)+1;
			free(lookup);
			g_hash_table_replace(hash,placeHolder,next);
		}
	}
	g_hash_table_foreach(hash, (GHFunc)iterator, "%s occurs %d times\n");
	g_hash_table_destroy(hash);
}