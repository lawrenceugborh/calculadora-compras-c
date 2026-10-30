#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

int main (void) {
    time_t t = time(NULL);         // Pega o timestamp atual
    struct tm data = *localtime(&t);  // Converte para data local

    int repetir;
    int dia = data.tm_mday;
    int mes = data.tm_mon + 1;     // tm_mon começa em 0 (janeiro = 0)
    int ano = data.tm_year + 1900; // tm_year conta a partir de 1900

	int codigoProduto;
	int regiao;
	int continuar = 1; // controla o while (loop da escolha dos produtos)
	float preco = 0.0; // preço do produto (unitário) - começa zerado pois irá receber diferentes valores
	float peso = 0.0; // peso do produto (unitário) - começa zerado pois irá receber diferentes valores
	char nome[50];
	int opcao; // é a variavel "deseja adicionar mais um produto"
	
	// As variáveis começam zeradas porque serão preenchidas conforme o usuário
	// adiciona produtos ao carrinho. Cada item escolhido soma preço e peso nelas.
	// No início da compra, não existe nenhum valor calculado, então todas começam em 0.0.

	float somaProdutos = 0;	// soma dos valores dos produtos no carrinho
	float totalantes = 0; // valor total antes do frete
	float pesoTotal = 0;
	float frete = 0;
	float totalFinal = 0;
	
	char nomesCarrinho[50][50]; 
	int codigosCarrinho[50];
	float pesosCarrinho[50];
	float precosCarrinho[50];
	int qtdProdutos = 0;
	int i;
	
	setlocale(LC_ALL, "Portuguese");
	
	//TELA INICIAL
	while (1) {
	
		while (continuar == 1) {
		 	system("cls");
		 	
		 	printf("ATACADÃO DO AMIGÃO - OS MELHORES PREÇOS DA REGIÃO\n\n");
		 	printf("LISTA DE PRODUTOS:\n");
		 	printf("[1] Mouse Gamer — R$ 89,90 — 0,3 kg\n");
	        printf("[2] Teclado Mecânico — R$ 199,90 — 1,0 kg\n");
	        printf("[3] Headset Bluetooth — R$ 149,90 — 0,5 kg\n");
	        printf("[4] Monitor 240hz — R$ 749,90 — 3,5 kg\n");
	        printf("[5] Cadeira Gamer — R$ 899,90 — 12 kg\n\n");
	
	        printf("Escolha o código do produto: ");
	        scanf("%d", &codigoProduto);
	        
	        if (codigoProduto < 1 || codigoProduto > 5) {
	            printf("\nOpção inválida! Digite um número de 1 a 5.\n");
	            system("pause");
	            system("cls");
	            continue; // Volta para a tela inicial
	    	}
		 
			switch (codigoProduto) {
				case 1:
					strcpy(nome, "Mouse Gamer");
					preco = 89.90;
					peso = 0.3;
					break;
					
				case 2:
					strcpy(nome, "Teclado Mecânico");
					preco = 199.90;
					peso = 1.0;
					break;
				
				case 3: 
					strcpy(nome, "Headset Bluetooth");
					preco = 149.90;
					peso = 0.5;
					break;
					
				case 4: 
					strcpy(nome, "Monitor 240hz");
					preco = 749.90;
					peso = 3.5;
					break;
				
				case 5: 
					strcpy(nome, "Cadeira Gamer");
					preco = 899.90;
					peso = 12.0;
					break;
	
			}
			
			// Salva no carrinho
			strcpy(nomesCarrinho[qtdProdutos], nome);
			codigosCarrinho[qtdProdutos] = codigoProduto;
			pesosCarrinho[qtdProdutos] = peso;
			precosCarrinho[qtdProdutos] = preco;
			qtdProdutos++;
			
			somaProdutos += preco;
			pesoTotal += peso;
			
			
			//2a TELA!!!
			
			system("cls");
			
			// mostra o produto selecionado
			printf("Carrinho\n");
			printf("Produto selecionado: %s\n", nome);
			printf("Preço: R$ %.2f\n", preco);
	    	printf("Peso: %.2f kg\n", peso);
	    	printf("Total: R$ %.2f\n", somaProdutos);
	    	printf("Peso total: %.2f kg\n", pesoTotal);
	    	
	    	// Pergunta do sim ou não - se deseja escolher mais produtos
	    	
	    	while(1) {
	    		printf("\nDeseja adicionar mais um produto?\n");
	    		printf("[1] Sim\n[2] Não\nEscolha: ");
	    		scanf("%d", &opcao);
	    		
	    		if (opcao == 1) {
	    			system("cls");
	    			break;			// volta pro inicio, aquele do while principal
				}
				
				else if (opcao == 2) {
					continuar = 0;
					system("cls");
					printf("========== RESUMO DO CARRINHO ==========\n");
					
					for (i = 0; i < qtdProdutos; i++) {
					    printf("\nProduto %d:", i + 1);
					    printf("\nCódigo: %d", codigosCarrinho[i]);
					    printf("\nNome: %s", nomesCarrinho[i]);
					    printf("\nPeso individual: %.2f kg", pesosCarrinho[i]);
					    printf("\nPreço: R$ %.2f\n", precosCarrinho[i]);
					}
					
					printf("\n-----------------------------------------");
					printf("\nPeso total: %.2f kg", pesoTotal);
					printf("\nValor total dos produtos: R$ %.2f\n", somaProdutos);
					system("pause");
					break;					
				}
				
				else {
					printf("\nOpção inválida!\n");
	                system("pause");
	                system("cls");
				}	
			}
	
	
			
		} // fim while principal
		
		while (1) {
				system("cls");
			    
			    // 3a TELA!!!!
			
			    printf("REGIÃO DE ENTREGA\n");
			    printf("[1] Sul\n");
			    printf("[2] Sudeste\n");
			    printf("[3] Norte\n");
			    printf("[4] Nordeste\n");
			    printf("Escolha uma região: ");
			    scanf("%d", &regiao);
			    
			    if (regiao < 1 || regiao > 4) {
		            printf("\nOpção inválida! Digite um número de 1 a 4.\n");
		            system("pause");
		            system("cls");
		            continue; // Volta para a tela inicial
		    	}
		    	else {
				    switch(regiao){
				    	case 1: // Região Sul
				    		if (pesoTotal <= 2) {
				    			frete = 30;
				            }
							else {
		    		            frete = 50;
				            }
				            break;
				        case 2: // Região Sudeste
				    		if (pesoTotal <= 2) {
				    			frete = 25;
				            }
							else {
		    		            frete = 45;
				            }
				            break;
				        case 3: // Região Norte
				    		if (pesoTotal <= 2) {
				    			frete = 35;
				            }
							else {
		    		            frete = 55;
				            }
				            break;
				        case 4: // Região Nordeste
				    		if (pesoTotal <= 2) {
				    			frete = 40;
				            }
							else {
		    		            frete = 60;
				            }
				            break;
			        }
				}
				break;	
			} // fim while região
			
			system("cls");
			
			totalFinal = somaProdutos + frete;

			printf("RESUMO FINAL\n");
			
			// Lista de produtos novamente
			for (i = 0; i < qtdProdutos; i++) {
			    printf("\nProduto %d:", i + 1);
			    printf("\nCódigo: %d", codigosCarrinho[i]);
			    printf("\nNome: %s", nomesCarrinho[i]);
			    printf("\nPeso individual: %.2f kg", pesosCarrinho[i]);
			    printf("\nPreço: R$ %.2f\n", precosCarrinho[i]);
			}
			
			printf("\n-----------------------------------------\n\n");
			printf("Região da entrega: ");
			
			switch(regiao){
			    case 1: printf("Sul\n"); break;
			    case 2: printf("Sudeste\n"); break;
			    case 3: printf("Norte\n"); break;
			    case 4: printf("Nordeste\n"); break;
			}
			
			printf("Peso total: %.2f kg\n", pesoTotal);
			printf("Frete: R$ %.2f\n", frete);
			printf("Valor final: R$ %.2f\n", totalFinal);
			printf("Data da compra: %02d/%02d/%d\n", dia, mes, ano);
			
			int diaPrevisto = dia +10;
			int mesPrevisto = mes;
			int anoPrevisto = ano;
			
			if(diaPrevisto > 30){
				diaPrevisto -= 30;
				mesPrevisto++;
			}	
			if(mesPrevisto > 12){
				mesPrevisto = 1;
				anoPrevisto++;
			}	
			
			printf("Data prevista de entrega: %02d/%02d/%d\n", diaPrevisto, mesPrevisto, anoPrevisto);
		    
			// Resetando variáveis do carrinho
		    somaProdutos = 0;
		    qtdProdutos = 0;
		    pesoTotal = 0;
		    frete = 0;
		    totalFinal = 0;
		    continuar = 1;
		    printf("\nObrigado pela compra! Volte sempre!\n");
		    system("pause"); 
	}
}
