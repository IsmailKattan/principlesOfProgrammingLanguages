package javaFileReader;
//char için bir düğüm sınıf
public class Node {

	private Node next;
	private char data;
	
	Node(char data)
	{
		this.data = data;
		this.next = null;
	}
	
	//get set metodları
	public void setNext(Node next)
	{
		this.next = next;
	}
	
	public Node getNext()
	{
		return this.next;
	}
	public void setData(char data)
	{
		this.data= data;
	}
	public char getData()
	{
		return this.data;
	}
}
