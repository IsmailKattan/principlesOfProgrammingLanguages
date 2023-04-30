package javaFileReader;
//String düğüm sınıf
public class SNode {

	private SNode next;
	private String data;
	
	SNode(String data)
	{
		this.data = data;
		this.next = null;
	}
	// get set metodları
	public void setNext(SNode next)
	{
		this.next = next;
	}
	
	public SNode getNext()
	{
		return this.next;
	}
	public void setData(String data)
	{
		this.data= data;
	}
	public String getData()
	{
		return this.data;
	}
}
