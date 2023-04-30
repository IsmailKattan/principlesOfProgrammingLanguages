package javaFileReader;
//parantez sayısını bilmek üzer yapılmıştır
public class Stack {
	
	private Node top;
	private int count;
	
	Stack()
	{
		top = null;
		count = 0;
	}
	
	public int getcount()
	{
		return count;
	}
	
	public void push(char data)  //veri ekleme
	{
		Node node = new Node(data);
		if(top != null)
		{
			node.setNext(top);
		}
		top = node;
		this.count++;
	}
	public void pull()  // veri çıkarma
	{
		if(top!=null)
		{
			top = top.getNext();
			this.count--;
		}
	}
	
	
	public char getTop() //en üstteki veri döndürür
	{
		if(top != null)
		{
			return top.getData();
		}
		else
		{
			System.out.println("tepe noktası boş !!!");
			return '0';
		}
	}
	public void printAll() {// yazdırma işlemi 
	    Node currentNode = top;
	    while(currentNode != null) {
	        System.out.print(currentNode.getData() + " ");
	        currentNode = currentNode.getNext();
	    }
	    System.out.print("\n");
	}
	
}
