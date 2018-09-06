package main;

import javax.swing.JOptionPane;

class Node {
	int n; // Armazena um n�mero qualquer
	
	Node esquerdo; // Armazena o n� esquerdo em rela��o � raiz.
	Node direito; // Armazena o n� direito em rela��o � raiz.
	
	/**
	 * Define valores iniciais.
	 * @param n - Um n�mero qualquer.
	 */
	Node(int n) {
		this.n = n; // Inicia 'n' com seu n�mero atual.
		esquerdo = null; // Inicia o n� esquerdo em rela��o � raiz com um valor nulo.
		direito = null; // Inicia o n� direito em rela��o � raiz com um valor nulo.
	}
}

public class Arvore {

	static Node raiz; // Raiz
	
	/**
	 * Define se o valor vai � esquerda ou direita da raiz.
	 * @param nAtual - O n�mero sendo processado atualmente.
	 * @param n - Um n�mero qualquer.
	 * @return	nAtual
	 */
	private Node adcionarRecursivo(Node nAtual, int n) {
	    if (nAtual == null) {
	        return new Node(n); // Retorna uma nova instancia do N�(N�mero qualquer).
	    }
	    
	    if (n < nAtual.n) {
	    	nAtual.esquerdo = adcionarRecursivo(nAtual.esquerdo, n); // Adciona � esquerda em rela��o � raiz.
	    } else if (n > nAtual.n) {
	    	nAtual.direito = adcionarRecursivo(nAtual.direito, n); // Adciona � direita em rela��o � raiz.
	    } else {
	        return nAtual; // Retorna valor processado.
	    }
	 
	    return nAtual; // Retorna valor processado.
	}
	
	/**
	 * Gera uma nova raiz com seus n�s, subsequentemente criando um novo n�vel.	
	 * @param n - Um n�mero qualquer.
	 */
	public void adcionar(int n) {
	    raiz = adcionarRecursivo(raiz, n); // Adciona o valor de retorno do m�todo "adcionarRecursivo" para a raiz. 
	}
	
	/**
	 * Cria uma nova �rvore.	
	 * @return arvore.
	 */
	private static Arvore criarArvore() {
		String aux = ""; // Armazena valor digitado pelo usu�rio.
	    Arvore arvore = new Arvore(); // Instancia uma nova �rvore.
	 
	    JOptionPane.showMessageDialog(null, "Digite 10 n�meros distintos."); // Mostra uma caixa de di�logo na tela com instru��es de procedimento.
	    
	    System.out.println("N�meros: "); // Escreve no console "N�meros: " para simplifica��o na leitura.
	    
	    for (int i = 0; i < 10; i++) {
	    aux = JOptionPane.showInputDialog(null, "Digite o " + (i+1) + "� n�mero: "); // Mostra uma caixa de di�logo que faz o requerimento de valores ao usu�rio.
	    arvore.adcionar(Integer.parseInt(aux)); // Adciona o valor digitado � �rvore.
	    System.out.print(" " + aux + " "); // Escreve no console o �ltimo n�mero digitado.
	    }
	 
	    return arvore; // Retorna valor processado. 
	}
	
	/**
	 * Retorna os valores na ordem raiz-esquerdo-direito.
	 * @param node - O valor do n�(raiz).
	 */
	public static void retornarRED(Node node) {
	    if (node != null) {
	        System.out.print(" " + node.n); // Escreve no console o valor da Raiz atual.
	        retornarRED(node.esquerdo); // Escreve no console o valor � esquerda da Raiz atual.
	        retornarRED(node.direito); // Escreve no console o valor � direita da Raiz atual.
	    }
	}
	
	/**
	 * Retorna os valores na ordem esquerdo-raiz-direito.
	 * @param node - O valor do n�(raiz).
	 */
	public static void retornarERD(Node node) {
	    if (node != null) {
	    	retornarERD(node.esquerdo); // Escreve no console o valor � esquerda da Raiz atual.
	        System.out.print(" " + node.n); // Escreve no console o valor da Raiz atual.
	        retornarERD(node.direito); // Escreve no console o valor � direita da Raiz atual.
	    }
	}
	
	/**
	 * Retorna os valores na ordem esquerdo-direito-raiz.
	 * @param node - O valor do n�(raiz).
	 */
	public static void retornarEDR(Node node) {
	    if (node != null) {
	        retornarEDR(node.esquerdo); // Escreve no console o valor � esquerda da Raiz atual.
	        retornarEDR(node.direito); // Escreve no console o valor � direita da Raiz atual.
	        System.out.print(" " + node.n); // Escreve no console o valor da Raiz atual.
	    }
	}
	
	public static void main(String[] args) {
		String[] opcoes = {"Red", "eRd", "edR"}; // Armazena e inicia as linhas de texto que ser�o exibidas nos bot�es da caixa de di�logo que pede a ordem de retorno desejada.
		int selecao = 0; // Armazena e inicia o valor correspondente ao bot�o pressionado na caixa de di�logo que pede a ordem de retorno desejada.

		criarArvore(); // Chama o m�todo que cria a �rvore Bin�ria.
		
		selecao = JOptionPane.showOptionDialog(null, "Selecione a opera��o: ", "Opera��o", JOptionPane.DEFAULT_OPTION, JOptionPane.PLAIN_MESSAGE, null, opcoes, opcoes[0]);
		// Mostra uma caixa de di�logo com bot�es para selecionar a ordem de retorno de valores desejada.
		
		if (selecao == 0) {
			System.out.println("\nResultado(ordem Raiz-esq-dir): "); // Escreve no console "Resultado(<ordem>) para simplifica��o na leitura.
			retornarRED(raiz); // Chama o m�todo que traz os valores na ordem raiz-esquerdo-direito.
		} else if (selecao == 1) {
			System.out.println("\nResultado(ordem esq-Raiz-dir): "); // Escreve no console "Resultado(<ordem>) para simplifica��o na leitura.
			retornarERD(raiz); // Chama o m�todo que traz os valores na ordem esquerdo-raiz-direito.
		} else if (selecao == 2) {
			System.out.println("\nResultado(ordem esq-dir-Raiz): "); // Escreve no console "Resultado(<ordem>) para simplifica��o na leitura.
			retornarEDR(raiz); // Chama o m�todo que traz os valores na ordem esquerdo-direito-raiz.
		} else {
			System.out.println("Opera��o invalida!"); // Escreve no console "Opera��o invalida!" em caso de erro na opera��o.
			System.exit(0); // Encerra o programa.
		}
		
		System.exit(0); // Encerra o programa.
		
		}
	}
