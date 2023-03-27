/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"


void
cal_1(char *host, int x, int z, char opr)
{
	CLIENT *clnt;
	int  *result_1;
	struct Parametros  suma_1_arg;
	int  *result_2;
	struct Parametros  resta_1_arg;
	int  *result_3;
	struct Parametros  mult_1_arg;
	float  *result_4;
	struct Parametros  div_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, cal, calc_ver, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
if(opr=='+'){
	suma_1_arg.a=x;
	suma_1_arg.b=z;
	//suma_1_arg.operator=opr;
	result_1 = suma_1(&suma_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("El resultado es %d\n",*result_1);
}else if(opr=='-'){
	resta_1_arg.a=x;
	resta_1_arg.b=z;
	//resta_1_arg.operator=opr;
	result_2 = resta_1(&resta_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("El resulatdo es %d\n",*result_2);
}else if(opr=='*'){
	mult_1_arg.a=x;
	mult_1_arg.b=z;
	result_3 = mult_1(&mult_1_arg, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("El resultado es %d\n",*result_3);
}else if(opr=='/'){
	div_1_arg.a=x;
	div_1_arg.b=z;
	if(z == 0){
		printf("Division entre cero no es valida.\n");
		exit(0);
	}else{
	result_4 = div_1(&div_1_arg, clnt);
	if (result_4 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("El resultado es %.2f\n",*result_4);
	}
}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	int x,z;
	char op;
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	printf("\nBienvenido a la calculadora RPC\n");
	printf("+ para suma\n - para Resta\n * para Multiplicar\n / para Dividir\n");
	printf("Ingrese el operador\n");
	scanf("%s",&op);
	printf("Ingrese el primer valor\n");
	scanf("%d",&x);
	printf("Ingrese el segundo valor\n");
	scanf("%d",&z);

	cal_1 (host,x,z,op);
exit (0);
}
