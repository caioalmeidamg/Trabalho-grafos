# Trabalho-grafos
Repositório destinado ao trabalho final da disciplina de algoritmo em grafos da Universidade Federal de Lavras - Alunos: Caio Almeida Santos &amp; Julio Henrique Oliveira Mariano.


Durante a pandemia, a demanda por serviços logísticos cresceu em virtude do aumento de compras online (Fonte: “Logística cresce na pandemia com aumento de 
compras pela internet”, por Paula Monteiro,em Pequenas Empresas & Grandes Negócios). Grandes empresas que realizam suas operações de entregas de produtos 
buscam sempre uma redução de custos logísticos, a fim de utilizar tal economia de recursos em outros investimentos de interesse corporativo.
    	Foi proposto portanto que realizemos uma solução em formato de código programável, o qual com uma base de dados em arquivo de formato texto sobre uma região com os custos para desloque
(tempo, distância, preço) deveria definir o menor caminho possível entre pontos distintos.


	Início Programa
		Chamar a leitura dos dados -> avalia se arquivo existe
			Se não pop out erro
				Enquanto o arquivo for possível ler adiciona informações getlines para pegar início/cabeçalho -> para registros respectivos usa um pegar tamanho dado pelo cabeçalho;
					le procurando doubles para registrar vértice -> casting de bits para converter em inteiros;
						Registra os caminhos entre esses em um matriz vector
	


Tendo a base de dados completa a partir de um dados de origem dado seria aplicado o algoritmo de dijkstra em primeira instancia:


      Realiza algortimo de dijkstra para primeira solução
        	Avalia se a primeira restrição e cumprida, caso não aplicaria-se o algoritmo de Floyd-warsha.
         		Caso sim avalia-se se a segunda obdece-> caso não haveria a quebra do grafo no ponto não obdecido e aplicaria-se apartir deste o algoritmo de dijkstra novamente.
  			somando com a primeira parte -> reaavalia se não obdecer muda de algortimo.
         			Se obdecer continua respectivamente...
          
	  
         Essa avaliação ocorreria assim:
                Tendo uma solução percorreria o grafo solução avaliando se ele obedece ao tipo de restrição enviado
                  Caso sim retorna true, caso não retornaria false
                    
          
       
    
  
