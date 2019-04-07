#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

void iterator(gpointer key, gpointer value, gpointer user_data) {
	printf(user_data, key, *(int*)value);
}

int main(){
	int init = 1;
	GList* list = NULL;
	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
	char newWord[30];
	while(scanf("%s", newWord) != EOF){
		char* placeHolder = g_strdup(newWord);
		int* lookup = g_hash_table_lookup(hash,placeHolder);
		if(lookup == NULL){
			g_hash_table_insert(hash,placeHolder,&init);
		} else {
			int* next = malloc(sizeof(int));
			*next = (*lookup)++;
			g_hash_table_replace(hash,placeHolder,next);
		}
	}
	g_hash_table_foreach(hash, (GHFunc)iterator, "%s occurs %d times\n");
	g_hash_table_destroy(hash);
}
// int main(int argc, char∗∗ argv) {
//  GHashTable∗ hash = g_hash_table_new(g_int_hash, g_int_equal);
//  gint∗ k_one = g_new(gint, 1), ∗k_two = g_new(gint, 1), ∗k_three = g_new(gint, 1);
//  ∗k_one = 1, ∗k_two=2, ∗k_three = 3;
//  g_hash_table_insert(hash, k_one, "one");
//  g_hash_table_insert(hash, k_two, "four");
//  g_hash_table_insert(hash, k_three, "nine");
//  g_hash_table_foreach(hash, (GHFunc)iterator, "The square of %d is %s\n");
//  g_hash_table_destroy(hash);
//  return 0;
// }