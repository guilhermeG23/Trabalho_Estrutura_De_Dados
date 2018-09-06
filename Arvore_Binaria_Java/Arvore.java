package main;

import javax.swing.JOptionPane;

class Node {
	int n; // Armazena um número qualquer
	
	Node esquerdo; // Armazena o nó esquerdo em relação à raiz.
	Node direito; // Armazena o nó direito em relação à raiz.
	
	/**
	 * Define valores iniciais.
	 * @param n - Um número qualquer.
	 */
	Node(int n) {
		this.n = n; // Inicia 'n' com seu número atual.
		esquerdo = null; // Inicia o nó esquerdo em relação à raiz com um valor nulo.
		direito = null; // Inicia o nó direito em relação à raiz com um valor nulo.
	}
}

public class Arvore {

	static Node raiz; // Raiz
	
	/**
	 * Define se o valor vai à esquerda ou direita da raiz.
	 * @param nAtual - O número sendo processado atualmente.
	 * @param n - Um número qualquer.
	 * @return	nAtual
	 */
	private Node adcionarRecursivo(Node nAtual, int n) {
	    if (nAtual == null) {
	        return new Node(n); // Retorna uma nova instancia do Nó(Número qualquer).
	    }
	    
	    if (n < nAtual.n) {
	    	nAtual.esquerdo = adcionarRecursivo(nAtual.esquerdo, n); // Adciona à esquerda em relação à raiz.
	    } else if (n > nAtual.n) {
	    	nAtual.direito = adcionarRecursivo(nAtual.direito, n); // Adciona à direita em relação à raiz.
	    } else {
	        return nAtual; // Retorna valor processado.
	    }
	 
	    return nAtual; // Retorna valor processado.
	}
	
	/**
	 * Gera uma nova raiz com seus nós, subsequentemente criando um novo nível.	
	 * @param n - Um número qualquer.
	 */
	public void adcionar(int n) {
	    raiz = adcionarRecursivo(raiz, n); // Adciona o valor de retorno do método "adcionarRecursivo" para a raiz. 
	}
	
	/**
	 * Cria uma nova Árvore.	
	 * @return arvore.
	 */
	private static Arvore criarArvore() {
		String aux = ""; // Armazena valor digitado pelo usuário.
	    Arvore arvore = new Arvore(); // Instancia uma nova Árvore.
	 
	    JOptionPane.showMessageDialog(null, "Digite 10 números distintos."); // Mostra uma caixa de diálogo na tela com instruções de procedimento.
	    
	    System.out.println("Números: "); // Escreve no console "Números: " para simplificação na leitura.
	    
	    for (int i = 0; i < 10; i++) {
	    aux = JOptionPane.showInputDialog(null, "Digite o " + (i+1) + "º número: "); // Mostra uma caixa de diálogo que faz o requerimento de valores ao usuário.
	    arvore.adcionar(Integer.parseInt(aux)); // Adciona o valor digitado à Árvore.
	    System.out.print(" " + aux + " "); // Escreve no console o último número digitado.
	    }
	 
	    return arvore; // Retorna valor processado. 
	}
	
	/**
	 * Retorna os valores na ordem raiz-esquerdo-direito.
	 * @param node - O valor do nó(raiz).
	 */
	public static void retornarRED(Node node) {
	    if (node != null) {
	        System.out.print(" " + node.n); // Escreve no console o valor da Raiz atual.
	        retornarRED(node.esquerdo); // Escreve no console o valor à esquerda da Raiz atual.
	        retornarRED(node.direito); // Escreve no console o valor à direita da Raiz atual.
	    }
	}
	
	/**
	 * Retorna os valores na ordem esquerdo-raiz-direito.
	 * @param node - O valor do nó(raiz).
	 */
	public static void retornarERD(Node node) {
	    if (node != null) {
	    	retornarERD(node.esquerdo); // Escreve no console o valor à esquerda da Raiz atual.
	        System.out.print(" " + node.n); // Escreve no console o valor da Raiz atual.
	        retornarERD(node.direito); // Escreve no console o valor à direita da Raiz atual.
	    }
	}
	
	/**
	 * Retorna os valores na ordem esquerdo-direito-raiz.
	 * @param node - O valor do nó(raiz).
	 */
	public static void retornarEDR(Node node) {
	    if (node != null) {
	        retornarEDR(node.esquerdo); // Escreve no console o valor à esquerda da Raiz atual.
	        retornarEDR(node.direito); // Escreve no console o valor à direita da Raiz atual.
	        System.out.print(" " + node.n); // Escreve no console o valor da Raiz atual.
	    }
	}
	
	public static void main(String[] args) {
		String[] opcoes = {"Red", "eRd", "edR"}; // Armazena e inicia as linhas de texto que serão exibidas nos botões da caixa de diálogo que pede a ordem de retorno desejada.
		int selecao = 0; // Armazena e inicia o valor correspondente ao botão pressionado na caixa de diálogo que pede a ordem de retorno desejada.

		criarArvore(); // Chama o método que cria a Árvore Binária.
		
		selecao = JOptionPane.showOptionDialog(null, "Selecione a operação: ", "Operação", JOptionPane.DEFAULT_OPTION, JOptionPane.PLAIN_MESSAGE, null, opcoes, opcoes[0]);
		// Mostra uma caixa de diálogo com botões para selecionar a ordem de retorno de valores desejada.
		
		if (selecao == 0) {
			System.out.println("\nResultado(ordem Raiz-esq-dir): "); // Escreve no console "Resultado(<ordem>) para simplificação na leitura.
			retornarRED(raiz); // Chama o método que traz os valores na ordem raiz-esquerdo-direito.
		} else if (selecao == 1) {
			System.out.println("\nResultado(ordem esq-Raiz-dir): "); // Escreve no console "Resultado(<ordem>) para simplificação na leitura.
			retornarERD(raiz); // Chama o método que traz os valores na ordem esquerdo-raiz-direito.
		} else if (selecao == 2) {
			System.out.println("\nResultado(ordem esq-dir-Raiz): "); // Escreve no console "Resultado(<ordem>) para simplificação na leitura.
			retornarEDR(raiz); // Chama o método que traz os valores na ordem esquerdo-direito-raiz.
		} else {
			System.out.println("Operação invalida!"); // Escreve no console "Operação invalida!" em caso de erro na operação.
			System.exit(0); // Encerra o programa.
		}
		
		System.exit(0); // Encerra o programa.
		
		}
	}
