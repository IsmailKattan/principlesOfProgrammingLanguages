package javaFileReader;
//bu sısnıf yorum sayısı ve yazılan bir yorum targeti bir yorum içinde olup olmadığını bilmek amacıyla yapımıştır
public class CommentProcesser {
	private SNode top;
	private int count;

	
	CommentProcesser() // kuruyucu
	{
		top = null;
		count = 0;
	}
	
	public int getcount() // var olan /* veya/**  sayısı döndürür 
	{
		return count;
	}
	
	public void push(String data)  // veri ekler (/** veya /*)
	{
		SNode node = new SNode(data);
		if(top != null)
		{
			node.setNext(top);
			
		}
		top = node;
		this.count++;
	}
	public void pull()     // veri çıkarır (/** veya /*)
	{
		if(top!=null)
		{
			top = top.getNext();
			this.count--;
		}
	}
	
	public String getTop() // en üstteki elemanı geri dödürür
	{
		if(top != null)
		{
			return top.getData();
		}
		else
		{
			System.out.println("tepe noktası boş !!!");
			return "";
		}
	}
	public void printAll() {  // yazdırma işlemi 
	    SNode currentNode = top;
	    while(currentNode != null) {
	        System.out.print(currentNode.getData() + " ");
	        currentNode = currentNode.getNext();
	    }
	    System.out.print("\n");
	}
}
