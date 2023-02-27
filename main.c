#include "source/source.h"
#include <stdio.h>
#include <stdlib.h>

int cont = 0;

void search(Node *init, Route **routes, int depth) {
	if (init->child != NULL) {
		for (int i = 0; i < init->numRel; i++) {
			Node *next = (Node*) init->child[i];
			printf("Salto de %s a %s\n", init->name, next->name);
			depth++;
			search(next, routes, depth);
			depth--;
			printf("Vuelvo a %s\n", init->name);
			//appendRelationship(routes[cont]->nodes, init, routes[cont]->steps);
		}
	} else {
		printf("¡He llegado a G!\n");
		routes[0]->steps = depth;
		cont++;
		printf("Iteracion: %i, profundidad: %i\n", cont, depth);
	}
}

int main() {

	Node A;
	Node B;
	Node C;
	Node D;
	Node E;
	Node F;
	Node G;

	/*
	 * CREACIÓN DEL GRAFO A RECORRER
	 */

	Node **nodeA = malloc(sizeof(Node*) * 2);
	nodeA[0] = &B;
	nodeA[1] = &C;
	Node **nodeB = malloc(sizeof(Node*) * 3);
	nodeB[0] = &C;
	nodeB[1] = &D;
	nodeB[2] = &F;
	Node **nodeC = malloc(sizeof(Node*) * 2);
	nodeC[0] = &E;
	nodeC[1] = &F;
	Node **nodeD = malloc(sizeof(Node*) * 1);
	nodeD[0] = &F;
	Node **nodeE = malloc(sizeof(Node*) * 1);
	nodeE[0] = &G;
	Node **nodeF = malloc(sizeof(Node*) * 2);
	nodeF[0] = &E;
	nodeF[1] = &G;

	/*
	 * INICIALIZACIÓN DE TODOS LOS NODOS CON SUS RESPECTIVAS RELACIONES
	 */

	initializeNode(&A, "A", nodeA, 2);
	initializeNode(&B, "B", nodeB, 3);
	initializeNode(&C, "C", nodeC, 2);
	initializeNode(&D, "D", nodeD, 1);
	initializeNode(&E, "E", nodeE, 1);
	initializeNode(&F, "F", nodeF, 2);
	initializeNode(&G, "G", NULL, 0);

	Route** routes = malloc(sizeof(Route*)+1);
	Route R1;

	R1.steps = 0;
	R1.nodes = malloc(sizeof(Node*));

	/*
	 * LLAMADA A LA FUNCIÓN RECURSIVA DE BÚSQUEDA
	 * SU FUNCIÓN SERÁ ENCONTRAR AQUEL NODO QUE NO TENGA TRANSICIONES A MÁS NODOS
	 */

	search(&A, routes, 0);
	printf("Despues de la busqueda, concluimos que hay %i recorridos distintos\n", cont);

	return 0;
}

